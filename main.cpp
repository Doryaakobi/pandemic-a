#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"


using namespace pandemic;
using namespace std;

#include <vector>
#include <iostream>
#include <stdexcept>



int main(){
    // Board board;  // Initialize an empty board (with 0 disease cubes in any city).
	// board[City::Kinshasa] = 3;      // put 3 yellow disease cubes in Kinshasa.
	// board[City::Kinshasa] = 2;      // change number of disease cubes in Kinshasa to 2.
	// board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity
	// board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
	// board[City::Chicago] = 1;       // put 1 blue disease cube in Chicago
    // cout << "board[City::Kinshasa] = "<< board[City::Kinshasa] << "\n";
	// OperationsExpert player {board, City::Atlanta};  
    // Board b;

    // Player p{b,City::Atlanta};

    // cout << player.role();
    Board b;
    std::cout << b.is_clean() << std::endl;













    return 0;
}



// clear && clang-9 -o run main.cpp -lstdc++ && ./run
// clang++-9 -o main main.cpp Board.o