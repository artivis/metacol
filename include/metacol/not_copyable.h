#ifndef _METACOL_NOT_COPYABLE_H_
#define _METACOL_NOT_COPYABLE_H_

namespace mco {

struct NotCopyable
{
  NotCopyable()          = default;

  // Inheritable
  virtual ~NotCopyable() = default;

  // Not copy constructible
  NotCopyable(NotCopyable&)                  = delete;
  NotCopyable(const NotCopyable&)            = delete;

  // Not copy assignable
  NotCopyable& operator=(NotCopyable&)       = delete;
  NotCopyable& operator=(const NotCopyable&) = delete;
};

} /* namespace mco */

#endif /* _METACOL_NOT_COPYABLE_H_ */

/*

Usage :

struct MyNotCopyableStruct : NotCopyable { }

*/
