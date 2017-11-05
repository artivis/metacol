#ifndef _METACOL_TS_FIRST_OF_H_
#define _METACOL_TS_FIRST_OF_H_

template <class T, class Tuple>
struct FirstOf { static constexpr int value = -1; };

template <class T, template <class...> class C, class... Types>
struct FirstOf<T, C<T, Types...>> {
    static constexpr int value = 0;
};

template <class T, class U, template <class...> class C, class... Types>
struct FirstOf<T, C<U, Types...>> {
    static_assert(FirstOf<T, C<Types...>>::value < sizeof...(Types)+1, "Type T not present in container");
    static constexpr int value = 1 + FirstOf<T, C<Types...>>::value;
};

#endif /* _METACOL_TS_FIRST_OF_H_ */

/*

// Usage :

#include <iostream>
#include <tuple>

using foo_t = std::tuple<int, char*, int, long>;

int main() {
    std::cout << "FirstOf<char, foo_t> = " << FirstOf<long, foo_t>::value << std::endl;
    
    // 'error: static assertion failed: Type T not present in tuple'
    // std::cout << "FirstOf<char, foo_t> = " << FirstOf<float, foo_t>::value << std::endl;
}

*/
