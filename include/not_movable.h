#ifndef _METACOL_NOT_MOVABLE_H_
#define _METACOL_NOT_MOVABLE_H_

namespace mco {

struct NotMovable
{
  NotMovable()          = default;

  // Inheritable
  virtual ~NotMovable() = default;

  // Not move constructible
  NotMovable(NotMovable&&)            = delete;

  // Not move assignable
  NotMovable& operator=(NotMovable&&) = delete;
};

} /* namespace mco */

#endif /* _METACOL_NOT_MOVABLE_H_ */

/*

Usage :

struct MyNotMovableStruct : NotMovable { }

*/
