#include "numberdialog.h"
#include "ui_numberdialog.h"
#include <QSignalMapper>

NumberDialog::NumberDialog(QWidget * parent) : QDialog(parent){
	setupUi(this);
	
	QSignalMapper *signalMapper = new QSignalMapper(this);
	connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(digitClicked(int)));
	for (int i = 1; i < 10; ++i){
			QString text = QString::number(i);	
			numberButtons[i] = new QPushButton(text, this);
			numberButtons[i]->resize(20, 20);
			numberButtons[i]->move((20 * i) + 50, 50);
			signalMapper->setMapping(numberButtons[i], i);
			connect(numberButtons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
	}
}

/*
*	Function that handles the number button clicks
*/
void NumberDialog::digitClicked(int button){
	NumberDialog::done(button);
}

/*
*	Function that handles the clear button
*/
void NumberDialog::on_clearButton_clicked(){
	NumberDialog::done(10);
}




