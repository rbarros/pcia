#include "TChrono.h"

namespace Core {
    TChrono::TChrono(): res(100) {};
    TChrono::~TChrono(){};
    void TChrono::Start() {
         cout << res << endl;
    };
};
