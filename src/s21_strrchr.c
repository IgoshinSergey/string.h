#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *char_ptr = S21_NULL;
  for (char_ptr = (str + s21_strlen(str)); char_ptr != str && *char_ptr != c;
       char_ptr--)
    ;
  char_ptr = (*char_ptr == c) ? char_ptr : S21_NULL;
  return (char *)char_ptr;
}
