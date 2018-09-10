#include "card.h"
#include <QVector>

#pragma once

// Deck of cards, cards can be shufled added and removed
// New cards are only generated at creation time, no new cards can be added later
// Any card removed from the deck must be returned to the deck
class Deck
{
public:
    Deck();
    Deck(const QList<const ColoredSymbol *> symbols,
         const QList<const ModifySymbol *> modifiers);
    Deck(const Card &obj);
    Card* GetCard();
    void ReturnCard(Card* pCard);
    void Shuffle();
private:
    QVector<Card> mCards;
    int getIdx;
};
