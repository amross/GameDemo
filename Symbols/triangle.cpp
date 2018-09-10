#include "triangle.h"
#include <QPainter>
#include <typeinfo>

Triangle::Triangle()
    : Triangle(Qt::black)
{
    qInfo( "Construct Triangle" );
}

Triangle::Triangle(Qt::GlobalColor color)
{
    qInfo( "Construct Coloured Triangle" );
    SetColor(color);
}

void Triangle::Draw(QPainter& painter) const
{
    qInfo( "DRAW Triangle" );

    QPainterPath path;
    QPolygonF triangle;
    int width = painter.device()->width();
    int height = painter.device()->height();
    int symbolWidth = width - 20;
    int symbolHeight = height - 20;
    int triangleBase = qMin(symbolWidth, symbolHeight);
    int center = painter.device()->width() / 2;
    int topPoint = (height / 2) - (triangleBase / 2);
    triangle.append(QPointF(center, topPoint));
    triangle.append(QPointF(10, topPoint + triangleBase));
    triangle.append(QPointF(10 + triangleBase, topPoint + triangleBase));
    triangle.append(QPointF(center, topPoint));
    path.addPolygon(triangle);

    painter.setBrush(color);

    painter.drawPath(path);
}

Triangle::operator QString() const
{
    QString str = "Triangle: ";
    str.append(QString(this->color));
    return str;
}

bool Triangle::operator==( const ColoredSymbol& obj ) const
{
    bool result = false;
    if((typeid(*this) != typeid(obj))
        && (this->GetColor() == obj.GetColor()))
    {
        result = true;
    }

    return result;
}
