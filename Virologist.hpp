#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
#include <ostream>

namespace pandemic{

    class Virologist: public Player {
        
        std::string expertise;

        public:
            Virologist(Board& board, City city): Player(board, city), expertise("Virologist"){}
            Player& treat(City city) override { std::cout << "temp"; return *this;};
            ~Virologist(){}
    };

}