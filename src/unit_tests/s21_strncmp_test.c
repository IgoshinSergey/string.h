#include "s21_string_test.h"

START_TEST(strncmp_test_desk_less_src_values) {
  char desk[] = "Helllooo";
  char src1[] = "Hello world\0";
  ck_assert_int_eq(strncmp(desk, src1, 5), s21_strncmp(desk, src1, 5));
  char src2[] = "Hello world\n\0";
  ck_assert_int_eq(strncmp(desk, src2, 5), s21_strncmp(desk, src2, 5));
  char src3[] = "a\n\0";
  ck_assert_int_eq(strncmp(desk, src3, 5), s21_strncmp(desk, src3, 5));
  char src4[] = " \n\0";
  ck_assert_int_eq(strncmp(desk, src4, 5), s21_strncmp(desk, src4, 5));
  char src5[] = "\n\0";
  ck_assert_int_eq(strncmp(desk, src5, 5), s21_strncmp(desk, src5, 5));
  char src6[] = "\0";
  ck_assert_int_eq(strncmp(desk, src6, 5), s21_strncmp(desk, src6, 5));
}
END_TEST

START_TEST(strncmp_test_desk_larger_src_values) {
  char desk[] = "12345678901234567890\0";
  char src1[] = "Hello world\0";
  ck_assert_int_eq(strncmp(desk, src1, 5), s21_strncmp(desk, src1, 5));
  char src2[] = "Hello world\n\0";
  ck_assert_int_eq(strncmp(desk, src2, 5), s21_strncmp(desk, src2, 5));
  char src3[] = "a\n\0";
  ck_assert_int_eq(strncmp(desk, src3, 4), s21_strncmp(desk, src3, 4));
  char src4[] = " \n\0";
  ck_assert_int_eq(strncmp(desk, src4, 4), s21_strncmp(desk, src4, 4));
  char src5[] = "\n\0";
  ck_assert_int_eq(strncmp(desk, src5, 3), s21_strncmp(desk, src5, 3));
  char src6[] = "\0";
  ck_assert_int_eq(strncmp(desk, src6, 2), s21_strncmp(desk, src6, 2));
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *suite = suite_create("\033[30;43m S21_STRNCMP \033[0m");
  TCase *tcase = tcase_create("tcase_strncmp");

  tcase_add_test(tcase, strncmp_test_desk_less_src_values);
  tcase_add_test(tcase, strncmp_test_desk_larger_src_values);

  suite_add_tcase(suite, tcase);
  return suite;
}
