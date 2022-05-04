//currentstl.h
#ifndef CURRENTSTL_H
#define CURRENTSTL_H


/** @file
* The file for managingt the list of STLS currently present in 'world'
*/


#include <QAbstractListModel>

class CurrentSTL : public QAbstractListModel
{
   Q_OBJECT 
public:
    // Constructor
   explicit CurrentSTL(QObject *parent = 0): QAbstractListModel(parent) {}


    // Virtual functions that must be defined in a valid ListModel
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;


    // To allow modifying CurrentSTLs stored list
    void addItem(const QString &newName);
    void insertItem(const QString &newName,  const QModelIndex &index);
    void removeItem(const QModelIndex &index);
    void clearList();


private:
    std::vector<QString> modelNames;
    
};

#endif // CURRENTSTL_H
