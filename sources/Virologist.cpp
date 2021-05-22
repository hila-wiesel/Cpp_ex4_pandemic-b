#include "Virologist.hpp"
#include "Color.hpp"

using namespace pandemic;
using namespace std;


Virologist:: Virologist(Board& board, City city):Player(board,city){}


Virologist& Virologist::treat(City city) {
    if (_board[city] == 0) {
        throw invalid_argument("The city desnt have desease");
    }
    Color color = _board.city_to_color(city);
    if (_board.have_medicane_color(color)) { 
        _board[city] = 0;
        return *this;
    }
    if(_city != city){
        if(_cards.find(city) != _cards.end()) { 
            _cards.erase(city);
            _board[city] -= 1;
        }
        else{
            throw invalid_argument("you dont have accurate cards");
        }
    }
    else{
            _board[city] -=1;
    }
    return *this;
}