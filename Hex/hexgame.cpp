#include "hexgame.h"
#include "button.h"

#include <iostream>
#include <QGraphicsTextItem>


HexGame::HexGame(QWidget *parent)
{
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);
}

void HexGame::DisplayMenu()
{
    //title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Hex Game"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    int titleX = this->width()/2 - titleText->boundingRect().width()/2;
    titleText->setPos(titleX, 150);
    scene->addItem(titleText);

    //play button
    Button* playButton = new Button(QString("Play"));
    int playX = this->width()/2 - playButton->boundingRect().width()/2;
    playButton->setPos(playX, 275);
    connect(playButton, SIGNAL(clicked()), this, SLOT(StartGame()));
    scene->addItem(playButton);

    //quit button
    Button* quitButton = new Button(QString("Quit"));
    int quitX = this->width()/2 - quitButton->boundingRect().width()/2;
    quitButton->setPos(quitX, 325);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);

}

void HexGame::UpdateTurn()
{
    if(hexBoard->WhosTurn == Player::BLUE)
    {
        turnText->setPlainText(QString("YOUR TURN!"));
        turnText->setPos(this->width()/2-turnText->boundingRect().width()/2 , 45);
    }
    else if(hexBoard->WhosTurn == Player::RED)
    {
        turnText->setPlainText(QString("COMPUTER'S TURN!"));
        turnText->setPos(this->width()/2-turnText->boundingRect().width()/2 , 45);
    }
}

void HexGame::StartGame()
{
    scene->clear();

    hexBoard = new HexBoard(11);
    hexBoard->DrawHexBoard();

    QFont textFont("comic sans", 10);

    QGraphicsTextItem* playerText = new QGraphicsTextItem(QString("Human: East to West"));
    playerText->setFont(textFont);
    playerText->setPos(50, 50);
    scene->addItem(playerText);

    QGraphicsTextItem* computerText = new QGraphicsTextItem(QString("Computer: North to South"));
    computerText->setFont(textFont);
    computerText->setPos(this->width()-computerText->boundingRect().width() - 50 , 50);
    scene->addItem(computerText);

    turnText = new QGraphicsTextItem();
    QFont turnFont("comic sans", 15);
    turnText->setFont(turnFont);
    scene->addItem(turnText);
    UpdateTurn();
}
