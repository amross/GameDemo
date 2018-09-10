#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "modifier.h"
#include <QPainter>

class Multiply : public Modifier
{
public:
    Multiply(int value);
    ~Multiply() override = default;
    void Draw(QPainter& painter) const override;
    int Apply(int value) const;

    operator QString() const override;

private:
    int factor;
};

#endif // MULTIPLY_H
