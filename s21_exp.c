#include "s21_math.h"

long double s21_exp(double x) {
  long double ans = 0;
  long double k = (long long int)(x / S21_LN2);
  long double r = x - k * S21_LN2;
  if (x == S21_INF_NEG) {
    ans = 0;
  } else {
    for (int i = 0; i < 200; i++) {
      ans += s21_powint(r, i) / factorial(i);
    }
    ans *= s21_powint(2, k);
  }
  return ans;
}
