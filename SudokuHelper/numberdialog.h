#ifndef NUMBERDIALOG_H
#define NUMBERDIALOG_H

#include <QDialog>
#include "ui_numberdialog.h"


class NumberDialog : public QDialog, public Ui::Dialog {
	Q_OBJECT

public:
	NumberDialog(QWidget *parent = 0);

private:
	QPushButton* numberButtons[9];

public slots:
	void digitClicked(int button);
	void on_clearButton_clicked();
};

#endif 