#include "Soldier.hpp"
#include <math.h>

namespace WarGame {

    // Soldier::Soldier()
    // {

    // }
    Soldier::Soldier(int numPlayer,int health, int damage): _numPlayer(numPlayer), _health(health), _damage(damage)
    {
        
    }
    double Soldier::Distance(const Soldier* target, const Board& board) const
    {
        std::pair<int,int> locationSource = board.locationSoldier(this);
        std::pair<int,int> locationTarget = board.locationSoldier(target);
        double dx = locationSource.first - locationTarget.first;
        double dy = locationSource.first - locationTarget.second;
        return sqrt(dx*dx + dy*dy);
    }

}