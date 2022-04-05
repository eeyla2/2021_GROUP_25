
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStatusBar>

#include <vtkNamedColors.h>
#include <QStatusBar>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <QMainWindow>
#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
#include <vtkSphereSource.h>
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkSTLReader.h>
#include <vtkPlane.h>
#include <vtkSmartPointer.h>
#include <vtkShrinkFilter.h>
#include <vtkClipPolyData.h>
#include <vtkPolyData.h>
#include <vtkClipDataSet.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkPolyData.h>
#include <vtkDataSetMapper.h>
#include <vtkProp3D.h>

#include <vtkCamera.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPlane.h>
#include <vtkPointData.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkCutter.h>

#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkGenericOpenGLRenderWindow.h>




namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

 
public slots:
    void handleOpenButton();
    void handleCubeButton();
    void handleSphereButton(); 
    void handleModelColor();
    void handleBackgroundColor();
    void handleCutShape();
    void handleMotion();
  



    void on_Shrink_Filter_toggled(bool Shrink_Filter_Status);
    void on_Clipper_Filter_toggled(bool Clipper_Filter_Status);
    
  

    // ---------------------------------------------------------------------

   
signals:
    void statusUpdateMessage(const QString& message, int timeout);
    
    // ---------------------------------------------------------------------

private:
    Ui::MainWindow* ui;
  
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    vtkSmartPointer<vtkClipDataSet> Clipper_Filter = vtkSmartPointer<vtkClipDataSet>::New();
    vtkSmartPointer<vtkShrinkFilter> Shrink_Filter = vtkSmartPointer<vtkShrinkFilter>::New();
    vtkSmartPointer<vtkPlane> planeLeft = vtkSmartPointer<vtkPlane>::New();
    vtkSmartPointer<vtkCubeSource> cubeSource =vtkSmartPointer<vtkCubeSource>::New();
    vtkSmartPointer<vtkSphereSource> sphereSource =vtkSmartPointer<vtkSphereSource>::New();

};

#endif // MAINWINDOW_H

