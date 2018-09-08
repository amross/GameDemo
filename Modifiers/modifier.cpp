#include "modifier.h"

#include <Symbols/symbol.h>

Modifier::Modifier()
{
    qInfo( "Construct Modifier" );
}

Modifier::~Modifier()
{
    qInfo( "Destruct Modifier" );
}

Modifier::Modifier(const Modifier &from)
{
    qInfo( "Copy Constructor Modifier" );
}

Symbol& Modifier::GetSymbol()
{
    qInfo( "Get Modifier symbol" );
}
