#include "Medic.hpp"
#include "Color.hpp"
#include "City.hpp"

using namespace pandemic;
using namespace std;


Medic::Medic(Board& board, City city):Player(board, city){}

Medic& Medic::treat(City city){
    if(city != _city){
        throw invalid_argument("you can treat only in your city!!");
    }
    if(_board[_city] == 0){
        throw invalid_argument("The city doesnthave desease");
    }
    _board[_city] = 0;
    return *this;
}

Medic& Medic::fly_direct(City city){
    if(city ==_city){
        throw invalid_argument("can't drive to your city");
    }
    if(_cards.find(city) == _cards.end()){
        throw invalid_argument("you dont have accurate cards for fly direct to this city");
    }
    _cards.erase(city);
    _city = city;
    treat_city(_city);
    return *this;
}

Medic& Medic::fly_charter(City city){
    if(city ==_city){
        throw invalid_argument("can't drive to your city");
    }
    if(_cards.find(_city) == _cards.end()){ 
        throw invalid_argument("you dont have accurate cards");
    }
    _cards.erase(_city);
    _city = city;
    treat_city(_city);
    return *this;
}

Medic& Medic::fly_shuttle(City city){
    if(city ==_city){
        throw invalid_argument("can't drive to your city");
    }
    if(!_board.have_research_station_in(city) || !_board.have_research_station_in(_city)){
        throw invalid_argument("one or both of the city doesnt have research station");
    }
    _city = city;
    treat_city(_city);
    return *this;
}

Medic& Medic::drive(City city){
    if(city ==_city){
        throw invalid_argument("can't drive to your city");
    }
    if (!_board.city_exist(city)) {
        throw invalid_argument("city doesnt exsit");
    }
    if(!_board.is_connected(_city, city)){
        throw invalid_argument("this city doenst connected to your city");
    }
    _city = city;
    treat_city(_city);
    return *this;
}

void Medic::treat_city(City city){
    Color color = _board.city_to_color(city);
    if(_board.have_medicane_color(color)){
        _board[city] = 0;
    }
}