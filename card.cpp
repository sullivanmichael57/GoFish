//
// Written by Kavya Duvedi and Michael Sullivan
//

#include "card.h"
#include <iostream>
#include <string>
#include "stdlib.h"
using namespace std;


// default, ace of spades
Card::Card() {
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}

// return string version e.g. Ac 4h Js
string Card::toString() const {
    return rankString(myRank)+suitString(mySuit);
}

// true if suit same as c
bool Card::sameSuitAs(const Card &c) const {
    return mySuit==c.mySuit;
}

// return rank, 1..13
int Card::getRank() const {
    return myRank;
}

// return "s", "h",...
string Card::suitString(Suit s) const {
    if (mySuit == spades) {
        return "s";
    } else if (mySuit == hearts) {
        return "h";
    } else if (mySuit == diamonds) {
        return "d";
    } else {
        return "c";
    }
}

// return "A", "2", ..."Q"
string Card::rankString(int r) const {
    switch (myRank){
        case 1:
            return "A";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "10";
        case 11:
            return "J";
        case 12:
            return "Q";
        default:
            return "K";
    }
}


bool Card::operator==(const Card &rhs) const {
    return mySuit==rhs.mySuit && myRank == rhs.myRank;
}


bool Card::operator!=(const Card &rhs) const {
    return mySuit!=rhs.mySuit || myRank != rhs.myRank;
}


ostream &operator<<(ostream &out, const Card &c) {
    out << c.toString();
    return out;
}

