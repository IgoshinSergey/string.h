#include <string.h>

#include "s21_string_test.h"

START_TEST(s21_memcmp_normal_test_1) {
  char str1[] = "54321";
  char str2[] = "ab\0cde";
  for (int n = 0; n < 5; n++) {
    ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
  }
  for (int n = 0; n < 5; n++) {
    ck_assert_int_eq(memcmp(str2, str1, n), s21_memcmp(str2, str1, n));
  }
}
END_TEST

START_TEST(s21_memcmp_normal_test_2) {
  char str1[] = "54321\0";
  char str2[] = "5432111";
  for (int n = 0; n < 5; n++) {
    ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
  }
  for (int n = 0; n < 5; n++) {
    ck_assert_int_eq(memcmp(str2, str1, n), s21_memcmp(str2, str1, n));
  }
}
END_TEST

START_TEST(s21_memcmp_normal_test_3) {
  char str1[] = "543\n21";
  char str2[] = "543a\0bc";
  for (int n = 0; n < 5; n++) {
    ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
  }
  for (int n = 0; n < 5; n++) {
    ck_assert_int_eq(memcmp(str2, str1, n), s21_memcmp(str2, str1, n));
  }
}
END_TEST

START_TEST(s21_memcmp_normal_test_4) {
  char str1[] = "abcd\0e";
  char str2[] = "543\n2111";
  for (int n = 0; n < 5; n++) {
    ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
  }
  for (int n = 0; n < 5; n++) {
    ck_assert_int_eq(memcmp(str2, str1, n), s21_memcmp(str2, str1, n));
  }
}
END_TEST

// segfaults
// START_TEST(s21_memcmp_test_null_str1_values) {
//     char *str1 = NULL;
//     char str2[] = "54321";
//     ck_assert_int_eq(memcmp(str1, str2, 5), s21_memcmp(str1, str2, 5));
// }
// END_TEST

// START_TEST(orig_memcmp_test_null_str1_values) {
//     char *str1 = NULL;
//     char str2[] = "54321";
//     ck_assert_int_eq(memcmp(str2, str1, 5), s21_memcmp(str2, str1, 5));
// }
// END_TEST

// START_TEST(s21_memcmp_test_null_str2_values) {
//     char str1[] = "54321";
//     char *str2 = NULL;
//     ck_assert_int_eq(memcmp(str1, str2, 5), s21_memcmp(str1, str2, 5));
// }
// END_TEST

// START_TEST(orig_memcmp_test_null_str2_values) {
//     char str1[] = "54321";
//     char *str2 = NULL;
//     ck_assert_int_eq(memcmp(str2, str1, 5), s21_memcmp(str2, str1, 5));
// }
// END_TEST

Suite *suite_memcmp(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[30;43m S21_MEMCMP \033[0m");
  tc = tcase_create("tcase_memcmp");

  tcase_add_test(tc, s21_memcmp_normal_test_1);
  tcase_add_test(tc, s21_memcmp_normal_test_2);
  tcase_add_test(tc, s21_memcmp_normal_test_3);
  tcase_add_test(tc, s21_memcmp_normal_test_4);
  // tcase_add_test_raise_signal(tc, s21_memcmp_test_null_str1_values, 11);
  // tcase_add_test_raise_signal(tc, orig_memcmp_test_null_str1_values, 11);
  // tcase_add_test_raise_signal(tc, s21_memcmp_test_null_str2_values, 11);
  // tcase_add_test_raise_signal(tc, orig_memcmp_test_null_str2_values, 11);

  suite_add_tcase(s, tc);
  return s;
}