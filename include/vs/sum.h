#ifndef _METACOL_VS_SUM_H_
#define _METACOL_VS_SUM_H_

namespace mco {

template <int... Args> struct sum;

template <int V, int... Args>
struct sum<V, Args...>
{
  static constexpr int value = V + sum<Args...>::value;
};

template <>
struct sum<>
{
  static constexpr int value = 0;
};

template <int... Args>
constexpr int sum_v = sum<Args...>::value;

} /* namespace mco */

#endif /* _METACOL_VS_SUM_H_ */

/*
Usage:

static_assert(sum<1,2,3>::value    == 6,  "nop");
static_assert(sum<-1,1,2,8>::value == 10, "nop");
static_assert(sum_v<>              == 0,  "nop");

*/
