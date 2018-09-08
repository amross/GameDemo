#include "deck.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Deck *pDeck =  new Deck();
    pDeck->Shuffle();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    pDeck->GetCard();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
