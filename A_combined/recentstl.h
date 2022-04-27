#ifndef RECENTSTL_H
#define RECENTSTL_H
#include <QAbstractListModel>

class RecentSTL : public QAbstractListModel
{
    Q_OBJECT
public:
     // Constructor
   explicit RecentSTL(QObject *parent = 0): QAbstractListModel(parent) {}

   // Virtual functions that must be defined in a valid ListModel
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;

// To allow modifying CurrentSTLs stored list
    void addItem(const QString &newName);
    void removeItem(const QModelIndex &index);
    void clearList();


private:
    std::vector<QString> modelNames;
};

#endif // RECENTSTL_H
