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

#include <iostream>
#include <fstream>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class player
{
  public:
    void HealthUp(int a);
    void HealthDown(int b);
    void ExecuteCommand(string CommandName);
    void Inventory();
    void LvlUp();
    bool PDeath = false;
    string Name;
    int Health = 10;
    int Lvl = 1;
    int Exp = 0;
    int Credits = 0;
    int AttackS = 2;
    int AttackTemp = 0;
    int DefenceS = 1;
    int PDef = 1;
    int OwnedCommandsCount = 0;
    int OwnedModsCount = 0;
    string OwnedCommands[10];
    string OwnedMods[10];
    string Slot1;
    string Slot2;
};

extern player Pone;

#endif //PLAYER_H
