#include <iostream>

#include <cstdlib> //for rand() and srand()
#include <ctime> //for time

#include "blackjackGame.h"
#include <sstream>

//To do:
//Ace can be 1 or 11
//Put in user input for when house gets blackjack
//Put in money system
//Add multiple players
//Add split, divide (and other blackjack specific actions)
//  split for when house and player ties


int main() {
    srand((unsigned) time(0)); //setting a seed (so that rand() function has different sequence for every execution)
    bool play = true;

    std::cout << "WELCOME TO BLACKJACK" << std::endl;
    std::cout << std::endl;

    while(play) {
        int x = blackjack(); //x = 1: win, x = 0: loss, x = -1: tie

        std::cout << "\n Do you want to play again? (y/n) " << std::endl;
        char charPlay;
        std::cin >> charPlay;
        while (charPlay != 'n' & charPlay != 'y'){
            std::cerr<<"Wrong input, please enter either y or n: " << std::endl;
            std::cin >> charPlay;
        }
        if (charPlay == 'y') {
            play = true;
        } else if (charPlay == 'n') {
            std::cout<<"Thank you for playing" << std::endl;
            play = false;
        }

    }


//    }


















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
