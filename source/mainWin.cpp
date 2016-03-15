#include "mainWin.h"

mainWin::mainWin()
{

	SBoard= new sodukoBoard();

	// creates a mainwindow widget to set the layout to
	QWidget *MainWindow = new QWidget;
    setCentralWidget(MainWindow); 

	for(int x = 0; x < 9; x++)
	{
		for(int y = 0; y < 9; y++)
		{
			board[x][y] = new QButtonCoor(x,y);
			board[x][y]->setMinimumHeight(50);
			board[x][y]->setMinimumWidth(50);
			board[x][y]->setMaximumHeight(50);
			board[x][y]->setMaximumWidth(50);
			connect(board[x][y], SIGNAL(sendingCoor(const int &, const int &)), this, SLOT(setnum(const int &, const int &)));
		}
	}

	clear_b= new QPushButton("clear");
	solve_b= new QPushButton("solve");
	gen_b= new QPushButton("generate");
	close_b= new QPushButton("close");
	connect(close_b, SIGNAL(clicked()), this, SLOT(close()));
	connect(clear_b, SIGNAL(clicked()), this, SLOT(clearBoard()));
	connect(solve_b, SIGNAL(clicked()), this, SLOT(solve_slot()));
	connect(gen_b, SIGNAL(clicked()), this, SLOT(generate_slot()));

	colorClock = new QTClock(false,0,this);
   connect(colorClock, SIGNAL(tick(const int &)), this, SLOT(animTick(const int &)));

   	// connecting buttons to the timer
   	connect(close_b, SIGNAL(clicked()), colorClock, SLOT(SingleClockLoop()));
	connect(clear_b, SIGNAL(clicked()), colorClock, SLOT(SingleClockLoop()));
	connect(solve_b, SIGNAL(clicked()), colorClock, SLOT(SingleClockLoop()));
	connect(gen_b, SIGNAL(clicked()), colorClock, SLOT(SingleClockLoop()));

	paint = new Canvas(this);
	std::vector< QTObject > lines;
	lines.push_back(QTObject(0,0,0,false,false,"",840, 555));
	lines[lines.size()-1].nextCoor(210,0);
	lines[lines.size()-1].nextCoor(210,730);

	lines.push_back(QTObject(0,0,0,false,false,"",840, 555));
	lines[lines.size()-1].nextCoor(0, 198);
	lines[lines.size()-1].nextCoor(730, 198);

	lines.push_back(QTObject(0,0,0,false,false,"",840, 555));
	lines[lines.size()-1].nextCoor(0, 404);
	lines[lines.size()-1].nextCoor(730, 404);

	lines.push_back(QTObject(0,0,0,false,false,"",840, 555));
	lines[lines.size()-1].nextCoor( 432,0);
	lines[lines.size()-1].nextCoor( 432, 730);



	for(int x = 0; x < lines.size(); x++)
		paint->insertObject(lines[x]);


	// creates a grid for the window
	QGridLayout *gridLayout = new QGridLayout;
	gridLayout->addWidget(paint, 0,0,9,9);
	for(int x = 0; x < 9; x++)
	{
		for(int y = 0; y < 9; y++)
		{
			gridLayout->addWidget(board[x][y], x,y,1,1);
		}
	}
	gridLayout->addWidget(clear_b, 10,0,1,2);
	gridLayout->addWidget(solve_b, 10,2,1,2);
	gridLayout->addWidget(gen_b,   10,4,1,2);
	gridLayout->addWidget(close_b, 10,6,1,3);
	
	MainWindow->setLayout(gridLayout);

	clearBoard();


}

void mainWin::setnum(const int &xx, const int &yy)
{
std::cerr << "\n\n x = " << xx << "\n y = " << yy << "\n\n";
	getNum_w = new getNum(this);
	getNum_w->show();
	getNum_w->setCoor(xx,yy);
	connect(getNum_w,SIGNAL(sendInfo(const int &, const int &, const int &)), this,  SLOT(returnNum(const int &, const int &, const int &)));

}

void mainWin::returnNum(const int &xx, const int &yy, const int &val)
{
	std::cerr << "\n\n" << val << "\n\n";
	if(SBoard->set(xx,yy,val))
	{
		board[xx][yy]->setTextFromInt(val);
		board[xx][yy]->setVal(val);
		board[xx][yy]->setStyleSheet("background-color: #45D963");
	}
	else
		board[xx][yy]->setStyleSheet("background-color: #D9253A");
	colorClock->SingleClockLoop();
	delete getNum_w;
}

void mainWin::clearBoard()
{
	for(int x = 0 ;x < 9; x++)
		for(int y = 0; y < 9; y ++)
		{
			board[x][y]->setVal(0);
			board[x][y]->setText("");
			board[x][y]->setStyleSheet("background-color: #ABA4A5");
		}
		SBoard->clear();
}

void mainWin::animTick(const int &info)
{
		for(int x = 0 ;x < 9; x++)
		for(int y = 0; y < 9; y ++)
		{
			if(board[x][y]->val == 0)
				board[x][y]->setStyleSheet("background-color: #ABA4A5");
			else
				board[x][y]->setStyleSheet("background-color: #00FF15");
		}
}


void mainWin::solve_slot()
{
	if(!SBoard->isSolved())
	{
		sodukoBoard *temp = solver.solveReturn(SBoard);

		if(temp->isSolved())
		{
			SBoard = temp;
			for(int x = 0 ;x < 9; x++)
			for(int y = 0; y < 9; y ++)
			{
				board[x][y]->setTextFromInt(SBoard->getVal(x,y));
				board[x][y]->val = SBoard->getVal(x,y);
				board[x][y]->setStyleSheet("background-color: #45D963");
			}
		}
		else
		{
			for(int x = 0 ;x < 9; x++)
			for(int y = 0; y < 9; y ++)
			{

				board[x][y]->setStyleSheet("background-color: #D9253A");

			}
		}
	}
}

void mainWin::generate_slot()
{
		clearBoard();
	SBoard->generateBoard(20);
	int value;
				for(int x = 0 ;x < 9; x++)
			for(int y = 0; y < 9; y ++)
			{
				value = SBoard->getVal(x,y);
				if(value == 0)
					board[x][y]->setText("");
				else
					board[x][y]->setTextFromInt(value);
				board[x][y]->val = SBoard->getVal(x,y);
				board[x][y]->setStyleSheet("background-color: #45D963");
			}
}
/*

	sodukoBoard *ab;
	ab = new sodukoBoard;
	ab->generateBoard(58);
	ab->printSolution();
	ab->draw();
	sodukoSolver soduko(ab);
	soduko.startSolve();
*/
