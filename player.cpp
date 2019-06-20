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
#include "weapons.h"
using namespace std;

void player::HealthUp(int a)
{
  Health = Health + a;
}

void player::HealthDown(int b)
{
  Health = Health - b;
}

void player::Attack()
{
  //Attack.

  Eone.HealthDown(Pone.AttackS);
}

void player::Defence(int state)
{
  //Defend.

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

void player::Inventory()
{
  int Opt1;
  bool running = true;

  while(running == true)
  {
    cout << "1) View Stats. 2) Manage Weapons. 3) Manage Items. 4) Exit." << endl;

    cout << ">";

    cin >> Opt1;

    switch(Opt1)
    {
      case 1:
      {
        cout << "Health: " << Health << " Level: " << Lvl << " Exp: " << Exp << " Credits: " << Credits << endl;
        cout << "Attack: " << AttackS << " Defence: " << DefenceS << endl;
        cout << "Weapons equipped: Left hand: " << LeftHand << " Right hand: " << RightHand << endl;

        break;
      }
      case 2:
      {
        bool runningWM = true;
        string WMOpt;

        cin.ignore();

        while(runningWM == true)
        {
          cout << "1) List. 2) Equip. 3) Unequip. 4) Exit." << endl;

          cout << ">";

          getline(cin, WMOpt);

          cout << endl;

          if(WMOpt.substr(0, 4) == "List")
          {
            for(int n = 0; n < 10; n++)
            {
              cout << OwnedWeapons[n] << " | ";
            }

            cout << endl;
          }
          else if(WMOpt.substr(0, 5) == "Equip")
          {
            //Equip waepons

            if(WMOpt.substr(6, 11) == "Short Sword")
            {
              SSword.Equip(WMOpt.substr(18, 5));
            }
          }
          else if(WMOpt.substr(0, 7) == "Unequip")
          {
            //Unequip weapons.

            if(WMOpt.substr(8, 11) == "Short Sword")
            {
              SSword.Unequip(WMOpt.substr(20, 5));
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
        bool runningIM = true;
        int IMOpt;

        while(runningIM == true)
        {
          cout << "1) List. 2) Use. 3) Equip. 4) Unequip. 5) exit." << endl;

          cout << ">";

          cin >> IMOpt;

          cout << endl;

          switch(IMOpt)
          {
            case 1:
            {
              for(int n = 0; n < 10; n++)
              {
                cout << OwnedItems[n] << " | ";
              }

              cout << endl;

              break;
            }
            case 2:
            {
              break;
            }
            case 3:
            {
              break;
            }
            case 4:
            {
              break;
            }
            case 5:
            {
              runningIM = false;

              break;
            }
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
