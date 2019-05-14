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

void Load()
{
  string LoadFileName;
  string LoadLine;
  int i = 1;

  cout << "Please enter save file name to load: ";

  cin >> LoadFileName;

  ifstream LoadFile(LoadFileName, ios::out);

  cout << "Loading save game file... ";

  if(LoadFile.is_open())
  {
    for(; i < 6; i++)
    {
      getline(LoadFile, LoadLine);

      switch(i)
      {
        case 1:
        {
          Pone.Name = LoadLine;

          break;
        }
        case 2:
        {
          Pone.Health = stoi(LoadLine);

          break;
        }
        case 3:
        {
          Pone.AttackS = stoi(LoadLine);

          break;
        }
        case 4:
        {
          Pone.DefenceS = stoi(LoadLine);

          break;
        }
        case 5:
        {
          Pone.Lvl = stoi(LoadLine);

          break;
        }
        case 6:
        {
          Pone.Exp = stoi(LoadLine);

          break;
        }
      }
    }
    LoadFile.close();
  }
  else
  {
    cout << "Error: Couldn't load save game file." << endl;
  }

  cout << "Loading game..." << endl;
}
