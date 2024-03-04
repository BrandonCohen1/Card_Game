#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include "Card.hpp"
#include <random>


template <typename CardType>
class Deck 
{
    public:
        /**
         * @post: Construct a new Deck object
         */
        Deck(){
            std::vector<CardType> cards_{};
        }

        /**
         * @post: Destroy the Deck object 
         */
        ~Deck(){
            cards_.clear();
        }

        /**
         * @post: Add a Card to the Deck
         * @param: const reference to CardType card
         */
        void AddCard(const CardType& card){
            cards_.push_back(card);
        }

        /**
         * @post: Draw a card from the deck
         * @pre: the deck is not empty
         * @return the right hand value of type CardType 
         */
        CardType&& Draw(){
            if(cards_.empty()){
                throw std::runtime_error("The deck is empty so no cards can be drawn.");
            }   

            CardType&& card = std::move(cards_.back());
            card.setDrawn(true);
            cards_.pop_back();
            return std::move(card);
        }

        /**
         * @return if the deck is empty 
         */
        bool IsEmpty() const{
            return cards_.empty();
        }

        /**
         * @post: Shuffle the deck 
         * Create a random number generator using std::mt19937 with seed 2028358904, 
         * to shuffle the deck  
         */
        void Shuffle(){
            std::mt19937 num_rand(2028358904);
            std::shuffle(cards_.begin(), cards_.end(), num_rand);
        }

        /**
         * @return the size of the deck 
         */
        int getSize() const{
            return cards_.size();
        }

        /**
         * @return the vector of cards in the deck 
         */
        std::vector<CardType> getDeck() const{
            return cards_;
        }

    private:
        std::vector<CardType> cards_;
};

#endif
