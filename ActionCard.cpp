#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include "Card.hpp"
#include "ActionCard.hpp"

// Default Constructor
ActionCard::ActionCard()
{
    setDrawn(false);
    setImageData(nullptr);
    setType(ACTION_CARD);
    setInstruction("");
}

// Checks if playble 
bool ActionCard::isPlayable()
{   
    std::regex draw("^DRAW [0-9] CARD\\(S\\)");
    std::regex play("PLAY [0-9] CARD\\(S\\)");

    // Check if instruction has draw, play, reverse, or swap
    if(std::regex_match(getInstruction(), draw) || std::regex_match(getInstruction(), play) || getInstruction() == "REVERSE HAND" || getInstruction() == "SWAP HAND WITH OPPONENT")
        return true; 
    // If not, return false for not playable 
    return false;
}

// Print
/**
 * Type: [CardType]
 * Instruction: [Instruction]
 * Card: 
 * [ImageData]
*/
void ActionCard::Print() const
{
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
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