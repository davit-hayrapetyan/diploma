#ifndef SORTINGPANELWIDGET_H
#define SORTINGPANELWIDGET_H

#include <QWidget>
#include <QSplitter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "PrioritySelectorListWidget.h"
#include "PrioritySelectedListWidget.h"

class SortingPanelWidget : public QWidget
{
	Q_OBJECT
public:
	SortingPanelWidget(QWidget *parent=0);
	~SortingPanelWidget();
	void setNamesList(QStringList list);
	QStringList l = { "sadqsd", "asdasd", "asdasdas" };
private:
	void setupUi();
	QHBoxLayout *m_pListsLayout;
	QVBoxLayout *m_pPanelLayout;
	PrioritySelectorListWidget *m_pPrioritySelectorWidget;
	PrioritySelectedListWidget *m_pPrioritySelectedWidget;
};

#endif