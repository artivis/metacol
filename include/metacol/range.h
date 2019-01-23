// From Joel Falcou CppCon 2017 talk
// "I wish I could use c++ 1x/y/z"
// https://www.youtube.com/watch?v=gPj90zwLphw

#ifndef _METACOL_TS_RANGE_H_
#define _METACOL_TS_RANGE_H_

namespace mco {

template <int... I> struct int_sequence 
{
  using type = int_sequence;
  using value_type = int;
  static constexpr unsigned int size() noexcept { return sizeof...(I); }
};

template <class, class, int> struct range_cat;

template <int... H, int... T, int Start>
struct range_cat<int_sequence<H...>, int_sequence<T...>, Start>
{
  using type = int_sequence<H..., Start+T...>;
};

template <int Start, unsigned int N>
struct range_ : range_cat< typename range_<Start, N / 2>::type,
                           typename range_<Start, N - N / 2>::type, 
                           N / 2 > { };

template <int Start> struct range_<Start, 1> { using type = int_sequence<Start>; };
template <int Start> struct range_<Start, 0> { using type = int_sequence<>; };

template <int Begin, int End>
using range = typename range_<Begin, End - Begin + 1>::type;

template <int End>
using make_int_sequence = typename range_<0, End + 1>::type;

} /* namespace mco */

#endif /* _METACOL_TS_RANGE_H_ */
