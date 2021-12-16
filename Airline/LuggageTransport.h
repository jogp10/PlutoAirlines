//
// Created by obulamu! on 16/12/2021.
//

#ifndef MAIN_CPP_LUGGAGETRANSPORT_H
#define MAIN_CPP_LUGGAGETRANSPORT_H



#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include "Luggage.h"

using namespace std;

class LuggageTransport{
    vector<stack<stack<Luggage>> Cart;

public:
    void placeInCart();

};

#endif //MAIN_CPP_LUGGAGETRANSPORT_H