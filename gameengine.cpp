#include "gameengine.h"
#include <QDebug>

GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{

}

void GameEngine::start()
{

}

void GameEngine::cardPicked(const CardSlot& cardSlot)
{
    qInfo() << "Card Picked";
}
