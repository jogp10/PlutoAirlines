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
    stack<stack<Luggage>> Cart;

public:

    LuggageTransport() = default;

    /**
     * Transport of a Airport's Luggage to the Airplane with a Cart
     * @param totalBags
     */
    void placeInCart(vector<Luggage>&totalBags);
};

#endif //MAIN_CPP_LUGGAGETRANSPORT_H