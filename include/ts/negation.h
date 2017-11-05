#ifndef _METACOL_TS_NEGATION_H_
#define _METACOL_TS_NEGATION_H_

#include "bool_constant.h"

namespace mco {

// NOT - available in cpp17
template<class B>
struct negation : bool_constant<!B::value> { };

} /* namespace mco */

#endif /* _METACOL_TS_NEGATION_H_ */
