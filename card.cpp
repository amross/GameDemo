#include "card.h"

#include <QDebug>

Card::Card()
{
    qInfo( "Construct Card" );
}

Card::Card(const Symbol &faceSymbol, const Modifier &modifier)
{
    qInfo( "Construct Card from symbol and modifier" );
    desc = "Card: ";
    desc.append(QString(faceSymbol));
    this->modifier = modifier;
    pFaceSymbol = faceSymbol.clone();
}

/**
  * Overloading operator for debugging purposes
  */
Card::operator QString() const
{
    return desc;
}
