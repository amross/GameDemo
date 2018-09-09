#pragma once

#include "card.h"
#include "cardslot.h"

#include <QFrame>

class GameEngine : public QObject
{
    Q_OBJECT
public:
    GameEngine();
    GameEngine(int clicksAllowed);
    virtual ~GameEngine();

private:
    int initialClicks;
    int clicksRemaining;
    int score;
    int inProgress;

public slots:
    void start();
    void cardPicked(const CardSlot& cardSlot);

signals:
    void scoreChanged(int score);
    void clicksChanged(int score);
};
