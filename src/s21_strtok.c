#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *save_ptr = S21_NULL;
  char *end;
  if (str == S21_NULL) str = save_ptr;
  if (*str == '\0') {
    save_ptr = str;
    return S21_NULL;
  }
  str += s21_strspn(str, delim);
  if (*str == '\0') {
    save_ptr = str;
    return S21_NULL;
  }
  end = str + s21_strcspn(str, delim);
  if (*end == '\0') {
    save_ptr = end;
    return str;
  }
  *end = '\0';
  save_ptr = end + 1;
  return str;
}