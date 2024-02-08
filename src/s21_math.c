#include "s21_math.h"

int s21_abs(int x) {
  if (x < 0) {
    x = -x;
  }
  return x;
}

long double s21_ceil(double x) {
  if (s21_isinf(x)) {
    return x;
  }

  int round = (int)x;
  if (x > S21_EPS && x != round) {
    x = round + 1;
  } else if (x < S21_EPS && x != round) {
    x = round;
  }
  return x;
}

long double s21_fabs(double x) {
  if (x < 0) {
    x = -x;
  }
  return x;
}

long double s21_floor(double x) {
  if (s21_isinf(x)) {
    return x;
  }

  int round = (int)x;
  if (x < S21_EPS && x != round) {
    x = round - 1;
  } else if (x > S21_EPS && x != round) {
    x = round;
  }
  return x;
}

long double s21_fmod(double x, double y) {
  if (s21_isnan(x) || s21_isnan(y) || s21_isinf(x)) {
    return S21_NAN;
  } else if (s21_isinf(y)) {
    return (long double)x;
  }
  if (y == 0) {
    return S21_NAN;
  }
  double n = (int)(x / y);
  long double res = (long double)x - n * (long double)y;
  return res;
}

int s21_isinf(double x) {
  int flag = 0;
  if ((x == S21_INFINITY || x == -S21_INFINITY)) {
    flag = 1;
  }
  return flag;
}

int s21_isnan(double x) {
  if (x != x)
    return 1;
  else
    return 0;
}

long double s21_cos(double x) {
  if (s21_isinf(x) || s21_isnan(x)) return S21_NAN;
  x = s21_fmod(x, 2 * S21_PI);
  long double a_n = 1;
  long double sum = 0;
  for (size_t i = 0; s21_fabs((double)a_n) >= S21_DBL_MIN; i++) {
    sum += a_n;
    a_n *= -1 * x * x / ((2 * i + 2) * (2 * i + 1));  // a_n = a_(n+1)
  }
  return sum;
}

long double s21_sin(double x) {
  if (s21_isinf(x) || s21_isnan(x)) return S21_NAN;
  x = s21_fmod(x, 2 * S21_PI);
  long double a_n = x;
  long double sum = 0;
  for (size_t i = 0; s21_fabs((double)a_n) >= S21_DBL_MIN; i++) {
    sum += a_n;
    a_n *= -1 * x * x / ((2 * i + 3) * (2 * i + 2));  // a_n = a_(n+1)
  }
  return sum;
}

long double s21_exp(double x) {
  int is_negative = x < 0.0L;

  if (x > 708.0)
    return S21_INFINITY;
  else if (x < -708.0)
    return 0.0L;
  else if (s21_isnan(x))
    return S21_NAN;

  x *= is_negative * (-2) + 1;
  long double a_n = 1.0L;
  long double sum = 0.0L;
  for (size_t i = 1; s21_fabs((double)a_n) >= S21_DBL_MIN; i++) {
    sum += a_n;
    a_n *= x / i;  // a_n = a_(n+1)
  }
  if (is_negative)
    return 1 / sum;
  else
    return sum;
}

long double s21_tan(double x) {
  if (s21_isnan(x) || s21_isinf(x)) return S21_NAN;
  x = s21_fmod(x, S21_PI);
  double a_n = x;
  double sin_ = 0;
  for (double n = 0.0L; a_n != 0.0; n++) {
    sin_ += a_n;
    a_n *= -1 * x * x / ((2 * n + 3) * (2 * n + 2));  // a_n = a_(n+1)
  }
  a_n = 1;
  double cos_ = 0;
  for (double n = 0.0L; a_n != 0.0; n++) {
    cos_ += a_n;
    a_n *= -1 * x * x / ((2 * n + 2) * (2 * n + 1));  // a_n = a_(n+1)
  }
  return sin_ / cos_;
}

long double s21_log(double x) {  // - Progress
  if (x == 0.0)
    return -S21_INFINITY;
  else if (x == S21_INFINITY)
    return x;
  else if (x < 0.0)
    return S21_NAN;

  size_t exp_pow = 0;
  long double result = 0.0l;
  long double previos;
  long double exp_tmp;

  for (; x >= S21_EXP; x /= S21_EXP) exp_pow++;   // x = a*e^n
  for (; x <= -S21_EXP; x += S21_EXP) exp_pow--;  // x = a*-e^n

  do {
    previos = result;
    exp_tmp = s21_exp(previos);
    result = previos + 2.0L * (x - exp_tmp) / (x + exp_tmp);
  } while (s21_fabs(result - previos) >= S21_EPS / 10);

  return (result + exp_pow);
}

long double s21_pow(double base, double exp) {
  long double result;
  if (s21_isnan(base) || s21_isnan(exp))
    result = S21_NAN;
  else if (base == -S21_INFINITY && exp == S21_INFINITY)
    result = S21_INFINITY;
  else if (exp == 0)
    result = 1;
  else if (s21_fabs(base) == 1 && s21_isinf(exp))
    result = 1;
  else if (base < 0 && base != -S21_INFINITY && (s21_fmod(exp, 1) != 0))
    result = S21_NAN;
  else
    result = s21_exp(exp * s21_log(s21_fabs(base))) *
             ((base < 0 && s21_fmod(exp, 2) != 0) * (-2) + 1);

  return result;
}

long double s21_acos(double x) {
  long double result = 0;
  if (s21_fabs(x) > 1) {
    result = S21_NAN;
  } else if (x > 0.707107) {
    result = s21_asin(s21_sqrt(1 - x * x));
  } else if (x < -0.707107) {
    result = S21_PI - s21_asin(s21_sqrt(1 - x * x));
  } else {
    result = S21_PI_2 - s21_asin(x);
  }
  return result;
}

long double s21_asin(double x) {
  long double result = x;
  if (s21_fabs(x) > 1.0L) {
    result = S21_NAN;
  } else if (x > 0.707107) {
    result = s21_acos(s21_sqrt(1 - x * x));
  } else if (x < -0.707107) {
    result = -s21_acos(s21_sqrt(1 - x * x));
  } else {
    long double a_n = x;
    for (long double n = 1.0L; s21_fabs(a_n) >= S21_EPS; n++) {
      a_n *= (2 * n - 1) * (2 * n - 1) / ((2 * n) * (2 * n + 1)) * x * x;
      result += a_n;
    }
  }
  return result;
}

long double s21_atan(double x) {
  long double result = 0;
  if (s21_fabs(x) > 0.4 && s21_fabs(x) < 10) {
    result = s21_asin(x * s21_sqrt(1 / (1 + x * x)));
  } else if (x == S21_INFINITY)
    return S21_PI_2;
  else {
    int direct = (s21_fabs(x) < 1);
    x = direct ? x : 1 / x;
    long double term = direct ? x : -x;
    result = term + (direct ? 0 : (x > 0 ? S21_PI_2 : -S21_PI_2));
    long double a_n = 1L;
    long double n = 1L;
    while (s21_fabs(a_n * term) > S21_DBL_MIN) {
      a_n = 1.0L / (2 * n++ + 1);
      term *= -x * x;
      result += a_n * term;
    }
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result = 0;
  if (x < 0 || s21_isnan(x))
    result = S21_NAN;
  else if (x > 0)
    result = s21_pow(x, 0.5);
  return result;
}