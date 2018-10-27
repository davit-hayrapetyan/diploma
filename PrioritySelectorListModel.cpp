#include "PrioritySelectorListModel.h"
#include <QColor>
#include <QSize>

PrioritySelectorListModel::PrioritySelectorListModel(QObject *parent)
	: QStringListModel(parent)
{
	//m_lstColnames << "Col1" << "Col2" << "Col3" << "Col4" << "Col5";
	//setStringList(m_lstColnames);
}

PrioritySelectorListModel::~PrioritySelectorListModel()
{
}

Qt::DropActions PrioritySelectorListModel::supportedDropActions() const
{
	return  Qt::CopyAction | Qt::MoveAction;
}

Qt::DropActions PrioritySelectorListModel::supportedDragActions() const
{
	return  Qt::CopyAction | Qt::MoveAction;
}

//void PrioritySelectorListModel::setParent(QListView * lstView)
//{
//	m_pLstView = lstView;
//}

void PrioritySelectorListModel::addCols(QStringList lstColNames)
{
	m_lstColnames = lstColNames;
}

QStringList PrioritySelectorListModel::mimeTypes() const
{
	QStringList types;
	types << "application/vnd.text.list";
	return types;
}

QMimeData * PrioritySelectorListModel::mimeData(const QModelIndexList & indexes)
{
	QMimeData* mimeData = new QMimeData();
	QByteArray encodedData;

	QDataStream stream(&encodedData, QIODevice::WriteOnly);
	foreach(const QModelIndex &index, indexes)
	{
		if (index.isValid()) {
		//	qDebug() << "Exporting index" << index.row();
			stream << index.row();
		}
	}

	mimeData->setData("application/vnd.text.list", encodedData);
	return mimeData;
}

bool PrioritySelectorListModel::dropMimeData(const QMimeData * data, Qt::DropAction action, int row, int column, const QModelIndex & parent)
{
	Q_UNUSED(column);
	Q_UNUSED(parent);

	if (action == Qt::IgnoreAction)
		return true;

	if (!(data->hasFormat("application/vnd.text.list")))
		return false;


	QByteArray encodedData = data->data("application/vnd.text.list");
	QDataStream stream(&encodedData, QIODevice::ReadOnly);
	QList<QString> newItems;
	QList<QString> finalItems;
	QList<int> toRemove;

	int itemPoz;
	int temp = 0;
	while (!stream.atEnd())
	{
		stream >> itemPoz;
		newItems << m_lstColnames.at(itemPoz);
		if (itemPoz < row)
			temp++;
		toRemove.append(itemPoz);
	//	qDebug() << "Append " << rootItem->child(itemPoz)->data(Qt::DisplayRole);

	}

	row -= temp;
	emit layoutAboutToBeChanged();

	for (QList<int>::Iterator itr = toRemove.end() - 1; itr != toRemove.begin() - 1; --itr)
	{
		//qDebug() << "Deleteting item" << *itr;
		//rootItem->deleteChild(*itr);
		m_lstColnames.removeAt(*itr);
	}
	emit layoutChanged();

	for (int it = 0; it < m_lstColnames.count(); it++)
	{
		finalItems.append(m_lstColnames.at(it));
		if (it == row)
		{
			QString pushedItem;
			newItems.push_front(pushedItem);
			finalItems.append(pushedItem);
		}
	}

	m_lstColnames.clear();
	m_lstColnames.append(finalItems);

	emit layoutChanged();
	return true;
}



int PrioritySelectorListModel::rowCount(const QModelIndex & parent) const
{
	return m_lstColnames.count();
}

QVariant PrioritySelectorListModel::data(const QModelIndex & index, int role) const
{
	if (!index.isValid())
		return QVariant();

	switch (role)
	{
	case Qt::DisplayRole:
		return m_lstColnames.at(index.row());

	case Qt::EditRole:
		return m_lstColnames.at(index.row());
	/*case Qt::CheckStateRole:
		return m_lstCheckedItems.contains(index) ? Qt::Checked : Qt::Unchecked;*/

	case Qt::BackgroundColorRole:
		return m_lstCheckedItems.contains(index) ? QColor("#ffffb2") : QColor("#ffffff");

	case Qt::SizeHintRole:
		return QSize(0, 30);
	}

	return QStringListModel::data(index, role);
}

Qt::ItemFlags PrioritySelectorListModel::flags(const QModelIndex &index) const
{
	Qt::ItemFlags defaultFlags = QStringListModel::flags(index);

//	if (index.isValid())
		return  Qt::ItemIsEditable
		| Qt::ItemIsDragEnabled
		| Qt::ItemIsDropEnabled
		| defaultFlags;
//	else
//		return Qt::ItemIsDropEnabled | defaultFlags;
}

bool PrioritySelectorListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;
	if (role == Qt::EditRole || role == Qt::DisplayRole) {
		m_lstColnames.replace(index.row(), value.toString());
		emit dataChanged(index, index);
		return true;
	}
	
	//if (role == Qt::EditRole)
	//{
	//	int row = index.row();
	//	int dragedRow = m_DragedItemIndex.row();
	//	if (row < dragedRow)
	//		dragedRow++;
	//	m_lstColnames.insert(row, value.toString());
	//	m_lstColnames.removeAt(dragedRow);
	//	emit dataChanged(index, index);
	//
	//	return false;
	//}
	////emit dataChanged(index, index);
	return true;
}
//
//QStringList PrioritySelectorListModel::mimeTypes() const
//{
//	QStringList types;
//	types << "application/vnd.text.list";
//	return types;
//}
//
//QMimeData * PrioritySelectorListModel::mimeData(const QModelIndexList & indexes) const
//{
//	QMimeData *mimeData = new QMimeData();
//	QByteArray encodedData;
//
//	QDataStream stream(&encodedData, QIODevice::WriteOnly);
//
//	foreach(const QModelIndex index, indexes) {
//		if (index.isValid()) {
//			m_DragedItemIndex = index;
//			QString text = data(index, Qt::DisplayRole).toString();
//			stream << text;
//		}
//	}
//
//	mimeData->setData("application/vnd.text.list", encodedData);
//	return mimeData;
//}
//
//bool PrioritySelectorListModel::dropMimeData(const QMimeData *data,
//	Qt::DropAction action, int row, int column, const QModelIndex &parent)
//{
//	if (action == Qt::IgnoreAction)
//		return true;
//
//	if (!data->hasFormat("application/vnd.text.list"))
//		return false;
//
//	if (column > 0)
//		return false;
//
//	int beginRow;
//
//	if (row != -1)
//		beginRow = row;
//	else if (parent.isValid())
//		beginRow = parent.row();
//	else
//		beginRow = rowCount(QModelIndex());
//	QByteArray encodedData = data->data("application/vnd.text.list");
//	QDataStream stream(&encodedData, QIODevice::ReadOnly);
//	QStringList newItems;
//	int rows = 0;
//
//	while (!stream.atEnd()) {
//		QString text;
//		stream >> text;
//		newItems << text;
//		++rows;
//	}
//
//	insertRows(beginRow, rows, QModelIndex());
//	foreach(QString text, newItems) {
//		QModelIndex idx = index(beginRow, 0, QModelIndex());
//		PrioritySelectorListModel :: setData(idx, text, Qt::EditRole);
//		beginRow++;
//	}
//
//	return true;
//}



/*
bool PrioritySelectorListModel::insertRows(int row, int count, const QModelIndex &index)
{
	if (count < 1 || row < 0 || row > rowCount() || index.isValid())
		return false;
	beginInsertRows(QModelIndex(), row, row );//+ count - 1);
	//for (int curIndex = row, end = row + count; curIndex < end; ++curIndex)
	//QModelIndex ItemIndex = m_pLstView->currentIndex();
	//QString itemText = ItemIndex.data(Qt::DisplayRole).toString();
		m_lstColnames.insert(row, index.data(Qt::DisplayRole).toString());
	endInsertRows();
	
	return true;
}*/
/*
bool PrioritySelectorListModel::removeRows(int row, int count, const QModelIndex &index)
{
	if (count < 1 || row < 0 || (row + count) > rowCount() || index.isValid())
		return false;
	beginRemoveRows(QModelIndex(), row, row );//+ count - 1);
	//for (int curIndex = row, end = row + count; curIndex < end; ++curIndex)
		m_lstColnames.removeAt(row);
	endRemoveRows();
	return true;
}
*/

