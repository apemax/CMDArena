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
#include "defend.h"
#include "mattackup.h"
#include "mdefenceup.h"
using namespace std;

void player::HealthUp(int a)
{
  Health = Health + a;
}

void player::HealthDown(int b)
{
  Health = Health - b;
}

void player::ExecuteCommand(string CommandName)
{
  if(CommandName == "attack")
  {
    AttackCommand.Execute();
  }
  else if(CommandName == "defend")
  {
    DefendCommand.Execute(Pone.PDef);

    Pone.PDef = Pone.PDef + 1;
  }
}

void player::Inventory()
{
  int Opt1;
  bool running = true;

  while(running == true)
  {
    cout << "1) View Stats. 2) Manage Commands. 3) Manage Mods. 4) Exit." << endl;

    cout << ">";

    cin >> Opt1;

    switch(Opt1)
    {
      case 1:
      {
        cout << "Health: " << Health << " Level: " << Lvl << " Exp: " << Exp << " Credits: " << Credits << endl;
        cout << "Attack: " << AttackS << " Defence: " << DefenceS << endl;
        cout << "Commands equipped: Slot 1: " << Slot1 << " Slot 2: " << Slot2 << endl;

        break;
      }
      case 2:
      {
        bool runningWM = true;
        string WMOpt;

        cin.ignore();

        while(runningWM == true)
        {
          cout << "List. Equip <Command name> <Slot number>. Unequip <Command name> <Slot number>. Exit." << endl;

          cout << ">";

          getline(cin, WMOpt);

          cout << endl;

          if(WMOpt.substr(0, 4) == "List")
          {
            cout << "Number of owned commands: " << OwnedCommandsCount << endl;

            for(int n = 0; n < OwnedCommandsCount; n++)
            {
              cout << OwnedCommands[n] << " | ";
            }

            cout << endl;
          }
          else if(WMOpt.substr(0, 5) == "Equip")
          {
            //Equip waepons

            if(WMOpt.substr(6, 6) == "Attack")
            {
              AttackCommand.Equip(WMOpt.substr(6, 8));
            }
            else if(WMOpt.substr(6, 6) == "Defend")
            {
              DefendCommand.Equip(WMOpt.substr(6, 8));
            }
          }
          else if(WMOpt.substr(0, 7) == "Unequip")
          {
            //Unequip weapons.

            if(WMOpt.substr(8, 6) == "Attack")
            {
              AttackCommand.Unequip(WMOpt.substr(8, 6));
            }
            else if(WMOpt.substr(8, 6) == "Defend")
            {
              DefendCommand.Unequip(WMOpt.substr(8, 6));
            }
          }
          else if(WMOpt.substr(0, 4) == "Exit")
          {
            runningWM = false;
          }

        }

        break;
      }
      case 3:
      {
        bool runningMM = true;
        string MMOpt;

        cin.ignore();

        while(runningMM == true)
        {
          cout << "List. Install <Mod name> <Command name> <Slot number>. Uninstall <Mod name> <Command name> <Slot number>. Exit." << endl;

          cout << ">";

          getline(cin, MMOpt);

          cout << endl;

          if(MMOpt.substr(0, 4) == "List")
          {
            cout << "Number of owned Mods: " << OwnedModsCount << endl;

            for(int n = 0; n < OwnedModsCount; n++)
            {
              cout << OwnedMods[n] << " | ";
            }

            cout << endl;
          }
          else if(MMOpt.substr(0, 7) == "Install")
          {
            if(MMOpt.substr(8, 9) == "Attack Up")
            {
              cout << "<Command name> <Slot number>" << endl;

              getline(cin, MMOpt);

              if (MMOpt.substr(0, 6) == "Attack")
              {
                AttackUpMod.AddToCommand(MMOpt.substr(7, 1));
              }
            }
            else if(MMOpt.substr(8, 10) == "Defence Up")
            {
              cout << "<Command name> <Slot number>" << endl;

              getline(cin, MMOpt);

              if (MMOpt.substr(0, 6) == "Defend")
              {
                DefenceUpMod.AddToCommand(MMOpt.substr(7, 1));
              }
            }
          }
          else if(MMOpt.substr(0, 9) == "Uninstall")
          {
            if(MMOpt.substr(8, 9) == "Attack Up")
            {
              cout << "<Command name> <Slot number>" << endl;

              getline(cin, MMOpt);

              if (MMOpt.substr(0, 6) == "Attack")
              {
                AttackUpMod.RemoveFromCommand(MMOpt.substr(7, 1));
              }
            }
            else if(MMOpt.substr(6, 6) == "Defence Up")
            {
              cout << "<Command name> <Slot number>" << endl;

              getline(cin, MMOpt);

              if (MMOpt.substr(0, 6) == "Defend")
              {
                DefenceUpMod.RemoveFromCommand(MMOpt.substr(7, 1));
              }
            }
          }
          else if(MMOpt.substr(0, 4) == "Exit")
          {
            runningMM = false;
          }
        }

        break;
      }
      case 4:
      {
        running = false;

        break;
      }
    }
  }
}

void player::LvlUp()
{
  Lvl = Lvl + 1;

  Health = Health + 10;

  AttackS = AttackS + 1;

  DefenceS = DefenceS + 1;

  Exp = 0;
}
