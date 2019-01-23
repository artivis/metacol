#ifndef _METACOL_TS_BOOL_CONSTANT_H_
#define _METACOL_TS_BOOL_CONSTANT_H_

#include <type_traits>

namespace mco {

// available in cpp17
template <bool B>
using bool_constant = std::integral_constant<bool, B>;

} /* namespace mco */

#endif /* _METACOL_TS_BOOL_CONSTANT_H_ */
