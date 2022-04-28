//tabcontent.h
#ifndef TABCONTENT_H
#define TABCONTENT_H
/** @file
* This file contains..........
*/

/** Brief description
* The description..............
*/

#include <QWidget>


namespace Ui {
class tabcontent;
}

class tabcontent : public QWidget
{
    Q_OBJECT

public:
    explicit tabcontent(QWidget *parent = nullptr);
    ~tabcontent();

signals:
    void statusUpdateMessage(const QString& message, int timeout);

private:
    Ui::tabcontent *ui;
};

#endif // TABCONTENT_H