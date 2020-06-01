#ifndef _PARAMEDIC_COMMANDER_HPP
#define _PARAMEDIC_COMMANDER_HPP
#include "Paramedic.hpp"
#include "Commander.hpp"
namespace WarGame {

    class ParamedicCommander:public Paramedic, public Commander<Paramedic>
    {
        public:
            ParamedicCommander(int numPlayer);
            const char* letter() const;
    };

}
#endif