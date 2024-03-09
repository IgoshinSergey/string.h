#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int output = 0;
  if (n > 0) {
    const char *char1_ptr = S21_NULL, *char2_ptr = S21_NULL;
    for (char1_ptr = str1, char2_ptr = str2;
         *char1_ptr && *char2_ptr && n > 0 && *char1_ptr == *char2_ptr;
         char1_ptr++, char2_ptr++, n--)
      ;
    output = *char1_ptr - *char2_ptr;
  }
  return output;
}