#ifndef _PARAMEDIC_HPP
#define _PARAMEDIC_HPP
#include "Soldier.hpp"
namespace WarGame {

    class Paramedic:public Soldier
    {
        public:
            Paramedic(int numPlayer);
            Paramedic(int numPlayer,int health,int damage);
            const char* letter() const;
            void attack(const Board& board) const;
            int maxHealth() const;

    };

}
#endif