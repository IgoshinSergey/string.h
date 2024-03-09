#include "s21_string.h"

/* Выполняет поиск первого вхождения символа c (беззнаковый тип); в первых n
 * байтах строки, на которую указывает аргумент str */
void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *out_ptr = S21_NULL;
  const char *char_ptr = str;
  for (s21_size_t i = 0; i < n; i++, char_ptr++) {
    if (*char_ptr == c) {
      out_ptr = (void *)char_ptr;
      break;
    }
  }
  return out_ptr;
}