// See https://stackoverflow.com/q/14637356

#ifndef _METACOL_TS_CONSTEXPR_FALSE_H_
#define _METACOL_TS_CONSTEXPR_FALSE_H_

namespace mco {

template <typename T>
inline constexpr bool constexpr_false() {
    return false;
}

} /* namespace mco */

/*
Usage :

template <typename T>
inline T doMath(T&)
{
  static_assert(constexpr_false() , "This function has to be specialized for each desired type !");
}
*/

#endif /* _METACOL_TS_CONSTEXPR_FALSE_H_ */
