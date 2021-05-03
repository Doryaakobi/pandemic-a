#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class FieldDoctor: public Player {
        
        std::string expertise;

        public:
            FieldDoctor(pandemic::Board& board, City city): Player(board, city), expertise("FieldDoctor") {}
            Player& treat(City c) override {std::cout << "temp"; return *this;}
            ~FieldDoctor(){}
    };

}