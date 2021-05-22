#ifndef PANDEMIC_A_MEDIC_HPP
#define PANDEMIC_A_MEDIC_HPP
#include "Player.hpp"


namespace pandemic{
    class Medic: public Player {
    public:
        Medic(Board& board, City city);
        std::string role() const override{
            return "Medic";
        }
        Medic &treat(City city) override;
        Medic &drive(City city) override;
        Medic &fly_direct(City city) override;
        Medic &fly_charter(City city) override;
        Medic &fly_shuttle(City city) override;
    private:
        void treat_city(City city);
    };
};


#endif
