#include "negate.h"
#include <QPainter>
#include <QDebug>

Negate::Negate()
{

}

void Negate::Draw(QPainter& painter) const
{
    QFont font = painter.font() ;
    font.setPointSize(50);
    painter.setFont(font);
    int width = painter.device()->width();
    int height = painter.device()->height();
    painter.drawText((width / 2) - 25, (height / 2) + 25, "!");
}

int Negate::Apply(int value) const
{
    return -value;
}

Negate::operator QString() const
{
    QString str = "Negate";
    return str;
}
