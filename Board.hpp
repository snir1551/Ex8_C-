/**
 * Header file for the board of the war game.
 * 
 * You can copy this file to a new file called Board.hpp, and extend it as you like.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */
#ifndef _BOARD_HPP
#define _BOARD_HPP

#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

namespace WarGame {
class Board {
  private:
    std::vector<std::vector<Soldier*>> board;

  public:
    enum MoveDIR { Up, Down, Right, Left };
    
    Board(uint numRows, uint numCols) : 
      board(numRows, std::vector<Soldier*>(numCols, nullptr)) {}

    ~Board()
    {
      board.clear();
    }

    // operator for putting soldiers on the game-board during initialization.
    Soldier*& operator[](std::pair<int,int> location);
    
    // operator for reading which soldiers are on the game-board.
    Soldier* operator[](std::pair<int,int> location) const;

	void removeDeadSoldiers();
    
    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument". 
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers 
    //      must be handled by polymorphism.
    void move(uint player_number, std::pair<int,int> source, MoveDIR direction);

    // returns true iff the board contains one or more soldiers of the given player.
    bool has_soldiers(uint player_number) const;

    int getNumCols() const
    {
      return board[0].size();
    }

    int getNumRows() const
    {
      return board.size();
    }


    void draw() const;

    void drawHealth() const;

    Soldier* getCloseToEnemy(const Soldier* source) const;

  template <class T>
	std::vector<Soldier*> getSoldiers(Soldier* soldier)
	{
		std::vector<Soldier*> vec;
		for (int row = 0; row < board.size(); row++)
		{
			for (int col = 0; col < board[0].size(); col++)
			{
				T* ptr = dynamic_cast<T*>(board[row][col]);
				if (ptr != nullptr && board[row][col]->getNumPlayer() == soldier->getNumPlayer())
					vec.push_back(ptr);
			}
		}
		return vec;
	}

    std::vector<Soldier*> getSoldierNear(const Soldier* source) const;

    Soldier* mostCurrentHealth(const Soldier* source) const;

    std::pair<int,int> locationSoldier(const Soldier* source) const;

    void clear();

           


};

}
#endif
