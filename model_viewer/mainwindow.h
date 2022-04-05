#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>

#include <QFileDialog>
#include <QFileInfo>
#include <QTextEdit>
#include <QString>
#include <QCheckBox>

#include <QColorDialog>


#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
#include <vtkPyramid.h>

#include <vtkCylinderSource.h> // for previous cylinder example

#include <vtkSphereSource.h>

#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkPolyData.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkGenericOpenGLRenderWindow.h>

// for loading cells/from file
#include <vtkCellArray.h>
#include <vtkCellType.h>
#include <vtkPoints.h>
#include <vtkProperty.h>
#include <vtkTetra.h>
#include <vtkUnstructuredGrid.h>

// for STLs
#include <vtkPolyDataMapper.h>
#include <vtkSTLReader.h>
//////////////////////////#include <iostream> //for stlfilename? - now included via model library

#include <vtkShrinkFilter.h>

#include <vtkGeometryFilter.h>
#include <vtkPointSource.h>
#include <vtkUnstructuredGridReader.h>
#include <vtkVertex.h>

#include <vtkClipDataSet.h>
#include <vtkPlane.h>

#include <array>    //for list of actor example?
//vectr included via library

#include <vtkHexahedron.h>

#include <vtkUnstructuredGridBase.h>

//################################

#include "copy_of_model_library/model_library/model.hpp"

//###########################


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //vtkPolyData* convert_ug_to_polydata(vtkNew<vtkUnstructuredGrid> the_ug);

public slots:

    void handleSaveAction();
    void handleOpenAction();

    void vtk_declare(Model &theModel);


    void handleCameraButton();
    void handleObjectColourButton();
    void handleBackgroundColourButton();
    void handleImportCubeButton();
    void handleImportPyramidButton();

    void handleShrinkCheckBox();
    void handleClipCheckBox();

signals:
    void statusUpdateMessage( const QString & message, int timeout );

private:
    Ui::MainWindow *ui;
    
    QString fileName; 


    char lastCharacterOfFile;

    QColor selectedShapeColor;
    QColor selectedBackgroundColor;
    

    vtkSmartPointer<vtkAlgorithm> modelData; //get rid of rhs?
    //vtkSmartPointer<vtkAlgorithm> modelData = vtkSmartPointer<vtkAlgorithm>::New(); //get rid of rhs?
    vtkNew<vtkNamedColors> colors;

    // vtkNew<vtkSTLReader> reader;
    
    int numSTL=0;
    std::vector<vtkSmartPointer<vtkSTLReader>> listOfSTLReaders;
    std::vector<vtkSmartPointer<vtkDataSetMapper>> listOfSTLMappers;
    std::vector<vtkSmartPointer<vtkActor>> listOfSTLActors;

    //vtkNew<vtkPolyDataMapper> mapper; 
    vtkNew<vtkDataSetMapper> mapper; 
    vtkNew<vtkActor> actor;


    //std::vector<vtkSmartPointer<vtkPolyDataAlgorithm>> listOfSources;
   
    std::vector<vtkSmartPointer<vtkDataSetMapper>> listOfMappers;
    std::vector<vtkSmartPointer<vtkActor>> listOfActors;
    std::vector<vtkSmartPointer<vtkUnstructuredGrid>> listOfUnstructuredGrids;
    



    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
};

#endif // MAINWINDOW_H