#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
#include <ostream>

namespace pandemic{

    class Researcher: public Player {

        std::string expertise;


        public:
            Researcher(Board& board, City city): Player(board, city), expertise("Researcher") {}
            Player& discover_cure(Color color){ std::cout << "temp"; return *this;}
            ~Researcher(){}
    };

}