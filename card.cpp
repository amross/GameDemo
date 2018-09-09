#include "card.h"
#include <QDebug>
#include <QPainter>

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
    pFaceSymbol = faceSymbol.Clone();
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

void Card::Draw(QPainter& paint)
{
    QRectF shape(5, 5, paint.device()->width() - 10, paint.device()->height() - 10);
    QBrush brush(Qt::white);
    paint.fillRect(shape, brush);
    pFaceSymbol->Draw(paint);
}

// Overloading operator for debugging purposes
Card::operator QString() const
{
    return desc;
}
