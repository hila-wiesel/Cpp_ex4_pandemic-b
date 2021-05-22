#ifndef PANDEMIC_A_GENESPLICER_HPP
#define PANDEMIC_A_GENESPLICER_HPP
#include "Player.hpp"


namespace pandemic{
    class GeneSplicer: public Player {
    public:
        GeneSplicer(Board& board, City city);
        std::string role() const override{
            return "GeneSplicer";
        }
        GeneSplicer &discover_cure(Color color) override;

    };
};

#endif
