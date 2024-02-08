#include "s21_tests.h"

START_TEST(abs_test) {
  ck_assert_double_eq_tol(abs(-7), s21_abs(-7), S21_EPS);
  ck_assert_double_eq_tol(abs(-98), s21_abs(-98), S21_EPS);
  ck_assert_double_eq_tol(abs(123), s21_abs(123), S21_EPS);
  ck_assert_double_eq_tol(abs(10009), s21_abs(10009), S21_EPS);
  ck_assert_double_eq_tol(abs(-10009), s21_abs(-10009), S21_EPS);
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_double_eq(fabs(INFINITY), s21_fabs(S21_INFINITY));
  ck_assert_double_eq(fabs(-INFINITY), s21_fabs(-S21_INFINITY));
  ck_assert_double_nan(fabs(NAN));
  ck_assert_double_nan(s21_fabs(S21_NAN));
  ck_assert_double_eq_tol(fabs(-7.0), s21_fabs(-7.0), S21_EPS);
  ck_assert_double_eq_tol(fabs(-98.1), s21_fabs(-98.1), S21_EPS);
  ck_assert_double_eq_tol(fabs(123.02), s21_fabs(123.02), S21_EPS);
  ck_assert_double_eq_tol(fabs(10009.0), s21_fabs(10009.0), S21_EPS);
  ck_assert_double_eq_tol(fabs(-10009.555), s21_fabs(-10009.555), S21_EPS);
  ck_assert_double_eq_tol(fabs(-0.10009), s21_fabs(-0.10009), S21_EPS);
  ck_assert_double_eq_tol(fabs(-1e23), s21_fabs(-1e23), S21_EPS);
}
END_TEST

START_TEST(floor_test) {
  ck_assert_double_eq(floor(INFINITY), s21_floor(S21_INFINITY));
  ck_assert_double_eq(floor(-INFINITY), s21_floor(-S21_INFINITY));
  ck_assert_double_nan(floor(NAN));
  ck_assert_double_nan(s21_floor(S21_NAN));
  ck_assert_double_eq_tol(floor(-7.0), s21_floor(-7.0), S21_EPS);
  ck_assert_double_eq_tol(floor(-98.1), s21_floor(-98.1), S21_EPS);
  ck_assert_double_eq_tol(floor(123.02), s21_floor(123.02), S21_EPS);
  ck_assert_double_eq_tol(floor(10009.00123), s21_floor(10009.00123), S21_EPS);
  ck_assert_double_eq_tol(floor(-10009.555), s21_floor(-10009.555), S21_EPS);
  ck_assert_double_eq_tol(floor(-0.10009), s21_floor(-0.10009), S21_EPS);
  ck_assert_double_eq_tol(floor(-1e-23), s21_floor(-1e-23), S21_EPS);
  ck_assert_double_eq_tol(floor(100091234.5), s21_floor(100091234.5), S21_EPS);
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_double_eq(ceil(INFINITY), s21_ceil(S21_INFINITY));
  ck_assert_double_eq(ceil(-INFINITY), s21_ceil(-S21_INFINITY));
  ck_assert_double_nan(ceil(NAN));
  ck_assert_double_nan(s21_ceil(S21_NAN));
  ck_assert_double_eq_tol(ceil(-7.0), s21_ceil(-7.0), S21_EPS);
  ck_assert_double_eq_tol(ceil(-98.1), s21_ceil(-98.1), S21_EPS);
  ck_assert_double_eq_tol(ceil(123.02), s21_ceil(123.02), S21_EPS);
  ck_assert_double_eq_tol(ceil(10009.00123), s21_ceil(10009.00123), S21_EPS);
  ck_assert_double_eq_tol(ceil(-10009.555), s21_ceil(-10009.555), S21_EPS);
  ck_assert_double_eq_tol(ceil(-0.10009), s21_ceil(-0.10009), S21_EPS);
  ck_assert_double_eq_tol(ceil(-1e-23), s21_ceil(-1e-23), S21_EPS);
}
END_TEST

START_TEST(fmod_test_1) {
  ck_assert_double_nan(fmod(1, 0));
  ck_assert_double_nan(s21_fmod(1, 0));
  ck_assert_double_eq_tol(fmod(0, -1), s21_fmod(0, -1), S21_EPS);
  ck_assert_double_eq_tol(fmod(0, 1), s21_fmod(0, 1), S21_EPS);
  ck_assert_double_nan(fmod(INFINITY, -1));
  ck_assert_double_nan(s21_fmod(INFINITY, -1));
  ck_assert_double_eq(fmod(-1, -INFINITY), s21_fmod(-1, -S21_INFINITY));
  ck_assert_double_eq(fmod(0, INFINITY), s21_fmod(0, S21_INFINITY));
  ck_assert_double_nan(s21_fmod(0, S21_NAN));
  ck_assert_double_nan(fmod(0, NAN));
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_double_nan(fmod(NAN, NAN));
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_INFINITY));
  ck_assert_double_nan(s21_fmod(S21_INFINITY, S21_NAN));
  ck_assert_double_nan(s21_fmod(S21_NAN, -S21_INFINITY));
  ck_assert_double_nan(s21_fmod(-S21_INFINITY, S21_NAN));
  ck_assert_double_nan(fmod(NAN, INFINITY));
  ck_assert_double_nan(fmod(INFINITY, NAN));
  ck_assert_double_nan(fmod(NAN, -INFINITY));
  ck_assert_double_nan(fmod(-INFINITY, NAN));
}
END_TEST

START_TEST(fmod_test_2) {
  for (double a = -1500; a < 1500; a += 123) {
    for (double b = -12; b < 12; b += 1.25) {
      ck_assert_double_eq_tol(fmod(a, b), s21_fmod(a, b), S21_EPS);
      ck_assert_double_eq_tol(fmod(b, a), s21_fmod(b, a), S21_EPS);
    }
  }
}
END_TEST

START_TEST(sin_test_1) {
  for (double x = -7; x <= 7; x += 1.0E-3)
    ck_assert_double_eq_tol(sinl(x), s21_sin(x), S21_EPS);
  for (double x = -1500; x < 1500; x += 123)
    ck_assert_double_eq_tol(sinl(x), s21_sin(x), S21_EPS);
}
END_TEST

START_TEST(sin_test_2) {
  double values[] = {-S21_INFINITY, S21_INFINITY, S21_NAN};
  for (int i = 0; i < 3; i++) ck_assert_double_nan(s21_sin(values[i]));
}
END_TEST

START_TEST(cos_test_1) {
  for (double x = -7; x <= 7; x += 1.0E-3)
    ck_assert_double_eq_tol(cosl(x), s21_cos(x), S21_EPS);
  for (double x = -1500; x < 1500; x += 123)
    ck_assert_double_eq_tol(cosl(x), s21_cos(x), S21_EPS);
}
END_TEST

START_TEST(cos_test_2) {
  double values[] = {-S21_INFINITY, S21_INFINITY, S21_NAN};
  for (int i = 0; i < 3; i++) ck_assert_double_nan(s21_cos(values[i]));
}
END_TEST

START_TEST(tan_test_1) {
  for (double x = -7; x <= 7; x += 1.0E-3)
    ck_assert_double_eq_tol(tanl(x), s21_tan(x), S21_EPS);
  for (double x = -1500; x < 1500; x += 123)
    ck_assert_double_eq_tol(tanl(x), s21_tan(x), S21_EPS);
}
END_TEST

START_TEST(tan_test_2) {
  double values[] = {-S21_INFINITY, S21_INFINITY, S21_NAN};
  for (int i = 0; i < 3; i++) ck_assert_double_nan(s21_tan(values[i]));
}
END_TEST

START_TEST(exp_test_1) {
  for (double x = -7; x <= 7; x += 1.0E-4)
    ck_assert_double_eq_tol(expl(x), s21_exp(x), S21_EPS);
}
END_TEST

START_TEST(exp_test_2) {
  ck_assert_double_eq(expl(S21_INFINITY), s21_exp(S21_INFINITY));
  ck_assert_double_eq(expl(-S21_INFINITY), s21_exp(-S21_INFINITY));
  ck_assert_double_nan(s21_exp(S21_NAN));
}
END_TEST

START_TEST(log_test_1) {
  for (double x = 1; x <= 7; x += 1.0E-4)
    ck_assert_double_eq_tol(logl(x), s21_log(x), S21_EPS);
  for (double x = 1; x <= 1500; x += 123)
    ck_assert_double_eq_tol(logl(x), s21_log(x), S21_EPS);
}
END_TEST

START_TEST(log_test_2) {
  ck_assert_double_eq(logl(S21_INFINITY), s21_log(S21_INFINITY));
  ck_assert_double_eq(logl(0.0), s21_log(0.0));
  ck_assert_double_nan(s21_log(-S21_INFINITY));
  ck_assert_double_nan(s21_log(S21_NAN));
  ck_assert_double_nan(s21_log(-1));
}
END_TEST

START_TEST(pow_test_1) {
  for (double a = 0.5; a < 15.0; a++)
    for (double b = -5.5; b < 5.0; b++)
      ck_assert_double_eq_tol(powl(a, b), s21_pow(a, b), S21_EPS);
}
END_TEST

START_TEST(pow_test_2) {
  double values[] = {S21_INFINITY, -S21_INFINITY, 1, -1, 0};
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      ck_assert_double_eq(powl(values[i], values[j]),
                          s21_pow(values[i], values[j]));

  ck_assert_double_nan(s21_pow(-1.0, 0.5));
}
END_TEST

START_TEST(sqrt_test_1) {
  for (double a = 0.0; a < 15.0; a += 0.5)
    ck_assert_double_eq_tol(sqrt(a), s21_sqrt(a), S21_EPS);
}
END_TEST

START_TEST(sqrt_test_2) {
  ck_assert_double_eq(sqrtl(S21_INFINITY), s21_sqrt(S21_INFINITY));
  ck_assert_double_nan(s21_sqrt(-S21_INFINITY));
  ck_assert_double_nan(s21_sqrt(S21_NAN));
  ck_assert_double_nan(s21_sqrt(-1.0));
}
END_TEST

START_TEST(asin_test_1) {
  for (double x = -1; x <= 1; x += 1.0E-4)
    ck_assert_double_eq_tol(asinl(x), s21_asin(x), S21_EPS);
}
END_TEST

START_TEST(asin_test_2) {
  double values[] = {-S21_INFINITY, S21_INFINITY, S21_NAN, -2, 2};
  for (int i = 0; i < 5; i++) ck_assert_double_nan(s21_asin(values[i]));
}
END_TEST

START_TEST(acos_test_1) {
  for (double x = -1; x <= 1; x += 1.0E-4)
    ck_assert_double_eq_tol(acosl(x), s21_acos(x), S21_EPS);
}
END_TEST

START_TEST(acos_test_2) {
  double values[] = {-S21_INFINITY, S21_INFINITY, S21_NAN, -2, 2};
  for (int i = 0; i < 5; i++) ck_assert_double_nan(s21_acos(values[i]));
}

START_TEST(atan_test_1) {
  for (double x = -7; x <= 7; x += 1.0E-3)
    ck_assert_double_eq_tol(atanl(x), s21_atan(x), S21_EPS);
  for (double x = -1500; x < 1500; x += 123)
    ck_assert_double_eq_tol(atanl(x), s21_atan(x), S21_EPS);
}
END_TEST

START_TEST(atan_test_2) {
  ck_assert_double_eq(atanl(S21_INFINITY), s21_atan(S21_INFINITY));
  ck_assert_double_eq(atanl(-S21_INFINITY), s21_atan(-S21_INFINITY));
  ck_assert_double_nan(s21_atan(S21_NAN));
}
END_TEST

Suite *s21_math_suite(void) {
  Suite *suite = suite_create("---s21_math---");
  TCase *tcase = tcase_create("math_tc");

  tcase_add_test(tcase, abs_test);
  tcase_add_test(tcase, fabs_test);
  tcase_add_test(tcase, floor_test);
  tcase_add_test(tcase, ceil_test);
  tcase_add_test(tcase, fmod_test_1);
  tcase_add_test(tcase, fmod_test_2);
  tcase_add_test(tcase, sin_test_1);
  tcase_add_test(tcase, sin_test_2);
  tcase_add_test(tcase, asin_test_1);
  tcase_add_test(tcase, asin_test_2);
  tcase_add_test(tcase, cos_test_1);
  tcase_add_test(tcase, cos_test_2);
  tcase_add_test(tcase, acos_test_1);
  tcase_add_test(tcase, acos_test_2);
  tcase_add_test(tcase, tan_test_1);
  tcase_add_test(tcase, tan_test_2);
  tcase_add_test(tcase, atan_test_1);
  tcase_add_test(tcase, atan_test_2);
  tcase_add_test(tcase, exp_test_1);
  tcase_add_test(tcase, exp_test_2);
  tcase_add_test(tcase, log_test_1);
  tcase_add_test(tcase, log_test_2);
  tcase_add_test(tcase, pow_test_1);
  tcase_add_test(tcase, pow_test_2);
  tcase_add_test(tcase, sqrt_test_1);
  tcase_add_test(tcase, sqrt_test_2);

  suite_add_tcase(suite, tcase);
  return suite;
}

int main(void) {
  // массив test suite с тест кейсами
  Suite *s21_math_tests[] = {s21_math_suite(), NULL};

  int failed = 0;
  for (int i = 0; s21_math_tests[i] != NULL; i++) {
    // создаем под каждый suite SRunner и запускаем тесты
    SRunner *sr = srunner_create(s21_math_tests[i]);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
