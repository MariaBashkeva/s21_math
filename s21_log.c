#include "s21_math.h"

long double s21_log(double x) {
  int exp = 0;
  double long ans = 0;
  double long cmp = 0;
  if (x == S21_INF_POS)
    ans = x;
  else if (x == 0)
    ans = S21_INF_NEG;
  else if (x < 0)
    ans = S21_NAN;
  else {
    for (; x >= S21_E; x /= S21_E, ++exp) continue;
    for (int i = 0; i < 100; ++i) {
      cmp = ans;
      ans = cmp + 2 * (x - s21_exp(cmp)) / (x + s21_exp(cmp));
    }
  }
  return (ans + exp);
}
