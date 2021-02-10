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
#include "store.h"
#include "attack.h"
#include "defend.h"
#include "mattackup.h"
#include "mdefenceup.h"
using namespace std;

void store::StoreMain()
{
  string SOpt;
  bool runningS = true;

  setup();

  cout << "Welcome to the store." << endl;

  cin.ignore();

  while(runningS)
  {
    cout << "How can I help you?" << endl;

    cout << ">";

    getline(cin, SOpt);

    if(SOpt == "buy commands")
    {
      for(int n = 0; n < 10; n++)
      {
        cout << CommandsInStock[n] << " | ";
      }

      cout << endl;

      cout << "Which do you want to buy?" << endl;

      cout << ">";

      getline(cin, SOpt);

      if(SOpt == "Attack")
      {
        cout << "That will cost: " << AttackCommand.Price << " Credits, Are you sure?" << endl;

        cout << ">";

        getline(cin, SOpt);

        if(SOpt == "yes")
        {
          Pone.Credits = Pone.Credits - AttackCommand.Price;

          Mstore.Credits = Mstore.Credits + AttackCommand.Price;

          AttackCommand.AddToPlayer();

          cout << "Thank you." << endl;
        }
      }
      else if(SOpt == "Defend")
      {
        cout << "That will cost: " << DefendCommand.Price << " Credits, Are you sure?" << endl;

        cout << ">";

        getline(cin, SOpt);

        if(SOpt == "yes")
        {
          Pone.Credits = Pone.Credits - DefendCommand.Price;

          Mstore.Credits = Mstore.Credits + DefendCommand.Price;

          DefendCommand.AddToPlayer();

          cout << "Thank you." << endl;
        }
      }
    }

    else if(SOpt == "sell commands")
    {
      cout << "sell commands." << endl;
    }

    else if(SOpt == "buy Mods")
    {
      for(int n = 0; n < 10; n++)
      {
        cout << ModsInStock[n] << " | ";
      }

      cout << endl;

      cout << "Which do you want to buy?" << endl;

      cout << ">";

      getline(cin, SOpt);

      if(SOpt == "Attack Up")
      {
        cout << "That will cost: " << AttackUpMod.Price << " Credits, Are you sure?" << endl;

        cout << ">";

        getline(cin, SOpt);

        if(SOpt == "yes")
        {
          Pone.Credits = Pone.Credits - AttackUpMod.Price;

          Mstore.Credits = Mstore.Credits + AttackUpMod.Price;

          AttackUpMod.AddToPlayer();

          cout << "Thank you." << endl;
        }
      }
      else if(SOpt == "Defence Up")
      {
        cout << "That will cost: " << DefenceUpMod.Price << " Credits, Are you sure?" << endl;

        cout << ">";

        getline(cin, SOpt);

        if(SOpt == "yes")
        {
          Pone.Credits = Pone.Credits - DefenceUpMod.Price;

          Mstore.Credits = Mstore.Credits + DefenceUpMod.Price;

          DefenceUpMod.AddToPlayer();

          cout << "Thank you." << endl;
        }
      }
    }

    else if(SOpt == "sell Mods")
    {
      cout << "sell Mods." << endl;
    }
    else if(SOpt == "exit")
    {
      runningS = false;
    }
  }
}

void store::setup()
{
  CommandsInStock[0] = AttackCommand.Name;
  CommandsInStock[1] = DefendCommand.Name;

  ModsInStock[0] = AttackUpMod.Name;
  ModsInStock[1] = DefenceUpMod.Name;
}
