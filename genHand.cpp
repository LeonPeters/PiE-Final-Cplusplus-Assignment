//
// Created by Leon on 16/11/2020.
//

#include "genHand.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

std::vector<int> genHand::takeCards(char dh, std::vector<int>& currentDeck){ //dh: d=deal, h=hit, deck= the current deck
    std::vector<int> newCards;
    if (dh == 'h') {
        deck = currentDeck;
        int hitCard = hit();
        currentDeck = deck;
        newCards.push_back(hitCard);
    }
    else if (dh == 'd'){
        deck = currentDeck;
        std::vector<int> dealtCards = deal();
        currentDeck = deck;
        newCards = dealtCards;
    }
    return newCards;
}

int genHand::handSum(std::vector<int> currentHand){
    int sum = 0;
    for (int & i : currentHand){
        if (i == 11){
            i = 10;
        }
        else if (i == 12){
            i = 10;
        }
        else if (i == 13){
            i = 10;
        }
        else if (i == 14){
            i = 11;   //ace can be 1 or 11
        }
        sum = sum + i;
    }
    return sum;
}

void genHand::displayHand(std::vector<int> currentHand, bool hidden){ //hidden is optional parameter
    std::stringstream strHand;
    for (int i : currentHand){
        std::string s;
        if (i == 11){
            s = 'B';
            strHand << s << " ";
        }
        else if (i == 12){
            s = 'Q';
            strHand << s << " ";
        }
        else if (i == 13){
            s = 'K';
            strHand << s << " ";
        }
        else if (i == 14){
            s = 'A';
            strHand << s << " ";
        }
        else{
            strHand << i << " ";
        }
    }
    if (!hidden){
        std::cout << strHand.str() << std::endl;
    }
    else if (hidden){
        std::string s;
        s = strHand.get();
        std::cout << s << " " << (char)219 << std::endl;  //(char)219 is a filled in square
    }

};

