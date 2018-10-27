#include "PrioritySelectedListWidget.h"


PrioritySelectedListWidget::PrioritySelectedListWidget(QWidget *parent) : QListView(parent)
{
	m_pPrioritySelectedListModel = new PrioritySelectedListModel();
	setModel(m_pPrioritySelectedListModel);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setSelectionMode(QAbstractItemView::ExtendedSelection);
	setDragEnabled(true);
	setAcceptDrops(true);
	setDropIndicatorShown(true);
	setDragDropMode(QAbstractItemView::DragDrop);
}


PrioritySelectedListWidget::~PrioritySelectedListWidget()
{
}

void PrioritySelectedListWidget::setListItems(QStringList list)
{
	setUpdatesEnabled(false);
	m_pPrioritySelectedListModel->addCols(list);
	update();
	setUpdatesEnabled(true);

}
