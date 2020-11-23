//
// Created by Leon on 22/11/2020.
//
#include "blackjackGame.h"

#include "Deck.h"
#include "genHand.h"
#include "Players.h"

#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> blackjack() {
    genHand h;
    Deck d;
    Players p;

    int playerSum;
    int houseSum;

    int playerNum;
    std::cout<<"How many people are you playing with: " << std::endl;
    std::cin >> playerNum;
    p.setNumPlayers(playerNum);

    std::cout << "Enter the player names: " << std::endl;
    for (int i = 0; i < playerNum; i++){
        std::string playerName;
        std::cin >> playerName;
        p.setPlayerName(i, playerName);
    }

    //Deal 2 cards to players and house
    std::vector<std::vector<int>> playersCardsMat((playerNum*playerNum), std::vector<int>(playerNum)); //matrix where each row is a new players hand
    //dealing cards to the given number of players
    for (int i = 0; i < playerNum; i++){
        playersCardsMat[i] = h.takeCards('d', d.deck);
    }

    std::vector<int> houseCards = h.takeCards('d', d.deck);
    //std::vector<int> playerCards = h.takeCards('d', d.deck); //REMOVE


    //Display player and house cards
    std::vector<int> initialDealtCards(2);
    for (int i = 0; i < playerNum; i++){
        for (int j = 0; j < 2; j++){
            initialDealtCards[j] = playersCardsMat[i].at(j);
        }
        std::cout << p.getPlayerName(i) << " has hand: ";
        h.displayHand(initialDealtCards);
    }

    std::cout << "\n" << "The house has hand: ";
    h.displayHand(houseCards, true); //optional parameter: hidden = true (to hide second card)

    for (int i = 0; i < playerNum; i++) {
        std::vector<int> playerCards(2);
            for (int j = 0; j < 2; j++) {
                playerCards[j] = playersCardsMat[i].at(j);
            }
            playerSum = h.handSum(playerCards);
            p.setPlayerSum(i,playerSum);
    }

    std::vector<int> playersWins(playerNum, 3); //3: default, 0: turn still in progress, 1: win, -1: loss, 2:tie

    //Calculate initial sum of house and player hands
    houseSum = h.handSum(houseCards);
    for (int i = 0; i < playerNum; i++) {
        playerSum = p.getPlayerSum(i);
        if (playerSum == 21) {
            playersWins[i] = 1;
            std::cout << p.getPlayerName(i) << " got blackjack!";
        }
        else{
            continue;
        }
    }

    //Ask player to hit or stay until they bust or dont want more cards
    while (std::find(playersWins.begin(), playersWins.end(), 3) != playersWins.end()) {
        for (int i = 0; i < playerNum; i++) {
            if (playersWins[i] == 3) {
                std::cout << std::endl;
                std::cout << "Would " << p.getPlayerName(i) << " like to hit or stay? (H/S)" << std::endl;
                std::cout << "Current hand: ";
                h.displayHand(playersCardsMat[i]);
                char playerDec;
                std::cin >> playerDec;
                while (playerDec != 'H' && playerDec != 'S'){
                    std::cerr<<"Wrong input, please enter either H for hit or S for stay: " << std::endl;
                    std::cin >> playerDec;
                }
                if (playerDec == 'H') {
                    std::vector<int> playerTemp = h.takeCards('h', d.deck);
                    playersCardsMat[i].push_back(playerTemp[0]);
                    std::cout << "Your hand is: ";
                    h.displayHand(playersCardsMat[i]);
                    playerSum = h.handSum(playersCardsMat[i]);
                    p.setPlayerSum(i, playerSum);
                    if (playerSum > 21) {
                        std::cout << "You busted" << std::endl;
                        playersWins[i] = -1;
                    }
                    if (playerSum == 21) {
                        playersWins[i] = 1;
                        std::cout << p.getPlayerName(i) << " got blackjack!";
                    }
                }
                else if (playerDec == 'S') {
                    //playerSum = h.handSum(playersCardsMat[i]);
                    playersWins[i] = 0;
                    }
                }
            }
        }


    //if there are only 0s and 1s left (at 21 or stayed below 21)
    if (std::find(playersWins.begin(), playersWins.end(), 0) != playersWins.end() || std::find(playersWins.begin(), playersWins.end(), 1) != playersWins.end()) {
        std::cout << "The house has hand: ";
        h.displayHand(houseCards);
        while (houseSum < 17) {
            std::vector<int> houseTemp = h.takeCards('h', d.deck);
            houseCards.push_back(houseTemp[0]);
            std::cout << "The house has hand: ";
            h.displayHand(houseCards);
            houseSum = h.handSum(houseCards);
            if (houseSum > 21) {
                std::cout << "House busts" << std::endl;
                //if house busts, then sets all players win status to 1 (execpt for already bust players)
                //std::fill(playersWins.begin(), playersWins.end(), 1);
                for (int i = 0; i < playerNum; i++){
                    if (playersWins[i] != -1){
                        playersWins[i] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < playerNum; i++) {
            playerSum = p.getPlayerSum(i);
            if (playerSum > houseSum && playerSum <= 21) {
                playersWins[i] = 1;
            }
            else if (playerSum == houseSum && playerSum <= 21 && houseSum <= 21) {
                playersWins[i] = 2;
            }
            else if (playerSum < houseSum && houseSum <= 21) {
                playersWins[i] = -1;
            }
        }
    }

    return (playersWins);
}
