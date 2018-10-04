#include "SortingPanelWidget.h"



SortingPanelWidget::SortingPanelWidget(QWidget *parent)
	:QWidget(parent)
{
	setupUi();
}


SortingPanelWidget::~SortingPanelWidget()
{
}

void SortingPanelWidget::setNamesList(QStringList list)
{
	m_pPrioritySelectorWidget->setListItems(list);	
}

void SortingPanelWidget::setupUi()
{
	m_pPanelLayout = new QVBoxLayout();
	m_pListsLayout = new QHBoxLayout();
	m_pPrioritySelectorWidget = new PrioritySelectorListWidget(); 
	m_pPrioritySelectedWidget = new PrioritySelectedListWidget();
	m_pListsLayout->addWidget(m_pPrioritySelectorWidget);
	m_pListsLayout->addWidget(m_pPrioritySelectedWidget);
	m_pPanelLayout->addLayout(m_pListsLayout);
	setLayout(m_pPanelLayout);
}
