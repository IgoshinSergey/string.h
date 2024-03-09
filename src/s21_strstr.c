#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = S21_NULL;
  for (int i = 0; i <= (int)s21_strlen(haystack) - (int)s21_strlen(needle);
       i++) {
    unsigned match = 0;
    for (int k = 0; k < (int)s21_strlen(needle); k++) {
      if (haystack[i + k] == needle[k]) {
        match++;
      } else {
        break;
      }
    }
    if (match == s21_strlen(needle)) {
      res = (char *)(haystack + i);
      break;
    }
  }
  return res;
}