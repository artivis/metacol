Easiest way to create a tester for sfinae :

```cpp
template<class, typename T> struct impl : std::false_type {};
template<typename T> struct impl<decltype( void(expr) ), T> : std::true_type {};
template<typename T> struct expr_is_well_formed : impl<void, T> {};
```

Where `expr` is the expression to be tested. E.g. 

```cpp
#include <type_traits>

struct A { int header; };

struct B { void header(); };

struct C { using header = int; };

struct D : A { };

template<class, typename T> struct has_header_impl : std::false_type {};

template<typename T> struct 
has_header_impl<decltype( void(Args::header) ), T> : std::true_type {};

template<typename T> struct has_header : has_header_impl<void, T> {};

static_assert(  has_header<A>::value, "yes has header");
static_assert(! has_header<B>::value, "yes does not have header");
static_assert(! has_header<C>::value, "yes does not have header");
static_assert(  has_header<D>::value, "yes has header");
```
