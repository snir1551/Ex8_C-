#include "SniperCommander.hpp"
namespace WarGame {

    SniperCommander::SniperCommander(int numPlayer): Sniper(numPlayer,120,100)
    {
        
    }
    const char* SniperCommander::letter() const
    {
        return "SC";
    }

	void SniperCommander::command(Board& board)
	{
		Commander::command(board.getSoldiers<Sniper>(this), board);
	}
}