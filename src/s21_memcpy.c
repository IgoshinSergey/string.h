#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  void *out_ptr = dest;
  char *dest_ptr = (char *)dest;
  const char *src_ptr = (const char *)src;
  for (; *(dest_ptr) && *(src_ptr) && n > 0; n--, dest_ptr++, src_ptr++) {
    *(dest_ptr) = *(src_ptr);
  }
  if (!*(src_ptr + n - 1)) {
    *(dest_ptr + n - 1) = '\0';
  }
  return out_ptr;
}