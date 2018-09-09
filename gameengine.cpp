#include "deck.h"
#include "gameengine.h"
#include <QDebug>

GameEngine::GameEngine()
    : GameEngine(20)
{
}

GameEngine::GameEngine(int clicksAllowed)
    : initialClicks(clicksAllowed)
{
    Deck *pDeck =  new Deck();
    pDeck->Shuffle();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    Qt::black;
}

GameEngine::~GameEngine()
{

}

void GameEngine::start()
{
    qInfo() << "Game started";
    score = 0;
    clicksRemaining = initialClicks;
    clicksChanged(clicksRemaining);
    scoreChanged(score);
    inProgress = true;
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
