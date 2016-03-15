#include "GHeader.h"
#include "mainWin.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	mainWin window;
	window.resize(700,700);
	window.setWindowTitle("soduko"); 
	window.show();
	return app.exec(); 
}
