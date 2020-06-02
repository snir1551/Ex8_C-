#include "Soldier.hpp"
#include "Commander.hpp"
#include "Board.hpp"
#include <stdexcept>
#include <iostream>
namespace WarGame {
    Soldier*& Board::operator[](std::pair<int,int> location)
    {
        if(location.first > board.size() || location.first < 0 || location.second > board.size() || location.second < 0 )
        {
            throw std::invalid_argument("Illegal location");
        }
        // else if(board[location.first][location.second] != nullptr)
        // {
        //     throw std::invalid_argument("another soldier in location");
        // }
        return board[location.first][location.second];
    }

    Soldier* Board::operator[](std::pair<int,int> location) const
    {
        if(location.first > board.size() || location.first < 0 || location.second > board.size() || location.second < 0 )
        {
            throw std::invalid_argument("Illegal location");
        }
        return board[location.first][location.second];
    }

    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction)
    {
        if(source.first > board.size() || source.first < 0 || source.second > board.size() || source.second < 0 )
        {
            throw std::invalid_argument("Illegal location");
        }
        if(board[source.first][source.second] == nullptr)
        {
            throw std::invalid_argument("in the source location not exist player to move");
        }
        if(board[source.first][source.second]->getNumPlayer() != player_number)
        {
            throw std::invalid_argument("already another player in the source location");
        }
        
        int targetRow, targetCol;
        switch(direction)
        {
            case MoveDIR::Up:
                targetRow = source.first + 1;
                targetCol = source.second;
                break;
            case MoveDIR::Down:
                targetRow = source.first - 1;
                targetCol = source.second;
                break;
            case MoveDIR::Right:
                targetRow = source.first;
                targetCol = source.second + 1;
                break;
            case MoveDIR::Left:
                targetRow = source.first;
                targetCol = source.second - 1;
                break;
        }
        if(targetRow > board.size() || targetRow < 0 || targetCol > board.size() || targetCol < 0 || board[targetRow][targetCol] != nullptr)
        {
            throw std::invalid_argument("exist player in the location target move");
        }

        board[targetRow][targetCol] = board[source.first][source.second];
		board[source.first][source.second] = nullptr;

		Commander* commander = dynamic_cast<Commander*>(board[targetRow][targetCol]);

		if (commander) // moving soldier is a commander
		{
			commander->command(*this);
		}
		else // moving soldier is not a commander
		{
			board[targetRow][targetCol]->attack(*this);
		}

		removeDeadSoldiers();
    }

    bool Board::has_soldiers(uint player_number) const
    {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] != nullptr && board[i][j]->getNumPlayer() == player_number)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void Board::draw() const
    {
      for(int row = 0; row < board.size(); row++)
      {
        for(int col = 0; col < board[0].size(); col++)
        {
          if(board[row][col] != nullptr)
            std::cout << board[row][col]->letter() << " ";
          else
             std::cout << "NU ";
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }

    void Board::drawHealth() const
    {
       for(int row = 0; row < board.size(); row++)
       {
        for(int col = 0; col < board[0].size(); col++)
        {
          if(board[row][col] != nullptr)
            std::cout << "[" << board[row][col]->getHealth() << "]" << "[" << board[row][col]->getDamage() << "]" << " ";
          else
            std::cout << "[UUU][UU] ";
        }
        std::cout << std::endl;
       }
       std::cout << std::endl;
    }

    Soldier* Board::getCloseToEnemy(const Soldier* source) const
    {
        double min = -1.0;
        Soldier* minSoldier = nullptr;

        for(int row = 0; row < board.size(); row++)
        {
            for(int col = 0; col < board[0].size(); col++)
            {
                if(board[row][col] != nullptr && board[row][col]->getNumPlayer() != source->getNumPlayer())
                {
                    int distance = source->Distance(board[row][col], *this);
                    if(minSoldier == nullptr || min > distance)
                    {
                        min = distance;
                        minSoldier = board[row][col];
                    }
                       
                }
            }
        }
        return minSoldier;
    }

    std::vector<Soldier*> Board::getSoldierNear(const Soldier* source) const
    {
        std::vector<int> dirs = {-1, 1, 0};
        std::vector<Soldier*> vec;
        std::pair<int,int> locationSource = locationSoldier(source);
        for(int dirX : dirs)
        {
            for(int dirY : dirs)
            {
                if(dirX == 0 && dirY == 0)
                {
                    continue;
                }
                else
                {
                    if(locationSource.first + dirX >= 0 && locationSource.first + dirX < board.size() && locationSource.first + dirY >= 0 && locationSource.first + dirY < board.size())
                    {
                        if(board[locationSource.first + dirX][locationSource.second + dirY] != nullptr && board[locationSource.first + dirX][locationSource.second + dirY]->getNumPlayer() == board[locationSource.first][locationSource.second]->getNumPlayer())
                        {
                            vec.push_back(board[locationSource.first + dirX][locationSource.second + dirY]);
                        }
                    }
                }
            }
        }

        return vec;
    }

    Soldier* Board::mostCurrentHealth(const Soldier* source) const
    {
        int mostHealth = -1;
        Soldier* target = nullptr;
        std::pair<int,int> locationSource = Board::locationSoldier(source);

        for(int i = 0; i < board.size(); i ++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] != nullptr && board[i][j]->getNumPlayer() != board[locationSource.first][locationSource.second]->getNumPlayer())
                {
                    if(mostHealth == -1 || mostHealth < board[i][j]->getHealth())
                    {
                        mostHealth = board[i][j]->getHealth();
                        target = board[i][j];
                    }
                }
            }
        }

        return target;
    }

    std::pair<int,int> Board::locationSoldier(const Soldier* source) const
    {
        std::pair<int,int> location;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == source)
                {
                    location.first = i;
                    location.second = j;
                    return location;
                }
            }
        }

        throw std::invalid_argument("not found soldier location");     
    }

    void Board::clear()
    {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                delete board[i][j];
                board[i][j] = nullptr;
            }
        }
    }

	void Board::removeDeadSoldiers()
	{
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (board[i][j] != nullptr && board[i][j]->getHealth() <= 0)
				{
					delete board[i][j];
					board[i][j] = nullptr;
				}
			}
		}
	}
}
