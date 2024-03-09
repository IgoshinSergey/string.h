#include "s21_string.h"

s21_size_t s21_strrspn(const char *str1, const char *str2) {
  _Bool to_exit = 0;
  s21_size_t str1_len = s21_strlen(str1), str2_len = s21_strlen(str2);
  if (str1_len-- && str2_len--) {
    for (; !to_exit; str1_len--) {
      for (s21_size_t i = 0; i <= str2_len; i++) {
        if (str1[str1_len] == str2[i] && i < str2_len) break;
        if (i == str2_len && str2[str2_len] != str1[str1_len]) to_exit = 1;
      }
    }
  } else {
    str1_len--;
  }
  return s21_strlen(str1) - ++str1_len - 1;
}