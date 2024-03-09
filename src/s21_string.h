#ifndef C2_S21_STRINGPLUS_S21_STRING_H_
#define C2_S21_STRINGPLUS_S21_STRING_H_

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

#define s21_size_t unsigned long
#define S21_NULL ((void *)0)

#define true 1
#define false 0

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

/*S21_SSCANF*/

#define LENGTHS "hlL"
#define SPECIFIES "cdieEfgGosuxXpn%%"
#define INT_SPECIERS "dioxX"
#define FLOAT_SPECIERS "eEgGf"

typedef struct {
  int width;
  bool no_read;
  char length[2];
  char specifier;
} form_specier;

int s21_sscanf(const char *str, const char *format, ...);

/*Вспомогательные функции*/
long double s21_strtod(const char *str, char **endptr, form_specier formspec,
                       bool *successful_assignments_num);
long long s21_strtol(const char *str_ptr, char **endptr, form_specier *formspec,
                     bool *successful_assignments_num);
bool s21_length_specier(char **format_ptr, form_specier *formspec);
bool s21_char_specier(char **str_ptr, form_specier formspec, va_list *arglist);
bool s21_int_specier(char **str_ptr, form_specier formspec, va_list *arglist);
bool s21_uint_specier(char **str_ptr, form_specier formspec, va_list *arglist);
bool s21_ptr_specier(char **str_ptr, form_specier formspec, va_list *arglist);
bool s21_scanned_char_num_specier(const char *str, char *str_ptr,
                                  form_specier formspec, va_list *arglist);
bool s21_float_specifier(char **str_ptr, form_specier formspec,
                         va_list *arglist, bool *to_break);
bool s21_string_specifier(char **str_ptr, form_specier formspec,
                          va_list *arglist);
bool s21_percent_specier(char **str_ptr, form_specier formspec);
s21_size_t s21_strrspn(const char *str1, const char *str2);
s21_size_t s21_strspn(const char *str1, const char *str2);

/*S21_SPRINTF*/

#define S21_BUF_SIZ 1024

typedef struct specification {
  int plus;
  int minus;
  int space;
  int grid;
  int zero;

  unsigned width;
  int point;
  unsigned precision;

  int sign;
  char length;
  char specifier;
} specification;

int s21_sprintf(char *str, const char *format, ...);

// парсинг форматной строки
void s21_parsing(specification *fl, const char *format, s21_size_t *f_index,
                 va_list *ap);
void s21_flags_parsing(specification *fl, const char *format,
                       s21_size_t *f_index);
void s21_width_parsing(specification *fl, const char *format,
                       s21_size_t *f_index, va_list *ap);
void s21_point_parsing(specification *fl, const char *format,
                       s21_size_t *f_index);
void s21_precision_parsing(specification *fl, const char *format,
                           s21_size_t *f_index, va_list *ap);
void s21_length_parsing(specification *fl, const char *format,
                        s21_size_t *f_index);
void s21_specifier_parsing(specification *fl, const char *format,
                           s21_size_t *f_index);
void s21_checking_flags(specification *fl);

// работа со спецификаторами
void s21_formatting(specification *fl, char *str, s21_size_t *s_index,
                    va_list *ap);
void s21_specifier_di(specification *fl, char *tmp, s21_size_t *t_index,
                      va_list *ap);
void s21_specifier_Xxoup(specification *fl, char *tmp, s21_size_t *t_index,
                         va_list *ap);
void s21_specifier_n(s21_size_t *t_index, va_list *ap);
void s21_specifier_percent(specification *fl, char *tmp, s21_size_t *t_index);
void s21_specifier_c(specification *fl, char *tmp, s21_size_t *t_index,
                     va_list *ap);
void s21_specifier_s(specification *fl, char *tmp, s21_size_t *t_index,
                     va_list *ap);
void s21_specifier_f(specification *fl, char *tmp, s21_size_t *t_index,
                     va_list *ap);
void s21_specifier_Ee(specification *fl, char *tmp, s21_size_t *t_index,
                      va_list *ap);
void s21_specifier_Gg(specification *fl, char *tmp, s21_size_t *t_index,
                      va_list *ap);

// вспомогательные функции
int s21_is_digit(char num);
void s21_str_reverse(char *str, s21_size_t t_index);
int s21_str_to_digit(const char *format, s21_size_t *f_index);
void s21_insert_symbol(char *str, s21_size_t length, char symbol,
                       s21_size_t index);
void s21_flag_grid(specification *fl, char *str, s21_size_t *index);
int s21_checking_double(specification *fl, double argument, char *tmp,
                        s21_size_t *t_index);
int s21_round_right_number(specification *fl, int *count_zero,
                           long double *right, long double *left);
void s21_str_precision(specification *fl, char *str, s21_size_t *index);
void s21_str_flags(specification *fl, char *str, s21_size_t *index);
void s21_str_width(specification *fl, char *str, s21_size_t *index);
void s21_concatination(char *str1, s21_size_t *start, char *str2,
                       s21_size_t count);
long double s21_normalization_e(long double argument, int *exp);
void s21_delete_zero(specification *fl, char *str, s21_size_t *s_index);
void s21_checking_precision_g(specification *fl, long double left,
                              long double right);
int s21_float_to_str(char *tmp, s21_size_t *t_index, long double argument,
                     int count_zero);

// фунции преобразования
void s21_Ee_to_str(specification *fl, char *tmp, s21_size_t *t_index,
                   long double argument);
void s21_f_to_str(specification *fl, char *tmp, s21_size_t *t_index,
                  long double argument);
void s21_di_to_str(specification *fl, char *tmp, s21_size_t *t_index,
                   long long argument);
void s21_Xxoup_to_str(specification *fl, char *tmp, s21_size_t *t_index,
                      unsigned long long argument, int base);

#endif  // C2_S21_STRINGPLUS_S21_STRING_H_
