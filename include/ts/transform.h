#ifndef _METACOL_TS_TRANSFORM_H_
#define _METACOL_TS_TRANSFORM_H_

namespace mco {

template<typename C, template <typename> class F>
struct transform;

template<template <class... Ts> class C, template <typename> class F, typename... Ts>
struct transform <C<Ts...>, F> {
    using type = C<typename F<Ts>::type...>;
};

template<typename C, template <typename> class F>
using transform_t = typename transform<C,F>::type;

} /* namespace mco */

/*

Usage :

#include <tuple>

template <typename T>
struct add_const
{
	using type = const T;
};

template <typename T>
struct add_const<const T>
{
	using type = const T;
};

using Foo = std::tuple<int, float, double>;
using FooConst = std::tuple<const int, const float, const double>;

int main()
{
  static_assert(std::is_same<FooConst, transform<Foo, add_const>::type >::value, "ok");
  static_assert(std::is_same<FooConst, transform_t<Foo, add_const> >::value, "ok");

  return 0;
}

*/

#endif /* _METACOL_TS_TRANSFORM_H_ */
