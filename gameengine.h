#pragma once

#include "card.h"
#include "cardslot.h"

#include <QFrame>

class GameEngine : public QObject
{
    Q_OBJECT
public:
    GameEngine();
    virtual ~GameEngine();

public slots:
    void start();
    void cardPicked(const CardSlot& cardSlot);
};
