#include "PrioritySelectorListWidget.h"



PrioritySelectorListWidget::PrioritySelectorListWidget(QWidget *parent) : QListView(parent)
{
	m_pPrioritySelectorListModel = new PrioritySelectorListModel();
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setSelectionMode(QAbstractItemView::ExtendedSelection);
	setDragEnabled(true);
	setAcceptDrops(true);
	setDropIndicatorShown(true);
	setDragDropMode(QAbstractItemView::DragDrop);
	setModel(m_pPrioritySelectorListModel);
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
void PrioritySelectorListWidget::startDrag(Qt::DropActions supportedActions)
{
	QModelIndexList list = this->selectionModel()->selectedIndexes();

	PrioritySelectorListModel* model = dynamic_cast<PrioritySelectorListModel*>(this->model());
	QMimeData* data = model->mimeData(list);

	if (!data)
	{
		qDebug() << "Error! no data obtained!";
		return;
	}

	QDrag* drag = new QDrag(this);
	drag->setMimeData(data);
	drag->exec(supportedActions, Qt::IgnoreAction);
}
void PrioritySelectorListWidget::dragEnterEvent(QDragEnterEvent * event)
{
	setState(DraggingState);
	event->accept();
}
void PrioritySelectorListWidget::dropEvent(QDropEvent * e)
{
	qDebug() << e->mimeData();

	QModelIndex index = indexVisuallyAt(e->pos());
	PrioritySelectorListModel* model = dynamic_cast<PrioritySelectorListModel*>(this->model());

	model->dropMimeData(e->mimeData(), e->dropAction(), index.row(), index.column(), index.parent());

	//QListView::dropEvent(e);
}
QModelIndex PrioritySelectorListWidget::indexVisuallyAt(const QPoint & p)
{
	if (viewport()->rect().contains(p))
	{
		QModelIndex index = indexAt(p);

		if (index.isValid() && visualRect(index).contains(p))
		{
			return index;
		}
	}

	return QModelIndex();
}
//
//void PrioritySelectorListWidget::mousePressEvent(QMouseEvent *event)
//{
//	if (event->button() == Qt::LeftButton)
//	{
//			m_DragStartPos = event->pos();
//		QDrag *drag = new QDrag(this);
//		QMimeData *mimeData = new QMimeData;
//
//		mimeData->setText((model()->data(indexAt(m_DragStartPos))).toString());
//		drag->setMimeData(mimeData);
//		Qt::DropAction dropAction = drag->exec();
//	}
//}
//
//void PrioritySelectorListWidget::mouseMoveEvent(QMouseEvent * event)
//{
//	if (!(event->buttons() & Qt::LeftButton))
//		return;
//	if ((event->pos() - m_DragStartPos).manhattanLength()
//		< QApplication::startDragDistance())
//		return;
//
//	QDrag *drag = new QDrag(this);
//	QMimeData *mimeData = new QMimeData;
//
//	mimeData->setText((model()->data(indexAt(m_DragStartPos))).toString());
//	drag->setMimeData(mimeData);
//
//	Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
//}
//
//void PrioritySelectorListWidget::dragEnterEvent(QDragEnterEvent *event)
//{
//	if (event->mimeData()->hasFormat("text/plain"))
//		event->acceptProposedAction();
//}
//
//void PrioritySelectorListWidget::dropEvent(QDropEvent *event)
//{
//	model()->setData(indexAt(event->pos()), event->mimeData()->text());
//
//	event->acceptProposedAction();
//}
