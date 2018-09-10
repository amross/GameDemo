#ifndef NEGATE_H
#define NEGATE_H

#include "modifysymbol.h"
#include <QPainter>

// Negate modifier negates the current score
class Negate : public ModifySymbol
{
public:
    Negate();
    ~Negate() override = default;
    void Draw(QPainter& painter) const override;
    int Apply(int value) const override;

    operator QString() const override;
};

#endif // NEGATE_H
