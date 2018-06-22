#ifndef _METACOL_VS_BINOMIAL_COEFFICIENT_H_
#define _METACOL_VS_BINOMIAL_COEFFICIENT_H_

namespace mco {

template <typename T>
constexpr T binomial_coefficient(const T n, const T k)
{
  return (n >= k) ? (k >= 0) ?
  (k*2 > n) ? binomial_coefficient(n, n-k) :
                     k ? binomial_coefficient(n, k - 1) * (n - k + 1) / k : 1
  // assert n ≥ k ≥ 0
  : (throw std::logic_error("k >= 0 !")) : (throw std::logic_error("n >= k !"));
}

} /* namespace mco */

#endif /* _METACOL_VS_BINOMIAL_COEFFICIENT_H_ */

/*
Usage:

constexpr int value = binomial_coefficient(49, 43); //mov DWORD PTR [rbp-4], 13983816
constexpr int value2 = binomial_coefficient(8, 2);  //mov DWORD PTR [rbp-8], 28 
constexpr int value3 = binomial_coefficient(2, 8);  // error: expression '<throw-expression>' is not a constant-expression
                                                    // : (throw std::logic_error("k >= 0 !")) : (throw std::logic_error("n >= k !"));
*/
