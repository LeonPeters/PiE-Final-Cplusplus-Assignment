#include <iostream>
#include <string>

int main() {
    // Generate some output and let the player start
    std::cout << "Welcome to BlaC++kJack!" << std::endl;
    std::cout << "With how many players would you like to play?" << std::endl;
    int playerNum;
    std::cin >> playerNum;
    while (playerNum < 1){
        std::cout << "Please enter a valid number of players: " << std::endl;
        std::cin >> playerNum;
    }
    std::cout << "Game starting with " << playerNum << " players." << std::endl;
    // Give the player(s) and the dealer their cards
    // Ask the player if they want to hit or stand
    std::cout << "Would you like to hit or stand? Please type in your choice:" << std::endl;
    std::string choice;
    std::cin >> choice;
    std::cout << "You chose to " << choice << std::endl;

    // If hit, give player another card
    // If >21, player loses
    // Repeat until stand or >21
    // Give dealer cards until >16
    // Declare winner
};