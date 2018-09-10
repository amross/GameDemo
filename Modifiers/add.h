#ifndef ADD_H
#define ADD_H

#include "modifysymbol.h"

// Add modified adds a fixed value to the current score
class Add : public ModifySymbol
{
public:
    Add(int value);
    virtual ~Add() override = default;
    void Draw(QPainter& painter) const override;
    int Apply(int value) const override;

    operator QString() const override;

private:
    int addValue;
};

#endif // ADD_H
