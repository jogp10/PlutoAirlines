//
// Created by obulamu! on 27/11/2021.
//

#ifndef MAIN_CPP_LUGGAGE_H
#define MAIN_CPP_LUGGAGE_H


class Luggage {
    int numBags;
public:

    Luggage() = default;

    /**
     * obulamu! - numBags = number of Luggage bags
     * @param x
     */
    explicit Luggage(int numBags);

    /**
     * obulamu! - Function to determine the number of bags!
     * @param luggage
     * @return
     */
    bool haveLuggage(Luggage luggage);

    void setnumBags(int numBags);
    int getnumBags();
};


#endif //MAIN_CPP_LUGGAGE_H
