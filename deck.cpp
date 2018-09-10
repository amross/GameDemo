#include "deck.h"

#include <QList>
#include <iostream>
#include <cstdlib>
#include <QTextStream>
#include <QtDebug>

Deck::Deck()
{

}

Deck::Deck(const QList<const ColoredSymbol *> symbols,
           const QList<const ModifySymbol *> modifiers)
{
    foreach(const ColoredSymbol* pShape, symbols)
    {
        foreach(const ModifySymbol* pModifier, modifiers)
        {
            mCards.append(Card(pShape, pModifier));

        }
    }
    getIdx = mCards.length() -1;
}

Card* Deck::GetCard()
{
    if(getIdx < 0)
    {
        Shuffle();
        getIdx = mCards.length() -1;
    }
    Card *pCard = new Card(mCards[getIdx]);
    pCard->FaceDown();
    --getIdx;

    return pCard;
}

void Deck::ReturnCard(Card *pCard)
{
    /*  Nothing to actually do as we never really removed it from the deck, just delete   */
    if(pCard != nullptr)
    {
        delete pCard;
    }
}
#include <algorithm>
void Deck::Shuffle()
{
    srand(time(nullptr));
    //--- Shuffle elements by randomly exchanging each with one other.
    for (int i = 0; i < mCards.length(); i++)
    {
        int r = rand() % (mCards.length() - 1);  // generate a random position
        mCards.insert(r, mCards.takeAt(i));
    }
}
