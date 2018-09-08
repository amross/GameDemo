#pragma once

#include "symbol.h"
#include "colour.h"

class Square: public Symbol
{
public:
    Square();
    Square (Square const &);
    Square* create() const override;
    Square* clone() const override;
    void Draw() override;
    operator QString() const override;

    Colour::Colours colour;

protected:
    QColor qColour;
};
