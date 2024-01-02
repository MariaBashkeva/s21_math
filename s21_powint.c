#include "s21_math.h"

long double s21_powint(double base, int exp) {
  long double ans = 1.0;
  short int znak = 0;
  if (exp > 0) {
    znak = 1;
    exp *= 1;
  } else {
    exp *= -1;
  }
  for (int i = 0; i < exp; ++i) {
    if (znak) {
      ans *= base;
    } else {
      ans /= base;
    }
  }
  return ans;
}
