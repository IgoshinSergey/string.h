#include <string.h>

#include "s21_string_test.h"

START_TEST(s21_strpbrk_normal_test_1) {
  char str11[] = "abcde";
  char str21[] = "123456abcd";
  ck_assert_str_eq(strpbrk(str11, str21), s21_strpbrk(str11, str21));

  char str12[] = "Hello, world!";
  char str22[] = ",";
  ck_assert_str_eq(strpbrk(str12, str22), s21_strpbrk(str12, str22));

  char str13[] = "Hello, world!";
  char str23[] = "!";
  ck_assert_str_eq(strpbrk(str13, str23), s21_strpbrk(str13, str23));

  char str14[] = "Hel\nlo, wo\0rld!";
  char str24[] = "w";
  ck_assert_str_eq(strpbrk(str14, str24), s21_strpbrk(str14, str24));

  char str15[] = "Hel\nlo, wo\0rld!";
  char str25[] = "p";
  ck_assert_pstr_eq(strpbrk(str15, str25), s21_strpbrk(str15, str25));

  char str16[] = "Hel\nlo, wo\0rld!";
  char str26[] = "";
  ck_assert_pstr_eq(strpbrk(str16, str26), s21_strpbrk(str16, str26));

  char str17[] = "";
  char str27[] = "";
  ck_assert_pstr_eq(strpbrk(str17, str27), s21_strpbrk(str17, str27));
}
END_TEST

START_TEST(s21_strpbrk_null_values_test) {
  char str11[] = "abcde";
  char str21[] = "123456\0abcd";
  ck_assert_pstr_eq(strpbrk(str11, str21), s21_strpbrk(str11, str21));

  char str12[] = "abc\0de";
  char str22[] = "123456d";
  ck_assert_pstr_eq(strpbrk(str12, str22), s21_strpbrk(str12, str22));

  char str13[] = "a\0bcde";
  char str23[] = "123456\0abcd";
  ck_assert_pstr_eq(strpbrk(str13, str23), s21_strpbrk(str13, str23));
}
END_TEST

Suite *suite_strpbrk(void) {
  Suite *s = suite_create("\033[30;43m S21_STRPBRK \033[0m");
  TCase *tc = tcase_create("tcase_strpbrk");

  tcase_add_test(tc, s21_strpbrk_normal_test_1);
  tcase_add_test(tc, s21_strpbrk_null_values_test);

  suite_add_tcase(s, tc);
  return s;
}