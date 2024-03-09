#include "s21_string_test.h"

START_TEST(memcpy_test_1) {
  char desk[] = "12345678901234567890\0";
  char src1[] = "Hello world\0";
  ck_assert_str_eq(memcpy(desk, src1, 5), s21_memcpy(desk, src1, 5));
  char src2[] = "Hello world\n\0";
  ck_assert_str_eq(memcpy(desk, src2, 5), s21_memcpy(desk, src2, 5));
  char src3[] = "a\n\0";
  ck_assert_str_eq(memcpy(desk, src3, 4), s21_memcpy(desk, src3, 4));
  char src4[] = " \n\0";
  ck_assert_str_eq(memcpy(desk, src4, 4), s21_memcpy(desk, src4, 4));
  char src5[] = "\n\0";
  ck_assert_str_eq(memcpy(desk, src5, 3), s21_memcpy(desk, src5, 3));
  char src6[] = "\0";
  ck_assert_str_eq(memcpy(desk, src6, 2), s21_memcpy(desk, src6, 2));
}
END_TEST

START_TEST(memcpy_test_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_test_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

// START_TEST(memcpy_test_4) {
//   char s1[] = "Hello, world!";
//   char s2[] = "Hello, world!";
//   char s3[] = "f";
//   s21_size_t n = 0;
//   ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
// }
// END_TEST

START_TEST(memcpy_test_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_test_6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_test_7) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "love";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_test_8) {
  char s1[] = "new_strnew_string";
  char s2[] = "new_strnew_string";
  char s3[] = "new_string";
  s21_size_t n = strlen(s3);
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_test_9) {
  char s1[] = "699\017020";
  char s2[] = "699\017020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_test_10) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "c";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_test_11) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_test_12) {
  char str_5[3] = "a\n\0";
  char str_6[3] = "\0";
  ck_assert_str_eq(memcpy(str_5, str_6, 2), s21_memcpy(str_5, str_6, 2));
}
END_TEST

START_TEST(memcpy_test_13) {
  char str_1[] = "\0";
  char str_2[] = " ";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 1));
}
END_TEST

START_TEST(memcpy_test_14) {
  char str_1[] = "copy_! ";
  char str_2[] = "n66";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

START_TEST(memcpy_test_15) {
  char str_1[] = "\n/n";
  char str_2[] = "-55";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

START_TEST(memcpy_test_16) {
  char str_1[] = "5656";
  char str_2[] = "\0\f";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

START_TEST(memcpy_test_17) {
  char str_1[] = "%hf*-5";
  char str_2[] = "\0\f";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

START_TEST(memcpy_test_18) {
  char s1[255] = "QWERTY";
  char s2[255] = "E";
  ck_assert_pstr_eq(memcpy(s1, s2, 6), s21_memcpy(s1, s2, 6));
}
END_TEST

Suite *suite_memcpy(void) {
  Suite *suite = suite_create("\033[30;43m S21_MEMCPY \033[0m");
  TCase *tcase = tcase_create("tcase_memcpy");

  tcase_add_test(tcase, memcpy_test_1);
  tcase_add_test(tcase, memcpy_test_2);
  tcase_add_test(tcase, memcpy_test_3);
  // tcase_add_test(tcase, memcpy_test_4);
  tcase_add_test(tcase, memcpy_test_5);
  tcase_add_test(tcase, memcpy_test_6);
  tcase_add_test(tcase, memcpy_test_7);
  tcase_add_test(tcase, memcpy_test_8);
  tcase_add_test(tcase, memcpy_test_9);
  tcase_add_test(tcase, memcpy_test_10);
  tcase_add_test(tcase, memcpy_test_11);
  tcase_add_test(tcase, memcpy_test_12);
  tcase_add_test(tcase, memcpy_test_13);
  tcase_add_test(tcase, memcpy_test_14);
  tcase_add_test(tcase, memcpy_test_15);
  tcase_add_test(tcase, memcpy_test_16);
  tcase_add_test(tcase, memcpy_test_17);
  tcase_add_test(tcase, memcpy_test_18);
  tcase_add_test(tcase, memcpy_test_18);

  suite_add_tcase(suite, tcase);
  return suite;
}
