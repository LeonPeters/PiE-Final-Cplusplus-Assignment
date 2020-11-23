//
// Created by Leon on 22/11/2020.
//

#include "Players.h"
#include <string>

void Players::setNumPlayers(int num){
        numPlayers = num;
}

void Players::setPlayerName(int playerIndex, std::string playerName){
        playersNames.resize(numPlayers);
        playersNames[playerIndex] = playerName;
}

std::string Players::getPlayerName(int playerIndex){
        std::string playerName;
        playerName = playersNames[playerIndex];
        return playerName;
}

void Players::setPlayerSum(int playerIndex, int currentSum){
        playersSums.resize(numPlayers);
        playersSums[playerIndex] = currentSum;
}

int Players::getPlayerSum(int playerIndex){
        return (playersSums[playerIndex]);
}

