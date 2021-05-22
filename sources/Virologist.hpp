#ifndef PANDEMIC_A_VIROLOGIST_HPP
#define PANDEMIC_A_VIROLOGIST_HPP
#include "Player.hpp"


namespace pandemic{
    class Virologist: public Player {
    public:
        Virologist(Board& board, City city);
        std::string role() const override{
            return "Virologist";
        }
        Virologist &treat(City city) override;

    };
};


#endif 
