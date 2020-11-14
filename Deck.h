//
// Created by Leon on 14/11/2020.
//

#ifndef PIE_FINALASSIGNMENT_DECK_H
#define PIE_FINALASSIGNMENT_DECK_H

#include <vector>

class Deck {
private:
    std::vector<int> deck = {};
public:
    //no default constructor (do I need one?)

    //functions
    std::vector<int> deal();
    int hit();
    void newDeck();
    void displayDeck();
};


#endif //PIE_FINALASSIGNMENT_DECK_H
