#pragma once

#include "card.h"
#include "cardslot.h"
#include "deck.h"

#include <QFrame>

class GameEngine : public QObject
{
    Q_OBJECT
public:
    GameEngine();
    virtual ~GameEngine();
    CardSlot *pMatcherSlot;
    QList<CardSlot*> slotList;

private:
    Deck *pDeck;
    int initialClicks;
    int clicksRemaining;
    int score;
    int inProgress;

public slots:
    void start();
    void cardPicked(CardSlot& cardSlot);

signals:
    void scoreChanged(int score);
    void clicksChanged(int score);
};
