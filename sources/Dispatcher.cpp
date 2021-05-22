#include "Dispatcher.hpp"
#include <exception>
using namespace pandemic;
using namespace std;

Dispatcher::Dispatcher(Board& board, City city):Player(board, city){
}
Dispatcher& Dispatcher::fly_direct(City city){
    if(city == _city){
        throw invalid_argument("can't fly to your city!!");
    }
    if(!_board.city_exist(city)){
        throw invalid_argument("the city doesn't exist!!");
    }
    if(_board.have_research_station_in(_city)){
        _city = city;
        return *this;
    }
    if(_cards.find(city) == _cards.end()){  
        throw invalid_argument("you dont have accurate cards");
    }
    _cards.erase(_city);
    _city = city;
    return  *this;
}