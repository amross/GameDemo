#ifndef CARDSLOT_H
#define CARDSLOT_H

#include "card.h"

#include <QLabel>

// Represents a card with symbol on face and modifier on back
// Can be draw into a QObject
class CardSlot : public QLabel {
    Q_OBJECT

public:
    explicit CardSlot(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~CardSlot() override = default;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void AddCard(Card* pCard);
    Card* RemoveCard(void);

protected:
    void mousePressEvent(QMouseEvent* event) override;

private:
    enum { BoardWidth = 10, BoardHeight = 22 };
    Card* pCard;

signals:
    void clicked(CardSlot& card);
};

#endif
