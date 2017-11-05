// From Joel Falcou CppCon 2017 talk
// "I wish I could use c++ 1x/y/z"
// https://www.youtube.com/watch?v=gPj90zwLphw

#ifndef _METACOL_VS_CALL_FOR_EACH_H_
#define _METACOL_VS_CALL_FOR_EACH_H_

namespace mco {

#include <functional>

template <typename F, typename... Args>
F call_for_each(F f, Args&&... args)
{
  return (void)std::initializer_list<int>{((void)std::ref(f)(std::forward<Args>(args)), 0)...}, f;
}

} /* namespace mco */

/*

Usage :

#include "metacol/vs/call_for_each.h"
#include <iostream> 

int main()
{
  auto f = [](int i){ std::cout << ++i << " "; };
  
  mco::call_for_each(f, 1, 2, 3);

  return 0;
}

*/

#endif /* _METACOL_VS_CALL_FOR_EACH_H_ */
