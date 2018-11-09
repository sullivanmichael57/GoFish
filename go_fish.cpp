// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides myfile and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


int main(){
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
    Card c1 = Card(); 
    Card c2 = Card(); 
    while(p1->checkHandForPair(c1,c2))
    {
        p1->checkHandForPair(c1,c2); 
        p1->bookCards(c1,c2);     
        p1->removeCardFromHand(c1);
        p1->removeCardFromHand(c2);
    }

    while(p2->checkHandForPair(c1,c2))
    {
        p2->checkHandForPair(c1,c2); 
        p2->bookCards(c1,c2);     
        p2->removeCardFromHand(c1);
        p2->removeCardFromHand(c2);
    }

    //This while loop is the big boy, when it is over, the game is over
    while(p1->getBookSize() + p2->getBookSize() < 52) {
        myfile << p1->getName() << ": " << p1->showHand() << endl;
        myfile << p2->getName() << ": " << p2->showHand() << endl;

        //if player 1 has no cards in hand they draw a card 
        if(p1->getHandSize() == 0)
        {
             p1->addCard(d.dealCard());

        }

        else
        {
            Card card_chosen = p1->chooseCardFromHand();
            myfile << p1->getName() <<" asks- Do you have a " << card_chosen.rankString(card_chosen.getRank()) << "?" << endl;

            if (p2->sameRankInHand(card_chosen)){
                //player 2 has at least one card of the rank that player 1 is asking about 

                int count = 0; 
                if (p2->cardInHand(Card(card_chosen.getRank(),Card::diamonds))){
                    p1->addCard(p2->removeCardFromHand(Card(card_chosen.getRank(),Card::diamonds)));
                    count++; 

                }
                else if (p2->cardInHand(Card(card_chosen.getRank(),Card::hearts))){

                    p1->addCard(p2->removeCardFromHand(Card(card_chosen.getRank(),Card::hearts)));
                    count++; 

                }
                else if (p2->cardInHand(Card(card_chosen.getRank(),Card::clubs))){
                    p1->addCard(p2->removeCardFromHand(Card(card_chosen.getRank(),Card::clubs)));
                    count++; 

                }
                else if (p2->cardInHand(Card(card_chosen.getRank(),Card::spades))){
                    p1->addCard(p2->removeCardFromHand(Card(card_chosen.getRank(),Card::spades)));
                    count++; 

                }
                myfile << p2->getName() <<" says- Yes. I have " << count << " " << "cards of rank " << card_chosen.rankString(card_chosen.getRank()) <<"." << endl;
            }

            else
            {
                //player 2 does not have any cards of that rank so player 1 draws a card from the deck 
                myfile << p2->getName() <<" says- Go Fish." << endl;
                Card drawn = d.dealCard(); 
                myfile <<p1->getName() << " has drawn a " << drawn.toString() << endl;   
                p1->addCard(drawn);
            }

            
            //player 1 checks for books and books any pairs 
            Card c1 = Card(); 
            Card c2 = Card(); 
            while(p1->checkHandForPair(c1,c2))
            {
                p1->checkHandForPair(c1,c2); 
                p1->bookCards(c1,c2);     
                p1->removeCardFromHand(c1);
                p1->removeCardFromHand(c2);
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
        myfile << " " << endl;

        if(p1->getBookSize() + p2->getBookSize() < 52)
            myfile <<"Next Round" << endl;        

    }

    //displays the winner depending on who has more books 
    myfile << "Game Over!" << endl; 
    myfile << p1->getName() << " has " << p1->getBookSize()/2 << " books." << endl;
    myfile << p2->getName() << " has " << p2->getBookSize()/2 << " books." << endl;

    if(p1->getBookSize() > p2->getBookSize())
    {
        myfile << p1->getName() << " wins!!!!!" << endl; 
    }
    else if(p1->getBookSize() < p2->getBookSize())
    {
        myfile << p2->getName() << " wins!!!!!" << endl; 
    }
    else
    {
        myfile << "There is a tie!" << endl; 
    }

    myfile << "The Game Has Ended. Wasn't That Fun!" << endl;
    myfile.close(); 
    return 0;
}








    
