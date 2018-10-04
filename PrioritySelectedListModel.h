#pragma once

#include <QStringListModel>
#include <QStringList>
#include <QPersistentModelIndex>
#include <QSet>
class PrioritySelectedListModel : public QStringListModel
{
	Q_OBJECT
public:
	PrioritySelectedListModel(QObject *parent = 0);
	~PrioritySelectedListModel();
	Qt::DropActions supportedDropActions() const;
	void addCols(QStringList lstColNames);
protected:
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
	virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;

private:
	QStringList m_lstColnames;

	QSet<QPersistentModelIndex> m_lstCheckedItems;
};