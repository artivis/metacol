#ifndef _METACOL_VS_CALL_FOR_EACH_IN_H_
#define _METACOL_VS_CALL_FOR_EACH_IN_H_

namespace mco {

#include <type_traits>
#include <functional>

template<typename F, template <class...Args> class C, typename... Args>
void call_for_each_in(F f, C<Args...>&& c, std::integral_constant<unsigned int, sizeof...(Args)>) { }

template<typename F, unsigned int I, template <class...> class C, typename... Args, typename = typename std::enable_if<I!=sizeof ...(Args)>::type >
void call_for_each_in(F f, C<Args...>&& c, std::integral_constant<unsigned int, I>)
{
  std::ref(f)(std::forward<decltype(std::get<I>(c))>(std::get<I>(c)));

	call_for_each_in(std::forward<F>(f), std::forward<C<Args...>>(c), std::integral_constant<unsigned int, I + 1>());
}

template<typename F, template <class...Args> class C, typename... Args>
void call_for_each_in(F&& f, C<Args...>&& c)
{
    call_for_each_in(std::forward<F>(f), std::forward<C<Args...>>(c), std::integral_constant<unsigned int, 0>());
}

} /* namespace mco */ 

#endif /* _METACOL_VS_CALL_FOR_EACH_IN_H_ */

/*

// Usage :

#include <iostream> 

int main()
{
  auto f = [](int i){ std::cout << ++i << " "; };

  std::tuple<int, int, int> t{4, 5, 6};

  call_for_each_in(f, std::tuple<int, int, int>{4, 5, 6});

  return 0;
}

*/
