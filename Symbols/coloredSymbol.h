#ifndef COLOURED_H
#define COLOURED_H

#include "symbol.h"
#include <QColor>

class ColoredSymbol : public Symbol
{
public:
    ColoredSymbol();
    ColoredSymbol(const ColoredSymbol&);
    void SetColor(Qt::GlobalColor color);
    Qt::GlobalColor GetColor() const;
    virtual bool operator== (const ColoredSymbol& symbol) const = 0;
protected:
    Qt::GlobalColor color;
};

#endif // COLOURED_H
