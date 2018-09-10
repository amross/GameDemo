#include "cardslot.h"
#include <QDebug>
#include <QPainter>

CardSlot::CardSlot(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    Q_UNUSED(f);
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);
    setScaledContents(true);
    QPixmap pix(60, 100);
    pix.fill(Qt::black);
    QPainter paint(&pix);
    setPixmap(pix);
    pCard = nullptr;
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
    this->pCard = pCard;

    QPixmap pix(60, 100);
    pix.fill(Qt::black);
    QPainter paint(&pix);
    this->pCard->Draw(paint);
    setPixmap(pix);
}

Card* CardSlot::RemoveCard()
{
    QPixmap pix(60, 100);
    pix.fill(Qt::black);
    QPainter paint(&pix);
    setPixmap(pix);
    Card* pReturn = pCard;
    pCard = nullptr;
    return pReturn;
}

void CardSlot::mousePressEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    emit clicked(*this);
}
