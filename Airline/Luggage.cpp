//
// Created by obulamu! on 27/11/2021.
//

#include "Luggage.h"

Luggage::Luggage(int x) {
    numBags = x;
}
bool Luggage::haveLuggage(Luggage luggage) {
    if (luggage.numBags == 0) return false;
    return true;
}