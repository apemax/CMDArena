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

void Fight()
{
  int Opt1;
  int PDef = 0;
  int EDef = 0;
  bool running = true;

  while (running == true)
  {
    if(PDef == 1)
    {
      Pone.Defence(2);

      PDef = PDef - 1;
    }

    cout << "1) Attack. 2) Defend. 3) Surrender." << endl;

    cout << "Your Health: " << Pone.Health << " Opponents Health: " << Eone.Health << endl;

    cout << ">";

    cin >> Opt1;

    switch(Opt1)
    {
      case 1:
      {
        //Attack

        Pone.Attack();

        break;
      }

      case 2:
      {
        //defend

        Pone.Defence(1);

        PDef = PDef + 1;

        break;
      }

      case 3:
      {
        running = false;

        break;
      }
    }

    //ai actions

    if(EDef == 1)
    {
      Eone.Defence(2);

      EDef = EDef - 1;
    }

    if(Eone.Health > 4)
    {
      Eone.Attack();
    }
    else if(Eone.Health <= 4)
    {
      //Defend.

      Eone.Defence(1);

      EDef = EDef + 1;
    }

    if(Pone.Health <= 0)
    {
      cout << "You have lost." << endl;

      running = false;

      Pone.PDeath + 1;
    }
    else if(Eone.Health <= 0)
    {
      cout << "You have won, You gained 10 Exp." << endl;

      Pone.Exp = Pone.Exp + 10;

      if (Pone.Exp >= 100)
      {
        Pone.LvlUp();
      }

      running = false;
    }
  }
}
