#include "Circle.h"
#include <QPainter>
#include <typeinfo>

Circle::Circle()
    : Circle(Qt::black)
{
    qInfo( "Construct Circle" );
}

Circle::Circle(Qt::GlobalColor color)
{
    qInfo( "Construct Coloured Circle" );
    SetColor(color);
}

void Circle::Draw(QPainter& painter) const
{
    qInfo( "DRAW Circle" );

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

bool Circle::operator==( const ColoredSymbol& obj ) const
{
    bool result = false;
    if((typeid(*this) != typeid(obj))
        && (this->GetColor() == obj.GetColor()))
    {
        result = true;
    }

    return result;
}
