#include "card.h"
#include <QVector>

#pragma once

class Deck
{
public:
    Deck();
    Card GetCard();
    void Shuffle();
private:
    QVector<Card> mCards;
};
