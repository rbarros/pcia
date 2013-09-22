#ifndef CORE_AI_INCLUDED
#define CORE_AI_INCLUDED

#include "Menu.h"

namespace Core {
    class AI {
          bool status;
          public:
                 Menu *menu;
                 AI();
                 virtual ~AI();
                 
                 void start();
    };
};

#endif
