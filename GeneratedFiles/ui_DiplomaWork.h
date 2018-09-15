/********************************************************************************
** Form generated from reading UI file 'DiplomaWork.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIPLOMAWORK_H
#define UI_DIPLOMAWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiplomaWorkClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DiplomaWorkClass)
    {
        if (DiplomaWorkClass->objectName().isEmpty())
            DiplomaWorkClass->setObjectName(QStringLiteral("DiplomaWorkClass"));
        DiplomaWorkClass->resize(600, 400);
        menuBar = new QMenuBar(DiplomaWorkClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        DiplomaWorkClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DiplomaWorkClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DiplomaWorkClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DiplomaWorkClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DiplomaWorkClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DiplomaWorkClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DiplomaWorkClass->setStatusBar(statusBar);

        retranslateUi(DiplomaWorkClass);

        QMetaObject::connectSlotsByName(DiplomaWorkClass);
    } // setupUi

    void retranslateUi(QMainWindow *DiplomaWorkClass)
    {
        DiplomaWorkClass->setWindowTitle(QApplication::translate("DiplomaWorkClass", "DiplomaWork", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DiplomaWorkClass: public Ui_DiplomaWorkClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIPLOMAWORK_H
