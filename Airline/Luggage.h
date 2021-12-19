//
// Created by obulamu! on 27/11/2021.
//

#ifndef MAIN_CPP_LUGGAGE_H
#define MAIN_CPP_LUGGAGE_H


class Luggage {
    int numBags{};

public:

    Luggage() = default;

    /**
     *
     * @param numBags number of Bags
     */
    explicit Luggage(int numBags) {this->numBags=numBags;};

    /**
     * Set Luggage's number of bags
     * @param numBags
     */
    void setnumBags(int numBags) {this->numBags=numBags;};

    /**
     * Get Luggage's number of bags
     * @return number of bags
     */
    int getnumBags() const {return numBags;};

    /**
     * Does it have bags
     * @param luggage
     * @return if Luggage has bags
     */
    bool haveLuggage() const {return numBags!=0;};
};


#endif //MAIN_CPP_LUGGAGE_H
