#ifndef CARDSLOT_H
#define CARDSLOT_H

#include <QLabel>

class CardSlot : public QLabel {
    Q_OBJECT

public:
    explicit CardSlot(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~CardSlot() override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    QLabel *pLabel;

protected:
    void mousePressEvent(QMouseEvent* event) override;

private:
    enum { BoardWidth = 10, BoardHeight = 22 };

signals:
    void clicked();
};

#endif
