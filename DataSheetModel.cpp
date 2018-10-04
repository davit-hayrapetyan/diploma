#include "DataSheetModel.h"
#include <QColor>
#include <QBrush>


DataSheetModel::DataSheetModel(QObject *parent)
	: QAbstractTableModel(parent)
{
	m_pData = new Data();
}


DataSheetModel::~DataSheetModel()
{
	delete m_pData;
}

int DataSheetModel::rowCount(const QModelIndex &parent) const
{
	return m_pData->m_Data.size();
}

int DataSheetModel::columnCount(const QModelIndex &parent) const
{
	return m_pData->m_Data.begin()->size();
}

QVariant DataSheetModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	switch (role)
	{
	case Qt::DisplayRole:
		return QString::number(m_pData->m_Data[m_pData->m_IndexMap[index.row()]].at(index.column()));

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
			for (auto&&[first, second] : m_pData->m_ColIndex)
			{
				if (section == second)
				{
					return QString::fromStdString(first);
				}
			}
		}
	}

	return QAbstractTableModel::headerData(section, orientation, role);
}

QStringList DataSheetModel::getColNames()
{
	QStringList Names;
	for (auto&&[first, second] : m_pData->m_ColIndex)
	{
		Names.append(QString::fromStdString(first));
	}
	return Names;
}

