#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include "Board.hpp"

using namespace pandemic;
using namespace std;

#include <vector>
#include <iostream>
#include <stdexcept>



int main(){

    Board b;

    Player p{b,City::Atlanta};

    cout << p.role();













    return 0;
}



// clear && clang-9 -o run main.cpp -lstdc++ && ./run