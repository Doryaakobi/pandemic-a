#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
using namespace std;

constexpr int Tests =  10;

// const std::map<City, Color> Black_city {
//     { City::Algiers, Color::Black },
//     { City::Baghdad, Color::Black },
//     { City::Cairo, Color::Black },
//     { City::Chennai, Color::Black },
//     { City::Delhi, Color::Black },
//     { City::Istanbul, Color::Black },
//     { City::Karachi, Color::Black },
//     { City::Kolkata, Color::Black },
//     { City::Moscow, Color::Black },
//     { City::Mumbai, Color::Black },
//     { City::Riyadh, Color::Black },
//     { City::Tehran, Color::Black },
// };


// const std::map<City, Color> Blue_city {
//     { City::Atlanta, Color::Blue },
//     { City::Chicago, Color::Blue },
//     { City::Essen, Color::Blue },
//     { City::London, Color::Blue },
//     { City::Madrid, Color::Blue },
//     { City::Milan, Color::Blue },
//     { City::Montreal, Color::Blue },
//     { City::NewYork, Color::Blue },
//     { City::Paris, Color::Blue },
//     { City::SanFrancisco, Color::Blue },
//     { City::StPetersburg, Color::Blue },
//     { City::Washington, Color::Blue }
// };

// const std::map<City, Color> Red_city {
//     { City::Bangkok, Color::Red },
//     { City::Beijing, Color::Red },
//     { City::HoChiMinhCity, Color::Red },
//     { City::HongKong, Color::Red },
//     { City::Jakarta, Color::Red },
//     { City::Manila, Color::Red },
//     { City::Osaka, Color::Red },
//     { City::Seoul, Color::Red },
//     { City::Shanghai, Color::Red },
//     { City::Sydney, Color::Red },
//     { City::Taipei, Color::Red },
//     { City::Tokyo, Color::Red },
// };

// const std::map<City, Color> Yellow_city {
//     { City::Bogota, Color::Yellow },
//     { City::BuenosAires, Color::Yellow },
//     { City::Johannesburg, Color::Yellow },
//     { City::Khartoum, Color::Yellow },
//     { City::Kinshasa, Color::Yellow },
//     { City::Lagos, Color::Yellow },
//     { City::Lima, Color::Yellow },
//     { City::LosAngeles, Color::Yellow },
//     { City::MexicoCity, Color::Yellow },
//     { City::Miami, Color::Yellow },
//     { City::Santiago, Color::Yellow },
//     { City::SaoPaulo, Color::Yellow },
// };



void take_5Blue_cards(Player& p){
    
     p.take_card(City::Atlanta),
     p.take_card(City::Essen),
     p.take_card(City::Chicago),
     p.take_card(City::London),
     p.take_card(City::Madrid);
}

void take_5Red_cards(Player& p){
    
     p.take_card(City::Seoul),
     p.take_card(City::Bangkok),
     p.take_card(City::Beijing),
     p.take_card(City::Manila),
     p.take_card(City::Osaka);
}

void take_5Black_cards(Player& p){

     p.take_card(City::Delhi),
     p.take_card(City::Algiers),
     p.take_card(City::Baghdad),
     p.take_card(City::Cairo),
     p.take_card(City::Chennai);
}

void take_5Yellow_cards(Player& p){

     p.take_card(City::Bogota),
     p.take_card(City::BuenosAires),
     p.take_card(City::Johannesburg),
     p.take_card(City::Khartoum),
     p.take_card(City::Lagos);
}


void take_5Mix_cards(Player& p){

     p.take_card(City::Atlanta),
     p.take_card(City::Seoul),
     p.take_card(City::Madrid),
     p.take_card(City::Chennai),
     p.take_card(City::Johannesburg);

}

// City random_city() {
//     size_t rnd = (size_t)rand() % 48;
//     int i = 0;
//     for(const auto& city: City) {
//         if(i == t) {
//             return city.first;
//         }
//         i++;
//     }
//     return City::Algiers;
// }





TEST_CASE("Board Funtions Test:"){

Board board;
CHECK(board.is_clean());
board[Atlanta] = 1;
CHECK_EQ(board[Atlanta],1);
CHECK_FALSE(board.is_clean());

}

TEST_CASE("OperationsExpert Test:"){

Board board;

OperationsExpert op {board,City::Atlanta};

take_5Mix_cards(op);








}



// TEST_CASE("Testing Dispacher Actions:"){

// Board board;
// Dispatcher dis {board, City::Atlanta};

// CHECK_EQ(dis.role(),"Dispatcher");
// CHECK(board.is_clean());
// board[Atlanta] = 1;
// CHECK_FALSE(board.is_clean());

// take

// }

