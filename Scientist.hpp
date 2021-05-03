#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Scientist: public Player {
        int num;
        std::string expertise;


        public:
            Scientist(Board& board, City city): Player(board, city), expertise("Scientist") {}
            Scientist(Board& board, City city, int num): Player(board, city), num(num), expertise("Scientist"){}
            Player& discover_cure(Color color) override{std::cout << "temp"; return *this;}
            ~Scientist(){}
    };

}