// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Hand.hpp"
#include "Deck.hpp"
#include "Player.hpp"


int main()
{
    int arr[80] = {
    23, 45, 67, 123, 56, 78, 200, 34, 55, 88, 100, 32, 12, 165, 78, 90,
    135, 150, 223, 99, 44, 77, 32, 210, 88, 60, 45, 75, 150, 200, 12,
    34, 98, 32, 65, 70, 250, 155, 95, 23, 47, 120, 189, 67, 23, 32, 112,
    45, 77, 89, 200, 34, 55, 88, 100, 32, 12, 165, 78, 90, 135, 150, 223,
    99, 44, 77, 32, 210, 88, 60, 45, 75, 150, 200, 12, 34, 98, 32, 65, 70,
    };
    int* bit = arr;

    
    PointCard a;
    PointCard b;
    

    a.setInstruction("154");
    a.setDrawn(false);
    a.setImageData(bit);
    b.setInstruction("9");
    b.setDrawn(false);
    b.setImageData(bit);

    //Student s1("John", 10);
    //Student s2 = s1; //copy constructor
    //Student s3;
    //s3 = s1; // copy assignment

    //Student s4("Jane", 12);
    //Student s5 = std::move(s4); // move constructor
    //Student s6;
    //s6 = std::move(s5); //move assignment

/*
    //Copy Constructor
    std::cout << "\nCard a before using copy constructor:" << std::endl;
    a.Print();

    PointCard c = a;
    std::cout << "\nCard a after being copied to Card c using copy constructor\n";
    a.Print();
    std::cout << "\nCard c created by Card a using copy constructor" << std::endl;
    c.Print();

    // Copy Constructor with empty PointCards
    std::cout << "\nCreate empty PointCard: card d";
    PointCard d;

    std::cout << "\nCard d created empty" << std::endl;
    d.Print();
    std::cout << "\nCard e created by Card d using copy constructor\n" << std::endl;
    PointCard e = d;

    std::cout << "Card d after d = e (Copy Constructor)" << std::endl;
    d.Print();
    std::cout << "\nCard e after Copy Constructor\n";
    e.Print();

    d.setInstruction("10");
    d.setDrawn(true);
    d.setImageData(bit);

    std::cout << "\nCard d receives members (no longer empty). See if card d and card e changed\n";
    std::cout << "\nCard d\n";
    d.Print();
    std::cout << "\nCard e\n";
    e.Print();

    std::cout << "\nFINISHED!!!\n";
*/

    // Move Constructor
    std::cout << "\nCard a before using move constructor:" << std::endl;
    a.Print();


    PointCard c;
    c = std::move(a);
    std::cout << "\nCard c created by Card a using move constructor" << std::endl;
    c.Print();
    std::cout << "\nCard a after being copied to Card c using move constructor\n";
    a.Print();


    // Copy Constructor with empty PointCards
    PointCard d;

    std::cout << "\nCard d created empty" << std::endl;
    d.Print();
    std::cout << "\nCard e created by Card d using move constructor\n" << std::endl;
    PointCard e;
    e = std::move(d);

    std::cout << "Card d after d = e (Move Constructor)" << std::endl;
    d.Print();
    std::cout << "\nCard e after Move Constructor\n";
    e.Print();

    d.setInstruction("10");
    d.setDrawn(false);
    d.setImageData(bit);

    std::cout << "\nCard d receives members (no longer empty). See if card d and card e changed\n";
    std::cout << "\nCard d\n";
    d.Print();
    std::cout << "\nCard e\n";
    e.Print();

    std::cout << "\nFINISHED!!!\n";
    std::cout << "-------------------------------" << std::endl;

///////////////////////////////////////////////////////////// isPlayable
    std::cout << "Card d should be playable. Is it PLayable? " << d.isPlayable() << std::endl;
    std::cout << "Card e is empty so it is not playable. Is it Playable? " << e.isPlayable() << std::endl << std::endl;
/*
    PointCard* ptr_d = new PointCard;
    ptr_d->setImageData(arr);
    ptr_d->Print();
    delete ptr_d;
    d.Print();
    std::cout << std::endl << std::endl;
*/

///////////////////// ActionCard

    ActionCard mo;
    mo.setDrawn(true);
    mo.setImageData(arr);
    mo.setInstruction("PLAY 10 CARDS");
    mo.Print();
    //mo.isPlayable();

///////////////////// WORKING WITH DECK
/*
    Deck<PointCard> pdeck;
    Deck<PointCard>* ptr_Deck;
    ptr_Deck = &pdeck;

    std::cout << "\nBefore adding cards to Deck<PointCard>, is it Empty: " << ptr_Deck->IsEmpty() << std::endl;
    std::cout << "What is the size of the Deck<PointCard> empty: " << ptr_Deck->getSize() << std::endl; 

    ptr_Deck->AddCard(a);
    std::cout << "add A" << std::endl;
    ptr_Deck->AddCard(b);
    std::cout << "add B" << std::endl;
 
    ptr_Deck->AddCard(c);   
    std::cout << "add c" << std::endl;


    ptr_Deck->AddCard(e);
    std::cout << "add E" << std::endl;



    std::cout << "\nAfter adding 4 cards to Deck<PointCard>, is it Empty: " << ptr_Deck->IsEmpty() << std::endl;
    std::cout << "What is the size of the Deck<PointCard> empty: " << ptr_Deck->getSize() << std::endl; 



    for(int i=0; i<ptr_Deck->getSize(); i++){
        ptr_Deck->getDeck()[i].Print();
    }
    std::cout << "\nAbove are the 4 cards fnally being deleted\n\n";

    ptr_Deck->Shuffle();
    for(int i=0; i<ptr_Deck->getSize(); i++){
        ptr_Deck->getDeck()[i].Print();
    }

    std::cout << "AFTER SHFFULING, BELOW IS DRAWING" << std::endl << std::endl;

    PointCard drawn_1 = ptr_Deck->Draw();
    drawn_1.Print();
    PointCard drawn_2 = ptr_Deck->Draw();
    drawn_2.Print();
    std::cout << "\n\nWhat is the size of the deck?: " << ptr_Deck->getSize() << std::endl;


    Deck<ActionCard> adeck;
    Deck<ActionCard>* ptr_Adeck;
*/



    
    std::cout << "FINSIHED" << std::endl;



    
    
    
// [9, 10]
    Hand hand;
    a = d;

    std::cout << "First card that enters the hand is added: card a and drawn is " << a.getDrawn() << std::endl << std::endl;
    hand.addCard(std::move(a));
    std::cout << "Second card that enters the hand is added: card b and drawn is " << b.getDrawn() << std::endl << std::endl;
    hand.addCard(std::move(b));

    std::cout << "Card a:" << std::endl;
    a.Print();
    std::cout << "\nCard a drawn is " << a.getDrawn() << std::endl; 
    std::cout << "Card b:" << std::endl;
    
    b.Print();
    std::cout << "\nCard b drawn is " << b.getDrawn() << std::endl; 


    for(int i=0; i<2; i++){
        std::cout << "Drawn is " << hand.getCards()[i].getDrawn() << std::endl;
    }
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "First card that entered the hand is played: card a" << std::endl << std::endl;
    int num = hand.PlayCard();


    std::cout << std::endl << "HAND IsEmpty: " << hand.isEmpty() << " and Number is " << num << std::endl;

    // Problem when I move card b and then add b to hand and playCard
    // the code ends. This is probably from hand.PlayCard() calling PointCard.isPlayable;
    num = hand.PlayCard();
    std::cout << std::endl << "HAND IsEmpty: " << hand.isEmpty() << " and Number is " << num << std::endl;


    //Player p1;
    //p1.setHand(hand);

    return 0;
}
