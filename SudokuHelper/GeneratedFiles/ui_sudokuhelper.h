/********************************************************************************
** Form generated from reading UI file 'sudokuhelper.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKUHELPER_H
#define UI_SUDOKUHELPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SudokuHelperClass
{
public:
    QWidget *centralWidget;
    QPushButton *solveButton;
    QPushButton *solveAndShowButton;
    QTextBrowser *textStatus;
    QPushButton *clearButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SudokuHelperClass)
    {
        if (SudokuHelperClass->objectName().isEmpty())
            SudokuHelperClass->setObjectName(QStringLiteral("SudokuHelperClass"));
        SudokuHelperClass->resize(301, 447);
        centralWidget = new QWidget(SudokuHelperClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        solveButton = new QPushButton(centralWidget);
        solveButton->setObjectName(QStringLiteral("solveButton"));
        solveButton->setGeometry(QRect(50, 290, 100, 23));
        solveAndShowButton = new QPushButton(centralWidget);
        solveAndShowButton->setObjectName(QStringLiteral("solveAndShowButton"));
        solveAndShowButton->setGeometry(QRect(150, 290, 100, 23));
        textStatus = new QTextBrowser(centralWidget);
        textStatus->setObjectName(QStringLiteral("textStatus"));
        textStatus->setGeometry(QRect(50, 350, 201, 41));
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(89, 320, 121, 23));
        SudokuHelperClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SudokuHelperClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 301, 21));
        SudokuHelperClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SudokuHelperClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SudokuHelperClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SudokuHelperClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SudokuHelperClass->setStatusBar(statusBar);

        retranslateUi(SudokuHelperClass);

        QMetaObject::connectSlotsByName(SudokuHelperClass);
    } // setupUi

    void retranslateUi(QMainWindow *SudokuHelperClass)
    {
        SudokuHelperClass->setWindowTitle(QApplication::translate("SudokuHelperClass", "SudokuHelper", 0));
        solveButton->setText(QApplication::translate("SudokuHelperClass", "Solve sudoku", 0));
        solveAndShowButton->setText(QApplication::translate("SudokuHelperClass", "Solve and show ", 0));
        clearButton->setText(QApplication::translate("SudokuHelperClass", "Clear sudoku board", 0));
    } // retranslateUi

};

namespace Ui {
    class SudokuHelperClass: public Ui_SudokuHelperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUHELPER_H
