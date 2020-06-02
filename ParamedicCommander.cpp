#include "ParamedicCommander.hpp"
namespace WarGame {
    ParamedicCommander::ParamedicCommander(int numPlayer): Paramedic(numPlayer,200,0)
    {
        
    }
    const char* ParamedicCommander::letter() const
    {
        return "PC";
    }

	void ParamedicCommander::command(Board& board)
	{
		Commander::command(board.getSoldiers<Paramedic>(), board);
	}

}