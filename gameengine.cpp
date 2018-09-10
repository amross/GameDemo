#include "deck.h"
#include "gameengine.h"
#include <QDebug>


GameEngine::GameEngine()
{
    inProgress = false;
    initialClicks = 20;
    pDeck =  new Deck();
}

GameEngine::~GameEngine()
{

}

void GameEngine::Start()
{
    qInfo() << "Game started";
    score = 0;
    clicksRemaining = initialClicks;
    ClicksChanged(clicksRemaining);
    ScoreChanged(score);
    Card* pCard = pDeck->GetCard();
    pCard->FaceUp();
    pMatcherSlot->AddCard(pCard);
    foreach(CardSlot* pSlot, slotList)
    {
        Card* pCard = pSlot->RemoveCard();
        if(pCard != nullptr)
        {
            pDeck->ReturnCard(pCard);
        }
        pCard = pDeck->GetCard();
        pCard->FaceDown();
        pSlot->AddCard(pCard);
    }
    inProgress = true;
}

void GameEngine::CardPicked(CardSlot& cardSlot)
{
    if(inProgress)
    {
        ClicksChanged(--clicksRemaining);
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

            /*  Select a new card to match  */
            pCard = pMatcherSlot->RemoveCard();
            pDeck->ReturnCard(pCard);
            pCard = pDeck->GetCard();
            pCard->FaceUp();
            pMatcherSlot->AddCard(pCard);
        }
        ScoreChanged(++score);
        if(clicksRemaining <= 0)
        {
            EndGame();
        }
    }
}

void GameEngine::EndGame()
{
    inProgress = false;
    Card* pCard = pMatcherSlot->RemoveCard();
    if(pCard != nullptr)
    {
        pDeck->ReturnCard(pCard);
    }
    foreach(CardSlot* pSlot, slotList)
    {
        Card* pCard = pSlot->RemoveCard();
        if(pCard != nullptr)
        {
            pDeck->ReturnCard(pCard);
        }
    }
}
