#pragma once

#include <Symbols/symbol.h>
#include <Modifiers/modifier.h>
#include <QObject>

class Card
{
public:
    Card();
    Card(const Symbol &faceSymbol, const Modifier &modifier);
    operator QString() const ;

private:
    Symbol *pFaceSymbol;
    Modifier modifier;
    QString desc;
};
