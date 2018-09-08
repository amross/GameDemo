#pragma once

#include <QColor>
#include <QObject>
#include <QDebug>
#include <QMetaEnum>

class Colour : public QObject {
  Q_OBJECT
public:
    enum Colours
    {
       RED,
       BLUE,
       GREEN,
       WHITE
    };
    Q_ENUM(Colours)
};
