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

#include <iostream>
using namespace std;

#ifndef WEAPONS_H
#define WEAPONS_H

class weapon
{
  public:
    void Equip();
    void Unequip();
    string name;
    int WAttackS;
    int WDefenceS;
    int Price = 2;
    int Value;
};

extern weapon SSword;

#endif //WEAPONS_H
