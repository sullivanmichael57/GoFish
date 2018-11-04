//
// Created by Michael Sullivan1 on 11/1/18.
//

#include "player.h"
#include "random"
#include "ctime"

Player::Player(){
    myName=" ";
}

void Player::addCard(Card c){
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);

}

Card Player::chooseCardFromHand() const{
    int randIndex = (rand()%getHandSize());
    return myHand[randIndex];
}

bool Player::cardInHand(Card c) const{
    vector<Card>::const_iterator handIter;
    for (handIter = myHand.begin() ; handIter != myHand.end();handIter++){
        if (*handIter == c){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c){

    vector<Card>::const_iterator handIter;
    for (handIter = myHand.begin() ; handIter != myHand.end();handIter++){
        if (*handIter == c){
            myHand.erase(handIter);
        }
    }
    return c;
}

string Player::showHand() const{
    vector<Card>::const_iterator handIter;
    string Hand;
    for (handIter = myHand.begin();handIter != myHand.end(); handIter++){
         Hand+=handIter->toString();
         Hand+=' ';
    }
    return Hand;
}

string Player::showBooks() const{
    vector<Card>::const_iterator bookIter;
    string Book;
    for (bookIter = myBook.begin();bookIter != myBook.end(); bookIter++){
        Book+=bookIter->toString();
        Book+=' ';
    }
    return Book;
}

int Player::getHandSize() const{
    return static_cast<int>(myHand.size());
}

int Player::getBookSize() const{
    return static_cast<int>(myBook.size());
}

bool Player::checkHandForPair(Card &c1, Card &c2){
    vector<Card>::iterator HandIterator1,HandIterator2;
    for (HandIterator1 = myHand.begin();
         HandIterator1!=myHand.end();
         HandIterator1++){
        for (HandIterator2 = HandIterator1+1;
             HandIterator2!=myHand.end();
             HandIterator2++){
            if (HandIterator1->getRank()==HandIterator2->getRank()){
                c1 = *HandIterator1;
                c2 = *HandIterator2;
                return true;
            }
        }
    }
    return false;
}

bool Player::sameRankInHand(Card c) const{
    vector<Card>::const_iterator bookIter;
    for (bookIter = myHand.begin();bookIter != myHand.end(); bookIter++){
        if (bookIter->getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}
