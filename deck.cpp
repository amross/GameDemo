#include "deck.h"

#include <Symbols/square.h>

Deck::Deck()
{
    Square faceSymbol;
    Modifier modifier;
    Card newCard(faceSymbol, modifier);
    mCards.append(newCard);
}

Card Deck::GetCard()
{

}
