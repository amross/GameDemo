#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "modifysymbol.h"
#include <QPainter>

// Multiply modifier multiplies the current score by a given factor
class Multiply : public ModifySymbol
{
public:
    Multiply(int value);
    ~Multiply() override = default;
    void Draw(QPainter& painter) const override;
    int Apply(int value) const override;

    operator QString() const override;

private:
    int factor;
};

#endif // MULTIPLY_H
