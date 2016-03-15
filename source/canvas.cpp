/*
   - author: Michael Wilson
   - prof: 
   - school class: 
   - class: canvas 
   - description **  **
   - Assignment 
*/

#include<QtGui>
#include "canvas.h"

// creates the objects
Canvas::Canvas( QWidget *parent)
{

   animClock = new QTClock(false, 10, this);
   connect(animClock, SIGNAL(tick(const int &)), this, SLOT(animTick(const int &)));

}
Canvas::~Canvas()
{
   std::cerr << "canvas.h : deleted hour"<< std::endl;

   std::cerr << "canvas.h : deleted hour - success "<< std::endl;
}
// slot so paint can be updated!
void Canvas::updatePaint()
{  

   update();
}

// draws shapes, paths, start, goal and path when it is found
void Canvas::paintEvent(QPaintEvent *event)
{
   
   QPainter paint(this);
   const QColor color(28,183,235);
   paint.setPen(QPen(color, 2, Qt::SolidLine));
   
   //****Draws the shapes****
   for(int x = 0; x < objects.size(); x++)
   {

         //makes a new brush with the colour of the object
         QColor color(objects[x].red,objects[x].green,objects[x].blue);

         paint.setPen(QPen(color, 2, Qt::SolidLine));

         // draws a line through all the coordinates
         for(int y = 0; y < objects[x].shapes.size()-1; y++)
         {
            paint.drawLine(objects[x].shapes[y].x, objects[x].shapes[y].y,
                          objects[x].shapes[y+1].x, objects[x].shapes[y+1].y);
         }
         //if the end and start of the vertices are connected, draw a line between them
         if(objects[x].connect)
            paint.drawLine(objects[x].shapes[0].x, objects[x].shapes[0].y,
                           objects[x].shapes[  objects[x].shapes.size()-1  ].x, objects[x].shapes[  objects[x].shapes.size()-1  ].y);

   }
}




void Canvas::updateTime(int h,int m, int s)
{


   std::cerr << "hour \n" << hour << " " << h << "\n";
   hour = h;
   minute = m;
   second= s;
   update();
}


void Canvas::animTick(const int &info)
{
   update();
}