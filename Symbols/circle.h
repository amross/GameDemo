#ifndef CIRCLE_H
#define CIRCLE_H

#include "coloredSymbol.h"
#include <QColor>
#include <QPixmap>

class Circle: public ColoredSymbol
{
public:
    Circle();
    Circle(Qt::GlobalColor color);
    virtual ~Circle() override = default;
    void Draw(QPainter& painter) const override;

    operator QString() const override;
};

#endif // CIRCLE_H
