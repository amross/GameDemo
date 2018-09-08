#pragma once

#include "symbol.h"

class Square: public Symbol
{
public:
    Square();
    Square (Square const &);
    ~Square () {}
    Square* create() const;
    Square* clone() const;
    void Draw();
};
