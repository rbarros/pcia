#ifndef CORE_MENU_INCLUDED
#define CORE_MENU_INCLUDED

typedef struct {
       char *texto;
} ListaMenu;

namespace Core {
    class Menu {
          ListaMenu *menu;
          public:
                 Menu();
                 virtual ~Menu();
                 
                 virtual Menu* setMenu(char* texto);
                 void getMenu();
    };
};

#endif
