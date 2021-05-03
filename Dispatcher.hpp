#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Dispatcher: public Player {
       
        std::string expertise;

        public:
            Dispatcher(Board& board, City city): Player(board, city), expertise("Dispatcher") {}
            Player& fly_direct(City c) override {std::cout << "temp"; return *this;}
            ~Dispatcher(){}
    };

}