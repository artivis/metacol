#ifndef _METACOL_STATIC_ASSERTS_H_
#define _METACOL_STATIC_ASSERTS_H_

#define XSTRINGIFY(a) STRINGIFY(a)
#define STRINGIFY(a) #a

#define static_assert_is_same(x,y) \
  static_assert(std::is_same<x,y>::value,\
  STRINGIFY(x) " not the same as " STRINGIFY(y));

#define static_assert_not_is_same(x,y) \
  static_assert(!std::is_same<x,y>::value,\
  STRINGIFY(x) " not the same as " STRINGIFY(y));

#define static_assert_is_base_of(x,y) \
  static_assert(std::is_base_of<x,y>::value, \
  STRINGIFY(x) " not the base of " STRINGIFY(y));
  
  #endif /* _METACOL_STATIC_ASSERTS_H_ */
