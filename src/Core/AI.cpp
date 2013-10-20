#include "Core.h"
#include "AI.h"

namespace Core {
    AI::AI(): status(true) {};
    AI::~AI(){};
    void AI::start() {
         this->menu = new Menu();
         cout << status << endl;
         this->menu->setMenu("Menu principal")->getMenu();
         this->menu->setMenu("(1) - Ajuda")->getMenu();
    };
};
