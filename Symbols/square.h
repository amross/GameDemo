#pragma once

#include "symbol.h"
#include <QColor>
#include <QPixmap>

class Square: public Symbol
{
public:
    Square();
    virtual ~Square() override = default;
    Square* Create() const override;
    Square* Clone() const override;
    void Draw(QPainter& paint) override;
    operator QString() const override;

    Qt::GlobalColor color;

private:
};
