#include "coloredSymbol.h"

ColoredSymbol::ColoredSymbol()
{

}

void ColoredSymbol::SetColor(Qt::GlobalColor color)
{
    this->color = color;
}

Qt::GlobalColor ColoredSymbol::GetColor() const
{
    return color;
}
