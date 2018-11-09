//
// Written by Kavya Duvedi and Michael Sullivan
//

#include "deck.h"
#include <string>
#include "stdlib.h"
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;


//creates deck in order suits going from spades, hearts, diamonds, clubs 
//goes from ace to king within each suit 
Deck::Deck() {
    unsigned int seed = (unsigned) time(0); //initializes random values only once
    srand(seed);
    myIndex = 0;
    int index = 0;

    for (int j = 1; j < 14; j++) {
        Card temp = Card(j, Card::spades);
        myCards[index] = temp;
        index++;
    }
    for (int j = 1; j < 14; j++) {
        Card temp = Card(j, Card::hearts);
        myCards[index] = temp;
        index++;
    }
    for (int j = 1; j < 14; j++) {
        Card temp = Card(j, Card::diamonds);
        myCards[index] = temp;
        index++;
    }
    for (int j = 1; j < 14; j++) {
        Card temp = Card(j, Card::clubs);
        myCards[index] = temp;
        index++;
    }


}

//shuffles the deck of cards 
void Deck::shuffle() {
    int currSize = size();
    if (currSize > 1) {
        for (int i = myIndex; i < 52; i++) {
            long rand1 = (rand() % currSize) + myIndex;
            long rand2 = (rand() % currSize) + myIndex;
            Card temp = Card();
            temp = myCards[rand1];
            myCards[rand1] = myCards[rand2];
            myCards[rand2] = temp;
        }

    }


}

//returns top card on deck
//precondition : the deck has at least one card on it
Card Deck::dealCard() {
    if (myIndex < 52) {
        myIndex++;
        return myCards[myIndex - 1];
    } else {
        //cout << "The Deck is empty" << endl;
        return Card();
    }
}

//returns how many cards are left on deck 
int Deck::size() const {
    return 52 - myIndex;
}