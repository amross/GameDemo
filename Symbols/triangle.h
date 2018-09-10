#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "coloredSymbol.h"
#include <QColor>
#include <QPixmap>

class Triangle: public ColoredSymbol
{
public:
    Triangle();
    Triangle(Qt::GlobalColor color);
    virtual ~Triangle() override = default;
    void Draw(QPainter& painter) const override;

    operator QString() const override;
};

#endif // TRIANGLE_H
