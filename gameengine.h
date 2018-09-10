#pragma once

#include "card.h"
#include "cardslot.h"
#include "deck.h"

#include <QFrame>

// Handles game
// Performs all actions required to run game
// Manipulates cards based on user input and calculates scores
class GameEngine : public QObject
{
    Q_OBJECT
public:
    GameEngine();
    GameEngine(const Card &obj);
    virtual ~GameEngine();
    CardSlot *pMatcherSlot;
    QList<CardSlot*> slotList;

private:
    Deck deck;
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
