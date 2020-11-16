#include <iostream>

#include <cstdlib> //for rand() and srand()
#include <ctime> //for time

#include "Deck.h"
#include "genHand.h"

#include <vector>
#include <sstream>

//To do:
//Ace can be 1 or 11
//What happens at tie



int main() {
    srand((unsigned) time(0)); //setting a seed (so that rand() function has different sequence for every execution)

    genHand h;
    Deck d;

    bool win;
    int playerSum;
    int houseSum;
    bool playDone = false;

    std::cout << "WELCOME TO BLACKJACK" << std::endl;
    std::cout << std::endl;

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
    if (playerSum == 21){
        win = true;
        playDone = true;
    }
    else if (houseSum == 21){
        win = false;
        playDone = true;
    }


    //Ask player to hit or stay until they bust or dont want more cards
    while (!playDone) {
        std::cout << std::endl;
        std::cout << "Do you want to hit or stay? (H/S) " << std::endl;
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
            if (playerSum == 21){
                win = true;
                playDone = true;
            }
        }
        else if (playerDec == 'S') {
            playerSum = h.handSum(playerCards);
            playDone = true;
        }
        //else error message and ask to reenter user input
    }

    if (playerSum < 21 && playerSum > 0){
        std::cout << "The house has hand: ";
        h.displayHand(houseCards);
        while (houseSum < 17){
            std::vector<int> houseTemp = h.takeCards('h', d.deck);
            houseCards.push_back(houseTemp[0]);
            std::cout << "The house has hand: ";
            h.displayHand(houseCards);
            houseSum = h.handSum(houseCards);
            if (houseSum > 21){
                std::cout << "House busts" << std::endl;
                win = true;
            }
        }

        if (playerSum > houseSum && playerSum <= 21){
            win = true;
        }
        else if (playerSum < houseSum && houseSum <= 21){
            win = false;
        }
        else if (playerSum == houseSum){
            std::cout << "You and the house tie" << std::endl;
        }
    }

    if (win){
        std::cout << "YOU WIN BLACKJACK" << std::endl;
    }
    if (!win){
        std::cout << "SORRY YOU LOSE" << std::endl;
    }


















//MAIN GAME FILE PSEUDOCODE:
//Deal two cards to player and house

//Hide one card of house

//Display player and house cards

//Ask player to hit or stay until they bust or dont want more cards

//Reveal house's cards

//Deal additional cards to house until they exceed 16

//If the house busts
    //everyone wins who is not busted
//Else
    //for each player that isn't busted, add the total of the cards and compare to house
        //if player total > house total, then player wins
        //else if player total < house total, player loses
        //else if player total = house total, ??????
//Remove everyones cards and get a new deck
    
    return 0;
}
