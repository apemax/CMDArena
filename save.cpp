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

void Save()
{
  string SaveFileName;

  cout << "Please enter save file name: ";

  cout << ">";

  cin >> SaveFileName;

  ofstream SaveFile(SaveFileName, ios::out | ios::app);

  cout << "Saving game...";

  if(SaveFile.is_open())
  {
    SaveFile << Pone.Name << endl;
    SaveFile << Pone.Health << endl;
    SaveFile << Pone.AttackS << endl;
    SaveFile << Pone.DefenceS << endl;
    SaveFile << Pone.Lvl << endl;
    SaveFile << Pone.Exp << endl;
    SaveFile.close();

    cout << " Game saved." << endl;
  }
  else
  {
    cout << " Error: Unable to open save file." << endl;
  }
}
