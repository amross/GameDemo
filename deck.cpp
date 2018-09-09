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
    foreach(Qt::GlobalColor colour, colourList )
    {
        faceSymbol.colour = colour;
        Card *pNewCard = new Card(faceSymbol, modifier);
        qInfo() << *pNewCard;
        mCards.append(*pNewCard);
    }
    getIdx = mCards.length() -1;
}

Card Deck::GetCard()
{
    if(getIdx < 0)
    {
        Shuffle();
        getIdx = mCards.length() -1;
    }
    Card card = mCards[getIdx];
    --getIdx;
    qInfo() << "Got card" << card;

    return card;
}

void Deck::Shuffle()
{
    qInfo() << "Shuffle";
}
