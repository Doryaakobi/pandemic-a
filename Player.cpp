#include "Player.hpp"


namespace pandemic{
    /* 
                Board& board;
            std::set<City> hand;
            City curr_city;
            std::string expertise;
            
            */

            Player& Player::take_card(City city){

                hand.insert(city);
                return *this; 
            }

            Player& Player::drive(City city){

                if(board.isConnected(curr_city,city)){
                    curr_city = city;
                }else{
                    throw std::invalid_argument("Unable to drive between not neighbour cities!");
                }
                return *this;
            }

            Player& Player::fly_charter(City city){

                return *this;
            }
            Player& Player::fly_shuttle(City city){

                return *this;
            }


            Player& Player::fly_direct(City city){
                return *this;
            }

            Player& Player::build(){

                board.buildResearch(curr_city);
                return *this;
            }

            Player& Player::discover_cure(Color color){

                // int count = 0;
                // if(board.hasResearch(curr_city)){

                //     for(auto city : hand){
                //         if(city_color(city) == color){
                //             count++;
                //         }
                //     }
                //     if(count>5){
                        
                //     }

                // }

                
                return *this;
            }
            Player& Player::treat(City city){

                return *this;
            }

            Player::~Player(){}

}