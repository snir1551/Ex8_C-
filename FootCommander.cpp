#include "FootCommander.hpp"
namespace WarGame {
    FootCommander::FootCommander(int numPlayer): FootSoldier(numPlayer,150,20)
    {
        
    }
    const char* FootCommander::letter() const
    {
        return "FC";
    }

	void FootCommander::command(Board& board)
	{
		Commander::command(board.getSoldiers<FootSoldier>(), board);
	}
}