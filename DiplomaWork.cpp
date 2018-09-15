#include "DiplomaWork.h"

DiplomaWork::DiplomaWork(QWidget *parent)
	: QMainWindow(parent)
{
	m_pMainWorkspace = new SortAreaWidget();
	setCentralWidget(m_pMainWorkspace);

	setMinimumSize(1024, 768);
	setWindowIcon(QIcon(":/Resources/icons/logo.png"));
	setWindowTitle("Sorting panel");
	showMaximized();

	m_pToolBar = new QToolBar(tr("Toolbar"));
	m_pToolBar->setFixedHeight(100);
	m_pToolBar->setIconSize(QSize(50, 50));
	addToolBar(m_pToolBar);

	const QIcon iconOpen = QIcon(":/Resources/icons/openFile.png");
	m_pOpenAct = new QAction(iconOpen, tr("Open"), this);
	m_pToolBar->addAction(m_pOpenAct);

	m_pToolBar->addSeparator();

	const QIcon iconRun = QIcon(":/Resources/icons/sort.png");
	m_pRunAct = new QAction(iconRun, tr("Run"), this);
	m_pToolBar->addAction(m_pRunAct);
}

DiplomaWork::~DiplomaWork()
{
}
