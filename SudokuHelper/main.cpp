#include "sudokuhelper.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SudokuHelper w;
	w.show();
	return a.exec();
}
