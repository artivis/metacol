#ifndef _METACOL_TS_DISJUNCTION_H_
#define _METACOL_TS_DISJUNCTION_H_

#include <type_traits>

namespace mco {

// OR - available in cpp17
template<class...> struct disjunction : std::false_type { };
template<class B1> struct disjunction<B1> : B1 { };
template<class B1, class... Bn>
struct disjunction<B1, Bn...>
    : std::conditional<bool(B1::value), B1, disjunction<Bn...>>::type  { };

} /* namespace mco */

#endif /* _METACOL_TS_DISJUNCTION_H_ */
