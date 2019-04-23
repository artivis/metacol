#ifndef _METACOL_TS_IS_ITERATOR_H_
#define _METACOL_TS_IS_ITERATOR_H_

#include <iterator>

namespace mco {

template<typename T, typename = void>
struct is_iterator : std::false_type {};

template<typename T>
struct is_iterator<T, typename std::enable_if<!std::is_same<typename std::iterator_traits<T>::value_type, void>::value>::type>
    : std::true_type {};

} /* namespace mco */

/*

Usage:

#include <vector>

int main()
{
  static_assert(!is_iterator<int>(), "ok");

  static_assert( is_iterator<std::vector<int>::iterator>(), "ok");
  static_assert( is_iterator<std::vector<int>::const_iterator>(), "ok");

  return 0;
}

*/

#endif /* _METACOL_TS_IS_ITERATOR_H_ */
