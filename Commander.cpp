#include "Commander.hpp"
#include <vector>
namespace WarGame {
    
	template <class T>
    void Commander<T>::command(Board& board)
    {
        std::vector<T*> vec = board.getSoldiers<T>();
        for(int i = 0; i < vec.size(); i++)
        {
            vec[i]->attack(board);
        }
    }
}