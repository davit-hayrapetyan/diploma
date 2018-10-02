#ifndef DATASHEETMODEL_H
#define DATASHEETMODEL_H

#include <QAbstractTableModel>
#include <Data.h>

class DataSheetModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	DataSheetModel(QObject *parent = 0);
	~DataSheetModel();

	Data* m_pData;

	virtual int rowCount(const QModelIndex & parent = QModelIndex()) const override;

	virtual int columnCount(const QModelIndex & parent = QModelIndex()) const override;

	virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

};

#endif
