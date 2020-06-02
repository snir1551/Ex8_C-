#include "Commander.hpp"

namespace WarGame {
	void Commander::command(std::vector<Soldier*> soldiers, Board& board)
    {
		for (int i = 0; i < soldiers.size(); i++)
		{
			soldiers[i]->attack(board);
		}
    }
}