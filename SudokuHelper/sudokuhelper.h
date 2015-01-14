#ifndef SUDOKUHELPER_H
#define SUDOKUHELPER_H

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include "ui_sudokuhelper.h"
//#include "numberdialog.h"

class SudokuHelper : public QMainWindow
{
	Q_OBJECT

public:
	SudokuHelper(QWidget* parent = 0);
	~SudokuHelper();
	void CreateSudoku();
	bool SolveSudoku();
	void SudokuToArray();
	void ShowSolution();
	void ClearBoard();
	bool FindEmptyLocation(int& x, int& y);
	bool FindConflicts(int x, int y, int num);
	bool CheckRow(int y, int num);
	bool CheckColumn(int x, int num);
	bool CheckBox(int x, int y, int num);


public slots:
	void digitClicked(QWidget* widget);
	void changeValue(QWidget* widget);
	void showValue(QWidget* widget);
	void on_solveButton_clicked();
	void on_solveAndShowButton_clicked();
	void on_clearButton_clicked();

private:
	Ui::SudokuHelperClass ui;
	QPushButton* buttons[9][9];
	int sudoku[9][9];
	bool solved = false;
	QHash<QPushButton*, QPair<int, int> > buttonHash;
};

#endif // SUDOKUHELPER_H
