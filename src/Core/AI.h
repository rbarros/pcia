#ifndef CORE_AI_INCLUDED
#define CORE_AI_INCLUDED

#include <iostream>
#include <locale>
#include <exception>
using namespace std;

namespace AI {
    class Expection : public std::exception {};
    class Test {
        public:
        Test() {
            cout << "AI Test" << endl;
        };
        //~Test();
    };
    void Parse(int x){
        cout << x << endl;
    };
};

#endif
