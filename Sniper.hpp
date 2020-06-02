#ifndef _FOOT_SNIPER_HPP
#define _FOOT_SNIPER_HPP
#include "Soldier.hpp"
namespace WarGame {

    class Sniper:public Soldier
    {
        public:
            Sniper(int numPlayer);
            Sniper(int numPlayer, int health, int damage);
            const char* letter() const;
            int maxHealth() const;
            void attack(Board& board) const;
    };

}
#endif