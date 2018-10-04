#include "PrioritySelectorListWidget.h"



PrioritySelectorListWidget::PrioritySelectorListWidget(QWidget *parent) : QListView(parent)
{
	m_pPrioritySelectorListModel = new PrioritySelectorListModel();
	setModel(m_pPrioritySelectorListModel);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setSelectionMode(QAbstractItemView::ExtendedSelection);
	setDragEnabled(true);
	setAcceptDrops(true);
	setDropIndicatorShown(true);
}


PrioritySelectorListWidget::~PrioritySelectorListWidget()
{
}

void PrioritySelectorListWidget::setListItems(QStringList list)
{
	setUpdatesEnabled(false);
	m_pPrioritySelectorListModel->addCols(list);
	update();
	setUpdatesEnabled(true);
	
}
