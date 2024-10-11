//
// Created by 40745 on 02/06/2024.
//

#ifndef OOP_A6_7_ELIZALUCHIAN_EVENTTABLEMODEL_H
#define OOP_A6_7_ELIZALUCHIAN_EVENTTABLEMODEL_H

#include <QAbstractTableModel>
#include "Controller/Controller.h"

class EventTableModel : public QAbstractTableModel {

private:
    Controller* controller;

public:
    explicit EventTableModel(Controller* controller, QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

};


#endif //OOP_A6_7_ELIZALUCHIAN_EVENTTABLEMODEL_H
