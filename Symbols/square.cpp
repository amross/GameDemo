#include "square.h"

Square::Square()
{

}

Square::Square(const Square &)
{

}

Square *Square::create() const
{
    return new Square();
}

Square *Square::clone() const
{
    return new Square(*this);
}

void Square::Draw()
{

}
