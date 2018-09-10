#include "Circle.h"
#include <QPainter>
#include <typeinfo>

Circle::Circle()
    : Circle(Qt::black)
{
}

Circle::Circle(Qt::GlobalColor color)
{
    SetColor(color);
}

void Circle::Draw(QPainter& painter) const
{
    QRectF shape(10, 30, 40, 40);
    painter.setBrush(color);
    painter.drawEllipse(shape);
}

Circle::operator QString() const
{
    QString str = "Circle: ";
    str.append(QString(this->color));
    return str;
}
