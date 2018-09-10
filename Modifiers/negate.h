#ifndef NEGATE_H
#define NEGATE_H

#include "modifier.h"
#include <QPainter>

class Negate : public Modifier
{
public:
    Negate();
    ~Negate() override = default;
    void Draw(QPainter& painter) const override;
    int Apply(int value) const;

    operator QString() const override;
};

#endif // NEGATE_H
