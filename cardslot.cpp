#include "cardslot.h"

CardSlot::CardSlot(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);
    pLabel = new QLabel;
    pLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    pLabel->setAlignment(Qt::AlignCenter);
}

CardSlot::~CardSlot()
{

}

QSize CardSlot::sizeHint() const
{
    return QSize(BoardWidth * 15 + frameWidth() * 2,
                 BoardHeight * 15 + frameWidth() * 2);
}

QSize CardSlot::minimumSizeHint() const
{
    return QSize(BoardWidth * 5 + frameWidth() * 2,
                 BoardHeight * 5 + frameWidth() * 2);
}

void CardSlot::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}
