#include "DataSheetWidget.h"
#include <QHeaderView>


DataSheetWidget::DataSheetWidget(QWidget *parent)
	: QTableView(parent)
{
	m_pDataSheetModeel = new DataSheetModel();
	setModel(m_pDataSheetModeel);

	verticalHeader()->hide();
	horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: #BDC3C7; padding: 10px; }");
}


DataSheetWidget::~DataSheetWidget()
{
}

void DataSheetWidget::runSort()
{
	setUpdatesEnabled(false);
	m_pDataSheetModeel->m_pData->sort();
	update();
	setUpdatesEnabled(true);
}

void DataSheetWidget::reset()
{
	setUpdatesEnabled(false);
	m_pDataSheetModeel->m_pData->reset();
	update();
	setUpdatesEnabled(true);
}
