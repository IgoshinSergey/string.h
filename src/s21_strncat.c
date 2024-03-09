#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *outptr = dest;
  dest += s21_strlen(dest);
  const char *found = s21_memchr(src, '\0', n);
  s21_size_t destlen = found ? (s21_size_t)(found - src) : n;
  dest[destlen] = '\0';
  s21_memcpy(dest, src, destlen);
  return outptr;
}