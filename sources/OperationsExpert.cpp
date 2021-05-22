#include "OperationsExpert.hpp"
#include "Color.hpp"
#include "City.hpp"
using namespace pandemic;
using namespace std;

OperationsExpert::OperationsExpert(Board& board, City city): Player(board,city){}

OperationsExpert& OperationsExpert::build(){
    if(!_board.have_research_station_in(_city)){ 
        _board.build_station_in(_city);
    }
    return *this;
}
