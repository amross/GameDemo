#pragma once

#include <Symbols/symbol.h>
#include <Modifiers/modifier.h>
#include <QObject>

class Card
{
public:
    Card();
    Card(const Symbol &faceSymbol, const Modifier &modifier);
    void Flip();
    void FaceUp();
    void FaceDown();
    bool IsFaceUp();
    operator QString() const ;

private:
    Symbol *pFaceSymbol;
    Modifier modifier;
    bool faceUp;
    QString desc;
};
