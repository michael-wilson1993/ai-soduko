#include "GHeader.h"
#include "mainWin.h"

int main(int argc, char *argv[])
{
	//creates application in QT
	QApplication app(argc, argv);
	//makes the main Window, resizes, sets the window title then shows it
	mainWin window;
	window.resize(700,700);
	window.setWindowTitle("soduko"); 
	window.show();
	return app.exec(); 
}
