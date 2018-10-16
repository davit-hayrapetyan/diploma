#ifndef PRIORITYSELECTORWIDGET_H
#define PRIORITYSELECTORWIDGET_H

#include <QListView>
#include <QMimeData>
#include <QDrag>
#include <QMouseEvent>
#include <QPoint>
#include <QApplication>

#include "PrioritySelectorListModel.h"
class PrioritySelectorListWidget :public QListView
{
	Q_OBJECT
public:
	PrioritySelectorListWidget(QWidget *parent = 0);
	~PrioritySelectorListWidget();
	void setListItems(QStringList list);
	/*
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);
	*/
private:
	PrioritySelectorListModel *m_pPrioritySelectorListModel;
	QStringList m_pNamesLists;
	QPoint m_DragStartPos;
};

#endif

