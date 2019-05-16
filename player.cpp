/*
    This file is part of STE.

    STE is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    STE is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with STE.  If not, see <http://www.gnu.org/licenses/>.
*/
// Copywright (C) 2018 - 2019
// Author: Peter (apemax) Wright
// CMDArena

#include "global.h"
#include "player.h"
#include "enemy.h"
using namespace std;

void player::HealthUp(int a)
{
  Health = Health + a;
}

void player::HealthDown(int b)
{
  Health = Health - b;
}

void player::Attack()
{
  //Attack.

  Eone.HealthDown(Pone.AttackS);
}

void player::Defence(int state)
{
  //Defend.

  switch(state)
  {
    case 1:
    {
      //Take DefenceS away from AttackS

      Eone.AttackTemp = Eone.AttackS;

      Eone.AttackS = Eone.AttackS - Pone.DefenceS;

      break;
    }

    case 2:
    {
      //Restore original value of AttackS

      Eone.AttackS = Eone.AttackTemp;

      break;
    }
  }
}

void player::Inventory()
{
  cout << "Health: " << Health << " Level: " << Lvl << " Exp: " << Exp << endl;
  cout << "Attack: " << AttackS << " Defence: " << DefenceS << endl;
}

void player::LvlUp()
{
  Lvl = Lvl + 1;

  Health = Health + 10;

  AttackS = AttackS + 1;

  DefenceS = DefenceS + 1;

  Exp = 0;
}
