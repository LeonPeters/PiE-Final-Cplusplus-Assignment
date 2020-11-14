#include <iostream>

#include <cstdlib> //for rand() and srand()
#include <ctime> //for time

#include "Deck.h"



int main() {
    srand((unsigned) time(0)); //setting a seed (so that rand() function has different sequence for every execution)

    Deck d;
    d.newDeck();
    auto cards = d.deal();
    std::cout << cards[0] << '\n' << cards[1] << std::endl;

    auto cards2 = d.deal();
    std::cout << cards2[0] << '\n' << cards2[1] << std::endl;

    auto card = d.hit();
    std::cout << card << std::endl;

    d.displayDeck();
    
    return 0;
}
