#include <stdlib.h>

#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *res = S21_NULL;
  if (str != S21_NULL) {
    res = calloc(sizeof(char), (s21_strlen(str) + 1));
    if (res) {
      for (unsigned i = 0; i < s21_strlen(str); i++) {
        if ((*(str + i) >= 'A') && (*(str + i) <= 'Z')) {
          *(res + i) = *(str + i) + 32;
        } else {
          *(res + i) = *(str + i);
        }
      }
      *(res + s21_strlen(str)) = '\0';
    }
  }
  return (void *)res;
}