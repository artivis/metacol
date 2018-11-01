#ifndef _METACOL_VS_CSQRT_H_
#define _METACOL_VS_CSQRT_H_

// credits : https://stackoverflow.com/a/34134071/9709397

namespace mco {

template <typename T>
double constexpr sqrtNewtonRaphson(T x, T curr, T prev)
{
  return curr == prev
          ? curr
          : sqrtNewtonRaphson(x, T(0.5) * (curr + x / curr), curr);
}

/*
* Constexpr version of the square root
* Return value:
*   - For a finite and non-negative value of "x", returns an approximation for the square root of "x"
*   - Otherwise, returns NaN
*/
template <typename T>
double constexpr csqrt(T x)
{
  return x >= T(0) && x < std::numeric_limits<T>::infinity()
        ? sqrtNewtonRaphson(x, x, T(0))
        : std::numeric_limits<T>::quiet_NaN();
}

} /* namespace mco */

#endif /* _METACOL_VS_CSQRT_H_ */
