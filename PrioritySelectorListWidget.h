#ifndef PRIORITYSELECTORWIDGET_H
#define PRIORITYSELECTORWIDGET_H

#include <QListView>
#include "PrioritySelectorListModel.h"
class PrioritySelectorListWidget :public QListView
{
	Q_OBJECT
public:
	PrioritySelectorListWidget(QWidget *parent = 0);
	~PrioritySelectorListWidget();
	void setListItems(QStringList list);
private:
	PrioritySelectorListModel *m_pPrioritySelectorListModel;
	QStringList m_pNamesLists;
};

#endif

