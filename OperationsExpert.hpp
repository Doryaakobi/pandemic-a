#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>

namespace pandemic{

    class OperationsExpert: public Player {

        std::string expertise;

        public:
            OperationsExpert(Board& board, City city): Player(board, city), expertise("OperationsExpert") {}
            Player& build() {std::cout << "build() override"; return *this;}
            ~OperationsExpert(){}
    };

}