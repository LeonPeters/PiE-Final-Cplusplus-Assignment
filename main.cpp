#include <iostream>

#include <vector>

#include <cstdlib> //for rand() and srand()
#include <ctime> //for time

#include <algorithm> //for find()


class Deck {
private:
    std::vector<int> deck = {};
public:
    //functions
    std::vector<int> deal() {
//   https://www.bitdegree.org/learn/random-number-generator-cpp#making-the-random-numbers-different-after-every-execution
//      if rand() and srand() aren't used together, the same sequence will occur everytime its run
//        srand((unsigned) time(0)); //setting a seed (so that rand() function has different sequence for every execution)

        int randomNumber1 = rand() % 13;  //if i use the library they say, it says to use the updated library
        int card1 = deck[randomNumber1];

        std::vector<int>::iterator position1 = std::find(deck.begin(), deck.end(), card1); //declare iterator as the position in deck vector where card1 is
        deck.erase(position1); //removes the dealt card from deck

        int randomNumber2 = rand() % 13;
        int card2 = deck[randomNumber2];

        std::vector<int>::iterator position2 = std::find(deck.begin(), deck.end(), card2);
        deck.erase(position2);

        std::vector<int> cards = {card1, card2};

        return cards; //need to return variables in vector since a function can't return more than 1 variable
    }

    int hit(){
        int randomNumber = rand() % 13;
        int card = deck[randomNumber];
        std::vector<int>::iterator position = std::find(deck.begin(), deck.end(), card);
        deck.erase(position);

        return card;
    }

    void newDeck(){
        deck = { 2,3,4,5,6,7,8,9,10,11,12,13,14,
                 2,3,4,5,6,7,8,9,10,11,12,13,14,
                 2,3,4,5,6,7,8,9,10,11,12,13,14,
                 2,3,4,5,6,7,8,9,10,11,12,13,14 }; //as there are 4 suits (which dont matter in blackjack)
    }

    void displayDeck(){
        for (int i = 0; i < deck.size(); i++){
            std::cout << deck[i] << '\t';
        }
        std::cout<<std::endl;
    }
};


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
