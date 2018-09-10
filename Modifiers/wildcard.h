#ifndef WILDCARD_H
#define WILDCARD_H

#include "modifysymbol.h"
#include <QPainter>

// Wildcard modifier always gives a fixed score regardless of current score
class Wildcard : public ModifySymbol
{
public:
    Wildcard(int value);
    ~Wildcard() override = default;
    void Draw(QPainter& painter) const override;
    int Apply(int value) const override;

    operator QString() const override;

private:
    int fixedScore;
};

#endif // WILDCARD_H
