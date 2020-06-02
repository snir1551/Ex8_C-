#include "FootSoldier.hpp"
#include "Board.hpp"
namespace WarGame {

    FootSoldier::FootSoldier(int numPlayer): Soldier(numPlayer,100,10)
    {
        
    }
    FootSoldier::FootSoldier(int numPlayer,int health,int damage): Soldier(numPlayer,health,damage)
    {
        
    }
    const char* FootSoldier::letter() const
    {
        return "FS";
    }
    int FootSoldier::maxHealth() const
    {
        return 100;
    }
    void FootSoldier::attack(Board& board) const
    {
        Soldier* target = board.getCloseToEnemy(this);
        target->setHealth(target->getHealth()-this->getDamage());
    }
}