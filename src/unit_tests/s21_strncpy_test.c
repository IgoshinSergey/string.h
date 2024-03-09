#include <string.h>

#include "s21_string_test.h"

START_TEST(s21_strncpy_normal_test_1) {
  char str11[] = "Hello, world!";
  char dest11[10] = "";
  char str12[] = "Hello, world!";
  char dest12[10] = "";
  ck_assert_str_eq(strncpy(dest11, str11, 5), s21_strncpy(dest12, str12, 5));

  char str21[] = "Hell\0o, world!\0";
  char dest21[10] = "";
  char str22[] = "Hell\0o, world!\0";
  char dest22[10] = "";
  ck_assert_str_eq(strncpy(dest21, str21, 5), s21_strncpy(dest22, str22, 5));

  char str31[] = "He\nll\0o, world!\0";
  char dest31[10] = "";
  char str32[] = "He\nll\0o, world!\0";
  char dest32[10] = "";
  ck_assert_str_eq(strncpy(dest31, str31, 6), s21_strncpy(dest32, str32, 6));

  char str41[10] = "Hello ";
  char dest41[] = "He\nllo, world!\0";
  char str42[10] = "Hello ";
  char dest42[] = "He\nllo, world!\0";
  ck_assert_str_eq(strncpy(dest41, str41, 6), s21_strncpy(dest42, str42, 6));

  char str51[10] = "Hello ";
  char dest51[] = "He\0llo, world!\0";
  char str52[10] = "Hello ";
  char dest52[] = "He\0llo, world!\0";
  ck_assert_str_eq(strncpy(dest51, str51, 6), s21_strncpy(dest52, str52, 6));
}
END_TEST

START_TEST(s21_strncpy_normal_test_2) {
  for (int n = 0; n < 10; n++) {
    char str11[11] = "";
    char str21[] = "Hello, \n\0World!";
    char str12[11] = "";
    char str22[] = "Hello, \n\0World!";
    ck_assert_str_eq(strncpy(str11, str21, n), s21_strncpy(str12, str22, n));
  }
}
END_TEST

START_TEST(s21_strncpy_normal_test_3) {
  for (int n = 0; n < 2; n++) {
    char str11[11] = "";
    char str21[] = "a\n b\0cde";
    char str12[11] = "";
    char str22[] = "a\n b\0cde";
    ck_assert_pstr_eq(strncpy(str11, str21, n), s21_strncpy(str12, str22, n));
  }
}
END_TEST

// segfaults
// START_TEST(s21_strncpy_dest_null_test) {
//     for (int n = 0; n < 10; n++) {
//         char *dest1 = S21_NULL;
//         char str1[] = "a\n\0 b\0cde";
//         char *dest2 = S21_NULL;
//         char str2[] = "a\n\0 b\0cde";
//         ck_assert_pstr_eq(strncpy(dest1, str1, n), s21_strncpy(dest2, str2,
//         n));
//     }
//     for (int n = 0; n < 10; n++) {
//         char dest1[] = "a\n\0 b\0cde";
//         char *str1 = S21_NULL;
//         char dest2[] = "a\n\0 b\0cde";
//         char *str2 = S21_NULL;
//         ck_assert_pstr_eq(strncpy(dest1, str1, n), s21_strncpy(dest2, str2,
//         n));
//     }
//     for (int n = 0; n < 10; n++) {
//         char *dest1 = S21_NULL;
//         char *str1 = S21_NULL;
//         char *dest2 = S21_NULL;
//         char *str2 = S21_NULL;
//         ck_assert_pstr_eq(strncpy(dest1, str1, n), s21_strncpy(dest2, str2,
//         n));
//     }
//     for (int n = -100; n < 0; n++) {
//         char str11[11] = "";
//         char str21[] = "12";
//         char str12[11] = "";
//         char str22[] = "12";
//         ck_assert_pstr_eq(strncpy(str11, str21, n), s21_strncpy(str12, str22,
//         n));
//     }
// }
// END_TEST

Suite *suite_strncpy(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[30;43m S21_STRNCPY \033[0m");
  tc = tcase_create("tcase_strncpy");

  tcase_add_test(tc, s21_strncpy_normal_test_1);
  tcase_add_test(tc, s21_strncpy_normal_test_2);
  tcase_add_test(tc, s21_strncpy_normal_test_3);
  // tcase_add_test_raise_signal(tc, s21_strncpy_dest_null_test, 11);

  suite_add_tcase(s, tc);
  return s;
}