#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res;
  if (y == 0 || S21_IS_INF(x)) {
    res = S21_NAN;
  } else if (S21_IS_INF(y)) {
    res = x;
  } else {
    res = x - (int)(x / y) * y;
  }
  return res;
}
