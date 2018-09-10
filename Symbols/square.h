#pragma once

#include "coloredSymbol.h"
#include <QPixmap>

class Square: public ColoredSymbol
{
public:
    Square();
    Square(Qt::GlobalColor color);
    virtual ~Square() override = default;
    void Draw(QPainter& painter) const override;

    operator QString() const override;
};
