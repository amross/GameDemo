#ifndef ZERO_H
#define ZERO_H

#include "modifysymbol.h"
#include <QPainter>

// Zero modifier always gives a zero score regardless of current score
class Zero : public ModifySymbol
{
public:
    Zero();
    ~Zero() override = default;
    void Draw(QPainter& painter) const override;
    int Apply(int value) const override;

    operator QString() const override;
};

#endif // ZERO_H
