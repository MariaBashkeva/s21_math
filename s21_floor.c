#include "s21_math.h"

long double s21_floor(double x) {
  long double ans = x;
  if (S21_IS_NAN(x))
    ans = S21_NAN;
  else if (S21_IS_INF(x))
    ans = (long double)ans;
  else if (x < 0 && (x != (long int)x)) {
    ans = (long int)x - 1;
  } else {
    ans = (long int)x;
  }
  return (long double)ans;
}