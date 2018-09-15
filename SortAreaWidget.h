#ifndef SORTAREAWIDGET_H
#define SORTAREAWIDGET_H

#include <QWidget>
#include <QSplitter>

#include "PrioritySelectorWidget.h"
#include "DataSheetWidget.h"

class SortAreaWidget : public QSplitter
{
	Q_OBJECT
public:
	SortAreaWidget(QWidget *parent = 0);
	~SortAreaWidget();
private:
	void setupUi();

	DataSheetWidget *m_pDataSheetWidget;
	PrioritySelectorWidget *m_pPrioritySelectorWidget;
};

#endif
