#include "s21_math.h"

long double s21_fabs(double x) {
  long double res = x;
  if (res == res) {
    if (x > S21_MAX_DOUBLE || s21_abs(x) > S21_MAX_DOUBLE || S21_IS_INF(x)) {
      res = S21_INF_POS;
    } else if (res < 0)
      res = -x;
  }
  return res;
}
