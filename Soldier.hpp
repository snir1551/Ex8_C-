#ifndef _SOLDIER_HPP
#define _SOLDIER_HPP

namespace WarGame {
	class Board;

    class Soldier
    {
        private:
            int _numPlayer;
            int _health;
            int _damage;

        public:
           Soldier(int numPlayer,int health, int damage);

           virtual ~Soldier()
           {

           }

           int getNumPlayer() const
           {
               return _numPlayer;
           }

           int getHealth() const
           {
               return _health;
           }

           void setHealth(int health)
           {
               this->_health = health;
           }

           int getDamage() const
           {
               return _damage;
           }

           void setDamage(int damage)
           {
               this->_damage = damage;
           }

           
           virtual const char* letter() const = 0;

           virtual void attack(Board& board) const = 0;
           
		   double Distance(const Soldier* target, const Board& board) const;

           virtual int maxHealth() const = 0;


    };

}
#endif
