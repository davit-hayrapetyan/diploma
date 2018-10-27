#ifndef DIPLOMAWORK_H
#define DIPLOMAWORK_H

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
	SortAreaWidget *m_pSortAreaWorkspace;
	QToolBar *m_pToolBar;
	QAction *m_pOpenAct;
	QAction *m_pRunAct;
	QAction *m_pReset;
signals:
	void sigSort();
public slots:
	void RunActHandle();
	void ResetHandle();
};

#endif //DIPLOMAWORK_H