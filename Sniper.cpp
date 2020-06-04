#include "Sniper.hpp"
#include "Board.hpp"

namespace WarGame {

    Sniper::Sniper(int numPlayer): Soldier(numPlayer,100,50)
    {
        
    }
    Sniper::Sniper(int numPlayer, int health, int damage): Soldier(numPlayer,health,damage)
    {
        
    }
    int Sniper::maxHealth() const
    {
        return 100;
    }
    const char* Sniper::letter() const
    {
        return "SN";
    }
    void Sniper::attack(Board& board) const
    {
        Soldier* target = board.mostCurrentHealth(this);

		if (target)
		{
			target->setHealth(target->getHealth() - this->getDamage());
			board.removeDeadSoldiers();
		}
       
    }
}