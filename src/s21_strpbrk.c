#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = S21_NULL;
  int flag = 1;
  for (s21_size_t i = 0; *(str1 + i) != '\0' && flag; i++) {
    for (s21_size_t k = 0; *(str2 + k) != '\0'; k++) {
      if (*(str1 + i) == *(str2 + k)) {
        res = (char *)(str1 + i);
        flag = 0;
        break;
      }
    }
  }
  return res;
}