#include "card.h"
#include <QDebug>

Card::Card()
{
    qInfo() << "Construct Card";
}

Card::Card(const Symbol &faceSymbol, const Modifier &modifier)
    : faceUp(false)
{
    qInfo( "Construct Card from symbol and modifier" );
    desc = "Card: ";
    desc.append(QString(faceSymbol));
    this->modifier = modifier;
    pFaceSymbol = faceSymbol.clone();
}

void Card::Flip()
{
    qInfo() << "Flip: " << desc;
    faceUp = !faceUp;
}

void Card::FaceUp()
{
    qInfo() << "Face up: " << desc;
    faceUp = true;
}

void Card::FaceDown()
{
    qInfo() << "Face down: " << desc;
    faceUp = false;
}

bool Card::IsFaceUp()
{
    return faceUp;
}

// Overloading operator for debugging purposes
Card::operator QString() const
{
    return desc;
}
