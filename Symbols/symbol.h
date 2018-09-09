#pragma once

#include <QPixmap>
#include <QString>

class Symbol
{
public:
    virtual ~Symbol() = default;
    virtual Symbol* Create() const = 0;
    virtual Symbol* Clone() const = 0;
    virtual void Draw(QPainter& paint) = 0;
    virtual operator QString() const = 0;
};
