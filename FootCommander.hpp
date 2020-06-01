#ifndef _FOOT_COMMANDER_HPP
#define _FOOT_COMMANDER_HPP
#include "Commander.hpp"
#include "FootSoldier.hpp"
namespace WarGame {

    class FootCommander:public FootSoldier, public Commander<FootSoldier>
    {
        public:
            FootCommander(int numPlayer);
            const char* letter() const;
    };

}
#endif