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

#include <iostream>
#include <fstream>
using namespace std;

#ifndef STORE_H
#define STORE_H

class store
{
  public:
    void StoreMain();
    void setup();
    string CommandsInStock[10];
    string ModsInStock[10];
    int Credits;
};

extern store Mstore;

#endif //STORE_H
