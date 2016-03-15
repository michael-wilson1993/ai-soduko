/*
  - Michael Wilson
  - canvas.h
  - AI 
  - prof: Yllias Chali
*/

#pragma once

#include "QTObject.h"
#include <QBrush>
#include <QColor>
#include "QTClock.h"
#include <string>
#include <QWidget>
#include <iostream>
#include <vector>

struct WRect // helper struct that holds four ints that make up a rectangle.
{
  WRect(int xx, int yy, int ww, int hh)
  {
    x = xx;
    y = yy;
    w = ww;
    h = hh;
  };
  int x, y, w, h;
};

class Canvas : public QWidget
{
 Q_OBJECT

public:
  // constructor
  Canvas(QWidget *parent = 0);
  //destructor
  ~Canvas();

 public slots:
   /*
   - void updatePaint();
   - this is a slot that will update the player and the it will repaint the canvas...
   */
   void updatePaint();
   
   // animTick is a slot that will be connected to a clock to make animation possible
  void animTick(const int &info);
  // updatesTime updates the time stored in this class
  void updateTime(int h,int m, int s); // updates the time
  // insertObject inserts an oobject into objects vector( this entire vector gets displayed)
  void insertObject(QTObject obj) {objects.push_back(obj);update();};


  protected:
    /*
     - void paintEvent();
     - this will paint all the objects onto the canvas
    */
     void paintEvent(QPaintEvent *);
  private:
    // animation clock
    QTClock *animClock;
    // vector storing QTOcjects that will get drawn to screen
    std::vector< QTObject > objects;
    // time that gets stored... not needed for soduko ai
    int hour,second, minute;




};
