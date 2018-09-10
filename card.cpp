#include "card.h"
#include <QDebug>
#include <QPainter>

Card::Card()
{
    qInfo() << "Construct Card";
}

Card::~Card()
{
    qInfo() << "#####Destructor Card";

}

Card::Card(const ColoredSymbol* pFaceSymbol, const Modifier* pModifier)
    : faceUp(false)
{
    qInfo( "Construct Card from symbol and modifier" );
    desc = "Card: ";
    desc.append(QString(*pFaceSymbol));
    this->pModifier = pModifier;
    this->pFaceSymbol = pFaceSymbol;
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
    qInfo() << "##########Face up?: " << faceUp;
    return faceUp;
}

void Card::Draw(QPainter& painter)
{
    int cardWidth = painter.device()->width() - 10;
    int cardHeight = painter.device()->height() - 10;
    QRectF shape(5, 5, cardWidth, cardHeight);
    if(faceUp)
    {
        QBrush brush(faceUp ? Qt::white : Qt::darkGray);
        painter.fillRect(shape, brush);
        pFaceSymbol->Draw(painter);
    }
    else
    {
        QBrush brush(faceUp ? Qt::white : Qt::darkGray);
        painter.fillRect(shape, brush);
        pModifier->Draw(painter);
    }
}

// Overloading operator for debugging purposes
Card::operator QString() const
{
    return desc;
}
