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
    virtual ~Symbol(){}
    virtual Symbol* create() const = 0;
    virtual Symbol* clone() const = 0;
    virtual void Draw() = 0;

protected:
    Colour colour;
    QColor qColour;

private:

};
