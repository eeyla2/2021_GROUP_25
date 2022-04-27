#ifndef CURRENTANDRECENTSTL_H
#define CURRENTANDRECENTSTL_H
#include <QAbstractListModel>

class CurrentAndRecentSTL : public QAbstractListModel
{
   Q_OBJECT 
public:
    // Constructor
   explicit CurrentAndRecentSTL(QObject *parent = 0): QAbstractListModel(parent) {}


    // Virtual functions that must be defined in a valid ListModel
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;

    // To allow modifying stored list
    void addItem(const QString &newName);
    void insertItem(const QString &newName, const QModelIndex &index);
    void removeItem(const QModelIndex &index);
    void clearList();

private:
    std::vector<QString> modelNames;
};

#endif // CURRENTANDRECENTSTL_H
