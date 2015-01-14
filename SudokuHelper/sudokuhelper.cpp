#include "sudokuhelper.h"
#include "numberdialog.h"
#include <QApplication>
#include <QObject>
#include <QSignalMapper>
#include <QPushButton>
#include <QString>
#include <QTextBrowser>

SudokuHelper::SudokuHelper(QWidget *parent)
	: QMainWindow(parent){
	ui.setupUi(this);
	CreateSudoku();	
}

SudokuHelper::~SudokuHelper(){

}

/*
*	Creates the sudoku board
*/
void SudokuHelper::CreateSudoku(){
	int distanceX = 50;
	int distanceY = 50;
	QSignalMapper *signalMapper = new QSignalMapper(this);
	connect(signalMapper, SIGNAL(mapped(QWidget*)), this, SLOT(digitClicked(QWidget*)));
	for (int y = 0; y < 9; ++y){
		if (y == 3 || y == 6){
			distanceY += 10;
		}
		for (int x = 0; x < 9; ++x) {
			QPair<int, int> gridCoordinates(x, y);
			QString text = QString::number(x);
			buttons[x][y] = new QPushButton("", this);
			buttons[x][y]->resize(20, 20);
			if (x == 3 || x == 6){
				distanceX += 10;
			}
			buttons[x][y]->move((20 * x) + distanceX, (20 * y) + distanceY);
			buttonHash.insert(buttons[x][y], gridCoordinates);
			signalMapper->setMapping(buttons[x][y], qobject_cast<QWidget*>(buttons[x][y]));
			connect(buttons[x][y], SIGNAL(clicked()), signalMapper, SLOT(map()));
		}
		distanceX = 50;
	}
	ClearBoard();
}

/*
*	Function that handles the clicked squares of the sudoku board
*	@param Qwidget* widget
*		pointer to the widget/button that been clicked
*/
void SudokuHelper::digitClicked(QWidget* widget){
	if (solved){
		showValue(widget);
	}
	else{
		changeValue(widget);
	}
}

/*
*	Changes the values of the sudoku squares if it isn't solved
*	@param Qwidget* widget
*		pointer to the widget/button that been clicked
*/
void SudokuHelper::changeValue(QWidget* widget){
	ui.textStatus->clear();
	QPair<int, int> gridCoordinates = buttonHash.value(qobject_cast<QPushButton*>(widget));
	int x = gridCoordinates.first;
	int y = gridCoordinates.second;
	int returnValue = 0;
	NumberDialog numberDialog;
	if (numberDialog.exec()){
		returnValue = numberDialog.result();
	}
	if (returnValue > 0 && returnValue < 10){ //Stops closing of dialog window to set square to a faulty value
		if (!FindConflicts(x, y, returnValue)){
			buttons[x][y]->setText(QString::number(returnValue));
			sudoku[x][y] = returnValue;
		}
		else{
			ui.textStatus->setText("You cant put that value there.\nTry again!");
		}
		
	}
	else if (returnValue == 10){
		buttons[x][y]->setText("");
	}
}

/*
*	Shows the values of the sudoku squares if it's solved
*	@param Qwidget* widget
*		pointer to the widget/button that been clicked
*/
void SudokuHelper::showValue(QWidget* widget){
	QPair<int, int> gridCoordinates = buttonHash.value(qobject_cast<QPushButton*>(widget));
	int x = gridCoordinates.first;
	int y = gridCoordinates.second;	
	buttons[x][y]->setText(QString::number(sudoku[x][y]));
}

/*
*	Function that handles the solve button
*/
void SudokuHelper::on_solveButton_clicked(){
	SudokuToArray();
	if (SolveSudoku()){
		solved = true;
		ui.textStatus->setText("Sudoku solved.\nPush buttons to reveal answers");
	}
	else{
		ui.textStatus->setText("Couldn't solve sudoku");
	}
}

/*
*	Function that handles the solve and show button
*/
void SudokuHelper::on_solveAndShowButton_clicked(){
	SudokuToArray();
	if (SolveSudoku()){
		solved = true;
		ui.textStatus->setText("Sudoku solved.");
		ShowSolution();
	}
	else{
		ui.textStatus->setText("Couldn't solve sudoku");
	}
	
}

/*
*	Function that handles the clear button
*/
void SudokuHelper::on_clearButton_clicked(){
	ClearBoard();
	solved = false;
	ui.textStatus->setText("Board cleared");

}

/*
*	Clear the board and the arrays.
*/
void SudokuHelper::ClearBoard(){
	for (int y = 0; y < 9; ++y){
		for (int x = 0; x < 9; ++x) {
			buttons[x][y]->setText("");
			sudoku[x][y] = 0;
		}
	}
}

/*
*	Transfer the board to an two-dimensional array of integers
*/
void SudokuHelper::SudokuToArray(){
	for (int y = 0; y < 9; ++y){
		for (int x = 0; x < 9; ++x) {
			if (buttons[x][y]->text() == ""){
				sudoku[x][y] = 0;
			}
			else{
				sudoku[x][y] = buttons[x][y]->text().toInt();
			}
		}
	}
}

/*
*	Solves the sudoku. Doesn't show the answers but lets the user show them one by one
*	@return
*		Returns true if the sudoku where solved
*/
bool SudokuHelper::SolveSudoku(){
	int x, y;
	if (!FindEmptyLocation(x, y)){
		return true; // all squares are filled with valid numbers
	}
		
	for(int num = 1; num <= 9; ++num) {
		if (!FindConflicts(x, y, num)) {
			sudoku[x][y] = num;
			if (SolveSudoku()){
				return true;
			}
			sudoku[x][y] = 0; // Go back from dead end
		}
	}
	return false; 
}

/*
*	Shows the solution of the sudoku
*/
void SudokuHelper::ShowSolution(){
	for (int y = 0; y < 9; ++y){
		for (int x = 0; x < 9; ++x) {
				buttons[x][y]->setText(QString::number(sudoku[x][y]));
		}
	}

}

/*
*	Finds an location thats contains 0
*	@param int x
*		x value for the column of the two-dimensional array
*	@param int y
*		y value for the row of the two-dimensional array
*	@return
*		Returns true if we find an empty location
*/
bool SudokuHelper::FindEmptyLocation(int& x, int& y){
	for (y = 0; y < 9; ++y){
		for (x = 0; x < 9; ++x) {
			if (sudoku[x][y] == 0){
				return true;
			}
		}
	}
	return false;
}

/*
*	Finds any conflicts from the choosen number according to the rules of sudoku
*	@param int x
*		x value for the column of the two-dimensional array
*	@param int y
*		y value for the row of the two-dimensional array
*	@param int num
*		value to look for conflicts against
*	@return
*		Returns true if we find conflicts
*/
bool SudokuHelper::FindConflicts(int x, int y, int num){
	if (CheckRow(y, num) || CheckColumn(x, num) || CheckBox(x - x % 3, y - y % 3, num)){
		return true;
	}
	return false;
}

/*
*	Checks rows for conflicts
*	@param int y
*		y value for the row of the two-dimensional array
*	@param int num
*		value to look for conflicts against
*	@return
*		Returns true if we find conflicts
*/
bool SudokuHelper::CheckRow(int y, int num){
	for (int x = 0; x < 9; x++){
		if (sudoku[x][y] == num){
			return true;
		}
	}
	return false;
}

/*
*	Checks columns for conflicts
*	@param int x
*		x value for the column of the two-dimensional array
*	@param int num
*		value to look for conflicts against
*	@return
*		Returns true if we find conflicts
*/
bool SudokuHelper::CheckColumn(int x, int num){
	for (int y = 0; y < 9; ++y){
		if (sudoku[x][y] == num){
			return true;
		}
	}
	return false;
}

/*
*	Checks 3x3 boxes for conflicts
*	@param int x
*		x value for the column of the two-dimensional array
*	@param int y
*		y value for the row of the two-dimensional array
*	@param int num
*		value to look for conflicts against
*	@return
*		Returns true if we find conflicts
*/
bool SudokuHelper::CheckBox(int x, int y, int num){
	for (int rowY = 0; rowY < 3; ++rowY){
		for (int rowX = 0; rowX < 3; ++rowX){
			if (sudoku[rowX + x][rowY + y] == num){
				return true;
			}
		}
	}				
	return false;
}
