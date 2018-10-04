#ifndef PRIORITYSELECTORMODEL_H
#define PRIORITYSELECTORMODEL_H

#include <QStringListModel>
#include <QStringList>
#include <QPersistentModelIndex>
#include <QSet>
class PrioritySelectorListModel : public QStringListModel
{
	Q_OBJECT
public:
	PrioritySelectorListModel(QObject *parent = 0);
	~PrioritySelectorListModel();
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

#endif