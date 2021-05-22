#ifndef PANDEMIC_A_DISPATCHER_HPP
#define PANDEMIC_A_DISPATCHER_HPP
#include "Player.hpp"


namespace pandemic{
    class Dispatcher: public Player {
    public:
        Dispatcher(Board& board, City city);
        std::string role() const override{
            return "Dispatcher";
        }
        Dispatcher &fly_direct(City city) override;
    };
};


#endif
