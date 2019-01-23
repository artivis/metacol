#ifndef _METACOL_TS_ZIP_H_
#define _METACOL_TS_ZIP_H_

namespace mco {

template <typename A, typename B>
struct zip;

template <template <class...T0s> class C0, template <class...T1s> class C1,
          typename... T0s, typename... T1s>
struct zip<C0<T0s...>, C1<T1s...>>
{
  using type = C0< C0<T0s,T1s>... >;
};

template <typename T0, typename T1>
using zip_t = typename zip<T0, T1>::type;

} /* namespace mco */

/* Usage :

#include "mco/zip.h"
#include <tuple>

int main() {

	using T0 = std::tuple <int, int, int>;
	using T1 = std::tuple <float, float, float>;
	using T2 = std::tuple <std::tuple<int, float>, std::tuple<int, float>, std::tuple<int, float>>;

	static_assert( std::is_same<zip_t<T0,T1>, T2>::value , "nop");

	return 0;
}

*/

#endif /* _METACOL_TS_ZIP_H_ */
