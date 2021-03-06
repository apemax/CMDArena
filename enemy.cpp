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
#include "attack.h"
#include "defend.h"
using namespace std;

void enemy::Setup(int preset)
{
  string FileName = "enemy-presets";
  string PresetLine;
  int i = 1;
  bool runningP = true;

  ifstream PresetFile(FileName, ios::in);

  if(PresetFile.is_open())
  {
    while(runningP == true)
    {
      getline(PresetFile, PresetLine);

      if(PresetLine.substr(0, 6) == "Preset")
      {
        if(stoi(PresetLine.substr(7)) == preset)
        {
          for (; i < 6; i++)
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
              case 5:
              {
                Eone.Slot1 = stoi(PresetLine.substr(6, 12));
                Eone.OwnedCommands[1] = stoi(PresetLine.substr(6, 12));
                Eone.OwnedCommandsCount++;

                break;
              }
              case 6:
              {
                Eone.Slot2 = stoi(PresetLine.substr(6, 12));
                Eone.OwnedCommands[2] = stoi(PresetLine.substr(6, 12));
                Eone.OwnedCommandsCount++;

                break;
              }
            }
          }
          runningP = false;
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

void enemy::ExecuteCommand(string CommandName)
{
  if(CommandName == "attack")
  {
    AttackCommand.Execute();
  }
  else if(CommandName == "defend")
  {
    DefendCommand.Execute(Eone.EDef);

    Eone.EDef = Eone.EDef + 1;
  }
}
