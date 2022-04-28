#ifndef TABCONTENT_H
#define TABCONTENT_H

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