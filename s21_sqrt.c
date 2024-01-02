#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res;
  if (x == 0) {
    res = x;
  } else if (S21_IS_NAN(x) || x < 0) {
    res = S21_NAN;
  } else if (S21_IS_INF(x)) {
    res = S21_INF_POS;
  } else {
    res = 1;
    for (;;) {
      long double tmp = (res + x / res) / 2;
      if (s21_fabs(res - tmp) < S21_EPSILON) break;
      res = tmp;
    }
  }
  return res;
}
