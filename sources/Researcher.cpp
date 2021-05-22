#include "Board.hpp"
#include "Researcher.hpp"
#include "Player.hpp"

using namespace std;
using namespace pandemic;

Researcher::Researcher(Board& board, City city):Player(board, city){
}

Researcher& Researcher::discover_cure(Color color){
    const int number_of_need_cards = 5;
    if (_board.have_medicane_color(color)) {
        return  *this;
    }
    if(_cards.size() < number_of_need_cards){
        throw invalid_argument("you don't have enough accurate cards");
    }
    std::set<City> remove_cards;
    int counter = 0;
    for(City curr_city: _cards){
        if(_board.city_to_color(curr_city) == color) {
            remove_cards.insert(curr_city);
            counter++;
            if (counter == number_of_need_cards) { break; }
        }
    }
    if(counter <number_of_need_cards ){
        throw invalid_argument("you don't have enough accurate cards");
    }
    for(City curr_city : remove_cards){
        _cards.erase(curr_city);
    }
    _board.add_medicane(color);
    return *this;

}