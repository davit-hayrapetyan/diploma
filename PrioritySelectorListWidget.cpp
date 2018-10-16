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
	//setDragDropMode(QAbstractItemView::InternalMove);
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
/*
void PrioritySelectorListWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
			m_DragStartPos = event->pos();
		QDrag *drag = new QDrag(this);
		QMimeData *mimeData = new QMimeData;

		mimeData->setText((model()->data(indexAt(m_DragStartPos))).toString());
		drag->setMimeData(mimeData);
		Qt::DropAction dropAction = drag->exec();
	}
}

void PrioritySelectorListWidget::mouseMoveEvent(QMouseEvent * event)
{
	if (!(event->buttons() & Qt::LeftButton))
		return;
	if ((event->pos() - m_DragStartPos).manhattanLength()
		< QApplication::startDragDistance())
		return;

	QDrag *drag = new QDrag(this);
	QMimeData *mimeData = new QMimeData;

	mimeData->setText((model()->data(indexAt(m_DragStartPos))).toString());
	drag->setMimeData(mimeData);

	Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
}

void PrioritySelectorListWidget::dragEnterEvent(QDragEnterEvent *event)
{
	if (event->mimeData()->hasFormat("text/plain"))
		event->acceptProposedAction();
}

void PrioritySelectorListWidget::dropEvent(QDropEvent *event)
{
	model()->setData(indexAt(event->pos()), event->mimeData()->text());

	event->acceptProposedAction();
}
*/