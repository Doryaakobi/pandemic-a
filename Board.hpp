#pragma once
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
#include <iostream>


namespace pandemic{

    class Board{

        static std::map<City,std::set<City>> board_graph;
        std::map<City,int> disease_level;
        std::set<City> cured;
        std::set<City> research_stations;

        public:
        
        Board(){}
        bool is_clean();
        void remove_cures();
        int& operator[](City);


        friend std::ostream& operator<<(std::ostream& os, const Board& b){std::cout << "oper << board"; return os;}

        ~Board(){}

    };
}