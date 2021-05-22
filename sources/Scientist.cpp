#include "Board.hpp"
#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Scientist::Scientist(Board& board, City city, int num):Player(board,city), n(num){
}

Scientist& Scientist::discover_cure(Color color){
    if(!_board.have_research_station_in(_city)){
        throw invalid_argument("there is no research station!!");
    }
    if (_board.have_medicane_color(color)){
        return *this;
    }
    if(_cards.size() < n){
        throw invalid_argument("you dont have enough accurate cards");
    }
    std::set<City> remove_cards;
    int counter = 0;
    for(City curr_city: _cards){
        if(_board.city_to_color(curr_city) == color) {
            remove_cards.insert(curr_city);
            counter++;
            if (counter == n) { break; }
        }
    }
    if(counter <n ){
        throw invalid_argument("you dont have enough accurate cards");
    }
    for(City curr_city : remove_cards){
        _cards.erase(curr_city);
    }
    _board.add_medicane(color); //add cure for this color
    return *this;
}