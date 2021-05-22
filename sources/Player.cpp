#include "Player.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"
#include <exception>
#include <iostream>

using namespace pandemic;
using namespace std;

Player::Player(Board& board, City city): _board(board),_city(city){}

Player& Player::take_card(City city) {
    if (!_board.city_exist(city)) {
        throw invalid_argument("city doesn't exist");
    }
    _cards.insert(city);
    return *this;
}

Player& Player::drive(City city){
    if(city ==_city){
        throw invalid_argument("can't drive to your city");
    }
    if (!_board.city_exist(city)) {
        throw invalid_argument("city doesn't exist");
    }
    if(!_board.is_connected(_city, city)){
        throw invalid_argument("this city doenst connected to your city");
    }
    _city = city;
    return *this;
}

Player& Player::fly_direct(City city){
    if(city ==_city){
        throw invalid_argument("can't fly to your city");
    }
    if (!_board.city_exist(city)) {
        throw invalid_argument("city doesn't exist");
    }
    if(_cards.find(city) == _cards.end()){
        throw invalid_argument("you don't have accurate card");
    }
    _cards.erase(city);
    _city = city;
    return *this;
}

Player& Player::fly_charter(City city){
    if(city ==_city){
        throw invalid_argument("can't fly to your city");
    }
    if (!_board.city_exist(city)) { 
        throw invalid_argument("city doesn't exist");
    }
    if(_cards.find(_city) == _cards.end()){
        throw invalid_argument("you don't have accurate card");
    }
    _cards.erase(_city);
    _city = city;
    return *this;
}

Player& Player::fly_shuttle(City city){
    if(city ==_city){
        throw invalid_argument("can't fly to your city");
    }
    if (!_board.city_exist(city)) { 
        throw invalid_argument("city doesn't exist");
    }
    if(!_board.have_research_station_in(city) || !_board.have_research_station_in(_city)){
            throw invalid_argument("one or both of the city doesnt have research station");
    }
    _city = city;
    return *this;
}

Player& Player::build(){
    if(_board.have_research_station_in(_city)){
        return *this;
    }
    if(_cards.find(_city) == _cards.end()) {
        throw invalid_argument("you don't have accurate card");
    }
    _board.build_station_in(_city);
    _cards.erase(_city);
    return *this;
}

Player& Player::discover_cure(Color color) {
    const int number_of_need_cards = 5;
    int counter = 0;

    if(!_board.have_research_station_in(_city)){
        throw invalid_argument("you dont have research station in this city");
    }
    if(_board.have_medicane_color(color)){  //this desease already have a cure
        return *this;
    }
    std::set<City> remove_the_cards;
    for(City curr_ciry:_cards){
        if (_board.city_to_color(curr_ciry) == color) {
            counter++;
            remove_the_cards.insert(curr_ciry);
        }
    }
    if(counter < number_of_need_cards){
        throw invalid_argument("you havn't enough accurate cards");
    }
    for(City curr_ciry: remove_the_cards){
      _cards.erase(curr_ciry);
    }
    _board.add_medicane(color);
    return *this;
}

Player& Player::treat(City city) {
    if (!_board.city_exist(city)) { 
        throw invalid_argument("city doesn't exist");
    }
    if(city != _city){
        throw("you can't find a cure at this city!!");
    }
    if(_board[city] == 0){
        throw invalid_argument("The city doesn't have desease!!");
    }
    Color color = _board.city_to_color(city);
    if(_board.have_medicane_color(color)) {  
        _board[city] = 0;
    }
    else{
        _board[city] -=1;
    }
        return *this;
}

void Player::remove_cards(){
    _cards.clear();
}
