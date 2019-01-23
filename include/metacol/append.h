#ifndef _METACOL_TS_APPEND_H_
#define _METACOL_TS_APPEND_H_

namespace mco {

template<typename C, typename... T>
struct append;

template<typename... T, template <class...> class C, typename... Args>
struct append <C<Args...>, T...> {
    using type = C<Args..., T...>;
};

template<typename C, typename... T>
using append_t = typename append<C,T...>::type;

} /* namespace mco */

/*

Usage :

#include <tuple>

int main()
{
  using t_t = std::tuple<int>;

  static_assert(std::is_same<std::tuple<int,float>, mco::append_t<t_t, float>>::value, "");
  static_assert(std::is_same<std::tuple<int,float,double>, mco::append_t<t_t, float, double>>::value, "");

  return 0;
}

*/

#endif /* _METACOL_TS_APPEND_H_ */
