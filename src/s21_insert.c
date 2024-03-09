#include <stdlib.h>

#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = S21_NULL;
  if (src != S21_NULL && str != S21_NULL && start_index <= s21_strlen(src)) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    s21_size_t res_len = src_len + str_len;
    res = (char *)calloc(sizeof(char), res_len + 1);
    if (res) {
      for (unsigned n = 0; n < start_index; n++) {
        *(res + n) = *(src + n);
      }
      for (unsigned n = 0; n < str_len; n++) {
        *(res + n + start_index) = *(str + n);
      }
      for (unsigned n = start_index; n < src_len; n++) {
        *(res + n + str_len) = *(src + n);
      }
      *(res + s21_strlen(res)) = '\0';
    }
  }
  return (void *)res;
}