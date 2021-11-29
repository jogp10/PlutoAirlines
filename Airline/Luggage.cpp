//
// Created by obulamu! on 27/11/2021.
//

#include "Luggage.h"

Luggage::Luggage(int numBags) {
    this->numBags= numBags;
}
void Luggage::setnumBags(int numBags) {
    this->numBags = numBags;
}
int Luggage::getnumBags() {
    return this->numBags;
}
bool Luggage::haveLuggage(Luggage luggage) {
    if (luggage.numBags == 0) return false;
    return true;
}