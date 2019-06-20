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
#include "weapons.h"
using namespace std;

void weapon::Equip(string Slot)
{
  if(Slot.substr(0, 4) == "Left")
  {
    Pone.LeftHand = Name;
  }
  else if(Slot == "Right")
  {
    Pone.RightHand = Name;
  }

  Pone.AttackS = Pone.AttackS + WAttackS;

  Pone.DefenceS = Pone.DefenceS + WDefenceS;

  cout << Name << " Equiped." << endl;
}

void weapon::Unequip(string Slot)
{
  if(Slot.substr(0, 4) == "Left")
  {
    Pone.LeftHand.clear();
  }
  else if(Slot == "Right")
  {
    Pone.RightHand.clear();
  }

  Pone.AttackS = Pone.AttackS - WAttackS;

  Pone.DefenceS = Pone.DefenceS - WDefenceS;

  cout << Name << " Unequipped." << endl;
}

void weapon::AddToPlayer()
{
  Pone.OwnedWeapons[0] = Name;
}

void weapon::RemoveFromPlayer()
{
  Pone.OwnedWeapons[0].clear();
}
