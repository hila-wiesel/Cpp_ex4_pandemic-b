#include "FieldDoctor.hpp"
#include<exception>

using namespace pandemic;
using namespace std;


FieldDoctor::FieldDoctor(Board& board, City city):Player(board,city){
}

FieldDoctor& FieldDoctor::treat(City city){
    if(city != _city && !_board.is_connected(_city,city)){
        throw("you can't treat this city");
    }
    if(_board[city] == 0){
        throw invalid_argument("this city doesn't have desease");
    }
    Color color = _board.city_to_color(city);
    if(_board.have_medicane_color(color)){
        _board[city] = 0;
    }
    else {
        _board[city] -= 1;
    }
    return *this;
}