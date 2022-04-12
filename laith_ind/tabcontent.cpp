#include "tabcontent.h"
#include "ui_tabcontent.h"
#include "mainwindow.h"

tabcontent::tabcontent(QWidget *parent) : QWidget(parent),
                                          ui(new Ui::tabcontent)
{
    ui->setupUi(this);

    //apply the interface of the black screen
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    ui->qvtkWidget->SetRenderWindow(renderWindow);

    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

    emit statusUpdateMessage(QString("New Tab"), 0);
}

tabcontent::~tabcontent()
{
    delete ui;
}
