#include "square.h"
#include <QPainter>
#include <typeinfo>

Square::Square()
    : Square(Qt::black)
{
    qInfo( "Construct Square" );
}

Square::Square(Qt::GlobalColor color)
{
    qInfo( "Construct Coloured Square" );
    SetColor(color);
}

void Square::Draw(QPainter& painter) const
{
    qInfo( "DRAW Square" );

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

bool Square::operator==( const ColoredSymbol& obj ) const
{
    bool result = false;
    if((typeid(*this) != typeid(obj))
        && (this->GetColor() == obj.GetColor()))
    {
        result = true;
    }

    return result;
}
