#include "deck.h"

#include <Symbols/square.h>
#include <QList>
#include <iostream>
#include <cstdlib>
#include <QTextStream>
#include <QtDebug>

Deck::Deck()
{
    static const QList<Qt::GlobalColor> colourList =
    {
        Qt::red,
        Qt::blue,
        Qt::green,
        Qt::white
    };
    qInfo( "Construct Deck" );
    Square faceSymbol;
    Modifier modifier;
    foreach(Qt::GlobalColor color, colourList )
    {
        faceSymbol.color = color;
        Card *pNewCard = new Card(faceSymbol, modifier);
        qInfo() << *pNewCard;
        mCards.append(*pNewCard);
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
    Card* pCard = &mCards[getIdx];
    pCard->FaceDown();
    --getIdx;
    qInfo() << "Got card from deck" << *pCard;

    return pCard;
}

void Deck::ReturnCard(Card *pCard)
{
    qInfo() << "Return card to deck" << *pCard;
    /*  Nothing to actually do as we never really removed it from the deck  */
}

void Deck::Shuffle()
{
    qInfo() << "Shuffle";
}
