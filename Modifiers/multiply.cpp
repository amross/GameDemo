#include "multiply.h"
#include <QPainter>
#include <QDebug>

Multiply::Multiply(int value)
    : factor(value)
{

}

void Multiply::Draw(QPainter& painter) const
{
    qInfo( "DRAW Multiply" );
    QFont font = painter.font() ;
    font.setPointSize(50);
    painter.setFont(font);
    int width = painter.device()->width();
    int height = painter.device()->height();
    painter.drawText((width / 2) - 25, (height / 2) + 25, "X");
}

int Multiply::Apply(int value) const
{
    return value * factor;
}

Multiply::operator QString() const
{
    QString str = "Multiply: ";
    str.append(factor);
    return str;
}
