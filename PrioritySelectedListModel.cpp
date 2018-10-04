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
		return false;

	//emit dataChanged(index, index);
	return true;
}