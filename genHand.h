//
// Created by peter on 16/11/2020.
//

#ifndef PIE_FINALASSIGNMENT_GENHAND_H
#define PIE_FINALASSIGNMENT_GENHAND_H

#include "Deck.h"
#include <vector>


class genHand: protected Deck {
public:
    //CONSTRUCTOR:

    //MEMBER FUNCTIONS:
    std::vector<int> takeCards(char dh, std::vector<int>& currentDeck); //dh: d=deal, h=hit, deck= the current deck
    int handSum(std::vector<int> currentHand);
    void displayHand(std::vector<int> currentHand, bool hidden = false);
};

#endif //PIE_FINALASSIGNMENT_GENHAND_H
