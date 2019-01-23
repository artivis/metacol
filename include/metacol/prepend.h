#ifndef _METACOL_TS_PREPEND_H_
#define _METACOL_TS_PREPEND_H_

namespace mco {

template<typename C, typename... T>
struct prepend;

template<typename... T, template <class...> class C, typename... Args>
struct prepend <C<Args...>, T...> {
    using type = C<T..., Args...>;
};

template<typename C, typename... T>
using prepend_t = typename prepend<C,T...>::type;

} /* namespace mco */

/*
Usage :
#include <tuple>
int main()
{
  using t_t = std::tuple<int>;
  static_assert(std::is_same<std::tuple<float, int>, mco::prepend_t<t_t, float>>::value, "");
  static_assert(std::is_same<std::tuple<float,double,int>, mco::prepend_t<t_t, float, double>>::value, "");
  return 0;
}
*/

#endif /* _METACOL_TS_PREPEND_H_ */
