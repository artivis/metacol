#ifndef _METACOL_VS_POLY_LAMBDA_H_
#define _METACOL_VS_POLY_LAMBDA_H_

// From Joel Falcou CppCon 2017 talk
// "I wish I could use c++ 1x/y/z"
// https://www.youtube.com/watch?v=gPj90zwLphw

#include <utility>

template <typename T1, typename T2>
struct poly_lambda_ : T1, T2 {
  poly_lambda_(T1&& t1, T2&& t2) :
  T1(std::forward<T1>(t1)),
  T2(std::forward<T2>(t2)) { }

  using T1::operator();
  using T2::operator();
};

template <typename T1, typename T2>
poly_lambda_<T1, T2> poly_lambda(T1&& t1, T2&& t2) {
  return { std::forward<T1>(t1), std::forward<T2>(t2) };
}

template <typename T, typename... Args>
auto
poly_lambda(T&& t, Args&&... args)
-> poly_lambda_<T, decltype(poly_lambda(std::declval<Args>()...))> {
  return { std::forward<T>(t), poly(std::forward<Args>(args)...) };
}

// C++17
// Reference: https://www.fluentcpp.com/2021/03/19/what-c-fold-expressions-can-bring-to-your-code/

template<typename... Lambdas>
struct overloaded_lambda : public Lambdas... {
  using Lambdas::operator()...;
};

template<typename... Lambdas> overloaded_lambda(Lambdas...) -> overloaded_lambda<Lambdas...>;

#endif /* _METACOL_VS_POLY_LAMBDA_H_ */

/*

// Usage :

#include <iostream>

int main()
{
    auto f = poly_lambda(
      [](int i) { std::cout << "int : " << i << "\n"; },
      [](float f) { std::cout << "float : " << f << "\n"; }
    );

    f(42);
    f(3.33f);
    
    auto f2 = overloaded_lambda{
      [](int i) { std::cout << "int : " << i << "\n"; },
      [](float f) { std::cout << "float : " << f << "\n"; }
    };

    f2(42);
    f2(3.33f);

    return 0;
}

*/
