//
// Created by obulamu! on 16/12/2021.
//

#include <iostream>
#include "LuggageTransport.h"
using namespace std;

void LuggageTransport::placeInCart(vector<Luggage> &totalBags) {
    stack<Luggage> first_stack;
    stack<Luggage> second_stack;
    stack<Luggage> third_stack;

    int total = totalBags.size();
    //carts (c) = 3
    int stacksSize = (total / 3) + 1;

    int it = 0;
    for(int i = 0; i < stacksSize; i++){
        first_stack.push(totalBags[it]);
        it++;
    }
    it = stacksSize;
    for(int i = 0; i < stacksSize; i++){
        second_stack.push(totalBags[it]);
        it++;
    }
    it = (2 *stacksSize);
    while(((2 * stacksSize) + third_stack.size()) != total ){
        third_stack.push(totalBags[it]);
        it++;
    }
    Cart.push(first_stack);
    Cart.push(second_stack);
    Cart.push(third_stack);
}