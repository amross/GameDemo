#include "deck.h"
#include "gameengine.h"
#include <QDebug>
#include <Symbols/circle.h>
#include <Symbols/square.h>
#include <Symbols/triangle.h>
#include <Modifiers/add.h>
#include <Modifiers/multiply.h>
#include <Modifiers/negate.h>
#include <Modifiers/wildcard.h>
#include <Modifiers/zero.h>

static int EvaluateScore(Card& card1, Card& card2);

GameEngine::GameEngine()
{
    static const QList<const ColoredSymbol *> shapeList =
    {
        new Square(Qt::red),
        new Circle(Qt::red),
        new Triangle(Qt::red),
        new Square(Qt::blue),
        new Circle(Qt::blue),
        new Triangle(Qt::blue),
        new Square(Qt::green),
        new Circle(Qt::green),
        new Triangle(Qt::green),
        new Square(Qt::yellow),
        new Circle(Qt::yellow),
        new Triangle(Qt::yellow)
    };
    static const QList<const ModifySymbol *> modifierList =
    {
        new Add(2),
        new Multiply(5),
        new Negate(),
        new Wildcard(1)
    };
    deck = Deck(shapeList, modifierList);
    inProgress = false;
    initialClicks = 20;
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
    deck.Shuffle();
    Card* pCard = deck.GetCard();
    pCard->FaceUp();
    pMatcherSlot->AddCard(pCard);
    foreach(CardSlot* pSlot, slotList)
    {
        Card* pCard = pSlot->RemoveCard();
        if(pCard != nullptr)
        {
            deck.ReturnCard(pCard);
        }
        pCard = deck.GetCard();
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
        if(pCard->IsFaceUp() == false)
        {
            pCard->Flip();
            cardSlot.AddCard(pCard);
        }
        else
        {
            /*  Evaluate score */
            Card* pMatchCard = pMatcherSlot->RemoveCard();
            score += EvaluateScore(*pMatchCard, *pCard);

            /*  Return both cards back to deck  */
            deck.ReturnCard(pCard);
            deck.ReturnCard(pMatchCard);

            /*  Place new cards  */
            cardSlot.AddCard(deck.GetCard());
            pCard = deck.GetCard();
            pCard->FaceUp();
            pMatcherSlot->AddCard(pCard);
        }
        ScoreChanged(score);
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
        deck.ReturnCard(pCard);
    }
    foreach(CardSlot* pSlot, slotList)
    {
        Card* pCard = pSlot->RemoveCard();
        if(pCard != nullptr)
        {
            deck.ReturnCard(pCard);
        }
    }
}

static int EvaluateScore(Card& cardToMatch, Card& cardPicked)
{
    int score = -2;

    if(cardToMatch.IsSameShape(cardPicked))
    {
        score += 3;
    }
    if(cardToMatch.GetColor() == cardPicked.GetColor())
    {
        score += 3;
    }
    score = cardPicked.ApplyModifier(score);
    qInfo() << "Card match score: " << score;

    return score;
}
