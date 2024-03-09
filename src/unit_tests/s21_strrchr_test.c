#include "s21_string_test.h"

START_TEST(strrchr_test_normal_value) {
  char str[] = "Hello world\n\0";
  ck_assert_ptr_eq(strrchr(str, 'o'), s21_strrchr(str, 'o'));
  ck_assert_pstr_eq(strrchr(str, 'q'), s21_strrchr(str, 'q'));
  ck_assert_ptr_eq(strrchr(str, '\n'), s21_strrchr(str, '\n'));
  ck_assert_ptr_eq(strrchr(str, '\0'), s21_strrchr(str, '\0'));
}
END_TEST

START_TEST(strrchr_test_empty_value) {
  char *str = "\0";
  ck_assert_ptr_eq(strrchr(str, '\0'), s21_strrchr(str, '\0'));
  ck_assert_ptr_eq(strrchr(str, '\0'), s21_strrchr(str, '\0'));
}
END_TEST

START_TEST(strrchr_test_double_ended_value) {
  char *str = "abcd\0efg\0";
  ck_assert_ptr_eq(strrchr(str, 'a'), s21_strrchr(str, 'a'));
  ck_assert_pstr_eq(strrchr(str, 'e'), s21_strrchr(str, 'e'));
}
END_TEST

Suite *suite_strrchr(void) {
  Suite *suite = suite_create("\033[30;43m S21_STRRCHR \033[0m");
  TCase *tcase = tcase_create("tcase_strrchr");

  tcase_add_test(tcase, strrchr_test_normal_value);
  tcase_add_test(tcase, strrchr_test_empty_value);
  tcase_add_test(tcase, strrchr_test_double_ended_value);

  suite_add_tcase(suite, tcase);

  return suite;
}