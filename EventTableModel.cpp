//
// Created by 40745 on 02/06/2024.
//


// EventTableModel.cpp

#include "EventTableModel.h"

EventTableModel::EventTableModel(Controller* controller, QObject* parent)
        : QAbstractTableModel(parent), controller(controller) {}

int EventTableModel::rowCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return controller->getAllEventsController().size();
}

int EventTableModel::columnCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return 9; // Title, Description, Link, Number of People, Day, Month, Year, Hours, Minutes
}

QVariant EventTableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        const auto& events = controller->getAllEventsController();
        const Event& event = events.at(index.row());
        switch (index.column()) {
            case 0: return QString::fromStdString(event.getTitle());
            case 1: return QString::fromStdString(event.getDescription());
            case 2: return QString::fromStdString(event.getLink());
            case 3: return event.getNumberOfPeople();
            case 4: return event.getDay();
            case 5: return event.getMonth();
            case 6: return event.getYear();
            case 7: return event.getHours();
            case 8: return event.getMinutes();
        }
    }
    return QVariant();
}

QVariant EventTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0: return "Title";
                case 1: return "Description";
                case 2: return "Link";
                case 3: return "Number of People";
                case 4: return "Day";
                case 5: return "Month";
                case 6: return "Year";
                case 7: return "Hours";
                case 8: return "Minutes";
            }
        }
    }
    return QVariant();
}


