#include "card.h"
#include <QDebug>
#include <QPainter>
#include <iostream>     // std::cout
#include <algorithm>    // std::swap
#include <vector>       // std::vector

Card::Card()
{

}

Card::Card(const ColoredSymbol* pFaceSymbol, const ModifySymbol* pModifier)
    : faceUp(false)
{
    desc = "Card: ";
    desc.append(QString(*pFaceSymbol));
    this->pModifier = pModifier;
    this->pFaceSymbol = pFaceSymbol;
}

// Overloading operator for debugging purposes
Card::operator QString() const
{
    return desc;
}

void Card::Flip()
{
    faceUp = !faceUp;
}

void Card::FaceUp()
{
    faceUp = true;
}

void Card::FaceDown()
{
    faceUp = false;
}

bool Card::IsFaceUp()
{
    return faceUp;
}

Qt::GlobalColor Card::GetColor() const
{
    return pFaceSymbol->GetColor();
}

bool Card::IsSameShape(Card &card)
{
    return(typeid(*pFaceSymbol) == typeid(*card.pFaceSymbol));
}

int Card::ApplyModifier(int value) const
{
    return pModifier->Apply(value);
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
