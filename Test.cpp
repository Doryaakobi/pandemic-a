#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <stdlib.h>

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

const City starting_point = City::Atlanta;

//std::map<City, Color> Black_city {
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


// std::map<City, Color> Blue_city {
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

// std::map<City, Color> Red_city {
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

// std::map<City, Color> Yellow_city {
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



Player& take_5Blue_cards(Player& p){
    
     return p.take_card(City::Atlanta),
     p.take_card(City::Essen),
     p.take_card(City::Chicago),
     p.take_card(City::London),
     p.take_card(City::Madrid);
}

Player& take_5Red_cards(Player& p){
    
     return p.take_card(City::Seoul),
     p.take_card(City::Bangkok),
     p.take_card(City::Beijing),
     p.take_card(City::Manila),
     p.take_card(City::Osaka);
}

Player& take_5Black_cards(Player& p){

     return p.take_card(City::Delhi),
     p.take_card(City::Algiers),
     p.take_card(City::Baghdad),
     p.take_card(City::Cairo),
     p.take_card(City::Chennai);
}

Player& take_5Yellow_cards(Player& p){

     return p.take_card(City::Bogota),
     p.take_card(City::BuenosAires),
     p.take_card(City::Johannesburg),
     p.take_card(City::Khartoum),
     p.take_card(City::Lagos);
}


Player& take_5Mix_cards(Player& p){

     return p.take_card(City::Atlanta),
     p.take_card(City::Seoul),
     p.take_card(City::Madrid),
     p.take_card(City::Chennai),
     p.take_card(City::Johannesburg);

}


TEST_CASE("Game Initialization Using Base Player methods:"){

     Board board;
     Player player(board,starting_point); // Each palyer starts at Atalanta

     CHECK(board.is_clean());
     board[City::Atlanta] = 1;
     CHECK_FALSE(board.is_clean());

     player.treat(City::Atlanta); // Decreasses the disease level to 0


     CHECK_THROWS(player.treat(City::Atlanta));  // treat() should trow exception, on account of disease level is 0.

     board[City::Atlanta] = 1;
     CHECK_NOTHROW(player.take_card(City::Atlanta).treat(City::Atlanta));


     CHECK(board.is_clean());

     CHECK(board[City::Atlanta] == 0);

     // Check if the board is correctly connected.

     CHECK_NOTHROW(player.drive(City::Washington)); // Connected to ATL.
     CHECK_NOTHROW(player.drive(City::NewYork)); // Connected to Washington.

     CHECK_NOTHROW(player.drive(City::Montreal)); // Connected to NewYork.

     CHECK_THROWS(player.drive(City::Seoul)); // Not connected to Montreal.
     CHECK_NOTHROW(player.drive(City::Chicago)); // Connected to Montreal.
     CHECK_NOTHROW(player.drive(City::LosAngeles));  // Not connected to Chicago.
     CHECK_THROWS(player.drive(City::Cairo)); // Not connected to Chicago.


     // Route in which the player can drive throught according to the relevant neighbours.
     CHECK_NOTHROW(player.drive(City::SanFrancisco)
                         .drive(City::Tokyo)
                         .drive(City::Seoul)
                         .drive(City::Beijing)); 


     CHECK_THROWS(player.build()); // in order to build() player must hold first the city's card.
     CHECK_NOTHROW(player.take_card(City::Beijing).build());

     board[City::Beijing] = 2;
     CHECK_EQ(board[City::Beijing],2);

     

     CHECK_NOTHROW(player.treat(City::Beijing)); // Decrease disease level by 1.
     CHECK_EQ(board[City::Beijing],1);

     CHECK_NOTHROW(player.treat(City::Beijing)); // Decrease disease level by 1.
     CHECK_EQ(board[City::Beijing],0);

     CHECK_NOTHROW(player.drive(City::Seoul));
     take_5Red_cards(player); // draw Seoul Card

     CHECK_THROWS(player.discover_cure(Color::Red)); // No research station in Seoul

     CHECK_NOTHROW(player.build()); // discarding Seoul card

     CHECK_THROWS(player.discover_cure(Color::Red)); // Currently player should hold 4 red cards.

     CHECK_NOTHROW(player.take_card(City::Seoul).discover_cure(Color::Red)); 

     board[City::Seoul] = 5;
     CHECK_EQ(board[City::Seoul], 5);
     player.treat(City::Seoul); // At this point the cure for the disease was discovered, casuing the level to drop to 0.
     CHECK_EQ(board[City::Seoul], 0);

     CHECK_NOTHROW(player.drive(City::Shanghai).drive(City::HongKong)); // NewYork is Londons neighbour
     CHECK_NOTHROW(player.take_card(City::HongKong).build()); // build a research station

     CHECK_NOTHROW(player.fly_shuttle(City::Seoul)); // it's allowed to perform "fly shuttle" between two cities with research stations.

     CHECK_THROWS(player.fly_shuttle(City::Johannesburg)); // no research station in Johannesburg

     CHECK_NOTHROW(player.take_card(City::Lima).fly_direct(City::Lima));

     CHECK_NOTHROW(player.take_card(City::Mumbai).fly_direct(City::Mumbai));
     CHECK_THROWS(player.fly_charter(City::Sydney)); // should throw exeption because player doesn't hold Mumbai card.
}

TEST_CASE("Medic:") {
    
     /* Medic expertise:
          * If treat() is invoked, drops disease level to 0.
          * If a cure was already discovered for a city which the Medic goes to automatically the disease level drops to 0. 
      
     */

     Board board;
     Medic medic(board, starting_point);


     medic.take_card(City::MexicoCity).fly_direct(City::MexicoCity);   // Fly to MexicoCity
     board[City::MexicoCity] = 10;
     CHECK_NOTHROW(medic.treat(City::MexicoCity)); // drops disease level to 0
     CHECK_THROWS(medic.treat(City::MexicoCity)); // already cleared from disease 

     board[City::LosAngeles] = 100;
     CHECK_NOTHROW(medic.drive(City::LosAngeles).take_card(City::LosAngeles).fly_charter(City::Chicago));
     CHECK_THROWS(medic.treat(City::Chicago));    // disease level is 0
     CHECK_NOTHROW(medic.take_card(City::Chicago).build());
     take_5Yellow_cards(medic);
     CHECK_NOTHROW(medic.discover_cure(Color::Yellow)); //Because Chicago has a reseasrch station, it is legal to perform "discover_cure" 
     medic.drive(City::LosAngeles);
     CHECK(board.is_clean()); // when a cure is discovered to a certain color, wherever the medic goes the disease level drops to 0


}

TEST_CASE("FieldDoctor:") {

     /* FieldDoctor expertise:
          * Able to treat every neighbour city without discarding a card.
     */

    Board board;
    FieldDoctor field_Dr(board, starting_point);

    board[City::Atlanta] = 1;
    board[City::Chicago] = 1;
    board[City::Miami] = 1;
    board[City::Washington] = 1;

    CHECK_NOTHROW(field_Dr.treat(City::Atlanta));

    CHECK_NOTHROW(field_Dr.take_card(City::Miami)
                            .treat(City::Miami));     // Take a card and treat chicago - Card should not be used!

    CHECK_NOTHROW(field_Dr.drive(City::Chicago)
                            .fly_charter(City::Washington));   // Should have the card to use fly_charter

    CHECK_THROWS(field_Dr.treat(City::Chicago));         // Chicago isn't Washingtons neighbour.

    CHECK_NOTHROW(field_Dr.treat(City::Washington));     
    CHECK_NOTHROW(field_Dr.treat(City::Miami));

    CHECK_THROWS(field_Dr.treat(City::Atlanta));        // disease level is 0
    CHECK_THROWS(field_Dr.treat(City::Montreal));        // disease level is 0 and while is a neighbor city.
    CHECK_THROWS(field_Dr.drive(City::Montreal).treat(City::NewYork));      // disease level is 0 and while is a neighbor city.

}


TEST_CASE("GeneSplicer:") {


     /* GeneSplicer expertise:
          * Able to discover a cure without having all same color cards.
     */

    Board board;
    GeneSplicer g_splicer(board, City::Atlanta);

    CHECK_THROWS(g_splicer.discover_cure(Color::Blue));   // No research station and not enough cards
    g_splicer.take_card(City::Atlanta).build();

    CHECK_THROWS(g_splicer.discover_cure(Color::Blue));                            // not enough cards
    CHECK_THROWS(g_splicer.take_card(City::Chicago).discover_cure(Color::Blue));   // 1 cards
    CHECK_THROWS(g_splicer.take_card(City::SanFrancisco).discover_cure(Color::Blue));   // 2 cards
    CHECK_THROWS(g_splicer.take_card(City::Montreal).discover_cure(Color::Blue));   // 3 cards
    CHECK_THROWS(g_splicer.take_card(City::NewYork).discover_cure(Color::Blue));   // 4 cards
    CHECK_NOTHROW(g_splicer.take_card(City::Atlanta).discover_cure(Color::Yellow));   // 5 *blue* cards - should work

    CHECK_NOTHROW(take_5Mix_cards(g_splicer).discover_cure(Color::Black)); // cures Black Disease.

    // Black and Yellow diseases are cured.

    CHECK_NOTHROW(take_5Mix_cards(g_splicer).discover_cure(Color::Black)); // shouldn't make the player discard his cards as well. 

    board[City::Johannesburg] = 100;
    CHECK_NOTHROW(g_splicer.fly_charter(City::Johannesburg));
    g_splicer.treat(City::Johannesburg);
    CHECK_EQ(board[City::Johannesburg],0); // Yellow disease cure was found already therfore, disease level should drop to 0.

}

TEST_CASE("Researcher:") {

     /* Researcher expertise:
          * Able to discover a cure in a city without a research station.
     */

     Board board;
     Researcher researcher(board,starting_point);

     CHECK_NOTHROW(take_5Blue_cards(researcher).discover_cure(Color::Blue));    // 5 Blue cards, will discover Blue cure, even thought there's no research station.
     CHECK_THROWS(researcher.discover_cure(Color::Blue));  // doesn't hold any cards

     researcher.drive(City::Miami);

     CHECK_THROWS(take_5Mix_cards(researcher).discover_cure(Color::Blue)); // Some 5 cards - need 5 of same disease color

     CHECK_NOTHROW(take_5Blue_cards(researcher).discover_cure(Color::Blue));    // Cure already discovered.

     CHECK_NOTHROW(take_5Yellow_cards(researcher).discover_cure(Color::Yellow));  // Able to cure another disease 


     board[City::MexicoCity] = 10; // Cure for a Yellow city was discovered already
     researcher.drive(City::MexicoCity).take_card(City::MexicoCity);
     CHECK_NOTHROW(researcher.treat(City::MexicoCity));
     CHECK_EQ(board[City::MexicoCity], 0); // After treat action for a cured diseases drops to 0.

}

TEST_CASE("Scientist:") {

     /* Scientist expertise:
          * Able to discover a cure with 'n' cards instead of 5.
     */

     Board board;
     const int min_cards = 2;
     Scientist scientist(board,starting_point, min_cards);

     scientist.take_card(City::Atlanta)
          .take_card(City::NewYork)
          .take_card(City::SanFrancisco);

     board[City::Miami] = 10;

     CHECK_THROWS(scientist.drive(City::Miami).discover_cure(Color::Yellow)); // cards with different color and no research station
     CHECK_THROWS(scientist.discover_cure(Color::Blue)); // Should cure the disease but no research station built yet.

     scientist.take_card(City::Miami).build();    // can build only player is currently there.

     CHECK_NOTHROW(scientist.discover_cure(Color::Blue)); // 

     CHECK_NOTHROW(scientist.treat(City::Miami)); // can treat only player is currently there.

     CHECK_EQ(board[City::Miami],0);
     
}   

TEST_CASE("Virologist:") {

     /* Virologist expertise:
          * Able to treat any city on the board, if the player holds the city card.
     */
     
     
     Board board;
     Virologist virologist(board,starting_point);

     board[City::SanFrancisco] = 10;
     board[City::Miami] = 12;

     virologist.take_card(City::SanFrancisco);
     CHECK_NOTHROW(virologist.drive(City::Washington).treat(City::SanFrancisco)); // decreases disease level by 1
     CHECK(board[City::SanFrancisco] == 9); 

     CHECK_THROWS(virologist.fly_direct(City::Algiers));  // has no cards.
     virologist.take_card(City::Washington);
     CHECK_THROWS(virologist.fly_charter(City::Delhi));  // holds washington card
     CHECK_THROWS(virologist.fly_shuttle(City::Tokyo));  // no research stations.
     virologist.drive(City::Miami);
     CHECK_NOTHROW(virologist.take_card(City::SanFrancisco).treat(City::SanFrancisco));
     CHECK(board[City::SanFrancisco] == 8);

     virologist.take_card(City::Miami).build();
     take_5Yellow_cards(virologist).discover_cure(Color::Yellow);

     CHECK_NOTHROW(virologist.treat(City::Miami));
     CHECK_EQ(board[City::Miami],0);

}


TEST_CASE("OperationsExpert:") {

     /* OperationsExpert expertise:
          * Able to build research stations in any city on the board without discarding the city card.
     */

     Board board;
     OperationsExpert  opExpert(board,starting_point);

     CHECK_NOTHROW(opExpert.build().drive(City::Chicago));
     CHECK_NOTHROW(opExpert.build().drive(City::SanFrancisco));
     CHECK_NOTHROW(opExpert.build().drive(City::LosAngeles));
     CHECK_NOTHROW(opExpert.build().drive(City::MexicoCity));
     CHECK_NOTHROW(opExpert.build().drive(City::Bogota));
     CHECK_NOTHROW(opExpert.build().drive(City::BuenosAires));
     CHECK_NOTHROW(opExpert.build().drive(City::SaoPaulo));
     
}



TEST_CASE("Dispacher:") { 


     /* Dispacher expertise:
          * if the current city has a research station, the Dispatcher can fly direct without discarding the city card.
     */
    
    Board board;
    Dispatcher dis{board,starting_point};
   
    CHECK_NOTHROW(dis.drive(City::Miami)); // connected to Atalanta.


    CHECK_NOTHROW(dis.take_card(City::Miami)
                   .take_card(City::SaoPaulo)   
                   .fly_direct(City::SaoPaulo));  // A Player can "fly direct" to any given city when holding the city's card.

    CHECK_THROWS(dis.fly_direct(City::Atlanta));    // dis doesn't hold Atalanta card.

     dis.take_card(City::SaoPaulo);
    CHECK_NOTHROW(dis.build().fly_direct(City::Miami)); // Checking that his ability is working. 

    CHECK_THROWS(dis.fly_direct(City::Bangkok));  // No research station built yet in Miami.
    dis.take_card(City::Miami).build();           // building a research station in Miami
    CHECK_NOTHROW(dis.fly_direct(City::Bangkok));

    CHECK_THROWS(dis.take_card(City::Bangkok).build().fly_shuttle(City::SaoPaulo));
    



}

