#include "s21_string_test.h"

START_TEST(to_lower_test_1) {
  char str1[] = "Hello, world!";
  char *res1 = s21_to_lower(str1);
  ck_assert_str_eq("hello, world!", res1);
  free(res1);

  char str2[] = "  TO_LOWER  |1234565?><{}[]*\n()&/$\\@!(!#";
  char *res2 = s21_to_lower(str2);
  ck_assert_str_eq("  to_lower  |1234565?><{}[]*\n()&/$\\@!(!#", res2);
  free(res2);

  char str3[] = "Hello,.565?><{\n}[]\0*()&/";
  char *res3 = s21_to_lower(str3);
  ck_assert_pstr_eq("hello,.565?><{\n}[]", res3);
  free(res3);

  char str4[] = "\tHello,.565\0?><{\n}[]\0*()&/\t";
  char *res4 = s21_to_lower(str4);
  ck_assert_str_eq("\thello,.565", res4);
  free(res4);

  char str5[] = "\nHello,.565?>\0<{\n}[]\0*()&/\n";
  char *res5 = s21_to_lower(str5);
  ck_assert_str_eq("\nhello,.565?>", res5);
  free(res5);

  char str6[] = "  Hello,.565?><{\n}[]\0*()&/  ";
  char *res6 = s21_to_lower(str6);
  ck_assert_str_eq("  hello,.565?><{\n}[]", res6);
  free(res6);

  char str7[] = "  TO_LOWER  ";
  char *res7 = s21_to_lower(str7);
  ck_assert_str_eq("  to_lower  ", res7);
  free(res7);
}
END_TEST

Suite *suite_to_lower(void) {
  Suite *suite = suite_create("\033[30;43m S21_TO_LOWER \033[0m");
  TCase *tcase = tcase_create("tcase_to_lower");

  tcase_add_test(tcase, to_lower_test_1);

  suite_add_tcase(suite, tcase);
  return suite;
}