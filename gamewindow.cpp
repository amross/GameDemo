/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>

#include "cardslot.h"
#include "gameengine.h"
#include "gamewindow.h"

GameWindow::GameWindow()
{
    matchLabel = new QLabel;
    matchLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    matchLabel->setAlignment(Qt::AlignCenter);

    scoreLcd = new QLCDNumber(5);
    scoreLcd->setSegmentStyle(QLCDNumber::Filled);
    clicksLcd = new QLCDNumber(5);
    clicksLcd->setSegmentStyle(QLCDNumber::Filled);

    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);

    GameEngine *pGameEngine = new GameEngine();
    pGameEngine->pMatcherSlot = new CardSlot();
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("CLICK REMAINING")), 0, 0, 1, 2);
    layout->addWidget(clicksLcd, 1, 0, 1, 2);
    layout->addWidget(createLabel(tr("SCORE")), 0, 2, 1, 2);
    layout->addWidget(scoreLcd, 1, 2, 1, 2);
    layout->addWidget(createLabel(tr("MATCH")), 2, 0);
    layout->addWidget(pGameEngine->pMatcherSlot, 3, 0);
    layout->addWidget(startButton, 5, 3);
    layout->addWidget(quitButton, 6, 3);
    for(int x = 1; x < 4; ++x)
    {
        for(int y = 2; y < 5; ++y)
        {
            CardSlot *pSlot = new CardSlot();
            layout->addWidget(pSlot, y, x);
            pGameEngine->slotList.append(pSlot);
            connect(pSlot, SIGNAL(clicked(CardSlot&)), pGameEngine, SLOT(CardPicked(CardSlot&)));
        }
    }
    setLayout(layout);

    connect(startButton, SIGNAL(clicked()), pGameEngine, SLOT(Start()));
    connect(quitButton , SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(pGameEngine, SIGNAL(ScoreChanged(int)), scoreLcd, SLOT(display(int)));
    connect(pGameEngine, SIGNAL(ClicksChanged(int)), clicksLcd, SLOT(display(int)));


    setWindowTitle(tr("Card Matcher"));
    resize(550, 370);
}

QLabel *GameWindow::createLabel(const QString &text)
{
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}

