#include <stdlib.h>

#include "s21_string_test.h"

START_TEST(sscanf_test_char_specifier_1) {
  char c = 0, sc = 0;
  char str[] = "c";
  char *format = "%c";
  ck_assert_int_eq(sscanf(str, format, &c), s21_sscanf(str, format, &sc));
  ck_assert_int_eq(c, sc);
}

START_TEST(sscanf_test_char_specifier_2) {
  char c_1, c_2, sc_1, sc_2;
  char *str = "ck";
  char *format = "%c%c";
  ck_assert_int_eq(sscanf(str, format, &c_1, &c_2),
                   s21_sscanf(str, format, &sc_1, &sc_2));
  ck_assert_int_eq(c_1, sc_1);
  ck_assert_int_eq(c_2, sc_2);
}

START_TEST(sscanf_test_char_specifier_3) {
  char c_1 = 0, c_2 = 0, sc_1 = 0, sc_2 = 0;
  char str[] = "ck";
  char *format = "%c %c";
  ck_assert_int_eq(sscanf(str, format, &c_1, &c_2),
                   s21_sscanf(str, format, &sc_1, &sc_2));
  ck_assert_int_eq(c_1, sc_1);
  ck_assert_int_eq(c_2, sc_2);
}

START_TEST(sscanf_test_char_specifier_4) {
  char c_1 = 0, c_2 = 0, sc_1 = 0, sc_2 = 0;
  char str[] = "c k";
  char *format = "%c%c";
  ck_assert_int_eq(sscanf(str, format, &c_1, &c_2),
                   s21_sscanf(str, format, &sc_1, &sc_2));
  ck_assert_int_eq(c_1, sc_1);
  ck_assert_int_eq(c_2, sc_2);
}

START_TEST(sscanf_test_char_specifier_5) {
  char c_1 = 0, c_2 = 0, sc_1 = 0, sc_2 = 0;
  char str[] = "c k";
  char *format = "%c %c";
  ck_assert_int_eq(sscanf(str, format, &c_1, &c_2),
                   s21_sscanf(str, format, &sc_1, &sc_2));
  ck_assert_int_eq(c_1, sc_1);
  ck_assert_int_eq(c_2, sc_2);
}

START_TEST(sscanf_test_char_specifier_6) {
  char c_1 = 0, c_2 = 0, sc_1 = 0, sc_2 = 0;
  char str[] = "c   k";
  char *format = "%c   %c";
  ck_assert_int_eq(sscanf(str, format, &c_1, &c_2),
                   s21_sscanf(str, format, &sc_1, &sc_2));
  ck_assert_int_eq(c_1, sc_1);
  ck_assert_int_eq(c_2, sc_2);
}

START_TEST(sscanf_test_char_specifier_7) {
  char c_1 = 0, c_2 = 0, sc_1 = 0, sc_2 = 0;
  char str[] = "c  k";
  char *format = "%c %c";
  ck_assert_int_eq(sscanf(str, format, &c_1, &c_2),
                   s21_sscanf(str, format, &sc_1, &sc_2));
  ck_assert_int_eq(c_1, sc_1);
  ck_assert_int_eq(c_2, sc_2);
}

START_TEST(sscanf_test_char_specifier_8) {
  char c_1 = 0, c_2 = 0, sc_1 = 0, sc_2 = 0;
  char str[] = "c k";
  char *format = "%c  %c";
  ck_assert_int_eq(sscanf(str, format, &c_1, &c_2),
                   s21_sscanf(str, format, &sc_1, &sc_2));
  ck_assert_int_eq(c_1, sc_1);
  ck_assert_int_eq(c_2, sc_2);
}

START_TEST(sscanf_test_char_specifier_9) {
  char format[] = "%c";
  char str[] = "\t\n\n  1 \n  \t";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_char_specifier_10) {
  char format[] = "%c";
  char str[] = "\t\n\n   \n  \ta";
  char c1, c2;
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_char_specifier_11) {
  char format[] = "%c%c%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_test_char_specifier_12) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  1    2 3 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_test_char_specifier_13) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_test_char_specifier_14) {
  char format[] = "%c %*c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c21, c22;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12);
  int16_t res2 = sscanf(str, format, &c21, &c22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
}
END_TEST

START_TEST(sscanf_test_dec_specifier_1) {
  int d = 0, sd = 0;
  char str[] = "1234567890";
  char *format = "%d";
  ck_assert_int_eq(sscanf(str, format, &d), s21_sscanf(str, format, &sd));
  ck_assert_int_eq(d, sd);
}

START_TEST(sscanf_test_dec_specifier_2) {
  int d_1, d_2, sd_1, sd_2;
  char *str = "1234567890 0987654321";
  char *format = "%d%d";
  ck_assert_int_eq(sscanf(str, format, &d_1, &d_2),
                   s21_sscanf(str, format, &sd_1, &sd_2));
  ck_assert_int_eq(d_1, sd_1);
  ck_assert_int_eq(d_2, sd_2);
}

START_TEST(sscanf_test_dec_specifier_3) {
  int d_1 = 0, d_2 = 0, sd_1 = 0, sd_2 = 0;
  char str[] = "1234567890 0987654321";
  char *format = "%d %d";
  ck_assert_int_eq(sscanf(str, format, &d_1, &d_2),
                   s21_sscanf(str, format, &sd_1, &sd_2));
  ck_assert_int_eq(d_1, sd_1);
  ck_assert_int_eq(d_2, sd_2);
}

START_TEST(sscanf_test_dec_specifier_4) {
  int d_1 = 0, d_2 = 0, sd_1 = 0, sd_2 = 0;
  char str[] = "1234567890     0987654321";
  char *format = "%d     %d";
  ck_assert_int_eq(sscanf(str, format, &d_1, &d_2),
                   s21_sscanf(str, format, &sd_1, &sd_2));
  ck_assert_int_eq(d_1, sd_1);
  ck_assert_int_eq(d_2, sd_2);
}

START_TEST(sscanf_test_dec_specifier_5) {
  int d = 0, sd = 0;
  char str[] = "0123";
  char *format = "%d";
  ck_assert_int_eq(sscanf(str, format, &d), s21_sscanf(str, format, &sd));
  ck_assert_int_eq(d, sd);
}

START_TEST(sscanf_test_dec_specifier_6) {
  int d = 0, sd = 0;
  char str[] = "0x123abc";
  char *format = "%d";
  ck_assert_int_eq(sscanf(str, format, &d), s21_sscanf(str, format, &sd));
  ck_assert_int_eq(d, sd);
}

START_TEST(sscanf_test_dec_specifier_7) {
  int d = 0, sd = 0;
  char str[] = "0X123ABC";
  char *format = "%d";
  ck_assert_int_eq(sscanf(str, format, &d), s21_sscanf(str, format, &sd));
  ck_assert_int_eq(d, sd);
}

START_TEST(sscanf_test_int_specifier_1) {
  int i = 0, si = 0;
  char str[] = "1234567890";
  char *format = "%i";
  ck_assert_int_eq(sscanf(str, format, &i), s21_sscanf(str, format, &si));
  ck_assert_int_eq(i, si);
}

START_TEST(sscanf_test_int_specifier_2) {
  int i = 0, si = 0;
  char str[] = "123.456";
  char *format = "%i";
  ck_assert_int_eq(sscanf(str, format, &i), s21_sscanf(str, format, &si));
  ck_assert_int_eq(i, si);
}

START_TEST(sscanf_test_int_specifier_3) {
  int i = 0, si = 0;
  char str[] = "052";
  char *format = "%i";
  ck_assert_int_eq(sscanf(str, format, &i), s21_sscanf(str, format, &si));
  ck_assert_int_eq(i, si);
}

START_TEST(sscanf_test_int_specifier_4) {
  int i = 0, si = 0;
  char str[] = "0X123ABC";
  char *format = "%i";
  ck_assert_int_eq(sscanf(str, format, &i), s21_sscanf(str, format, &si));
  ck_assert_int_eq(i, si);
}

START_TEST(sscanf_test_int_specifier_5) {
  int i = 0, si = 0;
  char str[] = "0x123abc";
  char *format = "%i";
  ck_assert_int_eq(sscanf(str, format, &i), s21_sscanf(str, format, &si));
  ck_assert_int_eq(i, si);
}

START_TEST(sscanf_test_exp_specifier_1) {
  float e = 0., se = 0.;
  char str[] = "123";
  char *format = "%e";
  ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
  ck_assert_float_eq(e, se);
}

START_TEST(sscanf_test_exp_specifier_2) {
  float e = 0., se = 0.;
  char str[] = "123.456";
  char *format = "%e";
  ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
  ck_assert_float_eq(e, se);
}

START_TEST(sscanf_test_exp_specifier_3) {
  float e = 0., se = 0.;
  char str[] = "123.456e-1";
  char *format = "%e";
  ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
  ck_assert_float_eq(e, se);
}

START_TEST(sscanf_test_exp_specifier_4) {
  float e = 0., se = 0.;
  char str[] = "123.456e+1";
  char *format = "%e";
  ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
  ck_assert_float_eq(e, se);
}

START_TEST(sscanf_test_exp_specifier_5) {
  float e = 0., se = 0.;
  char str[] = "123.456e1";
  char *format = "%e";
  ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
  ck_assert_float_eq(e, se);
}

START_TEST(sscanf_test_exp_specifier_6) {
  float e = 0., se = 0.;
  char str[] = "123e-1";
  char *format = "%e";
  ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
  ck_assert_float_eq(e, se);
}

// START_TEST(sscanf_test_exp_specifier_7) {
//   float e = 0., se = 0.;
//   char str[] = ".123";
//   char *format = "%e";
//   ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
//   ck_assert_float_eq(e, se);
// }

// START_TEST(sscanf_test_exp_specifier_8) {
//   float e = 0., se = 0.;
//   char str[] = ".123e-1";
//   char *format = "%e";
//   ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
//   ck_assert_float_eq(e, se);
// }

START_TEST(sscanf_test_exp_specifier_9) {
  float e = 0., se = 0.;
  char str[] = "123.456E-1";
  char *format = "%e";
  ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
  ck_assert_float_eq(e, se);
}

START_TEST(sscanf_test_big_exp_specifier_1) {
  float e = 0., se = 0.;
  char str[] = "123";
  char *format = "%E";
  ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
  ck_assert_float_eq(e, se);
}

START_TEST(sscanf_test_big_exp_specifier_2) {
  float e = 0., se = 0.;
  char str[] = "123.456";
  char *format = "%E";
  ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
  ck_assert_float_eq(e, se);
}

START_TEST(sscanf_test_big_exp_specifier_3) {
  float e = 0., se = 0.;
  char str[] = "123.456E-1";
  char *format = "%E";
  ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
  ck_assert_float_eq(e, se);
}

START_TEST(sscanf_test_big_exp_specifier_4) {
  float e = 0., se = 0.;
  char str[] = "123.456E+1";
  char *format = "%E";
  ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
  ck_assert_float_eq(e, se);
}

START_TEST(sscanf_test_big_exp_specifier_5) {
  float e = 0., se = 0.;
  char str[] = "123.456E1";
  char *format = "%E";
  ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
  ck_assert_float_eq(e, se);
}

START_TEST(sscanf_test_big_exp_specifier_6) {
  float e = 0., se = 0.;
  char str[] = "123E-1";
  char *format = "%E";
  ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
  ck_assert_float_eq(e, se);
}

// START_TEST(sscanf_test_big_exp_specifier_7) {
//   float e = 0., se = 0.;
//   char str[] = ".123";
//   char *format = "%E";
//   ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
//   ck_assert_float_eq(e, se);
// }

// START_TEST(sscanf_test_big_exp_specifier_8) {
//   float e = 0., se = 0.;
//   char str[] = ".123E-1";
//   char *format = "%E";
//   ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
//   ck_assert_float_eq(e, se);
// }

START_TEST(sscanf_test_big_exp_specifier_9) {
  float e = 0., se = 0.;
  char str[] = "123.456e-1";
  char *format = "%E";
  ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
  ck_assert_float_eq(e, se);
}

START_TEST(sscanf_test_float_specifier_1) {
  float f = 0., sf = 0.;
  char str[] = "123";
  char *format = "%f";
  ck_assert_int_eq(sscanf(str, format, &f), s21_sscanf(str, format, &sf));
  ck_assert_int_eq(f, sf);
}

START_TEST(sscanf_test_float_specifier_2) {
  float f = 0., sf = 0.;
  char str[] = "123.456";
  char *format = "%f";
  ck_assert_int_eq(sscanf(str, format, &f), s21_sscanf(str, format, &sf));
  ck_assert_int_eq(f, sf);
}

START_TEST(sscanf_test_float_specifier_3) {
  float f = 0., sf = 0.;
  char str[] = "123.456E-1";
  char *format = "%f";
  ck_assert_int_eq(sscanf(str, format, &f), s21_sscanf(str, format, &sf));
  ck_assert_int_eq(f, sf);
}

START_TEST(sscanf_test_float_specifier_4) {
  float f = 0., sf = 0.;
  char str[] = "123.456E+1";
  char *format = "%f";
  ck_assert_int_eq(sscanf(str, format, &f), s21_sscanf(str, format, &sf));
  ck_assert_int_eq(f, sf);
}

START_TEST(sscanf_test_float_specifier_5) {
  float f = 0., sf = 0.;
  char str[] = "123.456E1";
  char *format = "%f";
  ck_assert_int_eq(sscanf(str, format, &f), s21_sscanf(str, format, &sf));
  ck_assert_int_eq(f, sf);
}

START_TEST(sscanf_test_float_specifier_6) {
  float f = 0., sf = 0.;
  char str[] = "123E-1";
  char *format = "%f";
  ck_assert_int_eq(sscanf(str, format, &f), s21_sscanf(str, format, &sf));
  ck_assert_int_eq(f, sf);
}

// START_TEST(sscanf_test_float_specifier_7) {
//   float f = 0., sf = 0.;
//   char str[] = ".123";
//   char *format = "%f";
//   ck_assert_int_eq(sscanf(str, format, &f), s21_sscanf(str, format, &sf));
//   ck_assert_int_eq(f, sf);
// }

// START_TEST(sscanf_test_float_specifier_8) {
//   float e = 0., se = 0.;
//   char str[] = ".123E-1";
//   char *format = "%f";
//   ck_assert_int_eq(sscanf(str, format, &e), s21_sscanf(str, format, &se));
//   ck_assert_int_eq(e, se);
// }

START_TEST(sscanf_test_float_specifier_9) {
  float f = 0., sf = 0.;
  char str[] = "123.456e-1";
  char *format = "%f";
  ck_assert_int_eq(sscanf(str, format, &f), s21_sscanf(str, format, &sf));
  ck_assert_int_eq(f, sf);
}

START_TEST(sscanf_test_float_specifier_10) {
  char format[] = "%f %f %f";
  char str[] = "123 +198 -87";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_11) {
  char format[] = "%fg %f w%fx";
  char str[] = "75g +19.8w -87.x";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_12) {
  char format[] = "%f %f %f %f";
  char str[] = "NAN nan -INF +inf";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(d1);
  ck_assert_float_nan(d2);
  ck_assert_float_nan(q1);
  ck_assert_float_nan(q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_13) {
  char format[] = "%f";
  char str[] = "Nap";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_14) {
  char format[] = "%f";
  char str[] = "Np";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_15) {
  char format[] = "%f";
  char str[] = "iNd";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_16) {
  char format[] = "%f";
  char str[] = "id";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_17) {
  char format[] = "%f %f %f %f";
  char str[] = "34.56e3 83.2e-4 .43e+1 +2.43e3";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_18) {
  char format[] = "%1f %1f %2f %1f";
  char str[] = "34.5+6e3 83.2e-4 .43e+1 +2.43e3";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_19) {
  char format[] = "%*f %7f %*f %*f";
  char str[] = "34.5+6e3 83.2e-4 +43e+1 +2.43e3";
  float d1, d2;
  float q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_20) {
  char format[] = "%fr %7f p";
  char str[] = "34.5r 83.2ep4";
  float d1, d2;
  float q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_21) {
  char format[] = "%1f %1f %1f %1f";
  char str[] = "34 32. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_22) {
  char format[] = "%2f %2f %2f %2f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_23) {
  char format[] = "%3f %3f %4f %3f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_24) {
  char format[] = "%4f %4f %4f %4f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_25) {
  char format[] = "%f %fx %2f1 %2fx %*f %*f";
  char str[] = "1.1 2.x 1.1 2.x 1.1 2.x";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_float_specifier_26) {
  char format[] = "%f %4f %5fq %6f %*f q%*f";
  char str[] = "1.3e1 1.4eq2 1.3e1q 1.4 1.3eq 1.4e2";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_dec_float_specifier_1) {
  int g = 0, sg = 0;
  char str[] = "1.234567890";
  char *format = "%g";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

// START_TEST(sscanf_test_dec_float_specifier_2) {
//   int g = 0, sg = 0;
//   char str[] = ".1234567890";
//   char *format = "%g";
//   ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
//   ck_assert_uint_eq(g, sg);
// }

START_TEST(sscanf_test_dec_float_specifier_3) {
  int g = 0, sg = 0;
  char str[] = "1234567890";
  char *format = "%g";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_specifier_4) {
  int g = 0, sg = 0;
  char str[] = "1234567890.0987654321";
  char *format = "%g";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_specifier_5) {
  int g = 0, sg = 0;
  char str[] = "123E-1";
  char *format = "%g";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_specifier_6) {
  int g = 0, sg = 0;
  char str[] = "123E+1";
  char *format = "%g";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_specifier_7) {
  int g = 0, sg = 0;
  char str[] = "123E1";
  char *format = "%g";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_specifier_8) {
  int g = 0, sg = 0;
  char str[] = "123.456E-1";
  char *format = "%g";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_specifier_9) {
  int g = 0, sg = 0;
  char str[] = "123.456E+1";
  char *format = "%g";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_specifier_10) {
  int g = 0, sg = 0;
  char str[] = "123.456E1";
  char *format = "%g";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_big_g_specifier_1) {
  int g = 0, sg = 0;
  char str[] = "1.234567890";
  char *format = "%G";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

// START_TEST(sscanf_test_dec_float_big_g_specifier_2) {
//   int g = 0, sg = 0;
//   char str[] = ".1234567890";
//   char *format = "%G";
//   ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
//   ck_assert_uint_eq(g, sg);
// }

START_TEST(sscanf_test_dec_float_big_g_specifier_3) {
  int g = 0, sg = 0;
  char str[] = "1234567890";
  char *format = "%G";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_big_g_specifier_4) {
  int g = 0, sg = 0;
  char str[] = "1234567890.0987654321";
  char *format = "%G";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_big_g_specifier_5) {
  int g = 0, sg = 0;
  char str[] = "123E-1";
  char *format = "%G";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_big_g_specifier_6) {
  int g = 0, sg = 0;
  char str[] = "123E+1";
  char *format = "%G";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_big_g_specifier_7) {
  int g = 0, sg = 0;
  char str[] = "123E1";
  char *format = "%G";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_big_g_specifier_8) {
  int g = 0, sg = 0;
  char str[] = "123.456E-1";
  char *format = "%G";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_big_g_specifier_9) {
  int g = 0, sg = 0;
  char str[] = "123.456E+1";
  char *format = "%G";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_dec_float_big_g_specifier_10) {
  int g = 0, sg = 0;
  char str[] = "123.456E1";
  char *format = "%G";
  ck_assert_int_eq(sscanf(str, format, &g), s21_sscanf(str, format, &sg));
  ck_assert_uint_eq(g, sg);
}

START_TEST(sscanf_test_oct_specifier_1) {
  int i = 0, si = 0;
  char str[] = "1234567890";
  char *format = "%o";
  ck_assert_int_eq(sscanf(str, format, &i), s21_sscanf(str, format, &si));
  ck_assert_uint_eq(i, si);
}

START_TEST(sscanf_test_oct_specifier_2) {
  int i = 0, si = 0;
  char str[] = "123.456";
  char *format = "%o";
  ck_assert_int_eq(sscanf(str, format, &i), s21_sscanf(str, format, &si));
  ck_assert_uint_eq(i, si);
}

START_TEST(sscanf_test_oct_specifier_3) {
  int i = 0, si = 0;
  char str[] = "052";
  char *format = "%o";
  ck_assert_int_eq(sscanf(str, format, &i), s21_sscanf(str, format, &si));
  ck_assert_uint_eq(i, si);
}

START_TEST(sscanf_test_oct_specifier_4) {
  int i = 0, si = 0;
  char str[] = "0X123ABC";
  char *format = "%o";
  ck_assert_int_eq(sscanf(str, format, &i), s21_sscanf(str, format, &si));
  ck_assert_uint_eq(i, si);
}

START_TEST(sscanf_test_oct_specifier_5) {
  int i = 0, si = 0;
  char str[] = "0x123abc";
  char *format = "%o";
  ck_assert_int_eq(sscanf(str, format, &i), s21_sscanf(str, format, &si));
  ck_assert_uint_eq(i, si);
}

START_TEST(sscanf_test_str_specifier_1) {
  unsigned int u = 0U, su = 0U;
  char str[] = "123";
  char *format = "%u";
  ck_assert_int_eq(sscanf(str, format, &u), s21_sscanf(str, format, &su));
  ck_assert_uint_eq(u, su);
}

START_TEST(sscanf_test_str_specifier_2) {
  unsigned int u_1 = 0U, u_2 = 0U, su_1 = 0U, su_2 = 0U;
  char str[] = "123 456";
  char *format = "%u %u";
  ck_assert_int_eq(sscanf(str, format, &u_1, &u_2),
                   s21_sscanf(str, format, &su_1, &su_2));
  ck_assert_uint_eq(u_1, su_1);
  ck_assert_uint_eq(u_2, su_2);
}

START_TEST(sscanf_test_str_specifier_3) {
  unsigned int u_1 = 0U, u_2 = 0U, su_1 = 0U, su_2 = 0U;
  char str[] = "123 456";
  char *format = "%u%u";
  ck_assert_int_eq(sscanf(str, format, &u_1, &u_2),
                   s21_sscanf(str, format, &su_1, &su_2));
  ck_assert_uint_eq(u_1, su_1);
  ck_assert_uint_eq(u_2, su_2);
}

START_TEST(sscanf_test_str_specifier_4) {
  unsigned int u = 0U, su = 0U;
  char str[] = "-123";
  char *format = "%u";
  ck_assert_int_eq(sscanf(str, format, &u), s21_sscanf(str, format, &su));
  ck_assert_uint_eq(u, su);
}

START_TEST(sscanf_test_str_specifier_5) {
  unsigned int u = 0U, su = 0U;
  char str[] = "123.456";
  char *format = "%u";
  ck_assert_int_eq(sscanf(str, format, &u), s21_sscanf(str, format, &su));
  ck_assert_uint_eq(u, su);
}

START_TEST(sscanf_test_str_specifier_6) {
  unsigned int u = 0U, su = 0U;
  char str[] = "0x123";
  char *format = "%u";
  ck_assert_int_eq(sscanf(str, format, &u), s21_sscanf(str, format, &su));
  ck_assert_uint_eq(u, su);
}

START_TEST(sscanf_test_str_specifier_7) {
  unsigned int u = 0U, su = 0U;
  char str[] = "0X123";
  char *format = "%u";
  ck_assert_int_eq(sscanf(str, format, &u), s21_sscanf(str, format, &su));
  ck_assert_uint_eq(u, su);
}

START_TEST(sscanf_test_hex_specifier_1) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "123aB";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_hex_specifier_2) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "0x123abc";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_hex_specifier_3) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "0X123ABC";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_hex_specifier_4) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "123.456";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_hex_specifier_5) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "-123";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_hex_specifier_6) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "0123";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_hex_specifier_7) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "0b123";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_hex_specifier_8) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "0B123";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_big_hex_specifier_1) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "123aB";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_big_hex_specifier_2) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "0x123abc";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_big_hex_specifier_3) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "0X123ABC";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_big_hex_specifier_4) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "123.456";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_big_hex_specifier_5) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "-123";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_big_hex_specifier_6) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "0123";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_big_hex_specifier_7) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "0b123";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_test_big_hex_specifier_8) {
  unsigned int x = 0U, sx = 0U;
  char str[] = "0B123";
  char *format = "%x";
  ck_assert_int_eq(sscanf(str, format, &x), s21_sscanf(str, format, &sx));
  ck_assert_uint_eq(x, sx);
}

START_TEST(sscanf_spec_p_1) {
  char format[] = "%p";
  char str[] = "0xAAAA";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_2) {
  char format[] = "%5p";
  char str[] = "0xAAAA";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_3) {
  char format[] = "%p";
  char str[] = "0xFFFFFF";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_4) {
  char format[] = "%p";
  char str[] = "0x0000";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_5) {
  char format[] = "%p";
  char str[] = "0xA2361598";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_6) {
  char format[] = "%p";
  char str[] = "0x34567hjk";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_7) {
  char format[] = "%p";
  char str[] = "0x34567hjk678";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_8) {
  char format[] = "%p";
  char str[] = "0x34ABcd68";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_9) {
  char format[] = "%p";
  char str[] = "1234567890ABCDEF";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_10) {
  char format[] = "%5p";
  char str[] = "0x237481";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_11) {
  char format[] = "%6p";
  char str[] = "0xdksajh";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_12) {
  char format[] = "%6p";
  char str[] = "0xAGAGUIY";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_13) {
  char format[] = "%p";
  char str[] = "0xAGAGUIYUYGFSV";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_14) {
  char format[] = "%p";
  char str[] = "0xAA64BB";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_15) {
  char format[] = "%p";
  char str[] = "0xGGH7TY";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_test_num_char_specifier_1) {
  char c = 0;
  int n = 0, sn = 0;
  char str[] = "a b c";
  char *format = "%c %n";
  ck_assert_int_eq(sscanf(str, format, &c, &n),
                   s21_sscanf(str, format, &c, &sn));
  ck_assert_uint_eq(n, sn);
}

START_TEST(sscanf_test_num_char_specifier_2) {
  char c = 0;
  int n = 0, sn = 0;
  char str[] = "a b c";
  char *format = "%c%n";
  ck_assert_int_eq(sscanf(str, format, &c, &n),
                   s21_sscanf(str, format, &c, &sn));
  ck_assert_uint_eq(n, sn);
}

START_TEST(sscanf_test_num_char_specifier_3) {
  char c = 0;
  int n = 0, sn = 0;
  char str[] = "a         b c";
  char *format = "%c %n";
  ck_assert_int_eq(sscanf(str, format, &c, &n),
                   s21_sscanf(str, format, &c, &sn));
  ck_assert_uint_eq(n, sn);
}

START_TEST(sscanf_test_num_char_specifier_4) {
  char c = 0;
  int n = 0, sn = 0;
  char str[] = "a         b c";
  char *format = "%c%n";
  ck_assert_int_eq(sscanf(str, format, &c, &n),
                   s21_sscanf(str, format, &c, &sn));
  ck_assert_uint_eq(n, sn);
}

START_TEST(sscanf_test_num_char_specifier_5) {
  char c = 0;
  int n = 0, sn = 0;
  char str[] = "a ";
  char *format = "%c %n";
  ck_assert_int_eq(sscanf(str, format, &c, &n),
                   s21_sscanf(str, format, &c, &sn));
  ck_assert_uint_eq(n, sn);
}

START_TEST(sscanf_test_num_char_specifier_6) {
  int d = 0;
  int n = 0, sn = 0;
  char str[] = "123 456";
  char *format = "%d %n";
  ck_assert_int_eq(sscanf(str, format, &d, &n),
                   s21_sscanf(str, format, &d, &sn));
  ck_assert_uint_eq(n, sn);
}

START_TEST(sscanf_test_num_char_specifier_7) {
  int d = 0;
  int n = 0, sn = 0;
  char str[] = "123        456";
  char *format = "%d %n";
  ck_assert_int_eq(sscanf(str, format, &d, &n),
                   s21_sscanf(str, format, &d, &sn));
  ck_assert_uint_eq(n, sn);
}

START_TEST(sscanf_test_num_char_specifier_8) {
  int d = 0;
  int n = 0, sn = 0;
  char str[] = "123 456";
  char *format = "%d%n";
  ck_assert_int_eq(sscanf(str, format, &d, &n),
                   s21_sscanf(str, format, &d, &sn));
  ck_assert_uint_eq(n, sn);
}

START_TEST(sscanf_test_num_char_specifier_9) {
  int d = 0;
  int n = 0, sn = 0;
  char str[] = "123        456";
  char *format = "%d%n";
  ck_assert_int_eq(sscanf(str, format, &d, &n),
                   s21_sscanf(str, format, &d, &sn));
  ck_assert_uint_eq(n, sn);
}

START_TEST(sscanf_test_num_char_specifier_10) {
  int d = 0;
  int n = 0, sn = 0;
  char str[] = "123.456";
  char *format = "%d%n";
  ck_assert_int_eq(sscanf(str, format, &d, &n),
                   s21_sscanf(str, format, &d, &sn));
  ck_assert_uint_eq(n, sn);
}

START_TEST(sscanf_test_num_char_specifier_11) {
  int d = 0;
  int n = 0, sn = 0;
  char str[] = "123";
  char *format = "%d%n";
  ck_assert_int_eq(sscanf(str, format, &d, &n),
                   s21_sscanf(str, format, &d, &sn));
  ck_assert_uint_eq(n, sn);
}

START_TEST(sscanf_test_empty_1) {
  char format[] = "%d";
  char str[] = "";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_test_empty_2) {
  char format[] = "%d";
  char str[] = "     ";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_test_empty_3) {
  char format[] = "%d";
  char str[] = "\n";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_test_empty_4) {
  char format[] = "%d";
  char str[] = "\t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_test_empty_5) {
  char format[] = "%d";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_test_empty_6) {
  char format[] = "";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_test_empty_7) {
  char format[] = "\t";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *suite_sscanf(void) {
  Suite *suite = suite_create("\033[30;43m S21_SSCANF \033[0m");
  TCase *tcase = tcase_create("tcase_sscanf_character");

  tcase_add_test(tcase, sscanf_test_char_specifier_1);
  tcase_add_test(tcase, sscanf_test_char_specifier_2);
  tcase_add_test(tcase, sscanf_test_char_specifier_3);
  tcase_add_test(tcase, sscanf_test_char_specifier_4);
  tcase_add_test(tcase, sscanf_test_char_specifier_5);
  tcase_add_test(tcase, sscanf_test_char_specifier_6);
  tcase_add_test(tcase, sscanf_test_char_specifier_7);
  tcase_add_test(tcase, sscanf_test_char_specifier_8);
  tcase_add_test(tcase, sscanf_test_char_specifier_9);
  tcase_add_test(tcase, sscanf_test_char_specifier_10);
  tcase_add_test(tcase, sscanf_test_char_specifier_11);
  tcase_add_test(tcase, sscanf_test_char_specifier_12);
  tcase_add_test(tcase, sscanf_test_char_specifier_13);
  tcase_add_test(tcase, sscanf_test_char_specifier_14);

  tcase_add_test(tcase, sscanf_test_dec_specifier_1);
  tcase_add_test(tcase, sscanf_test_dec_specifier_2);
  tcase_add_test(tcase, sscanf_test_dec_specifier_3);
  tcase_add_test(tcase, sscanf_test_dec_specifier_4);
  tcase_add_test(tcase, sscanf_test_dec_specifier_5);
  tcase_add_test(tcase, sscanf_test_dec_specifier_6);
  tcase_add_test(tcase, sscanf_test_dec_specifier_7);

  tcase_add_test(tcase, sscanf_test_int_specifier_1);
  tcase_add_test(tcase, sscanf_test_int_specifier_2);
  tcase_add_test(tcase, sscanf_test_int_specifier_3);
  tcase_add_test(tcase, sscanf_test_int_specifier_4);
  tcase_add_test(tcase, sscanf_test_int_specifier_5);

  tcase_add_test(tcase, sscanf_test_exp_specifier_1);
  tcase_add_test(tcase, sscanf_test_exp_specifier_2);
  tcase_add_test(tcase, sscanf_test_exp_specifier_3);
  tcase_add_test(tcase, sscanf_test_exp_specifier_4);
  tcase_add_test(tcase, sscanf_test_exp_specifier_5);
  tcase_add_test(tcase, sscanf_test_exp_specifier_6);
  // tcase_add_test(tcase, sscanf_test_exp_specifier_7);
  // tcase_add_test(tcase, sscanf_test_exp_specifier_8);
  tcase_add_test(tcase, sscanf_test_exp_specifier_9);

  tcase_add_test(tcase, sscanf_test_big_exp_specifier_1);
  tcase_add_test(tcase, sscanf_test_big_exp_specifier_2);
  tcase_add_test(tcase, sscanf_test_big_exp_specifier_3);
  tcase_add_test(tcase, sscanf_test_big_exp_specifier_4);
  tcase_add_test(tcase, sscanf_test_big_exp_specifier_5);
  tcase_add_test(tcase, sscanf_test_big_exp_specifier_6);
  // tcase_add_test(tcase, sscanf_test_big_exp_specifier_7);
  // tcase_add_test(tcase, sscanf_test_big_exp_specifier_8);
  tcase_add_test(tcase, sscanf_test_big_exp_specifier_9);

  tcase_add_test(tcase, sscanf_test_float_specifier_1);
  tcase_add_test(tcase, sscanf_test_float_specifier_2);
  tcase_add_test(tcase, sscanf_test_float_specifier_3);
  tcase_add_test(tcase, sscanf_test_float_specifier_4);
  tcase_add_test(tcase, sscanf_test_float_specifier_5);
  tcase_add_test(tcase, sscanf_test_float_specifier_6);
  // tcase_add_test(tcase, sscanf_test_float_specifier_7);
  // tcase_add_test(tcase, sscanf_test_float_specifier_8);
  tcase_add_test(tcase, sscanf_test_float_specifier_9);
  tcase_add_test(tcase, sscanf_test_float_specifier_10);
  tcase_add_test(tcase, sscanf_test_float_specifier_11);
  tcase_add_test(tcase, sscanf_test_float_specifier_12);
  tcase_add_test(tcase, sscanf_test_float_specifier_13);
  tcase_add_test(tcase, sscanf_test_float_specifier_14);
  tcase_add_test(tcase, sscanf_test_float_specifier_15);
  tcase_add_test(tcase, sscanf_test_float_specifier_16);
  tcase_add_test(tcase, sscanf_test_float_specifier_17);
  tcase_add_test(tcase, sscanf_test_float_specifier_18);
  tcase_add_test(tcase, sscanf_test_float_specifier_19);
  tcase_add_test(tcase, sscanf_test_float_specifier_20);
  tcase_add_test(tcase, sscanf_test_float_specifier_21);
  tcase_add_test(tcase, sscanf_test_float_specifier_22);
  tcase_add_test(tcase, sscanf_test_float_specifier_23);
  tcase_add_test(tcase, sscanf_test_float_specifier_24);
  tcase_add_test(tcase, sscanf_test_float_specifier_25);
  tcase_add_test(tcase, sscanf_test_float_specifier_26);

  tcase_add_test(tcase, sscanf_test_dec_float_specifier_1);
  // tcase_add_test(tcase, sscanf_test_dec_float_specifier_2);
  tcase_add_test(tcase, sscanf_test_dec_float_specifier_3);
  tcase_add_test(tcase, sscanf_test_dec_float_specifier_4);
  tcase_add_test(tcase, sscanf_test_dec_float_specifier_5);
  tcase_add_test(tcase, sscanf_test_dec_float_specifier_6);
  tcase_add_test(tcase, sscanf_test_dec_float_specifier_7);
  tcase_add_test(tcase, sscanf_test_dec_float_specifier_8);
  tcase_add_test(tcase, sscanf_test_dec_float_specifier_9);
  tcase_add_test(tcase, sscanf_test_dec_float_specifier_10);

  tcase_add_test(tcase, sscanf_test_dec_float_big_g_specifier_1);
  // tcase_add_test(tcase, sscanf_test_dec_float_big_g_specifier_2);
  tcase_add_test(tcase, sscanf_test_dec_float_big_g_specifier_3);
  tcase_add_test(tcase, sscanf_test_dec_float_big_g_specifier_4);
  tcase_add_test(tcase, sscanf_test_dec_float_big_g_specifier_5);
  tcase_add_test(tcase, sscanf_test_dec_float_big_g_specifier_6);
  tcase_add_test(tcase, sscanf_test_dec_float_big_g_specifier_7);
  tcase_add_test(tcase, sscanf_test_dec_float_big_g_specifier_8);
  tcase_add_test(tcase, sscanf_test_dec_float_big_g_specifier_9);
  tcase_add_test(tcase, sscanf_test_dec_float_big_g_specifier_10);

  tcase_add_test(tcase, sscanf_test_oct_specifier_1);
  tcase_add_test(tcase, sscanf_test_oct_specifier_2);
  tcase_add_test(tcase, sscanf_test_oct_specifier_3);
  tcase_add_test(tcase, sscanf_test_oct_specifier_4);
  tcase_add_test(tcase, sscanf_test_oct_specifier_5);

  tcase_add_test(tcase, sscanf_test_str_specifier_1);
  tcase_add_test(tcase, sscanf_test_str_specifier_2);
  tcase_add_test(tcase, sscanf_test_str_specifier_3);
  tcase_add_test(tcase, sscanf_test_str_specifier_4);
  tcase_add_test(tcase, sscanf_test_str_specifier_5);
  tcase_add_test(tcase, sscanf_test_str_specifier_6);
  tcase_add_test(tcase, sscanf_test_str_specifier_7);

  tcase_add_test(tcase, sscanf_test_hex_specifier_1);
  tcase_add_test(tcase, sscanf_test_hex_specifier_2);
  tcase_add_test(tcase, sscanf_test_hex_specifier_3);
  tcase_add_test(tcase, sscanf_test_hex_specifier_4);
  tcase_add_test(tcase, sscanf_test_hex_specifier_5);
  tcase_add_test(tcase, sscanf_test_hex_specifier_6);
  tcase_add_test(tcase, sscanf_test_hex_specifier_7);
  tcase_add_test(tcase, sscanf_test_hex_specifier_8);

  tcase_add_test(tcase, sscanf_test_big_hex_specifier_1);
  tcase_add_test(tcase, sscanf_test_big_hex_specifier_2);
  tcase_add_test(tcase, sscanf_test_big_hex_specifier_3);
  tcase_add_test(tcase, sscanf_test_big_hex_specifier_4);
  tcase_add_test(tcase, sscanf_test_big_hex_specifier_5);
  tcase_add_test(tcase, sscanf_test_big_hex_specifier_6);
  tcase_add_test(tcase, sscanf_test_big_hex_specifier_7);
  tcase_add_test(tcase, sscanf_test_big_hex_specifier_8);

  tcase_add_test(tcase, sscanf_spec_p_1);
  tcase_add_test(tcase, sscanf_spec_p_2);
  tcase_add_test(tcase, sscanf_spec_p_3);
  tcase_add_test(tcase, sscanf_spec_p_4);
  tcase_add_test(tcase, sscanf_spec_p_5);
  tcase_add_test(tcase, sscanf_spec_p_6);
  tcase_add_test(tcase, sscanf_spec_p_7);
  tcase_add_test(tcase, sscanf_spec_p_8);
  tcase_add_test(tcase, sscanf_spec_p_9);
  tcase_add_test(tcase, sscanf_spec_p_10);
  tcase_add_test(tcase, sscanf_spec_p_11);
  tcase_add_test(tcase, sscanf_spec_p_12);
  tcase_add_test(tcase, sscanf_spec_p_13);
  tcase_add_test(tcase, sscanf_spec_p_14);
  tcase_add_test(tcase, sscanf_spec_p_15);

  tcase_add_test(tcase, sscanf_test_num_char_specifier_1);
  tcase_add_test(tcase, sscanf_test_num_char_specifier_2);
  tcase_add_test(tcase, sscanf_test_num_char_specifier_3);
  tcase_add_test(tcase, sscanf_test_num_char_specifier_4);
  tcase_add_test(tcase, sscanf_test_num_char_specifier_5);
  tcase_add_test(tcase, sscanf_test_num_char_specifier_6);
  tcase_add_test(tcase, sscanf_test_num_char_specifier_7);
  tcase_add_test(tcase, sscanf_test_num_char_specifier_8);
  tcase_add_test(tcase, sscanf_test_num_char_specifier_9);
  tcase_add_test(tcase, sscanf_test_num_char_specifier_10);
  tcase_add_test(tcase, sscanf_test_num_char_specifier_11);

  tcase_add_test(tcase, sscanf_test_empty_1);
  tcase_add_test(tcase, sscanf_test_empty_2);
  tcase_add_test(tcase, sscanf_test_empty_3);
  tcase_add_test(tcase, sscanf_test_empty_4);
  tcase_add_test(tcase, sscanf_test_empty_5);
  tcase_add_test(tcase, sscanf_test_empty_6);
  tcase_add_test(tcase, sscanf_test_empty_7);

  suite_add_tcase(suite, tcase);

  return suite;
}