#include "FootCommander.hpp"
namespace WarGame {
    FootCommander::FootCommander(int numPlayer): FootSoldier(numPlayer,150,20)
    {
        
    }
    const char* FootCommander::letter() const
    {
        return "FC";
    }
    // void FootCommander::command(Board& board) const
    // {
    //     std::vector<FootSoldier*> vec = board.getSoldiers<FootSoldier>();
    //     for(int i = 0; i < vec.size(); i++)
    //     {
    //         vec[i]->attack(board);
    //     }
    // }
}