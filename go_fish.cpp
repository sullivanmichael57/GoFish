// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;



// PROTOTYPES for functions used by this demonstration program:
//void dealHand(Deck &d, Player &p, int numCards);


//void bookPairs(Player p);
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


    //cout << p1.getName() << ": " << p1.showHand() << endl;
    //cout << p2.getName() << ": " << p2.showHand() << endl;

    //bookPairs(p1);
    //bookPairs(p2);
    //cout << p1.getName() << ": " << p1.showBooks() << endl;
    //cout << p2.getName() << ": " << p2.showBooks() << endl;


    //This while loop is the big boy, when it is over, the game is over
  
    int turn = 0; 
    while(p1.getBookSize() + p2.getBookSize() < 52 && d.size()>0){
        cout << p1.getName() << ": " << p1.showHand() << endl;
        cout << p2.getName() << ": " << p2.showHand() << endl;
        if(p1.getHandSize() == 0)
        {
             p1.addCard(d.dealCard());

        }
        else
        {
            Card card_chosen = p1.chooseCardFromHand();
            cout << p1.getName() <<" asks- Do you have a " << card_chosen.rankString(card_chosen.getRank()) << "?" << endl;

            if (p2.sameRankInHand(card_chosen)){
                //okay they had at least one of the cards, remove them from p2 and give to p1
                int count = 0; 
                if (p2.cardInHand(Card(card_chosen.getRank(),Card::diamonds))){
                    p1.addCard(p2.removeCardFromHand(Card(card_chosen.getRank(),Card::diamonds)));
                    count++; 

                }
                else if (p2.cardInHand(Card(card_chosen.getRank(),Card::hearts))){

                    p1.addCard(p2.removeCardFromHand(Card(card_chosen.getRank(),Card::hearts)));
                    count++; 

                }
                else if (p2.cardInHand(Card(card_chosen.getRank(),Card::clubs))){
                    p1.addCard(p2.removeCardFromHand(Card(card_chosen.getRank(),Card::clubs)));
                    count++; 

                }
                else if (p2.cardInHand(Card(card_chosen.getRank(),Card::spades))){
                    p1.addCard(p2.removeCardFromHand(Card(card_chosen.getRank(),Card::spades)));
                    count++; 

                }
                cout << p2.getName() <<" says- Yes. I have " << count << " " << " cards of rank " << card_chosen.rankString(card_chosen.getRank()) <<"." << endl;
            }

            else
            {
                cout << p2.getName() <<" says- Go Fish." << endl;
                Card drawn = d.dealCard(); 
                cout <<p1.getName() << " has drawn a " << drawn.toString() << endl;   
                p1.addCard(drawn);
            }
       
            Card c1 = Card(); 
            Card c2 = Card(); 
            while(p1.checkHandForPair(c1,c2))
            {
            p1.checkHandForPair(c1,c2); 
            p1.bookCards(c1,c2);     
            p1.removeCardFromHand(c1);
            p1.removeCardFromHand(c2);
            }
     
            
        }
        cout << p1.getName() << " has " << p1.getBookSize()/2 << " books." << endl;
        cout << p1.getName() << "'s books: " << p1.showBooks() << endl;
        //cout << p1.getName() << ": " << p1.showHand() << endl;
        //cout << p2.getName() << ": " << p2.showHand() << endl;
         

        //change turns
        if(d.size() != 0) 
        {    
            cout << "Next round" << endl;
            cout << p1.getName() << ": " << p1.showHand() << endl;
            cout << p2.getName() << ": " << p2.showHand() << endl;
            if(p2.getHandSize() == 0)
            {
                 p2.addCard(d.dealCard());

            }
            else
            {
                Card card_chosen = p2.chooseCardFromHand();
                cout << p2.getName() <<" asks- Do you have a " << card_chosen.rankString(card_chosen.getRank()) << "?" << endl;

                if (p1.sameRankInHand(card_chosen)){
                    //okay they had at least one of the cards, remove them from p1 and give to p2
                    int count = 0; 
                    if (p1.cardInHand(Card(card_chosen.getRank(),Card::diamonds))){
                        p2.addCard(p1.removeCardFromHand(Card(card_chosen.getRank(),Card::diamonds)));
                        count++; 

                    }
                    else if (p1.cardInHand(Card(card_chosen.getRank(),Card::hearts))){

                        p2.addCard(p1.removeCardFromHand(Card(card_chosen.getRank(),Card::hearts)));
                        count++; 

                    }
                    else if (p1.cardInHand(Card(card_chosen.getRank(),Card::clubs))){
                        p2.addCard(p1.removeCardFromHand(Card(card_chosen.getRank(),Card::clubs)));
                        count++; 

                    }
                    else if (p1.cardInHand(Card(card_chosen.getRank(),Card::spades))){
                        p2.addCard(p1.removeCardFromHand(Card(card_chosen.getRank(),Card::spades)));
                        count++; 

                    }
                    cout << p1.getName() <<" says- Yes. I have " << count << " " << " cards of rank " << card_chosen.rankString(card_chosen.getRank()) <<"." << endl;
                }

                else
                {
                    cout << p1.getName() <<" says- Go Fish." << endl;  
                    Card drawn2 = d.dealCard(); 
                    cout << p2.getName() << " has drawn a " << drawn2.toString() << endl; 
                    p2.addCard(drawn2);
                }
           
                Card c1 = Card(); 
                Card c2 = Card(); 
                while(p2.checkHandForPair(c1,c2))
                {
                p2.checkHandForPair(c1,c2); 
                p2.bookCards(c1,c2);     
                p2.removeCardFromHand(c1);
                p2.removeCardFromHand(c2);
                }
         
                
            }
            cout << p2.getName() << " has " << p2.getBookSize()/2 << " books." << endl;
            cout << p2.getName() << "'s books: " << p2.showBooks() << endl;
            //cout << p2.getName() << ": " << p2.showHand() << endl;
            //cout << p1.getName() << ": " << p1.showHand() << endl;
            cout << "Next round" << endl;
        }

  

    }
    cout << p1.getName() << " has " << p1.getBookSize()/2 << " books." << endl;
    cout << p2.getName() << " has " << p2.getBookSize()/2 << " books." << endl;
    if(p1.getBookSize() > p2.getBookSize())
    {
        cout << p1.getName() << " wins!!!!!" << endl; 
    }
    else if(p1.getBookSize() < p2.getBookSize())
    {
        cout << p2.getName() << " wins!!!!!" << endl; 
    }
    else
    {
        cout << "There is a tie!" << endl; 
    }
    cout << "The Game Has Ended. Wasn't That Fun!" << endl;
    return 0;
}








    
