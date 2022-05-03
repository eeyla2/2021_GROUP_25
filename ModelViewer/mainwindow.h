//mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/** @file
* This file contains the necessary Qt and VTK libraries for the program to run.
*/

/** Brief description
* The declaration of how things (actors, mappers etc.) will be stored.
* Declaration of the various functions that will be called when buttons are pressed in the GUI.
*/

#include <QMainWindow>
#include <QStatusBar>
#include <QFileDialog>
#include <QFile>
#include <QColorDialog>
#include <QColor>
#include <QDebug>
#include <QApplication>
#include <QString>
#include <QWidget>
#include <QMessageBox>
#include <QModelIndex>

#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
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
#include <vtkSTLReader.h>
#include <vtkCompositeDataPipeline.h>
#include <vtkAlgorithm.h>
#include <vtkGeometryFilter.h>
#include <vtkPlane.h>
#include <vtkClipDataSet.h>
#include <vtkShrinkFilter.h>
#include <vtkCellArray.h>
#include <vtkPoints.h>
#include <vtkPyramid.h>
#include <vtkUnstructuredGrid.h>
#include <vtkCutter.h>
#include <vtkProp3d.h>
#include <vtkMassProperties.h>

#include <vtkOutlineFilter.h>
#include <vtkPolyDataMapper.h>

// Printing to .PNG
#include <vtkPNGWriter.h>
#include <vtkVersion.h>
#include <vtkWindowToImageFilter.h>

//list of current STLs and recent files
#include <QAbstractListModel>
#include "currentstl.h"
#include "recentstl.h"


#include "../model_library/model.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    // Now need to create a VTK render window and link it to the QtVTK widget
	vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;

	// Create an actor that is used to set the model's properties for rendering and place it in the window
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

    // Create a mapper that will hold the cube's geometry in a format suitable for rendering
	vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();

	// Create colors
    vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();

    // Create a renderer, and render window
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

	// Clip Filter
	vtkSmartPointer<vtkPlane> planeLeft = vtkSmartPointer<vtkPlane>::New();
	vtkSmartPointer<vtkClipDataSet> clipFilter = vtkSmartPointer<vtkClipDataSet>::New();

	// Shrink Filter
	vtkSmartPointer<vtkShrinkFilter> shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();

	// Model Properties
	vtkSmartPointer<vtkMassProperties> modelProperties = vtkSmartPointer<vtkMassProperties>::New(); 

	//Cutter
	vtkSmartPointer<vtkCutter> planeCutter = vtkSmartPointer<vtkCutter>::New();
	vtkSmartPointer<vtkPlane> plane = vtkSmartPointer<vtkPlane>::New();

	// Load and Render STL
	vtkSmartPointer<vtkAlgorithm> modelData;      // Generic Pointer  - prev called operation filter

	vtkNew<vtkOutlineFilter> outlineFilter;

	vtkNew<vtkDataSetMapper> outlineMapper;

	vtkNew<vtkActor> outlineActor;

	vtkNew<vtkSTLReader> reader;

	vtkSmartPointer<vtkCubeSource> cubeSource = vtkSmartPointer<vtkCubeSource>::New();

	vtkSmartPointer<vtkGeometryFilter> convertToPolygonal = vtkSmartPointer<vtkGeometryFilter>::New();

	// Screenshot
    vtkNew<vtkWindowToImageFilter> windowToImageFilter;
    vtkNew<vtkPNGWriter> writer;

//add and removing from list
	void listCurrentSTLs(const QString& fileName);
	void listRecentSTLs(const QString& fileName);
    void removeCurrentSTLs();

    ~MainWindow();

public slots:
    void handleRenderCube();
    void handleRenderPyramid();
    void handleChangeModelColor();
    void handleChangeOutlineColor();
    void handleChangeBackgroundColor();
	
	void handleChangePosition();
//	void handleDisplayProperties();
	void handleCutter(); // will modify to fit format

	void handleInsertObject();
	void handleRemoveObject();

	void on_clipFilter_stateChanged(int);
    void on_shrinkFilter_stateChanged(int);
    void on_outlineFilter_stateChanged(int);
    void on_edgeVisibilityFilter_stateChanged(int);

    void on_actionFileOpen_triggered();
	//void vtk_declare(Model &theModel);

    void on_actionHelp_triggered();
    void on_actionPrint_triggered();

	void handleNewWindowButton();
	void on_tabWidget_tabCloseRequested(int index);

signals:
	void statusUpdateMessage( const QString & message, int timeout );

private:
    Ui::MainWindow *ui;
	
	int x;
	int y;
	int z;
//  double volume;

	QString fileName; 


    char lastCharacterOfFile;


    int numSTL=0;
    std::vector<vtkSmartPointer<vtkSTLReader>> listOfSTLReaders;
    std::vector<vtkSmartPointer<vtkDataSetMapper>> listOfSTLMappers;
    std::vector<vtkSmartPointer<vtkActor>> listOfSTLActors;


    std::vector<vtkSmartPointer<vtkDataSetMapper>> listOfMappers;
    std::vector<vtkSmartPointer<vtkActor>> listOfActors;
    std::vector<vtkSmartPointer<vtkUnstructuredGrid>> listOfUnstructuredGrids;

    QModelIndex selectedIndexAdd;
    QModelIndex selectedIndexRemove;
	CurrentSTL nameListCurrent;
	RecentSTL nameListRecent;
	
};

//class for list of stl

// class currentModelList : public QAbstractListModel
// {
//     Q_OBJECT
// public:
// 	// Constructor
//     explicit currentModelList(QObject *parent = 0) : QAbstractListModel(parent) {}

#endif // MAINWINDOW_H
