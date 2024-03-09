#include "s21_string_test.h"

START_TEST(strlen_test_normal_values) {
  const char str1[] = "12345678901234567890\0";
  ck_assert_uint_eq(strlen(str1), s21_strlen(str1));
  char str2[] = "Hello world\0";
  ck_assert_uint_eq(strlen(str2), s21_strlen(str2));
  char str3[] = "Hello world\n\0";
  ck_assert_uint_eq(strlen(str3), s21_strlen(str3));
  char str4[] = "a\n\0";
  ck_assert_uint_eq(strlen(str4), s21_strlen(str4));
  char str5[] = " \n\0";
  ck_assert_uint_eq(strlen(str5), s21_strlen(str5));
  char str6[] = "\n\0";
  ck_assert_uint_eq(strlen(str6), s21_strlen(str6));
  char str7[] = "\0";
  ck_assert_uint_eq(strlen(str7), s21_strlen(str7));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *suite = suite_create("\033[30;43m S21_STRLEN \033[0m");
  TCase *tcase = tcase_create("tcase_strlen");
  tcase_add_test(tcase, strlen_test_normal_values);
  suite_add_tcase(suite, tcase);
  return suite;
}