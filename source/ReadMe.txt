- author: Michael Wilson
- prof: Yllias Chali
- school class: Artificial Intelligence 
- description ** this is a program that finds the closest path through a field of obsticles**
- Assignment 3

GUI: I used QT!

Instructions:
	to make the program you type make
	then you run the program.
	if the makeFile does not exsist
		type these to lines into console (these will generate the makefile)
			-	$ qmake-qt4 -project
			-	$ qmake-qt4 AIAss3.pro
	you run the program by typing ./AIAss3
	- close - closes the window
	- generate will generate a new soduko board that could be a valid board or not
	- solve - solves the soduko board
	- clear - clears the board 
	- you can click on any part of the board to insert a number.
		- if the number is valid it will light up green
		- if the number is not valid it will light up red


classes:

 - mainWin
 	it is the main window in QT that gets displayed and the canvas is contained within it. this class is just to hold all the visual stuff.
 - canvas 
 	- paints the lines for the soduko board
 - GHeader 
 	- contains a bunch of headers that are used by all classes
 - QButtonCoor
 	- contains a QPushbutton and the coordinates for that button
 - QTClock
 	- is a clock used to light up the buttons one second after inputing them
 - getNum 
 	- is a QTWidget that will return a number ( it is the pop out widget with numbers 1-9)
 - main 
 	- main that starts the application
 - sodukoBoard 
 	- contains a board of integers and functions (the functions are the constraints in the CSP program)
 - sodukoSolver 
 	- uses recursion and CSP to solve the soduko board. 
 	- this contains a sodukoBoard


 contents:
 	-	ReadMe.txt
 	-	mainWin.cc & .h
	-	canvas.cc & .h
 	-	getNum.cc & .h
 	-	sodukoBoard.cc & .h
 	-	sodukoSolver.cc & .h
 	-	QTClock.cc & .h
 	-	QButtonCoor.cc & .h
 	-	QTObject.cc & .h
 	-	GHeader.h
 	-	main.cc
 	-	makeFile
 	-	AIAss3.pro