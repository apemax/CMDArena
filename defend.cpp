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
// Copywright (C) 2018 - 2020
// Author: Peter (apemax) Wright
// CMDArena

#include "global.h"
#include "player.h"
#include "enemy.h"
#include "defend.h"
using namespace std;

Defend::Defend (int c)
{
  string FileName = "commands";
  string FileLine;
  int i = 1;
  bool runningP = true;

  ifstream CommandsFile(FileName, ios::in);

  if(CommandsFile.is_open())
  {
    while(runningP == true)
    {
      getline(CommandsFile, FileLine);

      if(FileLine.substr(0, 7) == "command")
      {
        if(stoi(FileLine.substr(8)) == c)
        {
          for (; i < 5; i++)
          {
            getline(CommandsFile, FileLine);

            switch(i)
            {
              case 1:
              {
                DefendCommand.Name = FileLine.substr(5, 6);

                break;
              }
              case 2:
              {
                DefendCommand.CDefendS = stoi(FileLine.substr(9, 1));

                break;
              }
              case 3:
              {
                DefendCommand.Price = stoi(FileLine.substr(6, 1));

                break;
              }
              case 4:
              {
                DefendCommand.Value = stoi(FileLine.substr(6, 1));

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

  CommandsFile.close();
  }
  else
  {
    cout << "Error: Unable to open file." << endl;
  }
}

void Defend::Execute(int state)
{
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

void Defend::Equip(string Slot)
{
  if(Slot.substr(7, 1) == "1")
  {
    Pone.Slot1 = Name;
  }
  else if(Slot.substr(7, 1) == "2")
  {
    Pone.Slot2 = Name;
  }

  Pone.DefenceS = Pone.DefenceS + CDefendS;

  cout << Name << " Equiped." << endl;
}

void Defend::Unequip(string Slot)
{
  if(Slot.substr(7, 1) == "1")
  {
    Pone.Slot1.clear();
  }
  else if(Slot.substr(7, 1) == "2")
  {
    Pone.Slot2.clear();
  }

  Pone.DefenceS = Pone.DefenceS - CDefendS;

  cout << Name << " Unequipped." << endl;
}

void Defend::AddToPlayer()
{
  Pone.OwnedCommands[Pone.OwnedCommandsCount] = Name;

  Pone.OwnedCommandsCount++;
}

void Defend::RemoveFromPlayer()
{
  Pone.OwnedCommands[Pone.OwnedCommandsCount].clear();

  Pone.OwnedCommandsCount++;
}
