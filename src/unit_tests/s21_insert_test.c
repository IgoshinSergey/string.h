#include <string.h>

#include "s21_string_test.h"

START_TEST(s21_insert_normal_test_1) {
  char *src = "12345678";
  char *str = "abcd";

  char *res1 = s21_insert(src, str, 6);
  ck_assert_pstr_eq("123456abcd78", res1);
  free(res1);

  char *res2 = s21_insert(src, str, 0);
  ck_assert_pstr_eq("abcd12345678", res2);
  free(res2);

  char *res3 = s21_insert(src, str, 1);
  ck_assert_pstr_eq("1abcd2345678", res3);
  free(res3);

  char *res4 = s21_insert(src, str, 2);
  ck_assert_pstr_eq("12abcd345678", res4);
  free(res4);

  char *res5 = s21_insert(src, str, 7);
  ck_assert_pstr_eq("1234567abcd8", res5);
  free(res5);

  char *res7 = s21_insert(src, str, 9);
  ck_assert_pstr_eq(S21_NULL, res7);
  free(res7);

  char *res8 = s21_insert(src, str, -1);
  ck_assert_pstr_eq(S21_NULL, res8);
  free(res8);
}
END_TEST

START_TEST(s21_insert_normal_test_2) {
  char *str1 = "";
  char *str2 = "";
  char *str3 = "1234";
  char *res1 = s21_insert(str1, str2, 0);
  ck_assert_pstr_eq("", res1);
  free(res1);

  char *res2 = s21_insert(str1, str3, 0);
  ck_assert_pstr_eq("1234", res2);
  free(res2);

  char *res3 = s21_insert(str3, str1, 0);
  ck_assert_pstr_eq("1234", res3);
  free(res3);
}
END_TEST

START_TEST(s21_insert_edge_cases_test) {
  char *src1 = "12345678";
  char *str1 = "";

  char *res1 = s21_insert(src1, str1, 1);
  ck_assert_pstr_eq("12345678", res1);
  free(res1);

  char *res2 = s21_insert(src1, str1, 4);
  ck_assert_pstr_eq("12345678", res2);
  free(res2);

  char *src = "";
  char *str = "abcde";

  char *res3 = s21_insert(src, str, 0);
  ck_assert_pstr_eq("abcde", res3);
  free(res3);

  char *res4 = s21_insert(src, str, 1);
  ck_assert_pstr_eq(S21_NULL, res4);
  free(res4);

  char *src3 = S21_NULL;
  char *str3 = "1234567";

  char *res5 = s21_insert(src3, str3, 0);
  ck_assert_pstr_eq(S21_NULL, res5);
  free(res5);

  char *res7 = s21_insert(src3, src3, 0);
  ck_assert_pstr_eq(S21_NULL, res7);
  free(res7);
}
END_TEST

Suite *suite_insert(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[30;43m S21_INSERT \033[0m");
  tc = tcase_create("tcase_insert");

  tcase_add_test(tc, s21_insert_normal_test_1);
  tcase_add_test(tc, s21_insert_normal_test_2);
  tcase_add_test(tc, s21_insert_edge_cases_test);

  suite_add_tcase(s, tc);
  return s;
}