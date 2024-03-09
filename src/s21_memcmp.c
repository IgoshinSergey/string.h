#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *tmp1 = (char *)str1;
  char *tmp2 = (char *)str2;
  int res = 0;
  for (s21_size_t i = 0; i < n; i++, tmp1++, tmp2++) {
    if (*tmp1 != *tmp2) {
      res = (*tmp1 - *tmp2);
      break;
    }
  }
  return res;
}