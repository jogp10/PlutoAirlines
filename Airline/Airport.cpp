//
// Created by john on 14/12/21.
//

#include "Airport.h"

vector<LandTransport> Airport::getSubway() const{
    BSTItrIn<LandTransport> bstItrIn(this->bst) ;
    vector<LandTransport> subway;

    while(!bstItrIn.isAtEnd()){
        LandTransport landTransport = bstItrIn.retrieve();
        bstItrIn.advance();
        if(landTransport.getTransType() == SUBWAY) subway.insert(subway.end(), landTransport);
    }

    return subway;
}


vector<LandTransport> Airport::getTrain() const{
    BSTItrIn<LandTransport> bstItrIn(this->bst) ;
    vector<LandTransport> train;

    while(!bstItrIn.isAtEnd()){
        LandTransport landTransport = bstItrIn.retrieve();
        bstItrIn.advance();
        if(landTransport.getTransType() == TRAIN) train.insert(train.end(), landTransport);
    }

    return train;
}


vector<LandTransport> Airport::getBus() const{
    BSTItrIn<LandTransport> bstItrIn(this->bst) ;
    vector<LandTransport> bus;

    while(!bstItrIn.isAtEnd()){
        LandTransport landTransport = bstItrIn.retrieve();
        bstItrIn.advance();
        if(landTransport.getTransType() == BUS) bus.insert(bus.end(), landTransport);
    }

    return bus;
}

vector<LandTransport> Airport::getByDistance() const{
    BSTItrIn<LandTransport> bstItrIn(this->bst) ;
    vector<LandTransport> bydistance;

    while(!bstItrIn.isAtEnd()){
        LandTransport landTransport = bstItrIn.retrieve();
        bstItrIn.advance();
        bydistance.insert(bydistance.end(), landTransport);
    }

    return bydistance;
}


LandTransport Airport::getNext() const{
    BSTItrLevel<LandTransport> bstItrLevel(bst);

    LandTransport min = bstItrLevel.retrieve();
    while(!bstItrLevel.isAtEnd()){
        LandTransport landTransport = bstItrLevel.retrieve();
        bstItrLevel.advance();
        if(landTransport.next()<min.next()) min = landTransport;
    }
    return min;
}


void Airport::insert(const LandTransport& landTransport) {
    bst.insert(landTransport);
}
