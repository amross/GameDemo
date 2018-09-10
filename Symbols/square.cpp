#include "square.h"
#include <QPainter>
#include <typeinfo>

Square::Square()
    : Square(Qt::black)
{
}

Square::Square(Qt::GlobalColor color)
{
    SetColor(color);
}

void Square::Draw(QPainter& painter) const
{
    QRectF shape(10, 30, 40, 40);
    QBrush brush(color);
    painter.fillRect(shape, brush);
}

Square::operator QString() const
{
    QString str = "Square: ";
    str.append(QString(this->color));
    return str;
}
