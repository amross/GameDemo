#include "deck.h"

#include <Symbols/Circle.h>
#include <Symbols/square.h>
#include <Symbols/triangle.h>
#include <QList>
#include <iostream>
#include <cstdlib>
#include <QTextStream>
#include <QtDebug>
#include <Modifiers/add.h>
#include <Modifiers/multiply.h>
#include <Modifiers/negate.h>
#include <Modifiers/wildcard.h>
#include <Modifiers/zero.h>

Deck::Deck()
{
    static const QList<ColoredSymbol *> shapeList =
    {
        new Square(Qt::red),
        new Circle(Qt::red),
        new Triangle(Qt::red),
        new Square(Qt::blue),
        new Circle(Qt::blue),
        new Triangle(Qt::blue),
        new Square(Qt::green),
        new Circle(Qt::green),
        new Triangle(Qt::green),
        new Square(Qt::yellow),
        new Circle(Qt::yellow),
        new Triangle(Qt::yellow)
    };
    static const QList<Modifier *> modifierList =
    {
        new Add(2),
        new Multiply(2),
        new Negate(),
        new Wildcard(),
        new Zero(),
    };
    qInfo( "Construct Deck" );
    foreach(ColoredSymbol* pShape, shapeList)
    {
        foreach(Modifier* pModifier, modifierList)
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
    qInfo() << "Got card from deck" << *pCard;

    return pCard;
}

void Deck::ReturnCard(Card *pCard)
{
    qInfo() << "Return card to deck" << *pCard;
    /*  Nothing to actually do as we never really removed it from the deck,just delete   */
    if(pCard != nullptr)
    {
        delete pCard;
    }
}

void Deck::Shuffle()
{
    qInfo() << "Shuffle";
}
