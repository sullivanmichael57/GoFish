cmake_minimum_required(VERSION 3.12)
project(GoFish)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GoFish
        card.cpp
        card.h
        card_demo.cpp
        deck.cpp
        deck.h
        player.cpp
        player.h)
