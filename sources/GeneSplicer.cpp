#include "GeneSplicer.hpp"
#include "Color.hpp"
#include "City.hpp"

using namespace std;
using namespace pandemic;

const int number_of_cards = 5;

GeneSplicer::GeneSplicer(Board& board, City city):Player(board,city){
}

GeneSplicer& GeneSplicer::discover_cure(Color color){
    const int number_of_need_cards = 5;
    if(!_board.have_research_station_in(_city)){
        throw invalid_argument("there is no research station in this city");
    }
    if (_board.have_medicane_color(color)){
        return *this;
    }
    if(_cards.size() < number_of_need_cards){
        throw invalid_argument("you havn't enough accurate cards");
    }
    std::set<City> remove_the_cards;
    int counter=0;
    for(City curr_city: _cards){
        remove_the_cards.insert(curr_city);
        counter++;
    }
    if(counter < number_of_need_cards){
        throw invalid_argument("you havn't enough accurate cards");
    }
    for(City curr_city : remove_the_cards){
        _cards.erase(curr_city);
    }
    _board.add_medicane(color);
    return *this;
}
