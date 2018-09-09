#pragma once

#include "symbol.h"
#include <QColor>

class Square: public Symbol
{
public:
    Square();
    Square (Square const &);
    Square* create() const override;
    Square* clone() const override;
    void Draw() override;
    operator QString() const override;

    Qt::GlobalColor colour;

protected:
    QColor qColour;
};
