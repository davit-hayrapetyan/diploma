#include "SortingPanelWidget.h"



SortingPanelWidget::SortingPanelWidget(QWidget *parent)
	:QWidget(parent)
{
	setupUi();
}


SortingPanelWidget::~SortingPanelWidget()
{
}

void SortingPanelWidget::setupUi()
{
	m_pPanelLayout = new QVBoxLayout();
	m_pListsLayout = new QHBoxLayout();
	m_pPrioritySelectorWidget1 = new PrioritySelectorWidget(); 
	m_pPrioritySelectorWidget2 = new PrioritySelectorWidget();
	m_pListsLayout->addWidget(m_pPrioritySelectorWidget1);
	m_pListsLayout->addWidget(m_pPrioritySelectorWidget2);
	m_pPanelLayout->addLayout(m_pListsLayout);
	setLayout(m_pPanelLayout);
}
