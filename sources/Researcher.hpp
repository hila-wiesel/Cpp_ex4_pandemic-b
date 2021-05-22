#ifndef PANDEMIC_A_RESEARCHER_HPP
#define PANDEMIC_A_RESEARCHER_HPP
#include "Player.hpp"

namespace pandemic{
    class Researcher: public Player {
    public:
        Researcher(Board& board, City city);
        std::string role() const override{
            return "Researcher";
        }
        Researcher &discover_cure(Color color) override;

    };
};


#endif
