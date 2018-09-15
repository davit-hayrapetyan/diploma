#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DiplomaWork.h"
#include <QMenuBar>
#include "SortAreaWidget.h"

class DiplomaWork : public QMainWindow
{
	Q_OBJECT
public:
	DiplomaWork(QWidget *parent = 0);
	~DiplomaWork();
private:
	SortAreaWidget *m_pMainWorkspace;
	QToolBar *m_pToolBar;
	QAction *m_pOpenAct;
	QAction *m_pRunAct;
};
