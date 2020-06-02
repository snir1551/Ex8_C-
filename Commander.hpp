#ifndef _COMMANDER_HPP
#define _COMMANDER_HPP
#include <vector>
#include "Board.hpp"
#include "Soldier.hpp"

namespace WarGame {
    class Commander
    {
	public:
		virtual void command(Board& board) = 0;

    protected:
		void command(std::vector<Soldier*> soldiers, Board& board);
    };

}
#endif