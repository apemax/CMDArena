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
#include "store.h"
using namespace std;

void store::StoreMain()
{
  string SOpt;
  bool runningS = true;

  cout << "Welcome to the store." << endl;

  while(runningS)
  {
    cout << "How can I help you?" << endl;

    cin.ignore();

    getline(cin, SOpt);

    if(SOpt == "buy weapons")
    {
      cout << "buy weapons." << endl;
    }

    else if(SOpt == "sell weapons")
    {
      cout << "sell weapons." << endl;
    }

    else if(SOpt == "buy items")
    {
      cout << "buy items." << endl;
    }

    else if(SOpt == "sell items")
    {
      cout << "sell items." << endl;
    }
    else if(SOpt == "exit")
    {
      runningS == false;
    }
  }
}
