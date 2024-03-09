#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  s21_size_t f_index = 0;
  s21_size_t s_index = 0;
  va_list ap;
  va_start(ap, format);
  int res = -1;
  if (str && format) {
    while (format[f_index] != '\0') {
      if (format[f_index] != '%') {
        str[s_index++] = format[f_index++];
      } else {
        f_index++;
        specification fl = {0};
        s21_parsing(&fl, format, &f_index, &ap);
        s21_formatting(&fl, str, &s_index, &ap);
      }
    }
    str[s_index] = '\0';
    res = s_index;
  }
  va_end(ap);
  return res;
}

void s21_formatting(specification *fl, char *str, s21_size_t *s_index,
                    va_list *ap) {
  char *tmp = calloc(sizeof(char), S21_BUF_SIZ);
  s21_size_t t_index = 0;
  if (tmp) {
    switch (fl->specifier) {
      case 'c':
        s21_specifier_c(fl, tmp, &t_index, ap);
        break;
      case 'd':
      case 'i':
        s21_specifier_di(fl, tmp, &t_index, ap);
        break;
      case 'x':
      case 'X':
      case 'o':
      case 'p':
      case 'u':
        s21_specifier_Xxoup(fl, tmp, &t_index, ap);
        break;
      case 'e':
      case 'E':
        s21_specifier_Ee(fl, tmp, &t_index, ap);
        break;
      case 'f':
        s21_specifier_f(fl, tmp, &t_index, ap);
        break;
      case 'g':
      case 'G':
        s21_specifier_Gg(fl, tmp, &t_index, ap);
        break;
      case 'n':
        s21_specifier_n(s_index, ap);
        break;
      case 's':
        s21_specifier_s(fl, tmp, &t_index, ap);
        break;
      case '%':
        s21_specifier_percent(fl, tmp, &t_index);
        break;
    }
    s21_concatination(str, s_index, tmp, t_index);
    free(tmp);
  }
}

void s21_specifier_Gg(specification *fl, char *tmp, s21_size_t *t_index,
                      va_list *ap) {
  if (fl->length == 'L') {
    long double long_argument = va_arg(*ap, long double);
    if (!s21_checking_double(fl, long_argument, tmp, t_index)) {
      if (long_argument != 0 &&
          (fabsl(long_argument) * pow(10, 4) < 1 ||
           fabsl(long_argument) / pow(10, fl->precision) > 1)) {
        s21_Ee_to_str(fl, tmp, t_index, long_argument);
      } else {
        s21_f_to_str(fl, tmp, t_index, long_argument);
      }
    }
  } else {
    double argument = va_arg(*ap, double);
    if (!s21_checking_double(fl, argument, tmp, t_index)) {
      if (argument != 0 && (fabsl(argument) * pow(10, 4) < 1 ||
                            fabsl(argument) / pow(10, fl->precision) > 1)) {
        s21_Ee_to_str(fl, tmp, t_index, argument);
      } else {
        s21_f_to_str(fl, tmp, t_index, argument);
      }
    }
  }
  s21_str_flags(fl, tmp, t_index);
  s21_str_width(fl, tmp, t_index);
}

void s21_specifier_Ee(specification *fl, char *tmp, s21_size_t *t_index,
                      va_list *ap) {
  if (fl->length == 'L') {
    long double long_argument = va_arg(*ap, long double);
    if (!s21_checking_double(fl, long_argument, tmp, t_index)) {
      s21_Ee_to_str(fl, tmp, t_index, long_argument);
    }
  } else {
    double argument = va_arg(*ap, double);
    if (!s21_checking_double(fl, argument, tmp, t_index)) {
      s21_Ee_to_str(fl, tmp, t_index, argument);
    }
  }
  s21_str_flags(fl, tmp, t_index);
  s21_str_width(fl, tmp, t_index);
}

void s21_Ee_to_str(specification *fl, char *tmp, s21_size_t *t_index,
                   long double argument) {
  int exp = 0;
  if (argument != 0) {
    argument = s21_normalization_e(argument, &exp);
  }
  s21_f_to_str(fl, tmp, t_index, argument);
  if (s21_strchr("Gg", fl->specifier)) {
    fl->specifier = (fl->specifier == 'G') ? 'E' : 'e';
  }
  s21_insert_symbol(tmp, (*t_index)++, fl->specifier, s21_strlen(tmp));
  if (exp < 0) {
    s21_insert_symbol(tmp, (*t_index)++, '-', s21_strlen(tmp));
    exp *= -1;
  } else {
    s21_insert_symbol(tmp, (*t_index)++, '+', s21_strlen(tmp));
  }
  if (exp < 10) {
    s21_insert_symbol(tmp, (*t_index)++, '0', s21_strlen(tmp));
  }
  specification spec_exp = {0};
  char *str_exp = calloc(sizeof(char), 128);
  s21_size_t e_index = 0;
  if (str_exp) {
    s21_di_to_str(&spec_exp, str_exp, &e_index, exp);
    s21_concatination(tmp, t_index, str_exp, e_index);
    free(str_exp);
  }
}

void s21_specifier_f(specification *fl, char *tmp, s21_size_t *t_index,
                     va_list *ap) {
  if (fl->length == 'L') {
    long double long_argument = va_arg(*ap, long double);
    if (!s21_checking_double(fl, long_argument, tmp, t_index)) {
      s21_f_to_str(fl, tmp, t_index, long_argument);
    }
  } else {
    double argument = va_arg(*ap, double);
    if (!s21_checking_double(fl, argument, tmp, t_index)) {
      s21_f_to_str(fl, tmp, t_index, argument);
    }
  }
  s21_str_flags(fl, tmp, t_index);
  s21_str_width(fl, tmp, t_index);
}

void s21_specifier_s(specification *fl, char *tmp, s21_size_t *t_index,
                     va_list *ap) {
  char *input = va_arg(*ap, char *);
  if (input != S21_NULL) {
    s21_concatination(tmp, t_index, input, s21_strlen(input));
  } else {
    s21_concatination(tmp, t_index, "(null)", 6);
  }
  s21_str_precision(fl, tmp, t_index);
  s21_str_flags(fl, tmp, t_index);
  s21_str_width(fl, tmp, t_index);
}

void s21_specifier_n(s21_size_t *s_index, va_list *ap) {
  int *pointer = (int *)va_arg(*ap, int *);
  *pointer = *s_index;
}

void s21_specifier_c(specification *fl, char *tmp, s21_size_t *t_index,
                     va_list *ap) {
  int symbol = va_arg(*ap, int);
  s21_insert_symbol(tmp, (*t_index)++, symbol, s21_strlen(tmp));
  s21_str_flags(fl, tmp, t_index);
  s21_str_width(fl, tmp, t_index);
}

void s21_specifier_percent(specification *fl, char *tmp, s21_size_t *t_index) {
  s21_insert_symbol(tmp, (*t_index)++, '%', 0);
  s21_str_flags(fl, tmp, t_index);
  s21_str_width(fl, tmp, t_index);
}

void s21_specifier_Xxoup(specification *fl, char *tmp, s21_size_t *t_index,
                         va_list *ap) {
  int base = 0;
  switch (fl->specifier) {
    case 'o':
      base = 8;
      break;
    case 'x':
    case 'X':
      base = 16;
      break;
    case 'u':
      base = 10;
      break;
    case 'p':
      base = 16;
      fl->grid = 1;
      fl->length = 'l';
      break;
  }
  switch (fl->length) {
    case 'h':;
      unsigned short short_argument = (unsigned short)va_arg(*ap, unsigned int);
      s21_Xxoup_to_str(fl, tmp, t_index, short_argument, base);
      break;
    case 'l':;
      unsigned long long_argument = (unsigned long)va_arg(*ap, unsigned long);
      s21_Xxoup_to_str(fl, tmp, t_index, long_argument, base);
      break;
    default:;
      unsigned argument = va_arg(*ap, unsigned);
      s21_Xxoup_to_str(fl, tmp, t_index, argument, base);
      break;
  }
}

void s21_specifier_di(specification *fl, char *tmp, s21_size_t *t_index,
                      va_list *ap) {
  switch (fl->length) {
    case 'h':;
      short short_argument = (short)va_arg(*ap, int);
      s21_di_to_str(fl, tmp, t_index, short_argument);
      break;
    case 'l':;
      long long_argument = (long)va_arg(*ap, long long);
      s21_di_to_str(fl, tmp, t_index, long_argument);
      break;
    default:;
      int argument = va_arg(*ap, int);
      s21_di_to_str(fl, tmp, t_index, argument);
      break;
  }
}

long double s21_normalization_e(long double argument, int *exp) {
  int sign = (argument < 0) ? -1 : 1;
  argument *= sign;
  while (argument > 10 || argument < 1) {
    if (argument >= 10) {
      argument /= 10;
      (*exp)++;
    } else {
      argument *= 10;
      (*exp)--;
    }
  }
  argument *= sign;
  return argument;
}

void s21_f_to_str(specification *fl, char *tmp, s21_size_t *t_index,
                  long double argument) {
  fl->sign = (argument < 0) ? -1 : 1;
  argument *= fl->sign;
  long double left = 0;
  long double right = modfl(argument, &left);

  if (s21_strchr("Gg", fl->specifier)) {
    s21_checking_precision_g(fl, left, right);
  }
  int count_zero = 0;
  int flag_round = s21_round_right_number(fl, &count_zero, &right, &left);
  if (roundl(argument) == 0) {
    tmp[(*t_index)++] = '0';
  } else if (fl->point == 1 && flag_round) {
    s21_float_to_str(tmp, t_index, roundl(argument), 0);
  } else {
    s21_float_to_str(tmp, t_index, left, 0);
  }
  if (!flag_round || (fl->grid && s21_strchr("GgEe", fl->specifier))) {
    s21_insert_symbol(tmp, (*t_index)++, '.', s21_strlen(tmp));
    char *rightt = calloc(sizeof(char), 256);
    if (rightt) {
      s21_size_t r_index = 0;
      int flag = s21_float_to_str(rightt, &r_index, right, count_zero);
      s21_concatination(tmp, t_index, rightt, r_index);
      free(rightt);
      if (!flag) {
        s21_str_precision(fl, tmp, t_index);
      }
    }
  }
  if (s21_strchr("Gg", fl->specifier) && !fl->grid) {
    s21_delete_zero(fl, tmp, t_index);
  }
}

void s21_checking_precision_g(specification *fl, long double left,
                              long double right) {
  if (left == 0 && right == 0 && !fl->grid) {
    fl->precision = 0;
  } else {
    char *tmp_left = calloc(sizeof(char), 128);
    if (tmp_left) {
      s21_size_t tmp_left_index = 0;
      s21_float_to_str(tmp_left, &tmp_left_index, left, 0);
      if (left != 0) {
        fl->precision -= (s21_strlen(tmp_left));
      }
      free(tmp_left);
    }
  }
}

int s21_round_right_number(specification *fl, int *count_zero,
                           long double *right, long double *left) {
  int flag = 0;
  if (fl->precision != 0) {
    if (*right != 0) {
      while (*right < 0.1 && fl->precision > 0) {
        *right *= 10;
        (*count_zero)++;
        if (!(*left == 0 && s21_strchr("Gg", fl->specifier))) {
          (fl->precision)--;
        }
      }
    } else {
      if (s21_strchr("Gg", fl->specifier)) flag = 1;
      *count_zero = fl->precision;
    }
    if (fl->precision > 0) {
      long double exp = powl(10, fl->precision);
      *right = floor((*right) * exp + 0.5);
      if ((*right == exp)) {
        if (*count_zero == 0) {
          *left += 1;
          *right = 0;
          if (s21_strchr("fEe", fl->specifier)) *count_zero = fl->precision;
          if (s21_strchr("Gg", fl->specifier)) fl->precision -= 1;
        } else {
          *count_zero -= 1;
        }
      }
    } else {
      if (floor((*right) + 0.5) > *right) {
        *count_zero -= 1;
        *right = floor(*right + 0.5);
      } else {
        if (*count_zero == 0) flag = 1;
      }
    }
  } else {
    flag = 1;
  }
  return flag;
}

int s21_float_to_str(char *tmp, s21_size_t *t_index, long double argument,
                     int count_zero) {
  int count = 0;

  while (argument >= 1) {
    char digits[] = "0123456789";
    int ost = (int)fmod(argument, 10);
    tmp[(*t_index)++] = digits[ost];
    argument /= 10;
    count++;
  }
  for (int i = 0; i < count_zero; i++) {
    tmp[(*t_index)++] = '0';
  }
  s21_str_reverse(tmp, *t_index);
  return count;
}

void s21_Xxoup_to_str(specification *fl, char *tmp, s21_size_t *t_index,
                      unsigned long long argument, int base) {
  char digits[] = "0123456789abcdef";
  if (fl->specifier == 'X') {
    for (int i = 10; i < 16; i++) {
      digits[i] -= ('a' - 'A');
    }
  }
  if ((argument == 0 && (!fl->point || (fl->point && fl->precision != 0)))) {
    s21_insert_symbol(tmp, (*t_index)++, '0', 0);
    if (fl->specifier != 'p') fl->grid = 0;
  }
  while (argument != 0) {
    tmp[(*t_index)++] = digits[(unsigned long long)argument % base];
    argument /= base;
  }
  if (fl->specifier == 'o' && fl->precision > *t_index) {
    fl->grid = 0;
  }
  tmp[*t_index] = '\0';
  s21_str_reverse(tmp, *t_index);
  s21_str_precision(fl, tmp, t_index);
  s21_str_flags(fl, tmp, t_index);
  s21_str_width(fl, tmp, t_index);
}

void s21_di_to_str(specification *fl, char *tmp, s21_size_t *t_index,
                   long long argument) {
  fl->sign = (argument < 0) ? -1 : 1;
  argument *= fl->sign;
  char digits[] = "0123456789";
  if (argument == 0 && (!fl->point || (fl->point && fl->precision != 0))) {
    s21_insert_symbol(tmp, (*t_index)++, '0', 0);
  }
  while (argument != 0) {
    tmp[(*t_index)++] = digits[argument % 10];
    argument /= 10;
  }
  tmp[*t_index] = '\0';
  s21_str_reverse(tmp, *t_index);
  if (s21_strchr("di", fl->specifier)) {
    s21_str_precision(fl, tmp, t_index);
    s21_str_flags(fl, tmp, t_index);
    s21_str_width(fl, tmp, t_index);
  }
}

void s21_str_width(specification *fl, char *str, s21_size_t *index) {
  int symbol = (fl->zero) ? '0' : ' ';
  int i = 0;
  if (fl->grid && symbol == '0' && s21_strchr("Xxo", fl->specifier)) {
    if (s21_strchr("xX", fl->specifier)) {
      i = 2;
    } else if (fl->specifier == 'o') {
      i = 1;
    }
  } else if ((fl->sign == -1 || fl->plus || fl->space) && symbol == '0') {
    i = 1;
  }
  while ((*index) < fl->width) {
    s21_insert_symbol(str, (*index)++, symbol, i);
  }
}

void s21_str_precision(specification *fl, char *str, s21_size_t *index) {
  if (fl->point) {
    if (s21_strchr("diouxXp", fl->specifier) && (fl->precision > *index)) {
      int symbol = '0';
      while (fl->precision - (*index) > 0) {
        s21_insert_symbol(str, (*index)++, symbol, 0);
      }
    } else if (fl->specifier == 's' && fl->precision < *index) {
      str[fl->precision] = '\0';
      *index = s21_strlen(str);
    }
  }
}

void s21_str_flags(specification *fl, char *str, s21_size_t *index) {
  if ((fl->sign == -1 || fl->plus == 1) &&
      (s21_strchr("difeEgG", fl->specifier))) {
    int sign = (fl->sign < 0) ? '-' : '+';
    s21_insert_symbol(str, (*index)++, sign, 0);
  }
  if (fl->grid == 1) {
    s21_flag_grid(fl, str, index);
  }
  if (fl->space == 1 && fl->sign != -1) {
    s21_insert_symbol(str, (*index)++, ' ', 0);
  }
  if (fl->minus == 1) {
    while (*index < fl->width) {
      str[*index] = ' ';
      (*index)++;
    }
  }
}

void s21_flag_grid(specification *fl, char *str, s21_size_t *index) {
  if (s21_strchr("Xxop", fl->specifier)) {
    s21_insert_symbol(str, (*index)++, '0', 0);
    if (s21_strchr("Xxp", fl->specifier)) {
      int symbol = (fl->specifier == 'X') ? 'X' : 'x';
      s21_insert_symbol(str, (*index)++, symbol, 1);
    }
  } else if (s21_strchr("f", fl->specifier)) {
    if (fl->precision == 0) {
      s21_insert_symbol(str, (*index)++, '.', s21_strlen(str));
    }
  }
}

void s21_insert_symbol(char *str, s21_size_t length, char symbol,
                       s21_size_t index) {
  str[length + 1] = '\0';
  while (length != index) {
    str[length] = str[length - 1];
    length--;
  }
  str[index] = symbol;
}

void s21_str_reverse(char *str, s21_size_t index) {
  int start = 0;
  int end = index - 1;
  while (start < end) {
    char tmp = str[start];
    str[start++] = str[end];
    str[end--] = tmp;
  }
}

void s21_parsing(specification *fl, const char *format, s21_size_t *f_index,
                 va_list *ap) {
  s21_flags_parsing(fl, format, f_index);
  s21_width_parsing(fl, format, f_index, ap);
  s21_point_parsing(fl, format, f_index);
  s21_precision_parsing(fl, format, f_index, ap);
  s21_length_parsing(fl, format, f_index);
  s21_specifier_parsing(fl, format, f_index);
  s21_checking_flags(fl);
}

void s21_flags_parsing(specification *fl, const char *format,
                       s21_size_t *f_index) {
  char flags[] = "+-0# ";
  while (s21_strchr(flags, format[*f_index]) && format[*f_index]) {
    switch (format[*f_index]) {
      case '+':
        fl->plus = 1;
        break;
      case '-':
        fl->minus = 1;
        break;
      case '0':
        fl->zero = 1;
        break;
      case '#':
        fl->grid = 1;
        break;
      case ' ':
        fl->space = 1;
        break;
    }
    (*f_index)++;
  }
}

void s21_width_parsing(specification *fl, const char *format,
                       s21_size_t *f_index, va_list *ap) {
  int width = 0;
  if (format[*f_index] == '*') {
    width = va_arg(*ap, int);
    (*f_index)++;
  } else {
    width = s21_str_to_digit(format, f_index);
  }
  if (width < 0) {
    fl->minus = -1;
    fl->width = -width;
  } else {
    fl->width = width;
  }
}

void s21_point_parsing(specification *fl, const char *format,
                       s21_size_t *f_index) {
  if (format[*f_index] == '.') {
    fl->point = 1;
    fl->precision = 0;
    (*f_index)++;
  }
}

void s21_precision_parsing(specification *fl, const char *format,
                           s21_size_t *f_index, va_list *ap) {
  int precision = 0;
  if (format[*f_index] == '*') {
    precision = va_arg(*ap, int);
    (*f_index)++;
  } else if (s21_is_digit(format[*f_index])) {
    precision = s21_str_to_digit(format, f_index);
  }
  fl->precision = precision;
}

void s21_length_parsing(specification *fl, const char *format,
                        s21_size_t *f_index) {
  char length_symbols[] = "hlL";
  if (s21_strchr(length_symbols, format[*f_index])) {
    fl->length = format[(*f_index)++];
  }
}

void s21_specifier_parsing(specification *fl, const char *format,
                           s21_size_t *f_index) {
  char specifier_symbols[] = "cdieEfgGosuxXpn%";
  if (s21_strchr(specifier_symbols, format[*f_index])) {
    fl->specifier = format[*f_index];
  }
  (*f_index)++;
}

void s21_checking_flags(specification *fl) {
  if (!s21_strchr("difeEgG", fl->specifier)) {
    fl->plus = 0;
    fl->space = 0;
  }
  if (s21_strchr("difeEgG", fl->specifier) && fl->plus && fl->space) {
    fl->space = 0;
  }
  if (!s21_strchr("foxXeEgG", fl->specifier)) {
    fl->grid = 0;
  }
  if (!s21_strchr("diouxXeEfgGsc%", fl->specifier) ||
      (s21_strchr("diouxX", fl->specifier) && fl->point)) {
    fl->zero = 0;
  }
  if (fl->specifier == 'c') {
    fl->point = 0;
    fl->precision = 0;
  }
  if (s21_strchr("feEgG", fl->specifier) && !fl->point) {
    fl->point = 1;
    fl->precision = 6;
  }
}

int s21_is_digit(char num) { return num >= '0' && num <= '9'; }

void s21_delete_zero(specification *fl, char *str, s21_size_t *s_index) {
  for (unsigned i = 0; str[*s_index - 1] == '0' && i < fl->precision;
       (*s_index)--) {
    str[*s_index - 1] = '\0';
  }
  if (str[*s_index - 1] == '.' && !fl->grid) {
    str[*s_index - 1] = '\0';
    (*s_index)--;
  }
}

int s21_checking_double(specification *fl, double argument, char *tmp,
                        s21_size_t *t_index) {
  int res = 0;
  if (argument == INFINITY || argument == -INFINITY) {
    s21_concatination(tmp, t_index, "inf", 3);
    res = 1;
    if (argument < 0) fl->sign = -1;
  } else if (argument != argument) {
    s21_concatination(tmp, t_index, "nan", 3);
    fl->plus = 0;
    res = 1;
  }
  if (res) fl->zero = 0;
  return res;
}

int s21_str_to_digit(const char *format, s21_size_t *f_index) {
  int res = 0;
  while (s21_is_digit(format[*f_index])) {
    res *= 10;
    res += format[(*f_index)++] - '0';
  }
  return res;
}

void s21_concatination(char *str1, s21_size_t *start, char *str2,
                       s21_size_t count) {
  for (unsigned i = 0; i < count; i++) {
    str1[(*start)++] = str2[i];
  }
}