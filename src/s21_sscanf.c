#include <stdlib.h>

#include "s21_string.h"

int SUCCESS_COUNT = 0;

int s21_sscanf(const char *str, const char *format, ...) {
  bool error = 0, field_scanned = false, format_scanned = false;
  int success_read = 0;
  char *str_ptr = (char *)str;
  char *format_ptr = (char *)format;
  va_list arglist;

  va_start(arglist, format);
  field_scanned = (s21_strspn(str, " \n\t") != s21_strlen(str));
  for (; *format_ptr; format_ptr++) {
    if (*(format_ptr) == '%') {
      form_specier formspec = {0};
      if (*(++format_ptr) == '*') {
        formspec.no_read = true, ++format_ptr;
      }
      formspec.width =
          (formspec.width = s21_strtol(format_ptr, &format_ptr,
                                       &(form_specier){-1, false, {0, 0}, 'd'},
                                       (bool *)S21_NULL))
              ? formspec.width
              : -1;
      error = s21_length_specier(&format_ptr, &formspec);
      if (s21_strchr(SPECIFIES, *format_ptr)) {
        format_scanned = true;
        formspec.specifier = *format_ptr;
        bool to_break = false;
        if (formspec.specifier != 'n' && formspec.specifier != 'c')
          str_ptr += s21_strspn(str_ptr, " \n\t");
        success_read +=
            s21_float_specifier(&str_ptr, formspec, &arglist, &to_break);
        success_read += s21_char_specier(&str_ptr, formspec, &arglist);
        success_read += s21_int_specier(&str_ptr, formspec, &arglist);
        success_read += s21_uint_specier(&str_ptr, formspec, &arglist);
        success_read += s21_ptr_specier(&str_ptr, formspec, &arglist);
        s21_scanned_char_num_specier(str, str_ptr, formspec, &arglist);
        success_read += s21_string_specifier(&str_ptr, formspec, &arglist);
        error = s21_percent_specier(&str_ptr, formspec);
        if (error) success_read--;
        if (to_break) break;
        continue;
      }
    } else {
      str_ptr += s21_strspn(str_ptr, " \n\t");
      if (*str_ptr == *format_ptr) str_ptr++;
      str_ptr += s21_strspn(str_ptr, " \n\t");
      continue;
    }
  }
  va_end(arglist);
  if (!field_scanned && format_scanned) success_read = -1;
  return success_read;
}

bool s21_length_specier(char **format_ptr, form_specier *formspec) {
  bool error = false;
  if (**format_ptr == 'L') {
    formspec->length[0] = **format_ptr, (*format_ptr)++;
  } else if (**format_ptr == 'h' || **format_ptr == 'l') {
    formspec->length[0] = **format_ptr, (*format_ptr)++;
    if (**format_ptr == formspec->length[0])
      formspec->length[1] = **format_ptr, (*format_ptr)++;
    else if (**format_ptr == 'l' || **format_ptr == 'L' || **format_ptr == 'h')
      error = true;
  }
  return error;
}

// Символ
bool s21_char_specier(char **str_ptr, form_specier formspec, va_list *arglist) {
  bool success_read = false;
  if (formspec.specifier == 'c') {
    if (!formspec.no_read) *va_arg(*arglist, char *) = **str_ptr;
    (*str_ptr)++;
    success_read = true;
  }
  return success_read && !formspec.no_read;
}

// Знаковое десятичное целое число
bool s21_int_specier(char **str_ptr, form_specier formspec, va_list *arglist) {
  bool success_read = 0;
  if (s21_strchr(INT_SPECIERS, formspec.specifier)) {
    long long output = s21_strtol(*str_ptr, str_ptr, &formspec, &success_read);
    if (!formspec.no_read && success_read) {
      if (formspec.length[0] == 'h' && formspec.length[1] == 'h') {
        *va_arg(*arglist, char *) = (char)output;
      } else if (formspec.length[0] == 'h') {
        *va_arg(*arglist, short int *) = (short int)output;
      } else if (formspec.length[0] == 'l' && formspec.length[1] == 'l') {
        *va_arg(*arglist, long long int *) = (long long int)output;
      } else if (formspec.length[0] == 'l') {
        *va_arg(*arglist, long int *) = (long int)output;
      } else if (formspec.length[0] == 0 && formspec.length[1] == 0) {
        *va_arg(*arglist, int *) = (int)output;
      }
    }
  }
  return success_read && !formspec.no_read;
}

// Безнаковое десятичное целое число
bool s21_uint_specier(char **str_ptr, form_specier formspec, va_list *arglist) {
  bool success_read = 0;
  if (formspec.specifier == 'u') {
    long unsigned int output = (long unsigned int)s21_strtol(
        *str_ptr, str_ptr, &formspec, &success_read);
    if (!formspec.no_read && success_read) {
      if (formspec.length[0] == 'h' && formspec.length[1] == 'h') {
        *va_arg(*arglist, unsigned char *) = (unsigned char)output;
      } else if (formspec.length[0] == 'h') {
        *va_arg(*arglist, short unsigned int *) = (short unsigned int)output;
      } else if (formspec.length[0] == 'l') {
        *va_arg(*arglist, long unsigned int *) = (long unsigned int)output;
      } else if (formspec.length[0] == 0 && formspec.length[1] == 0) {
        *va_arg(*arglist, unsigned int *) = (unsigned int)output;
      }
    }
  }
  return success_read && !formspec.no_read;
}

// // Адрес указателя
bool s21_ptr_specier(char **str_ptr, form_specier formspec, va_list *arglist) {
  bool success_read = false;
  if (formspec.specifier == 'p') {
    void *output =
        (void *)s21_strtol(*str_ptr, str_ptr, &formspec, &success_read);
    if (!formspec.no_read && success_read) *va_arg(*arglist, void **) = output;
  }
  return success_read && !formspec.no_read;
}

// // Количество символов, считанных до появления %n
bool s21_scanned_char_num_specier(const char *str, char *str_ptr,
                                  form_specier formspec, va_list *arglist) {
  bool success_read = false;
  if (formspec.specifier == 'n') {
    long long output = (str_ptr - str);
    if (!formspec.no_read) {
      if (formspec.length[0] == 'h' && formspec.length[1] == 'h') {
        *va_arg(*arglist, char *) = (char)(str_ptr - str);
      } else if (formspec.length[0] == 'h') {
        *va_arg(*arglist, short int *) = (short int)output;
      } else if (formspec.length[0] == 'l' && formspec.length[1] == 'l') {
        *va_arg(*arglist, long long int *) = (long long)output;
      } else if (formspec.length[0] == 'l') {
        *va_arg(*arglist, long int *) = (long int)output;
      } else if (formspec.length[0] == 0 && formspec.length[1] == 0) {
        *va_arg(*arglist, int *) = (int)output;
      }
    }
  }
  return success_read;
}

// // Десятичное число с плавающей точкой или научная нотация
bool s21_float_specifier(char **str_ptr, form_specier formspec,
                         va_list *arglist, bool *to_break) {
  bool success_read = false;
  if (s21_strchr(FLOAT_SPECIERS, formspec.specifier)) {
    long double output = s21_strtod(*str_ptr, str_ptr, formspec, &success_read);
    *to_break = !success_read;
    if (!formspec.no_read && success_read) {
      if (formspec.length[0] == 'l') {
        *va_arg(*arglist, double *) = (double)output;
      } else if (formspec.length[0] == 'L') {
        *va_arg(*arglist, long double *) = (long double)output;
      } else if (formspec.length[0] == 0) {
        *va_arg(*arglist, float *) = (float)output;
      }
    }
  }
  return success_read && !formspec.no_read;
}

bool s21_string_specifier(char **str_ptr, form_specier formspec,
                          va_list *arglist) {
  bool success_read = false;
  if (formspec.specifier == 's' && **str_ptr) {
    char *arg = va_arg(*arglist, char *);
    for (*arg = **str_ptr; **str_ptr && (**str_ptr != ' ') && formspec.width;
         arg++, (*str_ptr)++, *arg = **str_ptr, formspec.width--)
      ;
    *arg = '\0';
    success_read = true;
  }
  return success_read && !formspec.no_read;
}

bool s21_percent_specier(char **str_ptr, form_specier formspec) {
  bool error = false;
  if (formspec.specifier == '%' && **str_ptr == '%') (*str_ptr)++;
  return error;
}