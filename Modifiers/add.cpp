#include "add.h"

#include <QPainter>
#include <QDebug>

Add::Add(int value)
    : addValue(value)
{

}

void Add::Draw(QPainter& painter) const
{
    QFont font = painter.font() ;
    font.setPointSize(50);
    painter.setFont(font);
    int width = painter.device()->width();
    int height = painter.device()->height();
    painter.drawText((width / 2) - 25, (height / 2) + 25, "+");
}

int Add::Apply(int value) const
{
    return value + addValue;
}

Add::operator QString() const
{
    QString str = "Add: ";
    str.append(addValue);
    return str;
}
