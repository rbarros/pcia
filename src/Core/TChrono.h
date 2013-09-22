#ifndef CORE_TCHRONO_INCLUDED
#define CORE_TCHRONO_INCLUDED

#include "Core.h"

namespace Core {
    class TChrono {
          int res;
          public:
                 TChrono();
                 virtual ~TChrono();
                 
                 void Start();
    };
};

#endif
