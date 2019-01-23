#ifndef _METACOL_TS_FIRST_OF_H_
#define _METACOL_TS_FIRST_OF_H_

namespace mco {

template <class T, class Tuple>
struct first_of { static constexpr int value = -1; };

template <class T, template <class...> class C, class... Types>
struct first_of<T, C<T, Types...>> {
    static constexpr int value = 0;
};

template <class T, class U, template <class...> class C, class... Types>
struct first_of<T, C<U, Types...>> {
    static_assert(first_of<T, C<Types...>>::value < sizeof...(Types)+1, "Type T not present in container");
    static constexpr int value = 1 + FirstOf<T, C<Types...>>::value;
};

} /* namespace mco */

#endif /* _METACOL_TS_FIRST_OF_H_ */

/*

// Usage :

#include <iostream>
#include <tuple>

using foo_t = std::tuple<int, char, int, long>;

int main() {
    std::cout << "first_of<char, foo_t> = " << first_of<long, foo_t>::value << std::endl;
    
    // 'error: static assertion failed: Type T not present in tuple'
    // std::cout << "first_of<char, foo_t> = " << first_of<float, foo_t>::value << std::endl;
}

*/
