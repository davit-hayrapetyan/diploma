#ifndef SORTINGPANELWIDGET_H
#define SORTINGPANELWIDGET_H

#include <QWidget>
#include <QSplitter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "PrioritySelectorWidget.h"

class SortingPanelWidget : public QWidget
{
	Q_OBJECT
public:
	SortingPanelWidget(QWidget *parent=0);
	~SortingPanelWidget();

private:
	void setupUi();
	QHBoxLayout *m_pListsLayout;
	QVBoxLayout *m_pPanelLayout;
	PrioritySelectorWidget *m_pPrioritySelectorWidget1;
	PrioritySelectorWidget *m_pPrioritySelectorWidget2;
};

#endif