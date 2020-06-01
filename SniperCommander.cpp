#include "SniperCommander.hpp"
namespace WarGame {

    SniperCommander::SniperCommander(int numPlayer): Sniper(numPlayer,100,50)
    {
        
    }
    const char* SniperCommander::letter() const
    {
        return "SC";
    }
}