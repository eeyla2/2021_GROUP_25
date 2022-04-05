
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/** @file
* This file contains the declaration of functions of the gui of the library.
*/

/** qt libraries
* all necessary qt headers inclusion for different libraries
*/
#include <QStatusBar>
#include <QMainWindow>

/** VTK libraries
* all necessary VTK headers inclusion for different libraries
*/
#include <vtkCubeSource.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkPolyDataMapper.h>
#include <vtkSTLReader.h>
#include <vtkPlane.h>
#include <vtkSmartPointer.h>
#include <vtkShrinkFilter.h>
#include <vtkClipPolyData.h>
#include <vtkPolyData.h>
#include <vtkClipDataSet.h>
#include <vtkSTLWriter.h>
#include <vtkTextMapper.h>
#include <vtkTextProperty.h>
#include <vtkAlgorithm.h>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

 /** functions
* all necessary functions declaration for different buttons in the gui
*/
public slots:
    void handleOpenFileButton();
    void handleSaveButton();
    void handleHelpButton();
    void handlePrintButton();
    void handleNewWindowButton();
    void on_shapeColor_released();
    void on_backgroundColor_released();
    void on_cube_released();
    void on_sphere_released();
    void on_shrinkFilter_toggled(bool Shrink_Status);
    void on_clipperFilter_toggled(bool Clipper_Status);

    
  

    // ---------------------------------------------------------------------

 /** signals
* all necessary signals inclusion for functions of the libraries
*/  
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
    vtkSmartPointer<vtkSTLWriter> Writer = vtkSmartPointer<vtkSTLWriter>::New();
    vtkSmartPointer<vtkAlgorithm> General;

    //screen2
    vtkSmartPointer<vtkActor> actor2 = vtkSmartPointer<vtkActor>::New();
    vtkSmartPointer<vtkNamedColors> colors2 = vtkSmartPointer<vtkNamedColors>::New();
    vtkSmartPointer<vtkDataSetMapper> mapper2 = vtkSmartPointer<vtkDataSetMapper>::New();
    vtkSmartPointer<vtkRenderer> renderer2 = vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow2 = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    vtkSmartPointer<vtkClipDataSet> Clipper_Filter2 = vtkSmartPointer<vtkClipDataSet>::New();
    vtkSmartPointer<vtkShrinkFilter> Shrink_Filter2 = vtkSmartPointer<vtkShrinkFilter>::New();
    vtkSmartPointer<vtkRenderer> renderer3 = vtkSmartPointer<vtkRenderer>::New();

};


#endif // MAINWINDOW_H

