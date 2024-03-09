#include <string.h>

#include "s21_string_test.h"

START_TEST(s21_strstr_normal_test) {
  char str1[] = "Hello\n, world!";
  char str2[] = ", wo";
  char str3[] = "world!";
  char str4[] = "! ";
  char str5[] = "hello";
  char str6[] = "";
  char str7[] = "\0";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
  ck_assert_pstr_eq(strstr(str1, str3), s21_strstr(str1, str3));
  ck_assert_pstr_eq(strstr(str1, str4), s21_strstr(str1, str4));
  ck_assert_pstr_eq(strstr(str1, str5), s21_strstr(str1, str5));
  ck_assert_pstr_eq(strstr(str1, str6), s21_strstr(str1, str6));
  ck_assert_pstr_eq(strstr(str1, str7), s21_strstr(str1, str7));
  ck_assert_pstr_eq(strstr(str3, str1), s21_strstr(str3, str1));
}
END_TEST

// segfaults
// START_TEST(s21_strstr_null_values_test) {
//     char *str11 = S21_NULL;
//     char str21[] = "Hello";
//     ck_assert_pstr_eq(strstr(str11, str21), s21_strstr(str11, str21));
//     ck_assert_pstr_eq(strstr(str21, str11), s21_strstr(str21, str11));

//     char *str12 = S21_NULL;
//     char *str22 = S21_NULL;
//     ck_assert_pstr_eq(strstr(str12, str22), s21_strstr(str12, str22));
// }
// END_TEST

Suite *suite_strstr(void) {
  Suite *s = suite_create("\033[30;43m S21_STRSTR \033[0m");
  TCase *tc = tcase_create("tcase_strstr");

  tcase_add_test(tc, s21_strstr_normal_test);
  // tcase_add_test_raise_signal(tc, s21_strstr_null_values_test, 11);

  suite_add_tcase(s, tc);
  return s;
}