#pragma once

#include <QString>

class Symbol
{
public:
    virtual ~Symbol(){}
    virtual Symbol* create() const = 0;
    virtual Symbol* clone() const = 0;
    virtual void Draw() = 0;
    virtual operator QString() const = 0;
};
