#ifndef _METACOL_MS_ENABLE_IF_H_
#define _METACOL_MS_ENABLE_IF_H_

#include "metacol/disjunction.h"

namespace mco {

template< class R, typename... Bs >
using enable_if_any = std::enable_if< disjunction< Bs... >::value, R >;

template< class R, typename... Bs >
using enable_if_all = std::enable_if< disjunction< Bs... >::value, R >;

template< typename T, typename... Ts >
using are_same = disjunction< std::is_same< T, Ts >... >;

template< typename T, typename... Ts >
using is_any_same_as = disjunction< std::is_same< T, typename std::decay<Ts>::type >... >;

template< typename T, typename... Ts >
using none_is_same_as = disjunction< negation<std::is_same< T, typename std::decay<Ts>::type >>... >;

template< class R, typename... Ts>
using enable_if_none_is_same_as = std::enable_if< none_is_same_as< R, Ts... >::value >;

} /* namespace mco */

#endif /* _METACOL_MS_ENABLE_IF_H_ */
