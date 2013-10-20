#ifndef CORE_INCLUDED
#define CORE_INCLUDED

#include <iostream>
#include <locale>
#include <exception>
#include <string>
#include <typeinfo>

using namespace std;

namespace Core {
    class Exception : public std::exception { };
}

#endif
