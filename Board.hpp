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
        std::set<Color> cured;
        // std::map<Color , bool> cured;
        std::set<City> research_stations;

        public:
        
        Board(){}
        ~Board(){}
        

        bool is_clean();
        void remove_cures();
        int& operator[](City city);
        bool isConnected(City&,City&);
        void markCure(Color);
        bool isCured(Color);
        bool hasResearch(City&);
        void buildResearch(City&);
        friend std::ostream& operator<<(std::ostream& out, const Board& b);


    };
}