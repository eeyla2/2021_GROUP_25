#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QColorDialog>
#include <QColor>
#include <QDebug>
#include <QApplication>
#include <QWidget>
#include <QMessageBox>

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

#include <vtkOutlineFilter.h>
#include <vtkPolyDataMapper.h>

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

	vtkNew<vtkActor> actor2;
    vtkNew<vtkActor> actor3;

	// Create colors
    vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();

    // Create a renderer, and render window
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

	// Clip Filter
	vtkSmartPointer<vtkPlane> planeLeft = vtkSmartPointer<vtkPlane>::New();
	vtkSmartPointer<vtkClipDataSet> clipFilter = vtkSmartPointer<vtkClipDataSet>::New();

	// Shrink Filter
	vtkSmartPointer<vtkShrinkFilter> shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();

	// Load and Render STL
	vtkSmartPointer<vtkAlgorithm> operationFilter;      // Generic Pointer

	vtkNew<vtkOutlineFilter> outlineFilter;

	vtkNew<vtkDataSetMapper> outlineMapper;

	vtkNew<vtkActor> outlineActor;

	vtkNew<vtkSTLReader> reader;

	vtkSmartPointer<vtkCubeSource> cubeSource = vtkSmartPointer<vtkCubeSource>::New();

	vtkSmartPointer<vtkGeometryFilter> convertToPolygonal = vtkSmartPointer<vtkGeometryFilter>::New();

    ~MainWindow();

public slots:
    void handleRenderCube();
    void handleRenderPyramid();
    void handleChangeModelColor();
    void handleChangeOutlineColor();
    void handleChangeBackgroundColor();

    void on_clipFilter_stateChanged(int);
    void on_shrinkFilter_stateChanged(int);
    void on_outlineFilter_stateChanged(int);
    void on_edgeVisibilityFilter_stateChanged(int);
    void on_actionFileOpen_triggered();
    void on_actionHelp_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
