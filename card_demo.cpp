// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
//#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
//void dealHand(Deck &d, Player &p, int numCards);



/*
int main( )
{
    int numCards = 5;
    Player p1("Joe");
    Player p2("Jane");
    Deck d;  //create a deck of cards
    d.shuffle();
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    return EXIT_SUCCESS;
}
void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
*/

int main(){
    cout << "Hello World" << endl;
    Card c1 = Card();
    cout << c1 << endl;
    c1 = Card(6,Card::hearts);
    Card c2 = Card(7,Card::hearts);
    cout << (c1 == c2) << endl;
    cout << c1.sameSuitAs(c2) << endl;
    cout << c1.getRank() << endl;
    cout << (c1 != c2) << endl;
    cout << c1 << "   " << c2 << endl;
    Deck d;
    int size = d.size(); 
    cout << size <<endl; 
    d.shuffle();
    cout << size <<endl; 
    c1 = d.dealCard(); 
    c2 = d.dealCard(); 
    cout << c1 << "   " << c2 << endl;
    d.shuffle();
    d.shuffle();
    c1 = d.dealCard(); 
    c2 = d.dealCard();
    size = d.size();
    cout << size <<endl; 
    cout << c1 << "   " << c2 << endl;


    return 0;
}