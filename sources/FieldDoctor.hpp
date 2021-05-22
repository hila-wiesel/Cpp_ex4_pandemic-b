#ifndef PANDEMIC_A_FIELDDOCTOR_HPP
#define PANDEMIC_A_FIELDDOCTOR_HPP
#include "Player.hpp"


namespace pandemic{
    class FieldDoctor: public Player {
    public:
        FieldDoctor(Board& board, City city);
        std::string role() const override{
            return "FieldDoctor";
        }
        FieldDoctor &treat(City city) override;

    };
};

#endif
