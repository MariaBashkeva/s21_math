#include "s21_math.h"

long double s21_cos(double x) {
  long double ans = 0;
  x = s21_fmod(x, 2 * S21_PI);
  if (x == 0) {
    ans = 1;
  } else {
    for (int i = 0; i < 500; ++i) {
      ans += s21_powint(-1, i) * s21_powint(x, 2 * i) / factorial(2 * i);
    }
  }
  return ans;
}
