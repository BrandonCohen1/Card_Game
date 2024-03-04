#include <iostream>
#include <string>
#include "Card.hpp"
#include "PointCard.hpp"

// Default Constructor
PointCard::PointCard()
{
    setDrawn(false);
    setImageData(nullptr);
    setType(POINT_CARD);
    setInstruction("");
}

// Is PLayable: if not drawn and instruction is int
bool PointCard::isPlayable()
{
    // First Check if it is playable
    if(getDrawn() && std::stoi(getInstruction()) >= 0)
        return true;  
    // Then check if empty
    if(getInstruction().empty())
        return false;
    // Last check if drawn
    if(getDrawn() == true)
        return false;
}

// Print
/**
 * Type: [CardType]
 * Instruction: [Instruction]
 * Card: 
 * [ImageData]
*/
void PointCard::Print() const
{
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;
    
    if(getImageData() != nullptr)
    {
        for(int i = 0; i < 80; ++i)
        {
            std::cout << getImageData()[i] << " " << std::endl;
        }
    }
    else
    {
        std::cout << "No image data" << std::endl;
    }
}