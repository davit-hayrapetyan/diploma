#ifndef PRIORITYSELECTORWIDGET_H
#define PRIORITYSELECTORWIDGET_H

#include <QListView>
#include "PrioritySelectorModel.h"
class PrioritySelectorWidget :public QListView
{
	Q_OBJECT
public:
	PrioritySelectorWidget(QWidget *parent = 0);
	~PrioritySelectorWidget();
private:
	PrioritySelectorModel *m_pPrioritySelectorModel;
};

#endif

