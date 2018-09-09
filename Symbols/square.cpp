#include "square.h"

Square::Square()
{
    qInfo( "Construct Square" );
}

Square::Square(const Square &)
{
    qInfo( "Copy Square" );
}

Square *Square::create() const
{
    qInfo( "Create Square" );
    return new Square();
}

Square *Square::clone() const
{
    qInfo( "Clone Square" );
    return new Square(*this);
}

void Square::Draw()
{
    qInfo( "DRAW Square" );
}

Square::operator QString() const
{
    QString str = "Square: ";
    str.append(QString(this->color));
    return str;
}
