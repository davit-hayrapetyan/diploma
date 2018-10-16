#ifndef PRIORITYSELECTORMODEL_H
#define PRIORITYSELECTORMODEL_H

#include <QStringListModel>
#include <QStringList>
#include <QPersistentModelIndex>
#include <QSet>
#include <QListView>
#include <QMimeData>
class PrioritySelectorListModel : public QStringListModel
{
	Q_OBJECT
public:
	PrioritySelectorListModel(QObject *parent = 0);
	~PrioritySelectorListModel();
	Qt::DropActions supportedDropActions() const;
	Qt::DropActions supportedDragActions() const;
	QStringList mimeTypes() const;
	QMimeData* mimeData(const QModelIndexList &indexes) const;
	bool dropMimeData(const QMimeData *data,
		Qt::DropAction action, int row, int column, const QModelIndex &parent);
	void addCols(QStringList lstColNames);
	void setParent(QListView* lstView);
protected:
//	bool insertRows(int row, int count, const QModelIndex &parent);
//	bool removeRows(int row, int count, const QModelIndex &parent);
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
	virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;

private:
	QListView* m_pLstView;
	QStringList m_lstColnames;
	mutable QModelIndex m_DragedItemIndex;

	QSet<QPersistentModelIndex> m_lstCheckedItems;
};

#endif