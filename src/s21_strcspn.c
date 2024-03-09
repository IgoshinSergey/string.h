#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  _Bool to_exit = 0;
  s21_size_t seg_len = 0;
  for (; *(str1 + seg_len) && !to_exit; seg_len++) {
    for (const char *char_ptr = str2; *char_ptr && !to_exit; char_ptr++) {
      to_exit = (*(str1 + seg_len) == *char_ptr);
    }
    if (to_exit) break;
  }
  return seg_len;
}