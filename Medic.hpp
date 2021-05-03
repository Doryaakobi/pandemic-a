#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Medic: public Player {

        std::string expertise;

        public:
            Medic(Board& board, City city): Player(board, city), expertise("Medic") {}
            Player& treat(City city){std::cout << "temp"; return *this;}
            ~Medic(){}
    };

}