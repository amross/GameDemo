#include "card.h"
#include <QVector>

#pragma once

class Deck
{
public:
    Deck();
    Card* GetCard();
    void ReturnCard(Card* pCard);
    void Shuffle();
private:
    QVector<Card> mCards;
    int getIdx;
};
