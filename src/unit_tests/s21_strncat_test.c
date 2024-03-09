#include "s21_string_test.h"

START_TEST(strncat_test_dest_larger_src_values_1) {
  char dest[100] = "12345678901234567890\0";
  char src[] = "Hello world\0";
  ck_assert_str_eq(strncat(dest, src, 5), s21_strncat(dest, src, 5));
}
END_TEST

START_TEST(strncat_test_dest_larger_src_values_2) {
  char dest[100] = "12345678901234567890\0";
  char src[] = "Hello world\n\0";
  ck_assert_str_eq(strncat(dest, src, 5), s21_strncat(dest, src, 5));
}
END_TEST

START_TEST(strncat_test_dest_larger_src_values_3) {
  char dest[100] = "12345678901234567890\0";
  char src[] = "a\n\0";
  ck_assert_str_eq(strncat(dest, src, 4), s21_strncat(dest, src, 4));
}
END_TEST

START_TEST(strncat_test_dest_larger_src_values_4) {
  char dest[100] = "12345678901234567890\0";
  char src[] = " \n\0";
  ck_assert_str_eq(strncat(dest, src, 4), s21_strncat(dest, src, 4));
}
END_TEST

START_TEST(strncat_test_dest_larger_src_values_5) {
  char dest[] = "12345678901234567890\0";
  char src[] = "\n\0";
  ck_assert_str_eq(strncat(dest, src, 3), s21_strncat(dest, src, 3));
}
END_TEST

// START_TEST(strncat_test_dest_larger_src_values_6) {
//   char dest[] = "12345678901234567890\0";
//   char src[] = "\0";
//   ck_assert_str_eq(strncat(dest, src, 2), s21_strncat(dest, src, 2));
// }
// END_TEST

Suite *suite_strncat(void) {
  Suite *suite = suite_create("\033[30;43m S21_STRNCAT \033[0m");
  TCase *tcase = tcase_create("tcase_strncat");

  tcase_add_test(tcase, strncat_test_dest_larger_src_values_1);
  tcase_add_test(tcase, strncat_test_dest_larger_src_values_2);
  tcase_add_test(tcase, strncat_test_dest_larger_src_values_3);
  tcase_add_test(tcase, strncat_test_dest_larger_src_values_4);
  tcase_add_test(tcase, strncat_test_dest_larger_src_values_5);
  // tcase_add_test(tcase, strncat_test_dest_larger_src_values_6);

  suite_add_tcase(suite, tcase);
  return suite;
}