#include "gameengine.h"
#include <QDebug>

GameEngine::GameEngine()
    : GameEngine(20)
{
}

GameEngine::GameEngine(int clicksAllowed)
    : initialClicks(clicksAllowed)
{
}

GameEngine::~GameEngine()
{

}

void GameEngine::start()
{
    score = 0;
    clicksRemaining = initialClicks;
    clicksChanged(clicksRemaining);
    scoreChanged(score);
    inProgress = true;
    qInfo() << "Game started";
}

void GameEngine::cardPicked(const CardSlot& cardSlot)
{
    qInfo() << "Card Picked";
    if(inProgress)
    {
        clicksChanged(--clicksRemaining);
        scoreChanged(++score);
        if(clicksRemaining <= 0)
        {
            inProgress = false;
        }
    }
}
