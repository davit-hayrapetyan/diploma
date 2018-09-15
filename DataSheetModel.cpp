#include "DataSheetModel.h"
#include <QColor>
#include <QBrush>


DataSheetModel::DataSheetModel(QObject *parent)
	: QAbstractTableModel(parent)
{
}


DataSheetModel::~DataSheetModel()
{
}

int DataSheetModel::rowCount(const QModelIndex &parent) const
{
	return 21;
}

int DataSheetModel::columnCount(const QModelIndex &parent) const
{
	return 11;
}

QVariant DataSheetModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	switch (role)
	{
	case Qt::DisplayRole:
		return QString("Row%1, Column%2")
			.arg(index.row() + 1)
			.arg(index.column() + 1);

	default:
		return QVariant();
	}

	return QVariant();
}

QVariant DataSheetModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal)
	{
		if (role == Qt::DisplayRole)
		{
			if (section == 0)
				return QString("first");

			if (section == 1)
				return QString("second");

			if (section == 2)
				return QString("third");
		}
	}

	return QAbstractTableModel::headerData(section, orientation, role);
}