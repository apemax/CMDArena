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
#include "attack.h"
using namespace std;

void attack::Execute()
{
  Eone.HealthDown(Pone.AttackS);
}

void attack::Equip(string Slot)
{
  if(Slot.substr(7, 1) == "1")
  {
    Pone.Slot1 = Name;
  }
  else if(Slot.substr(7, 1) == "2")
  {
    Pone.Slot2 = Name;
  }

  Pone.AttackS = Pone.AttackS + CAttackS;

  cout << Name << " Equiped." << endl;
}

void attack::Unequip(string Slot)
{
  if(Slot.substr(7, 1) == "1")
  {
    Pone.Slot1.clear();
  }
  else if(Slot.substr(7, 1) == "2")
  {
    Pone.Slot2.clear();
  }

  Pone.AttackS = Pone.AttackS - CAttackS;

  cout << Name << " Unequipped." << endl;
}

void attack::AddToPlayer()
{
  Pone.OwnedCommands[Pone.OwnedCommandsCount] = Name;

  Pone.OwnedCommandsCount++;
}

void attack::RemoveFromPlayer()
{
  Pone.OwnedCommands[Pone.OwnedCommandsCount].clear();

  Pone.OwnedCommandsCount--;
}
