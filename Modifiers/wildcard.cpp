#include "wildcard.h"

Wildcard::Wildcard()
{

}

void Wildcard::Draw(QPainter& painter) const
{
    qInfo( "DRAW Plus" );
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
    return 3;
}

Wildcard::operator QString() const
{
    QString str = "Wildcard";
    return str;
}
