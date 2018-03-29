#ifndef _METACOL_TS_APPEND_H_
#define _METACOL_TS_APPEND_H_

namespace mco {

template<typename L, typename R>
struct container_cat;

template<typename... TL, typename... TR>
struct container_cat<std::tuple<TL...>, std::tuple<TR...>> {
    using type = std::tuple<TL..., TR...>;
};

template<typename L, typename R>
using container_cat_t = typename container_cat<L,R>::type;

} /* namespace mco */

/*

Usage :

#include <tuple>

int main()
{
  using Foo = std::tuple<int>;
  using Bar = std::tuple<float, double>;

  static_assert(std::is_same<container_cat_t<Foo,Bar>, std::tuple<int, float, double> >::value, "");

  return 0;
}

*/

#endif /* _METACOL_TS_APPEND_H_ */
