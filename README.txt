README
This program creates a card game between two players. There are two types of card: PointCard and ActionCard.
These cards are derived from the class Card. The cards will be stored in pointdeck cards and actioncard decks in the template class Deck.
class Hand will hold a vector of PointCards. class Player holds a hand, actiondeck, pointdeck, opponent, and score.
It is important that every card hold a dynamically allocated bitmap but this bitmap does not affect the game.