#include <deque>
#include "PointCard.hpp"
#include "Hand.hpp"

// Default Constructor
Hand::Hand() {
    std::deque<PointCard> cards_{};
}

// Destructor
Hand::~Hand() {
    cards_.clear();
}

// Copy Constructor
Hand::Hand(const Hand& other) {
    for (auto itr = other.cards_.cbegin(); itr != other.cards_.cend(); ++itr) {
        // Copy card and then place at the end of the vector
        PointCard cop_card = *itr;
        cards_.insert(cards_.end(), cop_card);
    }
}

// Copy Assignment
Hand& Hand::operator=(const Hand& other) {
    if (this != &other) {
        // Clear the hand before coping from another hand
        this->cards_.clear();  // calls destructor

        for (auto itr = other.cards_.cbegin(); itr != other.cards_.cend(); ++itr) {
            // Copy card and then place at the end of the vector
            PointCard cop_card = *itr;
            this->cards_.insert(cards_.end(), cop_card);
        }
    }
    return *this;
}

// Move Constructor
Hand::Hand(Hand&& other) {
    cards_ = std::move(other.cards_);
}

// Move Assgnment
Hand& Hand::operator=(Hand&& other) {
    if (this != &other) {
        cards_.clear();  // calls destructor
        
        for (auto itr = other.cards_.cbegin(); itr != other.cards_.cend(); ++itr) {
            PointCard cop_card = *itr;
            this->cards_.insert(cards_.end(), cop_card);
        }
    }
    return *this;
}

const std::deque<PointCard>& Hand::getCards() const {
    return cards_;
}

void Hand::addCard(PointCard&& card) {
    // Set to drawn because it is the assumption that it is drawn if added to the hand
    card.setDrawn(true);
    cards_.push_back(std::move(card));
}

bool Hand::isEmpty() const {
    return (cards_.empty());
}

void Hand::Reverse() {
    for (size_t i = 0; i < cards_.size() / 2; ++i) {
        std::swap(cards_[i], cards_[cards_.size() - i - 1]);
    }
}

int Hand::PlayCard() {
    if (isEmpty()) {
        throw std::invalid_argument("\nPlease check the deck: size and instruction");
    }

    PointCard& card = cards_.front();

    // Check if the card is playable
    if (card.isPlayable()) {
        int num = std::stoi(card.getInstruction());
        cards_.pop_front();
        return num;
    } else {
        // If it is not playable, you still have to remove the card
        cards_.pop_front();
        delete card.getImageData();
        return 0;
    }
}
