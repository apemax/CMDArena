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
#include "characters.h"
using namespace std;

void Arena()
{
  int Opt1;
  string running = "true";

  while (running == "true")
  {
    if(Pone.PDeath == 1)
    {
      running = "false";
    }

    cout << "1) Fight. 2) Store. 3) Inventory. 4) Exit." << endl;

    cin >> Opt1;

    switch (Opt1)
    {
      case 1:
      {
        // Fight

        Fight();

        break;
      }
      case 2:
      {
        // Store

        break;
      }
      case 3:
      {
        // Inventory

        Pone.Inventory();

        break;
      }
      case 4:
      {
        // Exit.

        running = "false";

        break;
      }
    }
  }
}
