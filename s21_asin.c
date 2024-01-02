#include "s21_math.h"

long double s21_asin(double x) {
  long double ans = S21_NAN;
  if (x == -1) {
    ans = -S21_PI / 2;
  } else if (x == 0) {
    ans = 0;
  } else if (x == 1) {
    ans = S21_PI / 2;
  } else if (x > -1 && x < 1) {
    ans = s21_atan(x / s21_sqrt(1 - x * x));
  }

  return ans;
}
