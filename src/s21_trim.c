#include <stdlib.h>

#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *trim_str = S21_NULL;
  if (src && trim_chars) {
    int from_char = s21_strspn(src, trim_chars),
        to_char = s21_strlen(src) - s21_strrspn(src, trim_chars);
    trim_str = malloc((to_char - from_char) * sizeof(char) + sizeof(char));
    if (trim_str) {
      int len = 0;
      for (int i = from_char; i < to_char; i++, len++) {
        *(trim_str + len) = src[i];
      }
      *(trim_str + len) = '\0';
    }
  }
  return (void *)trim_str;
}