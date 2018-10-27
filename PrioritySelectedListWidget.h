#ifndef PRIORIYSELECTEDWIDGET_H
#define PRIORIYSELECTEDWIDGET_H


#include <QListView>
#include "PrioritySelectedListModel.h"
class PrioritySelectedListWidget :public QListView
{
	Q_OBJECT
public:
	PrioritySelectedListWidget(QWidget *parent = 0);
	~PrioritySelectedListWidget();
	void setListItems(QStringList list);
private:
	PrioritySelectedListModel *m_pPrioritySelectedListModel;
	QStringList m_pNamesLists;
};

#endif