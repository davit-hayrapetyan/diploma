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
