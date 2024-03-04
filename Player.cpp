#include "Hand.hpp" 
#include "Deck.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Player.hpp"

// Default Constructor
Player::Player() {
    score_ = 0;
    opponent_ = nullptr;
    actiondeck_ = nullptr;
    pointdeck_ = nullptr;
}

// Destructor
Player::~Player() {
    // Only delete if actiondeck is only being pointed by you
    if (actiondeck_ == opponent_->getActionDeck())
        actiondeck_ = nullptr;
    else
        delete actiondeck_;

    // Only delete if pointdeck is only being pointed by you
    if (pointdeck_ == opponent_->getPointDeck())
        pointdeck_ = nullptr;
    else
        delete pointdeck_;
}

// Returns hand
const Hand& Player::getHand() const {
    return hand_;
}

// Set hand
void Player::setHand(const Hand& hand) {
    hand_ = hand;
}

// Get Score
int Player::getScore() const {
    return score_;
}

// Set Score
void Player::setScore(const int& score) {
    score_ = score;
}

// PLay Card (4 types of play actions)
void Player::play(ActionCard&& card) {
    // Print what type of action card will be played
    std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;

    // Create regular expression to check what type of play
    std::string instruction = card.getInstruction();
    std::regex play("PLAY (\\d+) CARD(\\(S\\))?");
    std::regex draw("DRAW (\\d+) CARD(\\(S\\))?");

    // Matcher for the expression
    std::smatch match;

    // IF else statements to check what is the correct instruction
    if (std::regex_match(instruction, match, play)) {
        int num = std::stoi(match[1].str());
        for (int i = 0; i < num; ++i) {
            playPointCard();
        }

    } else if (std::regex_match(instruction, match, draw)) {
        int num = std::stoi(match[1].str());
        for (int i = 0; i < num; ++i) {
            drawPointCard();
        }

    } else if (instruction == "SWAP HAND WITH OPPONENT") {
        // Set your hand to the opponent's
        setHand(std::move(opponent_->getHand()));

        // Set the opponent's to your hand
        Hand h = std::move(getHand());
        opponent_->setHand(std::move(h));

    } else if (instruction == "REVERSE HAND") {
        hand_.Reverse();
    }
}

// Draw a point card from pointdeck
void Player::drawPointCard() {
    hand_.addCard(std::move(pointdeck_->Draw()));
}

// Play PointCard from hand
void Player::playPointCard() {
    if (!hand_.isEmpty())
        // Add to score
        score_ += hand_.PlayCard();
}

// Set Opponent
void Player::setOpponent(Player* opponent) {
    opponent_ = opponent;
}

// Return opponent
Player* Player::getOpponent() {
    return opponent_;
}

// Set Action Deck
void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
    actiondeck_ = actiondeck;
}

// Get Action Deck
Deck<ActionCard>* Player::getActionDeck() {
    return actiondeck_;
}

// Set PointDeck
void Player::setPointDeck(Deck<PointCard>* pointdeck) {
    pointdeck_ = pointdeck;
}

// Get PointDeck
Deck<PointCard>* Player::getPointDeck() {
    return pointdeck_;
}
