#include "s21_math.h"

long double s21_acos(double x) {
  long double ans = S21_NAN;
  if (x == -1) {
    ans = S21_PI;
  } else if (x == 0) {
    ans = S21_PI / 2;
  } else if (x == 1) {
    ans = 0;
  } else if (x > 0 && x < 1) {
    ans = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x > -1 && x < 0) {
    ans = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  }
  return ans;
}
