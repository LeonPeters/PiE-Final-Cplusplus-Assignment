//
// Created by Leon on 22/11/2020.
//

#ifndef PIE_FINALASSIGNMENT_PLAYERS_H
#define PIE_FINALASSIGNMENT_PLAYERS_H

#include "Deck.h"
#include "genHand.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

class Players{
private:
    //variables
    int numPlayers;
    std::vector<std::string> playersNames;
    std::vector<int> playersSums;
public:
    //set and get functions
    void setNumPlayers(int num);

    void setPlayerName(int playerIndex, std::string playerName);
    std::string getPlayerName(int playerIndex);

    void setPlayerSum(int playerIndex, int currentSum);
    int getPlayerSum(int playerIndex);
};

#endif //PIE_FINALASSIGNMENT_PLAYERS_H
