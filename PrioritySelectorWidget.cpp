#include "PrioritySelectorWidget.h"



PrioritySelectorWidget::PrioritySelectorWidget(QWidget *parent) : QListView(parent)
{
	m_pPrioritySelectorModel = new PrioritySelectorModel();
	setModel(m_pPrioritySelectorModel);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
}


PrioritySelectorWidget::~PrioritySelectorWidget()
{
}
