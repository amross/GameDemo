#include "cardslot.h"
#include <QDebug>

CardSlot::CardSlot(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);
}

CardSlot::~CardSlot()
{

}

QSize CardSlot::sizeHint() const
{
    int width = BoardWidth * 15 + frameWidth() * 2;
    return QSize(width, (width * 3) / 2);
}

QSize CardSlot::minimumSizeHint() const
{
    int width = BoardWidth * 15 + frameWidth() * 2;
    return QSize(width, (width * 3) / 2);
}

void CardSlot::AddCard(Card* pCard)
{
    qInfo() << "Add Card: " << *pCard;
    this->pCard = pCard;
    this->setText(*pCard);
}

Card* CardSlot::RemoveCard()
{
    return pCard;
}

void CardSlot::mousePressEvent(QMouseEvent* event)
{
    emit clicked(*this);
}
