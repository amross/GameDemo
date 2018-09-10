#ifndef COLOURED_H
#define COLOURED_H

#include "symbol.h"
#include <QColor>

class ColoredSymbol : public Symbol
{
public:
    ColoredSymbol();
    void SetColor(Qt::GlobalColor color);
    Qt::GlobalColor GetColor() const;
protected:
    Qt::GlobalColor color;
};

#endif // COLOURED_H
