//
// Created by obulamu! on 27/11/2021.
//

#ifndef MAIN_CPP_LUGGAGE_H
#define MAIN_CPP_LUGGAGE_H


class Luggage {
<<<<<<< HEAD
    int numBags;
public:
    Luggage();
    Luggage(int x);
=======

    int numBags;

public:

    /**
     * obulamu! - numBags = number of Luggage bags
     * @param x
     */

    Luggage(int numBags);

    /**
     * obulamu! - Function to determine the number of bags!
     * @param luggage
     * @return
     */
>>>>>>> 91e02e9c380feb53f427ddf5272eed0e6a976c60

    bool haveLuggage(Luggage luggage);

    void setnumBags(int numBags);
    int getnumBags();
};


#endif //MAIN_CPP_LUGGAGE_H
