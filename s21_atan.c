#include "s21_math.h"

long double s21_atan(double x) {
  long double ans = 0;
  if (x == S21_INF_NEG) {
    ans = -S21_PI / 2;
  } else if (x == 1) {
    ans = 0.785398163;
  } else if (x == -1) {
    ans = -0.785398163;
  } else if (x == S21_INF_POS) {
    ans = S21_PI / 2;
  } else if (S21_IS_NAN(x)) {
    ans = S21_NAN;
  } else if (x > -1 && x < 1) {
    for (int i = 0; i < 5000; ++i) {
      ans += s21_powint(-1, i) * s21_powint(x, 1 + 2 * i) / (1 + 2 * i);
    }
  } else if (x < -1 || x > 1) {
    for (int i = 0; i < 5000; ++i) {
      ans += s21_powint(-1, i) * s21_powint(x, -1 - 2 * i) / (1 + 2 * i);
    }
    ans = (S21_PI * s21_sqrt(x * x)) / (2 * x) - ans;
  }
  return ans;
}
