#ifndef _FOOT_SOLDIER_HPP
#define _FOOT_SOLDIER_HPP
#include "Soldier.hpp"
namespace WarGame {

    class FootSoldier:public Soldier
    {
        public:
            FootSoldier(int numPlayer);
            FootSoldier(int numPlayer,int health, int damage);
            const char* letter() const;
            void attack(Board& board) const;
            int maxHealth() const;
            
    };

}
#endif