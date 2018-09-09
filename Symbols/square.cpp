#include "square.h"
#include <QPainter>

Square::Square()
{
    qInfo( "Construct Square" );
}

Square *Square::Create() const
{
    qInfo( "Create Square" );
    return new Square();
}

Square *Square::Clone() const
{
    qInfo( "Clone Square" );
    return new Square(*this);
}

void Square::Draw(QPainter& paint)
{
    qInfo( "DRAW Square" );

    QRectF shape(10, 30, 40, 40);
    QBrush brush(Qt::cyan);
    paint.fillRect(shape, brush);

//    QPainterPath path;
//    QPolygonF triangle;
//    triangle.append(QPointF(0,10));
//    triangle.append(QPointF(10,0));
//    triangle.append(QPointF(20,10));
//    triangle.append(QPointF(0,10));
//    path.addPolygon(triangle);

//    QPainter painter(pPix);
//    painter.fillRect(0, 0, 100, 100, Qt::white);
//    painter.setPen(QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
//                        Qt::FlatCap, Qt::MiterJoin));
//    painter.setBrush(QColor(122, 163, 39));

//    painter.drawPath(path);
}

Square::operator QString() const
{
    QString str = "Square: ";
    str.append(QString(this->color));
    return str;
}
