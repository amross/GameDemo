#ifndef WILDCARD_H
#define WILDCARD_H

#include "modifier.h"
#include <QPainter>

class Wildcard : public Modifier
{
public:
    Wildcard();
    ~Wildcard() override = default;
    void Draw(QPainter& painter) const override;
    int Apply(int value) const;

    operator QString() const override;
};

#endif // WILDCARD_H
