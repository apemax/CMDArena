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

void enemy::Setup()
{
  string FileName;
  string PresetLine;
  int i = 1;

  FileName = "preset";

  ifstream PresetFile(FileName, ios::in);

  if(PresetFile.is_open())
  {
    for (; i < 4; i++)
    {
      getline(PresetFile, PresetLine);

      switch(i)
      {
        case 1:
        {
          Eone.Name = PresetLine.substr(5, 8);

          break;
        }
        case 2:
        {
          Eone.Health = stoi(PresetLine.substr(7, 8));

          break;
        }
        case 3:
        {
          Eone.AttackS = stoi(PresetLine.substr(7));

          break;
        }
        case 4:
        {
          Eone.DefenceS = stoi(PresetLine.substr(8));

          break;
        }
      }
    }
  PresetFile.close();
  }
  else
  {
    cout << "Error: Unable to open file." << endl;
  }
}

void enemy::HealthUp(int a)
{
  Health = Health + a;
}

void enemy::HealthDown(int b)
{
  Health = Health - b;
}

void enemy::Attack()
{
  //Attack.

  Pone.HealthDown(Eone.AttackS);
}

void enemy::Defence(int state)
{
  //Defend.

  switch(state)
  {
    case 1:
    {
      //Take DefenceS away from AttackS

      Pone.AttackTemp = Pone.AttackS;

      Pone.AttackS = Pone.AttackS - Eone.DefenceS;

      break;
    }

    case 2:
    {
      //Restore original value of AttackS

      Pone.AttackS = Pone.AttackTemp;

      break;
    }
  }
}
