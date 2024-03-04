#include "Card.hpp"
#include <iostream>
#include <string>

// Default Constructor
Card::Card()
{
    instruction_ = "";
    bitmap_ = nullptr;
    drawn_ = false;
}

// Destructor
Card::~Card()
{
    if(bitmap_ != nullptr)
        delete[] bitmap_;
	bitmap_= nullptr;
}

// Copy Assgnment
Card::Card(const Card& rhs)
{
	instruction_= rhs.instruction_;
	drawn_ = rhs.drawn_;
	cardType_ = rhs.cardType_;

    if(rhs.bitmap_ == nullptr)
    {
        bitmap_ = nullptr;
    }
    else{
        // Allocate of size 80
	    bitmap_ = new int[80];
	    for(int i = 0; i < 80; ++i){
		    bitmap_[i] = rhs.bitmap_[i];
	    }
    }
}

// Copy Assignment
Card& Card::operator=(const Card& rhs)
{
	if(this != &rhs){//if this lhs isn't equal to rhs then:
		instruction_ = rhs.instruction_;
		drawn_ = rhs.drawn_;
		cardType_ = rhs.cardType_;

        // Delete if bitmap was already dynamically allocated
        if(bitmap_ != nullptr){
		    delete[] bitmap_;
            bitmap_ = nullptr;
        }

        if(rhs.bitmap_ == nullptr)
            bitmap_ = nullptr;
        else
        {
		    bitmap_ = new int[80];
		    for(int i = 0; i < 80; ++i){
			    bitmap_[i] = rhs.bitmap_[i];
		    }
        }
	}
	return *this;
}

// Move Constructor
Card::Card(Card&& rhs)
{
	cardType_ = std::move(rhs.cardType_);
	drawn_= std::move(rhs.drawn_);
	instruction_ = std::move(rhs.instruction_);

	bitmap_= rhs.bitmap_;
	rhs.bitmap_ = nullptr;
}

// Move Assignment
Card& Card::operator=(Card&& rhs)
{
	if(this != &rhs){//if lhs not equal to rhs then: 
		cardType_ = std::move(rhs.cardType_);
		drawn_= std::move(rhs.drawn_);
		instruction_ = std::move(rhs.instruction_);

		        // Delete if bitmap was already dynamically allocated
        if(bitmap_ != nullptr){
		    delete[] bitmap_;
            bitmap_= nullptr;
        }
		bitmap_ = rhs.bitmap_;
		rhs.bitmap_ = nullptr;
	}
	return *this;	
}

// Get Type
std::string Card::getType() const 
{
    // Switch statement to check cardtype
    switch ((cardType_))
    {
    case POINT_CARD:
        return "POINT_CARD";
        break;
    case ACTION_CARD:
        return "ACTION_CARD";
        break;
    default:
        break;
    }
}   

// Return Type
void Card::setType(const CardType& type)
{
    cardType_ = type;
}

// Get Instruction
const std::string& Card::getInstruction() const
{
    return instruction_;
}

// Set instruction
void Card::setInstruction(const std::string& instruction)
{
    instruction_ = instruction;
}

// Get bitmap
const int* Card::getImageData() const
{
    return bitmap_;
}

// Set bitmap
void Card::setImageData(int* data)
{
    bitmap_ = data;
}

// Get drawn
bool Card::getDrawn() const
{
    return drawn_;
}

// Set DRAWN
void Card::setDrawn(const bool& drawn)
{
    drawn_ = drawn;
}