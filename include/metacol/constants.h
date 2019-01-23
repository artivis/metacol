#ifndef _METACOL_VS_CONSTANTS_H_
#define _METACOL_VS_CONSTANTS_H_

#include "metacol/csqrt.h"

namespace mco {

template <typename Scalar>
struct Constants
{
  static constexpr Scalar pi     = Scalar(M_PI);
  static constexpr Scalar to_rad = Scalar(pi / 180.0);
  static constexpr Scalar to_deg = Scalar(180.0 / pi);
};

} /* namespace mco */

#endif /* _METACOL_VS_CONSTANTS_H_ */
