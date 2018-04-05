#ifndef _METACOL_VS_CALL_FOR_EACH_IN_H_
#define _METACOL_VS_CALL_FOR_EACH_IN_H_

#include <metacol/ts/range.h>

namespace mco {

template<typename T, typename F, template <int... I> class S, int... I>
void call_for_each(F f, T&& t, S<I...>)
{
  auto l = { (f(std::get<I>(std::forward<T>(t))), 0)... };
}

template<typename F, template <class...Ts> class C, typename... Ts>
void call_for_each(F f, C<Ts...>&& t)
{
  call_for_each(std::forward<F>(f), std::forward<C<Ts...>>(t), make_int_sequence<sizeof...(Ts)>());
}

} /* namespace mco */ 

#endif /* _METACOL_VS_CALL_FOR_EACH_IN_H_ */

/*
// Usage :
#include <iostream> 
int main()
{
  auto f = [](const int& i){ std::cout << i << " "; };
  std::tuple<int, int, int> t{4, 5, 6};
  call_for_each(f, std::tuple<int, int, int>{4, 5, 6});
  return 0;
}
*/
