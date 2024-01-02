#include "s21_math.h"

long double s21_ceil(double x) {
  long double res;
  if (x == S21_INF_POS)
    res = S21_INF_POS;
  else if (x == S21_INF_NEG)
    res = S21_INF_NEG;
  else if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (!S21_IS_NAN(x) || !-S21_IS_INF(x) || x != 0) {
    if (x <= 0 || x == (int)x) {
      res = (long double)((long long)x);
    } else {
      res = 1 + (long double)((long long)x);
    }
  }
  return res;
}