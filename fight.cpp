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
#include "attack.h"
#include "defend.h"
using namespace std;

void Fight()
{
  string Opt1;
  int EDef = 0;
  bool running = true;

  cin.ignore();

  while (running == true)
  {
    if(Pone.PDef == 2)
    {
      DefendCommand.Execute(Pone.PDef);

      Pone.PDef = Pone.PDef - 1;
    }

    cout << "1) Attack. 2) Defend. 3) Surrender." << endl;

    cout << "Your Health: " << Pone.Health << " Opponents Health: " << Eone.Health << endl;

    cout << ">";

    getline(cin, Opt1);

    if(Opt1.substr(0, 6) == "attack")
    {
      cout << Opt1 << endl;
      Pone.ExecuteCommand(Opt1.substr(0, 6));
    }
    else if(Opt1.substr(0, 6) == "defend")
    {
      Pone.ExecuteCommand(Opt1.substr(0, 6));

      Pone.PDef = Pone.PDef + 1;
    }
    else if(Opt1.substr(0, 9) == "surrender")
    {
      running = false;
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

      Pone.PDeath = false;
    }
    else if(Eone.Health <= 0)
    {
      cout << "You have won, You gained 10 Exp and 10 Credits." << endl;

      Pone.Credits = Pone.Credits + 10;

      Pone.Exp = Pone.Exp + 10;

      if (Pone.Exp >= 100)
      {
        Pone.LvlUp();
      }

      running = false;
    }
  }
}
