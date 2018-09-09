#include "cardslot.h"

CardSlot::CardSlot(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);
    pLabel = new QLabel;
    pLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    pLabel->setAlignment(Qt::AlignCenter);
pCard = new Card();
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

void CardSlot::mousePressEvent(QMouseEvent* event)
{
    emit clicked(*this);
}
