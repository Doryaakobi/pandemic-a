#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class GeneSplicer: public Player {
        
        std::string expertise;

        public:
            GeneSplicer(Board& board, City city): Player(board, city), expertise("GeneSplicer") {}
            Player& discover_cure(Color color) override {std::cout << "temp"; return *this;}
            ~GeneSplicer(){}
    };

}