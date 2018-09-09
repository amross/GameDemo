#include "deck.h"
#include "gameengine.h"
#include <QDebug>


GameEngine::GameEngine()
{
    inProgress = false;
    initialClicks = 20;
    pDeck =  new Deck();
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
    Card* pCard = pDeck->GetCard();
    pCard->FaceUp();
    pMatcherSlot->AddCard(pCard);
    foreach(CardSlot* pSlot, slotList)
    {
        pCard = pDeck->GetCard();
        pCard->FaceDown();
        pSlot->AddCard(pCard);
    }
    inProgress = true;
}

void GameEngine::cardPicked(CardSlot& cardSlot)
{
    if(inProgress)
    {
        clicksChanged(--clicksRemaining);
        Card* pCard = cardSlot.RemoveCard();
        qInfo() << "Card Picked: " << *pCard;
        if(pCard->IsFaceUp() == false)
        {
            qInfo() << "Card Flipped: " << *pCard;
            pCard->Flip();
            cardSlot.AddCard(pCard);
        }
        else
        {
            qInfo() << "Card Evaluate: " << *pCard;
            pDeck->ReturnCard(pCard);
            cardSlot.AddCard(pDeck->GetCard());
        }
        scoreChanged(++score);
        if(clicksRemaining <= 0)
        {
            inProgress = false;
        }
    }
}
