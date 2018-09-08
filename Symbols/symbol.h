#pragma once

#include <QColor>

class Symbol
{
public:
    enum Colour
    {
       RED,
       BLUE,
       GREEN,
       WHITE
    };
    Symbol();
    Symbol(Colour colour);
    virtual ~Symbol(){}
    virtual void Draw() = 0;
    Colour GetColour();

protected:
    QColor qColor;

private:
    Colour colour;

};
