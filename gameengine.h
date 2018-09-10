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
    void EndGame();

public slots:
    void Start();
    void CardPicked(CardSlot& cardSlot);

signals:
    void ScoreChanged(int score);
    void ClicksChanged(int score);
};
