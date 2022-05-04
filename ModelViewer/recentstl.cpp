//recentstl.h


#include "recentstl.h"

int RecentSTL::rowCount(const QModelIndex &parent) const
{
    return modelNames.size();
}

// function allows the listView to request data at index
// QVariant is just Qt's way of defining a variable that could be any
// basic type (int, float, double, string, ... )
QVariant RecentSTL::data(const QModelIndex &index, int role) const
{
    // Check that the index is valid
    if (!index.isValid())

        return QVariant();

    if (index.row() >= modelNames.size() || index.row() < 0)
        return QVariant();

    // Return item name as display variable
    if (role == Qt::DisplayRole)
    {
        return QVariant(modelNames[index.row()]);
    }
    else
    {
        return QVariant();
    }
}

// To allow modifying stored list
void RecentSTL::addItem(const QString &newName )
{
    // This emits a signal to warn the listView that extra rows will be added
    emit beginInsertRows(QModelIndex(), modelNames.size(), modelNames.size() );
    // Add the extra item to the list
    modelNames.push_back(newName);
    // Emits a signal to say rows have been added.
    emit endInsertRows();
}

void RecentSTL::removeItem(const QModelIndex &index)
{
    //?? (~ same as add item)
    //int currentRow = index.row();

    emit beginRemoveRows(QModelIndex(), index.row(), index.row());
    //some code to remove the row at a specific 
    auto itPos = modelNames.begin() + index.row();

    modelNames.erase(itPos);
    emit endRemoveRows();
}