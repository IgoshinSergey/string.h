#include "s21_string_test.h"

START_TEST(memchr_test_1) {
  char str[] = "Hello world\n\0";
  ck_assert_ptr_eq(memchr(str, 'o', 15), s21_memchr(str, 'o', 15));
  ck_assert_ptr_eq(memchr(str, 'o', 12), s21_memchr(str, 'o', 12));
  ck_assert_ptr_eq(memchr(str, 'o', 10), s21_memchr(str, 'o', 10));
  ck_assert_ptr_eq(memchr(str, 'o', 6), s21_memchr(str, 'o', 6));
  ck_assert_ptr_eq(memchr(str, 'o', 5), s21_memchr(str, 'o', 5));
  ck_assert_ptr_eq(memchr(str, 'o', 3), s21_memchr(str, 'o', 3));
  ck_assert_ptr_eq(memchr(str, 'q', 10), s21_memchr(str, 'q', 10));
  ck_assert_ptr_eq(memchr(str, '\n', 13), s21_memchr(str, '\n', 13));
  ck_assert_ptr_eq(memchr(str, '\0', 13), s21_memchr(str, '\0', 13));
}
END_TEST

START_TEST(memchr_test_2) {
  char *str = "\0";
  ck_assert_ptr_eq(memchr(str, '\0', 5), s21_memchr(str, '\0', 5));
  ck_assert_ptr_eq(memchr(str, '\0', 1), s21_memchr(str, '\0', 1));
}
END_TEST

START_TEST(memchr_test_3) {
  char *str = "abcd\0efg\0";
  ck_assert_ptr_eq(memchr(str, 'a', 5), s21_memchr(str, 'a', 5));
  ck_assert_pstr_eq(memchr(str, 'e', 9), s21_memchr(str, 'e', 9));
}
END_TEST

START_TEST(memchr_test_4) {
  char *s1 = "0";
  ck_assert_pstr_eq(memchr(s1, 48, 1), s21_memchr(s1, 48, 1));
}
END_TEST

START_TEST(memchr_test_5) {
  char str_9[12] = "Hello world";
  ck_assert_str_eq(memchr(str_9, 'w', strlen(str_9)),
                   s21_memchr(str_9, 'w', s21_strlen(str_9)));
}
END_TEST

START_TEST(memchr_test_6) {
  char str_3[12] = "i am\nproger";
  ck_assert_str_eq(memchr(str_3, '\n', 6), s21_memchr(str_3, '\n', 6));
}
END_TEST

START_TEST(memchr_test_7) {
  char str_5[5] = " \n\0\0";
  ck_assert_str_eq(memchr(str_5, '\0', 4), s21_memchr(str_5, '\0', 4));
}
END_TEST

START_TEST(memchr_test_8) {
  char str_1[12] = "Hello world";
  ck_assert_str_eq(memchr(str_1, 'w', strlen(str_1)),
                   s21_memchr(str_1, 'w', s21_strlen(str_1)));
}
END_TEST

START_TEST(memchr_test_9) {
  char str_1[20] = "Per aspera ad astra";
  ck_assert_ptr_eq(memchr(str_1, 'p', 2), s21_memchr(str_1, 'p', 2));
}
END_TEST

START_TEST(memchr_test_10) {
  char str_1[4] = "a\n\0";
  ck_assert_str_eq(memchr(str_1, '\0', 4), s21_memchr(str_1, '\0', 4));
}
END_TEST

START_TEST(memchr_test_11) {
  char *s1 = "0";
  ck_assert_pstr_eq(memchr(s1, 2, 4), s21_memchr(s1, 2, 4));
}
END_TEST

START_TEST(memchr_test_12) {
  char str_3[12] = "i am\nproger";
  ck_assert_ptr_eq(memchr(str_3, 'p', 2), s21_memchr(str_3, 'p', 2));
}
END_TEST

START_TEST(memchr_test_13) {
  char *s1 = "0";
  ck_assert_pstr_eq(memchr(s1, 85, 1), s21_memchr(s1, 85, 1));
}
END_TEST

START_TEST(memchr_test_14) {
  char str[] = "Hello w\0orld\0";
  ck_assert_pstr_eq(memchr(str, 'r', 5), s21_memchr(str, 'r', 5));
}
END_TEST

START_TEST(memchr_test_15) {
  char str2[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(memchr(str2, 's', 6), s21_memchr(str2, 's', 6));
}
END_TEST

START_TEST(memchr_test_16) {
  char str3[] = {'q', 'r', 's', 't', 'w', '\0'};
  ck_assert_pstr_eq(memchr(str3, 's', 5), s21_memchr(str3, 's', 5));
}
END_TEST

START_TEST(memchr_test_17) {
  char str[] = "Hello, world!";
  int ch = ' ';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_test_18) {
  char str[] = "Hello, world!";
  int ch = 101;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_test_19) {
  char str[] = "Hello, world!";
  int ch = '1';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_test_20) {
  char str[] = "Hello, world!";
  int ch = 65;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_test_21) {
  char str[] = "Hello, world!";
  int ch = 'l';
  s21_size_t len = 10;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_test_22) {
  char str[] = "Hello, world!";
  int ch = 'w';
  s21_size_t len = 5;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_test_23) {
  char str[] = "69917020";
  int ch = '3';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_test_24) {
  char str[] = "69917020";
  int ch = '6';
  s21_size_t len = 0;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_test_25) {
  char str[] = "69917020";
  int ch = 'g';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_test_26) {
  char str[] = "69917020";
  int ch = '\0';
  s21_size_t len = 9;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_test_27) {
  char str[] = "69917020\0\0";
  int ch = '\0';
  s21_size_t len = 10;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

Suite *suite_memchr(void) {
  Suite *suite = suite_create("\033[30;43m S21_MEMCHR \033[0m");
  TCase *tcase = tcase_create("tcase_memchr");

  tcase_add_test(tcase, memchr_test_1);
  tcase_add_test(tcase, memchr_test_2);
  tcase_add_test(tcase, memchr_test_3);
  tcase_add_test(tcase, memchr_test_4);
  tcase_add_test(tcase, memchr_test_5);
  tcase_add_test(tcase, memchr_test_6);
  tcase_add_test(tcase, memchr_test_7);
  tcase_add_test(tcase, memchr_test_8);
  tcase_add_test(tcase, memchr_test_9);
  tcase_add_test(tcase, memchr_test_10);
  tcase_add_test(tcase, memchr_test_11);
  tcase_add_test(tcase, memchr_test_12);
  tcase_add_test(tcase, memchr_test_13);
  tcase_add_test(tcase, memchr_test_14);
  tcase_add_test(tcase, memchr_test_15);
  tcase_add_test(tcase, memchr_test_16);
  tcase_add_test(tcase, memchr_test_17);
  tcase_add_test(tcase, memchr_test_18);
  tcase_add_test(tcase, memchr_test_19);
  tcase_add_test(tcase, memchr_test_20);
  tcase_add_test(tcase, memchr_test_21);
  tcase_add_test(tcase, memchr_test_22);
  tcase_add_test(tcase, memchr_test_23);
  tcase_add_test(tcase, memchr_test_24);
  tcase_add_test(tcase, memchr_test_25);
  tcase_add_test(tcase, memchr_test_26);
  tcase_add_test(tcase, memchr_test_27);

  suite_add_tcase(suite, tcase);
  return suite;
}