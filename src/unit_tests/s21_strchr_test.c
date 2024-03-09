#include <string.h>

#include "s21_string_test.h"

START_TEST(s21_strchr_normal_test_1) {
  char str[] = "Hello! ";
  int c = 'e';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_normal_test_2) {
  char str[] = "Hel\nlo! ";
  int c = 'l';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_normal_test_3) {
  char str[] = "Hel\nl\0o! ";
  int c = '!';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_normal_test_4) {
  char str[] = "Hel\0\nl\0o! ";
  int c = 'l';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_normal_test_5) {
  char str[] = "Hel\0\nl\0o! ";
  int c = 'B';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_normal_test_6) {
  char str[] = "Hel\nl\0o! ";
  int c = '\n';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_normal_test_7) {
  char str[] = "Hel\nl\0o! ";
  int c = '\0';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_normal_test_8) {
  char str[] = "Hel\0\nl\0o! ";
  int c = 'e';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_normal_test_9) {
  char *str = "123456";
  int c = -100;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

// segfault
// START_TEST(s21_strchr_null_test) {
//   char *str = S21_NULL;
//   int c = 'e';
//   ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
// }
// END_TEST

Suite *suite_strchr(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[30;43m S21_STRCHR \033[0m");
  tc = tcase_create("tcase_strchr");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strchr_normal_test_1);
  tcase_add_test(tc, s21_strchr_normal_test_2);
  tcase_add_test(tc, s21_strchr_normal_test_3);
  tcase_add_test(tc, s21_strchr_normal_test_4);
  tcase_add_test(tc, s21_strchr_normal_test_5);
  tcase_add_test(tc, s21_strchr_normal_test_6);
  tcase_add_test(tc, s21_strchr_normal_test_7);
  tcase_add_test(tc, s21_strchr_normal_test_8);
  tcase_add_test(tc, s21_strchr_normal_test_9);
  // tcase_add_test_raise_signal(tc, s21_strchr_null_test, 11);

  suite_add_tcase(s, tc);
  return s;
}
