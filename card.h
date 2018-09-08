#include <Symbols/symbol.h>

#include <Modifiers/modifier.h>

#pragma once

class Card
{
public:
    Card();
    Card(const Symbol &faceSymbol, const Modifier &modifier);

private:
    Symbol *pFaceSymbol;
    Modifier modifier;
};
