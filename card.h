#pragma once

#include <Symbols/coloredSymbol.h>
#include <Modifiers/modifier.h>
#include <QObject>

class Card
{
public:
    Card();
    ~Card();
    Card(const ColoredSymbol* pFaceSymbol, const Modifier* pModifier);
    void Flip();
    void FaceUp();
    void FaceDown();
    bool IsFaceUp();
    void Draw(QPainter& painter);
    operator QString() const ;

private:
    const ColoredSymbol *pFaceSymbol;
    const Modifier *pModifier;
    bool faceUp;
    QString desc;
};
