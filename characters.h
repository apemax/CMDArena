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
#include <fstream>
using namespace std;

#ifndef CHARACTERS_H
#define CHARACTERS_H

class player
{
  int Health = 10;
  public:
    //player();
    void HealthUp(int a);
    void HealthDown(int b);
    int GetHealth();
    void Attack();
    void Defence(int state);
    void Inventory();
    int PDeath = 0;
    string Name;
    int AttackS = 2;
    int AttackTemp = 0;
    int DefenceS = 1;
};

class enemy
{
  int Health;
  public:
    void Setup();
    void HealthUp(int a);
    void HealthDown(int b);
    int GetHealth();
    void Attack();
    void Defence(int state);
    string Name;
    int AttackS;
    int AttackTemp;
    int DefenceS;
};

extern player Pone;
extern enemy Eone;

#endif //CHARACTERS_H
