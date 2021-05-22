#ifndef PANDEMIC_A_OPERATIONEXPERT_HPP
#define PANDEMIC_A_OPERATIONEXPERT_HPP
#include "Player.hpp"


namespace pandemic{
    class OperationsExpert: public Player {
    public:
        OperationsExpert(Board& board, City city);
        std::string role() const override{
            return "OperationsExpert";
        }
        OperationsExpert &build() override;

    };
};


#endif
