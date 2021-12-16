//
// Created by john on 14/12/21.
//

#include "Airport.h"

vector<LandTransport> Airport::getSubway() {
    BSTItrIn<LandTransport> bstItrIn(this->bst) ;
    vector<LandTransport> subway;

    while(!bstItrIn.isAtEnd()){
        LandTransport landTransport = bstItrIn.retrieve();
        bstItrIn.advance();
        if(landTransport.transType == SUBWAY) subway.insert(subway.end(), landTransport);
    }

    return subway;
}

vector<LandTransport> Airport::getTrain() {
    BSTItrIn<LandTransport> bstItrIn(this->bst) ;
    vector<LandTransport> train;

    while(!bstItrIn.isAtEnd()){
        LandTransport landTransport = bstItrIn.retrieve();
        bstItrIn.advance();
        if(landTransport.transType == TRAIN) train.insert(train.end(), landTransport);
    }

    return train;
}

vector<LandTransport> Airport::getBus() {
    BSTItrIn<LandTransport> bstItrIn(this->bst) ;
    vector<LandTransport> bus;

    while(!bstItrIn.isAtEnd()){
        LandTransport landTransport = bstItrIn.retrieve();
        bstItrIn.advance();
        if(landTransport.transType == BUS) bus.insert(bus.end(), landTransport);
    }

    return bus;
}

vector<LandTransport> Airport::getByDistance() {
    BSTItrIn<LandTransport> bstItrIn(this->bst) ;
    vector<LandTransport> bydistance;

    while(!bstItrIn.isAtEnd()){
        LandTransport landTransport = bstItrIn.retrieve();
        bstItrIn.advance();
        bydistance.insert(bydistance.end(), landTransport);
    }

    return bydistance;
}

void Airport::insert(const LandTransport& landTransport) {
    bst.insert(landTransport);
}

LandTransport Airport::getMinDistance() {
    return bst.findMin();
}

LandTransport Airport::getMaxDistance() {
    return bst.findMax();
}

LandTransport Airport::getNext() {
    BSTItrLevel<LandTransport> bstItrLevel(bst);

    LandTransport min = bstItrLevel.retrieve();
    while(!bstItrLevel.isAtEnd()){
        LandTransport landTransport = bstItrLevel.retrieve();
        bstItrLevel.advance();
        if(landTransport.next()<min.next()) min = landTransport;
    }
    return min;
}

