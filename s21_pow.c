#include "s21_math.h"

long double check_base_0(double exp) {
  long double result = 1.0;
  if (S21_IS_NAN(exp))
    result = S21_NAN;
  else if (exp < 0)
    result = S21_INF_POS;
  else
    result = 0;
  return result;
}

long double check_base_inf_pos(double exp) {
  long double result = 1.0;
  if (S21_IS_NAN(exp))
    result = S21_NAN;
  else if (exp < 0)
    result = 0;
  else
    result = S21_INF_POS;
  return result;
}

long double check_exp_inf_pos(double base) {
  long double result = 1.0;
  if (s21_fabs(base) < 1)
    result = 0;
  else
    result = S21_INF_POS;
  return result;
}

long double check_base_inf_neg(double exp) {
  long double result = 1.0;
  if (S21_IS_NAN(exp))
    result = S21_NAN;
  else if (exp < 0)
    result = 0;
  else if (s21_fmod(exp, 2))
    result = S21_INF_NEG;
  else
    result = S21_INF_POS;
  return result;
}

long double check_exp_inf_neg(double base) {
  long double result = 1.0;
  if (s21_fabs(base) < 1)
    result = S21_INF_POS;
  else
    result = 0;
  return result;
}

long double s21_pow(double base, double exp) {
  long double result = 1.0;
  long double copy = base;
  long long int copy_exp_int = (long long int)exp;
  if (exp == 0 || base == 1)
    result = 1;
  else if (base == 0) {
    result = check_base_0(exp);
  } else if (S21_IS_NAN(base) && exp != 0)
    result = S21_NAN;
  else if ((base == -1 && S21_IS_INF(exp)) || base == 1) {
    result = 1;
  } else if (exp == S21_INF_POS) {
    result = check_exp_inf_pos(base);
  } else if (exp == S21_INF_NEG) {
    result = check_exp_inf_neg(base);
  } else if (base == S21_INF_NEG) {
    result = check_base_inf_neg(exp);
  } else if (base == S21_INF_POS) {
    result = check_base_inf_pos(exp);
  } else if (copy < 0 && exp != copy_exp_int)
    result = S21_NAN;
  else if (copy < 0) {
    copy = -copy;
    result = s21_exp(exp * s21_log(copy));
    if (s21_fmod(exp, 2) != 0) result = -result;
  } else
    result = s21_exp(exp * s21_log(base));
  return result;
}
