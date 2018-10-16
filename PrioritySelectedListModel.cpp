#include "PrioritySelectedListModel.h"

#include <QColor>
#include <QSize>

PrioritySelectedListModel::PrioritySelectedListModel(QObject *parent)
	: QStringListModel(parent)
{
	//m_lstColnames << "Col1" << "Col2" << "Col3" << "Col4" << "Col5";
	//setStringList(m_lstColnames);
}

PrioritySelectedListModel::~PrioritySelectedListModel()
{
}

Qt::DropActions PrioritySelectedListModel::supportedDropActions() const
{
	return Qt::CopyAction | Qt::MoveAction;
}

Qt::DropActions PrioritySelectedListModel::supportedDragActions() const
{
	return Qt::CopyAction | Qt::MoveAction;
}

QStringList PrioritySelectedListModel::mimeTypes() const
{
	QStringList types;
	types << "text/plain";
	return types;
}

QMimeData * PrioritySelectedListModel::mimeData(const QModelIndexList & indexes) const
{
	QMimeData *mimeData = new QMimeData();
	QByteArray encodedData;

	QDataStream stream(&encodedData, QIODevice::WriteOnly);

	foreach(QModelIndex index, indexes) {
		if (index.isValid()) {
			m_DragedItemindex = index;
			QString text = data(index, Qt::DisplayRole).toString();
			stream << text;
		}
	}

	mimeData->setData("text/plain", encodedData);
	return mimeData;
}

bool PrioritySelectedListModel::dropMimeData(const QMimeData * data, Qt::DropAction action, int row, int column, const QModelIndex & parent)
{
	if (action == Qt::IgnoreAction)
		return true;

	if (!data->hasFormat("text/plain"))
		return false;

	if (column > 0)
		return false;

	int beginRow;

	if (row != -1)
		beginRow = row;
	else if (parent.isValid())
		beginRow = parent.row();
	else
		beginRow = rowCount(QModelIndex());
	QByteArray encodedData = data->data("text/plain");
	QDataStream stream(&encodedData, QIODevice::ReadOnly);
	QStringList newItems;
	int rows = 0;

	while (!stream.atEnd()) {
		QString text;
		stream >> text;
		newItems << text;
		++rows;
	}

	insertRows(beginRow, rows, QModelIndex());
	foreach(QString text, newItems) {
		QModelIndex idx = index(beginRow, 0, QModelIndex());
		PrioritySelectedListModel::setData(idx, text, Qt::EditRole);
		beginRow++;
	}

	return true;
}

void PrioritySelectedListModel::addCols(QStringList lstColNames)
{
	m_lstColnames = lstColNames;
}



int PrioritySelectedListModel::rowCount(const QModelIndex & parent) const
{
	return m_lstColnames.count();
}

QVariant PrioritySelectedListModel::data(const QModelIndex & index, int role) const
{
	if (!index.isValid())
		return QVariant();

	switch (role)
	{
	case Qt::DisplayRole:
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

Qt::ItemFlags PrioritySelectedListModel::flags(const QModelIndex &index) const
{
	Qt::ItemFlags defaultFlags = QStringListModel::flags(index);
	if (index.isValid())
		return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | defaultFlags;
	else
		return Qt::ItemIsDropEnabled | defaultFlags;
}

bool PrioritySelectedListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (!index.isValid() || role != Qt::CheckStateRole)
		return false;

	if (value == Qt::Checked)
		m_lstCheckedItems.insert(index);
	else
		m_lstCheckedItems.remove(index);

	if (role == Qt::EditRole)
	{
		int row = index.row();
		int dragedRow = m_DragedItemindex.row();
		if (row < dragedRow)
			dragedRow++;
		m_lstColnames.insert(row, value.toString());
		m_lstColnames.removeAt(dragedRow);
		emit dataChanged(index, index);

		return false;
	}

	//emit dataChanged(index, index);
	return true;
}