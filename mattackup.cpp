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
// Copywright (C) 2018 - 2021
// Author: Peter (apemax) Wright
// CMDArena

#include "global.h"
#include "player.h"
#include "enemy.h"
#include "attack.h"
#include "mattackup.h"
using namespace std;

MAttackUp::MAttackUp (int m)
{
  string FileName = "mods";
  string FileLine;
  int i = 1;
  bool runningP = true;

  ifstream ModsFile(FileName, ios::in);

  if(ModsFile.is_open())
  {
    while(runningP == true)
    {
      getline(ModsFile, FileLine);

      if(FileLine.substr(0, 3) == "mod")
      {
        if(stoi(FileLine.substr(4)) == m)
        {
          for (; i < 6; i++)
          {
            getline(ModsFile, FileLine);

            switch(i)
            {
              case 1:
              {
                Name = FileLine.substr(5, 9);

                break;
              }
              case 2:
              {
                Id = stoi(FileLine.substr(3, 1));

                break;
              }
              case 3:
              {
                Price = stoi(FileLine.substr(6, 1));

                break;
              }
              case 4:
              {
                Value = stoi(FileLine.substr(6, 1));

                break;
              }
              case 5:
              {
                MAttackUpS = stoi(FileLine.substr(11, 1));

                break;
              }
            }
          }
          runningP = false;
        }
      }
      else if(FileLine.substr(0, 3) == "EOF")
      {
        cout << "End of commands file reached." << endl;

        runningP = false;
      }
    }

  ModsFile.close();
  }
  else
  {
    cout << "Error: Unable to open file." << endl;
  }
}

void MAttackUp::AddToCommand(string Slot)
{
  if(Slot.substr(0, 1) == "1")
  {
    AttackCommand.ModSlot1 = Id;
  }
  else if(Slot.substr(0, 1) == "2")
  {
    AttackCommand.ModSlot2 = Id;
  }

  AttackCommand.CAttackS = AttackCommand.CAttackS + MAttackUpS;

  cout << Name << " Mod added to Command." << endl;
}

void MAttackUp::RemoveFromCommand(string Slot)
{
  if(Slot.substr(0, 1) == "1")
  {
    AttackCommand.ModSlot1 = 0;
  }
  else if(Slot.substr(0, 1) == "2")
  {
    AttackCommand.ModSlot2 = 0;
  }

  AttackCommand.CAttackS = AttackCommand.CAttackS - MAttackUpS;

  cout << Name << " Mod removed from Command." << endl;
}

void MAttackUp::AddToPlayer()
{
  Pone.OwnedMods[Pone.OwnedModsCount] = Name;

  Pone.OwnedModsCount++;
}

void MAttackUp::RemoveFromPlayer()
{
  Pone.OwnedMods[Pone.OwnedModsCount].clear();

  Pone.OwnedModsCount--;
}
