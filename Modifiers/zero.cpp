#include "zero.h"
#include <QPainter>
#include <QDebug>

Zero::Zero()
{

}

void Zero::Draw(QPainter& painter) const
{
    QFont font = painter.font() ;
    font.setPointSize(50);
    painter.setFont(font);
    int width = painter.device()->width();
    int height = painter.device()->height();
    painter.drawText((width / 2) - 25, (height / 2) + 25, "0");
}

int Zero::Apply(int value) const
{
    Q_UNUSED(value)
    return 0;
}

Zero::operator QString() const
{
    QString str = "Zero";
    return str;
}
