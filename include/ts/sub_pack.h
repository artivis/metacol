#ifndef _METACOL_TS_SUB_PACK_H_
#define _METACOL_TS_SUB_PACK_H_

#include "range.h"
#include <type_traits>

namespace mco {

#include <functional>

namespace detail {

template <template <class...> class P, typename... Args, typename... PArgs>
auto make_pack_helper(P<PArgs...>, Args...) -> P<Args...>
{
  return P<Args...>{};
}

} /* namespace detail */

template <typename T, typename S>
struct sub_pack;

template <template <class...> class C, template <int...> class S, 
          typename... Args, int... Indices>
struct sub_pack < C<Args...>, S<Indices...> >
{
  /// @todo what are the req for std::get ?? 
  using type = decltype( detail::make_pack_helper(std::declval<C<Args...>>(), 
                         std::get<Indices>( std::declval<C<Args...>>() )... ) );
};

template <typename... Ts>
using sub_pack_t = typename sub_pack<Ts...>::type;

} /* namespace mco */

/*

Usage :

#include <tuple>

int main()
{
  using Tuple = std::tuple<int,float,double>;
  
  // First 2 types
  using SubTuple0 = sub_pack_t<Tuple, make_int_sequence<1>>;
  
  static_assert(std::is_same<std::tuple<int,float>, SubTuple0>::value, "");
  
  // Types 1-2
  using SubTuple1 = sub_pack_t<Tuple, range<1,2> >;
  
  static_assert(std::is_same<std::tuple<float,double>, SubTuple1>::value, "");

  return 0;
}

*/

#endif /* _METACOL_TS_SUB_PACK_H_ */
