#ifndef PANDEMIC_A_SCIENTIST_HPP
#define PANDEMIC_A_SCIENTIST_HPP
#include "Player.hpp"


namespace pandemic{
    class Scientist: public Player {
    public:
        Scientist(Board& board, City city, int num);
        std::string role() const override{
            return "Scientist";
        }
        Scientist &discover_cure(Color color) override;
    protected:
        int n;
    };
};


#endif 
