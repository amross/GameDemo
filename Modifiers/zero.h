#ifndef ZERO_H
#define ZERO_H

#include "modifier.h"
#include <QPainter>

class Zero : public Modifier
{
public:
    Zero();
    ~Zero() override = default;
    void Draw(QPainter& painter) const override;
    int Apply(int value) const;

    operator QString() const override;
};

#endif // ZERO_H
