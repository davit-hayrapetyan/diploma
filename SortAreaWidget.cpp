#include "SortAreaWidget.h"
#include <QListView>
#include <QTreeView>
#include <QTextEdit>
SortAreaWidget::SortAreaWidget(QWidget *parent)
	: QSplitter(parent)
{
	setupUi();
}

SortAreaWidget::~SortAreaWidget()
{
}

void SortAreaWidget::setupUi()
{
	QListView *listview = new QListView;

	m_pDataSheetWidget = new DataSheetWidget();
	m_pPrioritySelectorWidget = new PrioritySelectorWidget();
	addWidget(m_pPrioritySelectorWidget);
	addWidget(m_pDataSheetWidget);
	//addWidget(gl);
	

	
	setStretchFactor(0, 3);
	setStretchFactor(1, 2);
	//setStretchFactor(2, 3);
}