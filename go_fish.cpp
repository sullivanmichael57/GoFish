



// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides myfile and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <fstream>

using namespace std;



void bookPairs(Player &p);

int main(){
    cout << "Program Started, Thats a Good Sign!" << endl;
    ofstream myfile;
    myfile.open("outputfile.txt");

    //players and pointers to players are created
    Player pl1 = Player("Michael");
    Player pl2 = Player("Kavya");
    Player *p1 = &pl1;
    Player *p2 = &pl2;
    Deck d;
    d.shuffle();

    //deals cards to players
    for (int i = 0;i<7;i++){
        p1->addCard(d.dealCard());
        p2->addCard(d.dealCard());
    }

    //shows original hands prior to booking cards
    myfile << p1->getName() <<"'s original hand" << ": " << p1->showHand() << endl;
    myfile << p2->getName() <<"'s original hand" << ": " << p2->showHand() << endl;
    myfile << " " << endl;

    //books cards for both players
    bookPairs(*p1);
    bookPairs(*p2);

    //play the game as long as cards haven't been booked
    while(p1->getBookSize() + p2->getBookSize() < 52) {
        myfile << p1->getName() << ": " << p1->showHand() << endl;
        myfile << p2->getName() << ": " << p2->showHand() << endl;

        //if player 1 has no cards in hand they draw a card

        if(p1->getHandSize() != 0) {
            Card card_chosen = p1->chooseCardFromHand();
            myfile << p1->getName() <<" asks- Do you have a " << card_chosen.rankString(card_chosen.getRank()) << "?" << endl;
            if (p2->sameRankInHand(card_chosen)) {
                //player 2 has at least one card of the rank that player 1 is asking about
                int count = 0;
                if (p2->cardInHand(Card(card_chosen.getRank(), Card::diamonds))) {
                    p1->addCard(p2->removeCardFromHand(Card(card_chosen.getRank(), Card::diamonds)));
                    count++;
                } else if (p2->cardInHand(Card(card_chosen.getRank(), Card::hearts))) {

                    p1->addCard(p2->removeCardFromHand(Card(card_chosen.getRank(), Card::hearts)));
                    count++;
                } else if (p2->cardInHand(Card(card_chosen.getRank(), Card::clubs))) {
                    p1->addCard(p2->removeCardFromHand(Card(card_chosen.getRank(), Card::clubs)));
                    count++;
                } else if (p2->cardInHand(Card(card_chosen.getRank(), Card::spades))) {
                    p1->addCard(p2->removeCardFromHand(Card(card_chosen.getRank(), Card::spades)));
                    count++;
                }
                myfile << p2->getName() << " says- Yes. I have " << count << " " << "cards of rank "
                       << card_chosen.rankString(card_chosen.getRank()) << "." << endl;
            }else { // Player 1 must go fish
                myfile << p2->getName() <<" says- Go Fish." << endl;
                if (d.size() != 0){
                    Card drawn = d.dealCard();
                    p1->addCard(drawn);
                    myfile << p1->getName() << " has drawn a " << drawn.toString() << endl;
                }else{
                    myfile << p1->getName() << "tried to draw a card, but the deck is empty! The End is almost near!" << endl;
                }
            }
            bookPairs(*p1);

        }else {
            myfile << p1->getName() << " has no cards." << endl;
            if (d.size() != 0){
                Card drawn = d.dealCard();
                p1->addCard(drawn);
                myfile << p1->getName() << " has drawn a " << drawn.toString() << endl;
            }else{
                myfile << p1->getName() << "tried to draw a card, but the deck is empty! The End is almost near!" << endl;
            }

        }

        //shows player 1's books and how many books player 1 has
        myfile << p1->getName() << " has " << p1->getBookSize()/2 << " books." << endl;
        myfile << p1->getName() << "'s books: " << p1->showBooks() << endl;

        //pointers to player switch so player 1 becomes player 2
        //i.e. the player who is asking for a certain card becomes the player who is asked (and vice versa)
        Player *temp = p1;
        p1 = p2;
        p2 = temp;
        myfile << endl;

        if(p1->getBookSize() + p2->getBookSize() < 52)
            myfile <<"Next Round" << endl;

    }

    //displays the winner depending on who has more books
    myfile << "Game Over!" << endl;
    myfile << p1->getName() << " has " << p1->getBookSize()/2 << " books." << endl;
    myfile << p2->getName() << " has " << p2->getBookSize()/2 << " books." << endl;

    if(p1->getBookSize() > p2->getBookSize())
        myfile << p1->getName() << " wins!!!!!" << endl;
    else if(p1->getBookSize() < p2->getBookSize())
        myfile << p2->getName() << " wins!!!!!" << endl;
    else
        myfile << "There is a tie!" << endl;

    myfile << "The Game Has Ended. Wasn't That Fun!" << endl;
    myfile.close();
    cout << "The Game Ended." << endl;
    return 0;

}


void bookPairs(Player &p){
    Card c1; // books initial pairs
    Card c2;
    while (p.checkHandForPair(c1,c2)){
        p.bookCards(c1,c2);
        p.removeCardFromHand(c1);
        p.removeCardFromHand(c2);
    }
}




