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

//player Pone;

int main()
{
  int Opt1;
  string running = "true";

  while (running == "true")
  {
    cout << "1) New Game. 2) Load Game. 3) Options. 4) Exit." << endl;

    cin >> Opt1;

    switch (Opt1)
    {
      case 1:
      {
        // New game

        cout << "Please enter a username:" << endl;

        cout << ">";

        cin >> Pone.Name;

        Arena();

        break;
      }

      case 2:
      {
        // Load game

        Load();

        Arena();

        break;
      }

      case 3:
      {
        // Options

        cout << "Options." << endl;

        break;
      }
      case 4:
      {
        running = "false";

        break;
      }
    }
  }

  return 0;
}
