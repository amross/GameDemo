#pragma once

#include <Symbols/coloredSymbol.h>
#include <Modifiers/modifysymbol.h>
#include <QObject>

// Represents a card with symbol on face and modifier on back
// Can be draw into a QObject
class Card
{
public:
    Card();
    Card(const ColoredSymbol* pFaceSymbol, const ModifySymbol* pModifier);
    void Flip();
    void FaceUp();
    void FaceDown();
    bool IsFaceUp();
    Qt::GlobalColor GetColor() const;
    bool IsSameShape(Card& card);
    int ApplyModifier(int value) const;
    void Draw(QPainter& painter);

    operator QString() const ;

private:
    const ColoredSymbol* pFaceSymbol;
    const ModifySymbol* pModifier;
    bool faceUp;
    QString desc;
};
