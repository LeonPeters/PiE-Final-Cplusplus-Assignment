//
// Created by Leon on 14/11/2020.
//

#ifndef PIE_FINALASSIGNMENT_DECK_H
#define PIE_FINALASSIGNMENT_DECK_H

#include <vector>

class Deck {
public:   //can only be accessed by other class members of same class and children classes
    std::vector<int> deck = { 2,3,4,5,6,7,8,9,10,11,12,13,14,
                              2,3,4,5,6,7,8,9,10,11,12,13,14,
                              2,3,4,5,6,7,8,9,10,11,12,13,14,
                              2,3,4,5,6,7,8,9,10,11,12,13,14 }; //should this go in private?


    //no default constructor (do I need one?)

    //functions
    std::vector<int> deal();
    int hit();
    void newDeck();
    std::vector<int> returnDeck();
};

#endif //PIE_FINALASSIGNMENT_DECK_H
