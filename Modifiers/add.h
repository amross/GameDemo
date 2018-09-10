#ifndef ADD_H
#define ADD_H

#include "modifier.h"

class Add : public Modifier
{
public:
    Add(int value);
    virtual ~Add() override = default;
    void Draw(QPainter& painter) const override;
    int Apply(int value) const;

    operator QString() const override;

private:
    int addValue;
};

#endif // ADD_H
