#include "card.h"

Card::Card()
{

}

Card::Card(const Symbol &faceSymbol, const Modifier &modifier)
{
    this->modifier = modifier;
    pFaceSymbol = faceSymbol.clone();
}
