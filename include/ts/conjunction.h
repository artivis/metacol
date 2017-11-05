#ifndef _METACOL_TS_CONJUCTION_H_
#define _METACOL_TS_CONJUCTION_H_

#include <type_traits>

namespace mco {

// AND - available in cpp17
template<class...> struct conjunction : std::true_type { };
template<class B1> struct conjunction<B1> : B1 { };
template<class B1, class... Bn>
struct conjunction<B1, Bn...>
    : std::conditional<bool(B1::value), conjunction<Bn...>, B1>::type {};

} /* namespace mco */

#endif /* _METACOL_TS_CONJUCTION_H_ */
