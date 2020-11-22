//
// Created by Leon on 22/11/2020.
//

#include "blackjackGame.h"

#include "Deck.h"
#include "genHand.h"

#include <vector>
#include <iostream>

int blackjack() {
    genHand h;
    Deck d;

    int win;
    int playerSum;
    int houseSum;
    bool playDone = false;


//Deal 2 cards to player and house (should put these into a class, also for more players later)
    std::vector<int> playerCards = h.takeCards('d', d.deck);
    std::vector<int> houseCards = h.takeCards('d', d.deck);

//    for (int i : d.returnDeck()){
//        std::cout << i << " ";
//    }

//Display player and house cards --> edit display function so that it converts 11-14 to card characters
//Hide one card of house
    std::cout << "You are dealt: ";
    h.displayHand(playerCards);

    std::cout << "The house has hand: ";
    h.displayHand(houseCards, true); //optional parameter: hidden = true (to hide second card)

// std::cout << "The house has cards: " << houseCards[0] << " *hidden*" << std::endl;

    playerSum = h.handSum(playerCards);
    houseSum = h.handSum(houseCards);
    if (playerSum == 21) {
        win = true;
        playDone = true;
    } else if (houseSum == 21) {
        win = false;
        playDone = true;
    }


//Ask player to hit or stay until they bust or dont want more cards
    while (!playDone) {
        std::cout << std::endl;
        std::cout << "Would you like to hit or stay? (H/S) " << std::endl;
        char playerDec;
        std::cin >> playerDec;

        if (playerDec == 'H') {
            std::vector<int> playerTemp = h.takeCards('h', d.deck);
//std::cout << "You got card: " << temp[0] << std::endl; //display cards function here
            playerCards.push_back(playerTemp[0]);
            std::cout << "Your hand is: ";
            h.displayHand(playerCards);
            playerSum = h.handSum(playerCards);
            if (playerSum > 21) {
                std::cout << "You busted" << std::endl;
                win = false;
                playDone = true;
            }
            if (playerSum == 21) {
                win = true;
                playDone = true;
            }
        } else if (playerDec == 'S') {
            playerSum = h.handSum(playerCards);
            playDone = true;
        }
//else error message and ask to reenter user input
    }

    if (playerSum < 21 && playerSum > 0) {
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
                win = true;
            }
        }

        if (playerSum > houseSum && playerSum <= 21) {
            win = true;
        } else if (playerSum < houseSum && houseSum <= 21) {
            win = false;
        } else if (playerSum == houseSum) {
            std::cout << "You and the house tie" << std::endl;
            return (-1);
        }
    }

    if (win) {
        std::cout << "YOU WIN BLACKJACK" << std::endl;
    }
    if (!win) {
        std::cout << "SORRY YOU LOSE" << std::endl;
    }

    return ((int) win);
}
