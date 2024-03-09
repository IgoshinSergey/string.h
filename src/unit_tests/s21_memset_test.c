#include <string.h>

#include "s21_string_test.h"

START_TEST(s21_memset_normal_test_1) {
  char s1[] = "1234567890";
  char s2[] = "1234567890";
  ck_assert_str_eq(memset(s1 + 2, '1', 3), s21_memset(s2 + 2, '1', 3));
  ck_assert_str_eq(memset(s1 + 1, '?', 5), s21_memset(s2 + 1, '?', 5));
  ck_assert_str_eq(memset(s1 + 2, '\n', 1), s21_memset(s2 + 2, '\n', 1));
  ck_assert_str_eq(memset(s1 + 8, '\0', 2), s21_memset(s2 + 8, '\0', 2));
  ck_assert_str_eq(memset(s1 + 3, 'a', 3), s21_memset(s2 + 3, 'a', 3));
  ck_assert_str_eq(memset(s1 + 2, '1', 3), s21_memset(s2 + 2, '1', 3));
}
END_TEST

START_TEST(s21_memset_normal_test_2) {
  char s1[] = "abcdef\n12345a\0bcde";
  char s2[] = "abcdef\n12345a\0bcde";
  ck_assert_str_eq(memset(s1 + 2, '1', 3), s21_memset(s2 + 2, '1', 3));
  ck_assert_str_eq(memset(s1 + 1, '?', 5), s21_memset(s2 + 1, '?', 5));
  ck_assert_str_eq(memset(s1 + 2, '\n', 1), s21_memset(s2 + 2, '\n', 1));
  ck_assert_str_eq(memset(s1 + 8, '\0', 1), s21_memset(s2 + 8, '\0', 1));
  ck_assert_str_eq(memset(s1 + 10, 'a', 1), s21_memset(s2 + 10, 'a', 1));
}
END_TEST

START_TEST(s21_memset_normal_test_3) {
  char s1[] = "1234567890";
  char s2[] = "1234567890";
  ck_assert_str_eq(memset(s1 + 2, '5', 1), s21_memset(s2 + 2, '5', 1));
  ck_assert_str_eq(memset(s1 + 1, '^', 5), s21_memset(s2 + 1, '^', 5));
  ck_assert_str_eq(memset(s1 + 2, '\n', 1), s21_memset(s2 + 2, '\n', 1));
  ck_assert_str_eq(memset(s1 + 8, '\0', 1), s21_memset(s2 + 8, '\0', 1));
  ck_assert_str_eq(memset(s1 + 9, 'a', 1), s21_memset(s2 + 9, 'a', 1));
}
END_TEST

Suite *suite_memset(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[30;43m S21_MEMSET \033[0m");
  tc = tcase_create("tcase_memset");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_memset_normal_test_1);
  tcase_add_test(tc, s21_memset_normal_test_2);
  tcase_add_test(tc, s21_memset_normal_test_3);

  suite_add_tcase(s, tc);
  return s;
}