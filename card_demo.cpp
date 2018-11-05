// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
//#include "player.h"
#include "deck.h"
#include "player.h"
using namespace std;


// PROTOTYPES for functions used by this demonstration program:
//void dealHand(Deck &d, Player &p, int numCards);

void bookPairs(Player p);



int main(){
    cout << "Hello World" << endl;

    Player p1 = Player("Michael");
    Player p2 = Player("Kavya");
    Deck d;
    d.shuffle();

    for (int i = 0;i<7;i++){ // deal cards to players
        p1.addCard(d.dealCard());
        p2.addCard(d.dealCard());
    }
    cout << p1.getName() << ": " << p1.showHand() << endl;
    cout << p2.getName() << ": " << p2.showHand() << endl;

    bookPairs(p1);
    bookPairs(p2);
    cout << p1.getName() << ": " << p1.showBooks() << endl;
    cout << p2.getName() << ": " << p2.showBooks() << endl;


    //This while loop is the big boy, when it is over, the game is over
    while (p1.getBookSize()<28 && p2.getBookSize()<28 && d.size()>0){
        Card card_chosen = p1.chooseCardFromHand();
        if (p2.sameRankInHand(card_chosen)){
            //okay they had at least one of the cards, remove them from p2 and give to p1
            if (p2.cardInHand(Card(card_chosen.getRank(),Card::Suit::diamonds))){
                p1.addCard(p2.removeCardFromHand(Card(card_chosen.getRank(),Card::Suit::diamonds)));

            }else if (p2.cardInHand(Card(card_chosen.getRank(),Card::Suit::hearts))){
                p1.addCard(p2.removeCardFromHand(Card(card_chosen.getRank(),Card::Suit::hearts)));

            }else if (p2.cardInHand(Card(card_chosen.getRank(),Card::Suit::clubs))){
                p1.addCard(p2.removeCardFromHand(Card(card_chosen.getRank(),Card::Suit::clubs)));

            }else if (p2.cardInHand(Card(card_chosen.getRank(),Card::Suit::spades))){
                p1.addCard(p2.removeCardFromHand(Card(card_chosen.getRank(),Card::Suit::spades)));

            }
        }else{
            //go fish
            p1.addCard(d.dealCard());
        }

    }
    cout << "The Game Has Ended. Wasn't That Fun!" << endl;
    return 0;
}


/*
 * first: player books all pairs they have
 * loop {
 * player1 asks player 2 if they have a certain rank
 * if player 2 has any cards of that rank, they are given to player 1
 * if not, player 1 must go fish
 * player 1 checks for pairs again and books them
 * player 2 repeats
 * }
 *
 */

void bookPairs(Player p){
    Card c1; // books initial pairs
    Card c2;
    while (p.checkHandForPair(c1,c2)){
        p.bookCards(c1,c2);
        p.removeCardFromHand(c1);
        p.removeCardFromHand(c2);
    }
}


