#include "s21_math.h"

long double factorial(int x) {
  return (x < 0) ? S21_INF_NEG : (x < 2) ? 1 : x * factorial(x - 1);
}
