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
// Copywright (C) 2018
// Author: Peter (apemax) Wright
// CMDArena

#include <iostream>
#include <fstream>
#include "global.h"
#include "characters.h"
using namespace std;

void Fight()
{
  int Opt1;
  int PDef = 0;
  int EDef = 0;
  string running = "true";

  while (running == "true")
  {
    if(PDef == 1)
    {
      Pone.Defence(2);

      PDef = PDef - 1;
    }

    cout << "1) Attack. 2) Defend. 3) Surrender." << endl;
    cout << "Your Health: " << Pone.GetHealth();

    cout << " Opponents Health: " << Eone.GetHealth() << endl;

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
        running = "false";

        break;
      }
    }

    //ai actions

    if(EDef == 1)
    {
      Eone.Defence(2);

      EDef = EDef - 1;
    }

    if(Eone.GetHealth() > 4)
    {
      Eone.Attack();
    }
    else if(Eone.GetHealth() <= 4)
    {
      //Defend.

      Eone.Defence(1);

      EDef = EDef + 1;
    }

    if(Pone.GetHealth() <= 0)
    {
      cout << "You have lost." << endl;

      running = "false";

      Pone.PDeath + 1;
    }
    else if(Eone.GetHealth() <= 0)
    {
      cout << "You have won." << endl;

      running = "false";
    }
  }
}
