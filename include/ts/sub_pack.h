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

template <typename T, int I>
using make_sub_pack = typename sub_pack<T, make_int_sequence<I-1>>::type;

} /* namespace mco */

/*

Usage :

#include <tuple>

int main()
{
  using t_t = std::tuple<int,float,double>;

  static_assert(std::is_same<std::tuple<int,float>, make_sub_pack<t_t, 2>>::value, "");

  return 0;
}

*/

#endif /* _METACOL_TS_SUB_PACK_H_ */
