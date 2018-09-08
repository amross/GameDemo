#include <Symbols/symbol.h>

#pragma once

class Modifier
{
public:
    Modifier();
    ~Modifier();
    Modifier(const Modifier& from);
    Symbol& GetSymbol();
};
