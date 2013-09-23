#include "Core.h"
#include "Menu.h"

namespace Core {
    Menu::Menu(){};
    Menu::~Menu(){
          delete this->menu;
    };
    Menu* Menu::setMenu(char texto) {
          Core::Exception exception;
          if(this->menu->texto == NULL) {
             //exception("Informe o texto do menu");
          }
          this->menu->texto = texto;
          return this;
    };
    void Menu::getMenu() {
         //cout << "\nmenu is: " << typeid(this->menu).name();
         cout << "\n====================";
         cout << "\n|  " << this->menu->texto << " |";
         cout << "\n====================";
    };
};
