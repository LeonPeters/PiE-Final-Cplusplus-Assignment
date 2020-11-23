cmake_minimum_required(VERSION 3.17)
project(PiE_FinalAssignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(PiE_FinalAssignment main.cpp Deck.cpp Deck.h genHand.cpp genHand.h blackjackGame.cpp blackjackGame.h Players.cpp Players.h)