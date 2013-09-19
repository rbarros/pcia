#include "Core/AI.h"

int main() {
    setlocale(LC_ALL, "C");
    
    cout << "AI initialized" << endl;
    
    AI::Test();
    AI::Parse(1);

    return 0;
}
