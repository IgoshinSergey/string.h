#include <string.h>

#include "s21_string_test.h"

START_TEST(s21_strerror_test) {
  for (int i = -50; i < 200; i++) {
    char *s21 = s21_strerror(i);
    char *orig = strerror(i);
    ck_assert_pstr_eq(s21, orig);
  }
  ck_assert_pstr_eq(s21_strerror(100), strerror(100));
  ck_assert_pstr_eq(s21_strerror(521), strerror(521));
  ck_assert_pstr_eq(s21_strerror(-999), strerror(-999));
  ck_assert_pstr_eq(s21_strerror(-99913), strerror(-99913));
  ck_assert_pstr_eq(s21_strerror(99913), strerror(99913));
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[30;43m S21_STRERROR \033[0m");
  tc = tcase_create("tcase_strerror");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strerror_test);

  suite_add_tcase(s, tc);
  return s;
}
