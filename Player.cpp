#include "Player.hpp"


namespace pandemic{

        // Player can take as many cards as he want (no two of the same city).                                                         
        Player& Player::take_card(City city){
            // if(hand.count(city) == 0){
            //     hand.insert(city);
            // }
            return *this; 
        }


        // To navigate between two cities they must be neighbours.
        Player& Player::drive(City city){

            // if(board.isConnected(curr_city,city)){
            //     curr_city = city;
            // }else{
            //     throw std::invalid_argument("Unable to drive between not neighbour cities!");
            // }
            return *this;
        }

        // To fly direct player must hold the destination city card.
        Player& Player::fly_direct(City dst){

            // if(hand.count(dst) == 0){
            //     throw std::invalid_argument("Player doesn't hold card for" + cityString(dst));
            // }

            // curr_city = dst;
            // hand.erase(dst);
            return *this;
        }

        // To fly charter player must hold the current city card.
        Player& Player::fly_charter(City dst){

            // if(hand.count(curr_city) > 0){
            //     hand.erase(curr_city);
            //     curr_city = dst;
            // }else throw std::invalid_argument("Player doesn't obtain current city card to fly charter");

            return *this;
        }

        // To fly shuttle both cities must have research stations.
        Player& Player::fly_shuttle(City dst){

            // if(board.hasResearch(curr_city) && board.hasResearch(dst)){
            //     curr_city = dst;
            // }else throw std::invalid_argument("No research station in destination city!");

            return *this;
        }

        Player& Player::build(){

            // // Player which has the city card and perform build (in a city without a research station) is required to discard the card.
            // if(hand.count(curr_city) > 0 && !board.hasResearch(curr_city)){
            //     board.buildResearch(curr_city);
            //     hand.erase(curr_city);
            // }// If the player doesn't hold the current city card cannot perform build.
            // else if(hand.count(curr_city) == 0){
            //     throw std::invalid_argument("Must obtain " + cityString(curr_city) + " in order to build.");
            // }

            // // Player which has the city card and perform build (in a city with a research station) is not required to discard the card.
            // if(hand.count(curr_city) > 0){  
            //     if(board.hasResearch(curr_city)){
            //         return *this;
            //     }
            // }


            
            return *this;
        }


        /*
            TODO: need to fix after cured drops level to 0.

        */ 


        Player& Player::treat(City city){

            // // If city that is treated has level 0 should throw execption
            // if(board[city] == 0){
            //     throw std::invalid_argument("Current city" + cityString(curr_city) + "has a disease level of 0");
            // }else if(curr_city != city){
            //     throw std::invalid_argument("To treat a player current city must be same as" + cityString(city));
            // }
            // else if(board.isCured(City_color.at(city))){ // If the city color disease was discovered treat action will drop level to 0
            //     board[city] = 0;
            // }
            // else {board[city]--;} // no cure discovered thefore disease level decreases by 1.

            return *this;
        }

        // To discover a cure player must have 5 of same color cards and current city with research station.
        Player& Player::discover_cure(Color color){

            // // No research station.
            // if(!board.hasResearch(curr_city)){
            //     throw std::invalid_argument("Unable to discover a cure in a city without a research staion.");
            // }

            // int count = 0;
            // for(auto& card : hand){ // going through the player hand to check for 5 cards with same color.
            //     if(City_color.at(card) == color){
            //         count++; 
            //     }
            // }

            // if(count > 5){ // can have more than 5 of same color

            //     if(board.isCured(color)){ // if a cure was already discovered, the player doesn't need to discard any cards.
            //         return *this;
            //     }

            //     board.markCure(color);
                
            //     int min = 5;
            //     for(auto& card : hand){
            //         if(min > 0){
            //             if(City_color.at(card) == color){
            //                 hand.erase(card);
            //             }
            //             min--;
            //         } // 5 cards need to be discard
            //     } // for iterating over hand
            // }else if(count < 5 ){
            //     throw std::invalid_argument("in order to discover color player needs at least 5 cards of same color!");
            // }

            return *this;
        }


        Player::~Player(){}

}