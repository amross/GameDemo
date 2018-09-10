#pragma once

#include <QPixmap>
#include <QString>

class Symbol
{
public:
    virtual ~Symbol() = default;
    virtual void Draw(QPainter& painter) const = 0;
    virtual operator QString() const = 0;
};
