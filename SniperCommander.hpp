#ifndef _SNIPER_COMMANDER_HPP
#define _SNIPER_COMMANDER_HPP
#include "Sniper.hpp"
#include "Commander.hpp"
namespace WarGame {

    class SniperCommander:public Sniper, public Commander<Sniper>
    {
        public:
            SniperCommander(int numPlayer);
            const char* letter() const;
    };

}
#endif