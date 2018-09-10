#ifndef MODIFYSYMBOL_H
#define MODIFYSYMBOL_H

#include <Symbols/symbol.h>

// Modifier symbol is a symbol with an associated modifer
// Modifier can be applied to any value using the Apply function
class ModifySymbol : public Symbol
{
public:
    virtual ~ModifySymbol() = default;
    virtual int Apply(int value) const = 0;
};

#endif // MODIFYSYMBOL_H
