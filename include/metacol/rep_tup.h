#ifndef _METACOL_TS_REP_TUP_H_
#define _METACOL_TS_REP_TUP_H_

#include "metacol/container_cat.h"

namespace mco {
namespace detail {
template <std::size_t I, typename... Args>
struct RepTup_
{
  using type = container_cat_t<std::tuple<Args...>,typename RepTup_<I-1, Args...>::type>;
};

template <typename... Args> struct RepTup_<2,Args...> { using type = std::tuple<Args...,Args...>;};
template <typename... Args> struct RepTup_<1,Args...> { using type = std::tuple<Args...>;};
template <typename... Args> struct RepTup_<0,Args...> { using type = std::tuple<>;};

} /* namespace detail */

template <std::size_t I, typename ... Args>
using rep_tup = typename detail::RepTup_<I, Args...>::type;

} /* namespace mco */

/*

Usage :

#include <tuple>

int main()
{
  using Foo = std::tuple<int, int, int, int>;
  using Bar = rep_tup<4, int>;
  using Far = rep_tup<2, int, int>;

  static_assert(std::is_same<Foo, Bar>::value, "");
  static_assert(std::is_same<Foo, Far>::value, "");

  return 0;
}

*/

#endif /* _METACOL_TS_REP_TUP_H_ */
