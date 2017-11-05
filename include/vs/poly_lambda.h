#ifndef _METACOL_VS_POLY_LAMBDA_H_
#define _METACOL_VS_POLY_LAMBDA_H_

// From Joel Falcou CppCon 2017 talk
// "I wish I could use c++ 1x/y/z"
// https://www.youtube.com/watch?v=gPj90zwLphw

#include <utility>

template <typename T1, typename T2>
struct poly_ : T1, T2
{
    poly_(T1&& t1, T2&& t2) :
    T1(std::forward<T1>(t1)),
    T2(std::forward<T2>(t2)) { }

    using T1::operator();
    using T2::operator();
};

template <typename T1, typename T2>
poly_<T1, T2> poly(T1&& t1, T2&& t2)
{
    return { std::forward<T1>(t1), std::forward<T2>(t2) };
}

template <typename T, typename... Args>
auto
poly(T&& t, Args&&... args) ->
poly_<T, decltype(poly(std::declval<Args>()...))>
{
    return { std::forward<T>(t), poly(std::forward<Args>(args)...) };
}

#endif /* _METACOL_VS_POLY_LAMBDA_H_ */

/*

// Usage :

#include <iostream>

int main()
{
    auto f = poly([](int i) { std::cout << "int : " << i << "\n"; },
                  [](float f) { std::cout << "float : " << f << "\n"; });

    f(42);
    f(3.33f);

    return 0;
}

*/
