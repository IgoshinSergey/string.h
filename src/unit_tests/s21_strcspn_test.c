#include "s21_string_test.h"

START_TEST(strcspn_test_desk_less_src_values) {
  char desk[] = "\0";
  char src1[] = "Hello world\0";
  ck_assert_uint_eq(strcspn(desk, src1), s21_strcspn(desk, src1));
  char src2[] = "Hello world\n\0";
  ck_assert_uint_eq(strcspn(desk, src2), s21_strcspn(desk, src2));
  char src3[] = "a\n\0";
  ck_assert_uint_eq(strcspn(desk, src3), s21_strcspn(desk, src3));
  char src4[] = " \n\0";
  ck_assert_uint_eq(strcspn(desk, src4), s21_strcspn(desk, src4));
  char src5[] = "\n\0";
  ck_assert_uint_eq(strcspn(desk, src5), s21_strcspn(desk, src5));
  char src6[] = "\0";
  ck_assert_uint_eq(strcspn(desk, src6), s21_strcspn(desk, src6));
}
END_TEST

START_TEST(strcspn_test_desk_larger_src_values) {
  char desk[] = "12345678901234567890\0";
  char src1[] = "Hello world\0";
  ck_assert_uint_eq(strcspn(desk, src1), s21_strcspn(desk, src1));
  char src2[] = "Hello world\n\0";
  ck_assert_uint_eq(strcspn(desk, src2), s21_strcspn(desk, src2));
  char src3[] = "a\n\0";
  ck_assert_uint_eq(strcspn(desk, src3), s21_strcspn(desk, src3));
  char src4[] = " \n\0";
  ck_assert_uint_eq(strcspn(desk, src4), s21_strcspn(desk, src4));
  char src5[] = "\n\0";
  ck_assert_uint_eq(strcspn(desk, src5), s21_strcspn(desk, src5));
  char src6[] = "\0";
  ck_assert_uint_eq(strcspn(desk, src6), s21_strcspn(desk, src6));
}
END_TEST

START_TEST(strcspn_1) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_2) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_3) {
  char s1[] = "v";
  char s2[] = "vendetta";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_4) {
  char s1[] = "";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_5) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_6) {
  char s1[] = "6";
  char s2[] = "67";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_7) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_8) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_9) {
  char s1[] = "699";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_10) {
  char s1[] = "69917020";
  char s2[] = "699";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_11) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_12) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *suite = suite_create("\033[30;43m S21_STRCSPN \033[0m");
  TCase *tcase = tcase_create("tcase_strcspn");

  tcase_add_test(tcase, strcspn_test_desk_less_src_values);
  tcase_add_test(tcase, strcspn_test_desk_larger_src_values);
  tcase_add_test(tcase, strcspn_1);
  tcase_add_test(tcase, strcspn_2);
  tcase_add_test(tcase, strcspn_3);
  tcase_add_test(tcase, strcspn_4);
  tcase_add_test(tcase, strcspn_5);
  tcase_add_test(tcase, strcspn_6);
  tcase_add_test(tcase, strcspn_7);
  tcase_add_test(tcase, strcspn_8);
  tcase_add_test(tcase, strcspn_9);
  tcase_add_test(tcase, strcspn_10);
  tcase_add_test(tcase, strcspn_11);
  tcase_add_test(tcase, strcspn_12);

  suite_add_tcase(suite, tcase);
  return suite;
}
