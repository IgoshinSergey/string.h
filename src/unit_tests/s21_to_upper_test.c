#include "s21_string_test.h"

START_TEST(s21_to_upper_test_1) {
  char str1[] = "Hello, world!";
  char *res1 = s21_to_upper(str1);
  ck_assert_str_eq("HELLO, WORLD!", res1);
  free(res1);

  char str2[] = "  to_upper  |1234565?><{}[]*\n()&/$\\@!(!#";
  char *res2 = s21_to_upper(str2);
  ck_assert_str_eq("  TO_UPPER  |1234565?><{}[]*\n()&/$\\@!(!#", res2);
  free(res2);

  char str3[] = "Hello,.565?><{\n}[]\0*()&/";
  char *res3 = s21_to_upper(str3);
  ck_assert_pstr_eq("HELLO,.565?><{\n}[]", res3);
  free(res3);

  char str4[] = "\tHello,.565\0?><{\n}[]\0*()&/\t";
  char *res4 = s21_to_upper(str4);
  ck_assert_str_eq("\tHELLO,.565", res4);
  free(res4);

  char str5[] = "\nHello,.565?>\0<{\n}[]\0*()&/\n";
  char *res5 = s21_to_upper(str5);
  ck_assert_str_eq("\nHELLO,.565?>", res5);
  free(res5);

  char str6[] = "  Hello,.565?><{\n}[]\0*()&/  ";
  char *res6 = s21_to_upper(str6);
  ck_assert_str_eq("  HELLO,.565?><{\n}[]", res6);
  free(res6);

  char str7[] = "  TO_UPPER  ";
  char *res7 = s21_to_upper(str7);
  ck_assert_str_eq("  TO_UPPER  ", res7);
  free(res7);
}
END_TEST

START_TEST(s21_to_upper_test_2) {
  char *str1 = S21_NULL;
  char *res1 = s21_to_upper(str1);
  ck_assert_pstr_eq(S21_NULL, res1);
  free(res1);

  char str2[] = "";
  char *res2 = s21_to_upper(str2);
  ck_assert_pstr_eq("", res2);
  free(res2);
}
END_TEST

Suite *suite_to_upper(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[30;43m S21_TO_UPPER \033[0m");
  tc = tcase_create("tcase_to_upper");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_to_upper_test_1);
  tcase_add_test(tc, s21_to_upper_test_2);

  suite_add_tcase(s, tc);
  return s;
}
