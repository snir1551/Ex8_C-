#include "Paramedic.hpp"
namespace WarGame {
    Paramedic::Paramedic(int numPlayer): Soldier(numPlayer,100,0)
    {
        
    }
    Paramedic::Paramedic(int numPlayer,int health, int damage): Soldier(numPlayer,health,damage)
    {
        
    }
    const char* Paramedic::letter() const
    {
        return "PA";
    }
    int Paramedic::maxHealth() const
    {
        return 100;
    }
    void Paramedic::attack(Board& board) const
    {
        // std::vector<Soldier*> vec = board.getSoldierNear(this);
        // for(int i = 0; i < vec.size(); i++)
        // {
        //     vec[i]->setHealth(vec[i]->maxHealth());
        // }
    }
}