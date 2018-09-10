#include "wildcard.h"
#include <QDebug>

Wildcard::Wildcard(int value)
    : fixedScore(value)
{

}

void Wildcard::Draw(QPainter& painter) const
{
    QFont font = painter.font() ;
    font.setPointSize(50);
    painter.setFont(font);
    int width = painter.device()->width();
    int height = painter.device()->height();
    painter.drawText((width / 2) - 25, (height / 2) + 25, "*");
}

int Wildcard::Apply(int value) const
{
    Q_UNUSED(value)
    return fixedScore;
}

Wildcard::operator QString() const
{
    QString str = "Wildcard";
    return str;
}
