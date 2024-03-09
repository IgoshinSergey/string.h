#include <errno.h>
#include <limits.h>

#include "s21_string.h"

long long s21_parce(const char **char_ptr, const char **endp, char **endptr,
                    int base, int width, unsigned long cutoff, int cutlim,
                    bool *overflow, bool *error, bool zero);
int s21_base_recognition(const char **char_ptr, const char **endp, int base,
                         int *width, bool *zero);
int s21_sign_recognition(const char **char_ptr, int *width);
int s21_specifier_base(form_specier formspec);
int isspace(int c);

long long s21_strtol(const char *str_ptr, char **endptr, form_specier *formspec,
                     bool *successful_assignments_num) {
  const char *char_ptr = str_ptr, *endp = S21_NULL;
  bool is_neg = 0, overflow = 0, error = 0, zero = 0;
  unsigned long long n = 0UL, cutoff = 0UL;
  int cutlim = 0;
  int base = s21_specifier_base(*formspec);
  error = (base < 0 || base == 1 || base > 36);
  if (!error) {
    endp = str_ptr;
    while (isspace(*char_ptr)) char_ptr++;
    is_neg = (s21_sign_recognition(&char_ptr, &formspec->width) == -1);
    if (!formspec->width) error = 1;
    base =
        s21_base_recognition(&char_ptr, &endp, base, &formspec->width, &zero);
    cutoff = (is_neg) ? -(LLONG_MIN / base) : LLONG_MAX / base;
    cutlim = (is_neg) ? -(LLONG_MIN % base) : LLONG_MAX % base;
    n = s21_parce(&char_ptr, &endp, endptr, base, formspec->width, cutoff,
                  cutlim, &overflow, &error, zero);
  }
  if (error) {
#ifdef EINVAL
    errno = EINVAL;
    n = 0L, is_neg = 0;
#endif
  }
  if (endptr) *endptr = (char *)endp;
  if (overflow) {
    errno = ERANGE;
    n = ((is_neg) ? LLONG_MIN : LLONG_MAX);
  }
  if (successful_assignments_num) {
    (*successful_assignments_num) += !error;
  }
  return (long long)((is_neg) ? -n : n);
}

long long s21_parce(const char **char_ptr, const char **endp, char **endptr,
                    int base, int width, unsigned long cutoff, int cutlim,
                    bool *overflow, bool *error, bool zero) {
  bool loopi = 0;
  unsigned long long n = 0UL;
  while (1) {
    if (!width) break;
    int c;
    if (**char_ptr >= 'A')
      c = ((**char_ptr - 'A') & (~('a' ^ 'A'))) + 10;
    else if (**char_ptr <= '9')
      c = **char_ptr - '0';
    else
      break;
    if (c < 0 || c >= base) {
      if (!loopi && !zero) *error = 1;
      break;
    }
    *endp = ++(*char_ptr);
    if (*overflow) {
      if (endptr) continue;
      break;
    }
    if (n > cutoff || (n == cutoff && c > cutlim)) {
      *overflow = 1;
      continue;
    }
    n = n * base + c;
    width--;
    loopi = 1;
  }
  return n;
}

int s21_base_recognition(const char **char_ptr, const char **endp, int base,
                         int *width, bool *zero) {
  if (**char_ptr == '0') {
    *zero = 1;
    (*char_ptr)++, (*width)--;
    *endp = *char_ptr;
    if (*width) {
      if (base == 16 && (**char_ptr == 'X' || **char_ptr == 'x')) {
        (*char_ptr)++, (*width)--;
      } else if (base == 2 && (**char_ptr == 'B' || **char_ptr == 'b')) {
        (*char_ptr)++, (*width)--;
      } else if (base == 0) {
        if (**char_ptr == 'X' || **char_ptr == 'x') {
          base = 16, (*char_ptr)++, (*width)--;
        } else if (**char_ptr == 'B' || **char_ptr == 'b') {
          base = 2, (*char_ptr)++, (*width)--;
        } else {
          base = 8;
        }
      }
    } else {
      base = 10;
    }
  } else if (base == 0) {
    base = 10;
  }
  return base;
}

int s21_sign_recognition(const char **char_ptr, int *width) {
  int sign_val = 0;
  if (**char_ptr == '+') {
    sign_val = 1, (*char_ptr)++, (*width)--;
  } else if (**char_ptr == '-') {
    sign_val = -1, (*char_ptr)++, (*width)--;
  }
  return sign_val;
}

int s21_specifier_base(form_specier formspec) {
  int base = 0;
  if (formspec.specifier == 'd')
    base = 10;
  else if (formspec.specifier == 'i')
    base = 0;
  else if (formspec.specifier == 'o')
    base = 8;
  else if (formspec.specifier == 'x' || formspec.specifier == 'X')
    base = 16;
  else if (formspec.specifier == 'u')
    base = 10;
  else if (formspec.specifier == 'p')
    base = 16;
  return base;
}