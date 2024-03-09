#include <errno.h>
#include <float.h>
#include <math.h>

#include "s21_string.h"

int isspace(int c);

bool is_digit(char c) {
  bool is_dig = false;
  if (c >= '0' && c <= '9') is_dig = true;
  return is_dig;
}

int is_sign(const char **str_ptr, form_specier *formspec) {
  int is_neg = 0;
  if (**str_ptr == '+') formspec->width--, (*str_ptr)++;
  if (**str_ptr == '-') {
    is_neg++;
    if (!formspec) formspec->width--;
    (*str_ptr)++;
  }
  return is_neg;
}

bool is_num_consept(const char **str_ptr, form_specier *formspec,
                    long double *n, bool *error) {
  bool readed = false;
  if (((*str_ptr)[0] == 'N' || (*str_ptr)[0] == 'n') &&
      ((*str_ptr)[1] == 'A' || (*str_ptr)[1] == 'a') &&
      ((*str_ptr)[2] == 'N' || (*str_ptr)[2] == 'n')) {
    if (formspec->width >= 3 || formspec->width < 0) {
      *n = NAN;
      *str_ptr += 3;
      formspec->width -= 3;
    } else {
      *error = true;
    }
    readed = true;
  } else if (((*str_ptr)[0] == 'I' || (*str_ptr)[0] == 'i') &&
             ((*str_ptr)[1] == 'N' || (*str_ptr)[1] == 'n') &&
             ((*str_ptr)[2] == 'F' || (*str_ptr)[2] == 'f')) {
    if (formspec->width >= 3 || formspec->width < 0) {
      *n = INFINITY;
      *str_ptr += 3;
      formspec->width -= 3;
    } else {
      *error = true;
    }
    readed = true;
  }
  return readed;
}

long double dec_digit_indicator(const char *str_ptr, char **endptr,
                                form_specier *formspec, bool *error,
                                bool *readed) {
  long double dec_digit = 0.;
  if (*str_ptr == '.' && formspec->width) {
    char before_point = *(str_ptr - 1), after_point = *(str_ptr + 1);
    if (is_digit(after_point) && !is_digit(before_point)) {
      --formspec->width;
      dec_digit = s21_strtol(++str_ptr, endptr, formspec, (bool *)S21_NULL);
    } else if (!is_digit(after_point) && is_digit(before_point)) {
      --formspec->width;
      *endptr = (char *)(++str_ptr), dec_digit = 0;
    } else if (is_digit(after_point) && is_digit(before_point)) {
      --formspec->width;
      dec_digit = s21_strtol(++str_ptr, endptr, formspec, (bool *)S21_NULL);
    } else {
      if (error) *error = true;
    }
    while ((int)dec_digit != 0) dec_digit /= 10.0;
    if (readed) *readed = true;
  } else {
    *endptr = (char *)str_ptr;
  }
  return dec_digit;
}

long double degree_indicator(long double num, const char *str_ptr,
                             char **endptr, form_specier *formspec) {
  bool is_neg = false;
  long double degval = 0, result = num;
  if ((*str_ptr == 'E' || *str_ptr == 'e') && formspec->width) {
    formspec->width--;
    if (formspec->width) {
      str_ptr++;
      if (is_sign(&str_ptr, formspec)) is_neg = true;
      degval = s21_strtol(str_ptr, endptr, formspec, (bool *)S21_NULL);
      result = (is_neg) ? num / pow(10.0, degval) : num * pow(10.0, degval);
    }
  } else {
    *endptr = (char *)str_ptr;
  }
  return result;
}

long double s21_strtod(const char *str_ptr, char **endptr,
                       form_specier formspec,
                       bool *successful_assignments_num) {
  const char *char_ptr = str_ptr, *endp;
  bool is_neg = false, overflow = false, error = false;
  long double n = 0.;

  while (isspace(*char_ptr)) char_ptr++;

  if (is_sign(&char_ptr, &formspec)) is_neg = true;

  if (!formspec.width) error = true;

  bool readed = false;

  readed = is_num_consept(&char_ptr, &formspec, &n, &error);

  if (!readed) {
    char *end1 = S21_NULL;
    n += dec_digit_indicator(char_ptr, &end1, &formspec, &error, &readed);
    char_ptr = (end1) ? end1 : char_ptr;
    endp = char_ptr;
  }

  bool loopi = false;
  while (true && !error && formspec.width && !readed) {
    int c;
    if (*char_ptr <= '9') {
      c = *char_ptr - '0';
    } else {
      if (!loopi) {
        error = true;
      }
      break;
    }
    if (c < 0 || c >= 10) {
      if (!loopi) error = true;
      break;
    }
    endp = ++char_ptr;
    if (overflow) {
      if (endptr) continue;
      break;
    }
    if (n > LDBL_MAX) {
      overflow = 1;
      continue;
    }
    n = n * 10. + c;
    formspec.width--;
    loopi = true;
  }

  if (!error && !overflow) {
    char *end = S21_NULL;
    n += dec_digit_indicator(char_ptr, &end, &formspec, (bool *)S21_NULL,
                             (bool *)S21_NULL);
    char_ptr = (end) ? end : char_ptr;
    endp = char_ptr;
    n = degree_indicator(n, char_ptr, &end, &formspec);
    char_ptr = (end) ? end : char_ptr;
    endp = char_ptr;
  }

  if (endptr) *endptr = (char *)endp;
  if (overflow) {
    errno = ERANGE;
    return (is_neg) ? LDBL_MIN : LDBL_MAX;
  }
  *successful_assignments_num += !error;
  return (is_neg) ? -n : n;
}