/** @file
 * This file contains the implementation of the gui of the library.
 */

/** VTK libraries
 * all necessary VTK headers inclusion for different libraries
 */
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
#include <vtkPolyDataMapper.h>
#include <vtkSTLReader.h>
#include <vtkPlane.h>
#include <vtkSTLWriter.h>
#include <vtkTextMapper.h>
#include <vtkTextProperty.h>
#include <vtkShrinkFilter.h>
#include <vtkSphereSource.h>
#include <vtkAlgorithm.h>



/** Qt libraries
 * all necessary Qt headers inclusion for different libraries
 */

#include <QColorDialog>
#include <QDebug>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QCheckBox>
#include <QStatusBar>
#include <QTabWidget>
#include <QString>


/** include lheaders
 * all necessary includes for other files required 
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabcontent.h"

/** Main Window
 * implementation of functions in the main window class
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
										  ui(new Ui::MainWindow)
{

	ui->setupUi(this);

	// Connect the statusUpdateMessage() signal of the showMessage slot of the status Bar
	connect(this, &MainWindow::statusUpdateMessage, ui->statusbar, &QStatusBar::showMessage);

	// Connect the triggered() signal of the saveButton object to the handleSaveButton slot in this object
	connect(ui->saveButton, &QAction::triggered, this, &MainWindow::handleSaveButton);

	// Connect the triggered() signal of the openFileButton object to the handleOpenFileButton slot in this object
	connect(ui->openFileButton, &QAction::triggered, this, &MainWindow::handleOpenFileButton);

	// Connect the triggered() signal of the printButton object to the handlePrintButton slot in this object
	connect(ui->printButton, &QAction::triggered, this, &MainWindow::handlePrintButton);

	// Connect the triggered() signal of the addButton object to the handleAddButton slot in this object
	connect(ui->helpButton, &QAction::triggered, this, &MainWindow::handleHelpButton);

	// Connect the triggered() signal of the addButton object to the handleAddButton slot in this object
	connect(ui->newWindowButton, &QAction::triggered, this, &MainWindow::handleNewWindowButton);

	// Connect the triggered() signal of the addButton object to the handleAddButton slot in this object
	//connect(ui->newTabButton, &QAction::triggered, this, &MainWindow::handleNewTabButton);

	vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
	ui->qvtkWidget->SetRenderWindow(renderWindow);

	renderer = vtkSmartPointer<vtkRenderer>::New();
	// vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
}

MainWindow::~MainWindow()
{
	delete ui;
}

/** handleOpenFile
 * opens and loads features of STL file into the renderer
 */
void MainWindow::handleOpenFileButton()
{

	QString fileName = QFileDialog::getOpenFileName(this, tr("Open STL File"), "/home", tr("STL Files (*.stl)"));

	// Convert QString to standard C string
	QByteArray STL = fileName.toLatin1();
	const char *c_fileName = STL.data();

	General = reader;
	reader->SetFileName(c_fileName);
	reader->Update();

	// Code to display the STL file data
	mapper->SetInputConnection(reader->GetOutputPort());

	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();

	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
	actor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());

	// Add the actor to the scene
	renderer->AddActor(actor);
	renderer->SetBackground(colors->GetColor3d("Blue").GetData());

	// Setup the renderers's camera
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);
	renderer->ResetCameraClippingRange();

	emit statusUpdateMessage(QString("STL File done loading"), 0);
	ui->qvtkWidget->GetRenderWindow()->Render();
}

/*
void handleSameWorld()
{

	QString fileName = QFileDialog::getOpenFileName(this, tr("Open STL File"), "/home", tr("STL Files (*.stl)"));

	// Convert QString to standard C string
	QByteArray STL = fileName.toLatin1();
	const char *c_fileName = STL.data();

	General = reader;
	reader->SetFileName(c_fileName);
	reader->Update();

	// Code to display the STL file data
	mapper->SetInputConnection(reader->GetOutputPort());

	// New adder created to store the actor for the new model inside
	vtkSmartPointer<vtkActor> actorNew = vtkSmartPointer<vtkActor>::New();
	actorNew->SetMapper(mapper);
	actorNew->GetProperty()->EdgeVisibilityOn();

	for (unsigned int i = 0; i < 3; i++)
	{
		if ((actor->GetPosition(i)) == actorNew->Getactor(i))
int greatestBound=-1000000;
			for (int j = 0; j < 6; j++)
			{
				if (actor->GetBounds(i)==
			}


		actorNew->AddPosition(i)->(actor->(GetPosition(i)+GetBounds)
		actor->SetMapper(mapper);
		actor->GetProperty()->EdgeVisibilityOn();


	actorNew->SetMapper(mapper);
	actorNew->GetProperty()->EdgeVisibilityOn();

	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
	
	actor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());

	// Add the actor to the scene
	renderer->AddActor(actor);
	renderer->SetBackground(colors->GetColor3d("Blue").GetData());

	// Setup the renderers's camera
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);
	renderer->ResetCameraClippingRange();
}
	*/

/** handleOpenfile
 * function that saves an STL files after making changes to it
 */
void MainWindow::handleSaveButton()
{

	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
													"/home",
													tr("Save in STL File (*.STL)"));

	// Convert QString to standard C string
	QByteArray STL = fileName.toLatin1();
	const char *c_fileName = STL.data();

	QFile file(fileName);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{

		// write file then close
		Writer->SetFileName(c_fileName);
		Writer->SetInputConnection(Writer->GetOutputPort());
		Writer->Write();
	}
	file.close();
}

/** handlePrintFile
 * function that prints an STL files into paper
 */
void MainWindow::handlePrintButton()
{
	// (https://kitware.github.io/vtk-examples/site/Cxx/GeometricObjects/ParametricObjectsDemo/) this link might help
}

/** handleHelpButton
 * function that displays a text file with instructions on how to use other parts of the software
 */
void MainWindow::handleHelpButton()
{
}

/** onShapeColor
 * function that enables the user to change the color of the object
 */
void MainWindow::on_shapeColor_released()
{

	QColor Color = QColorDialog::getColor(Qt::white, this, "Choose Color");

	// validation of color selected
	if (Color.isValid())
	{

		double red = Color.redF();
		double green = Color.greenF();
		double blue = Color.blueF();
		actor->GetProperty()->SetColor(red, green, blue);
	}

	// rerenders the window after the color change
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();
	emit statusUpdateMessage(QString("Object color changed"), 0);
}

/** onShrinkFilters
 * function that enables the user to shrink the object
 */
void MainWindow::on_shrinkFilter_toggled(bool Shrink_Status)
{

	if (Shrink_Status == true)
	{
		//  all the other filters are disabled when shrinking is applied
		emit statusUpdateMessage(QString("Shrink filter activated"), 3000);

		Shrink_Filter->SetInputConnection(General->GetOutputPort());
		Shrink_Filter->SetShrinkFactor(.5);
		Shrink_Filter->Update();

		mapper->SetInputConnection(Shrink_Filter->GetOutputPort());
	}
	else
	{
		mapper->SetInputConnection(General->GetOutputPort());
	}
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();
}

/** onBackGroundColor
 * function that enables the user to change the background color
 */
void MainWindow::on_backgroundColor_released()
{
	QColor Color = QColorDialog::getColor(Qt::white, this, "Choose Back Ground Color");

	if (Color.isValid())
	{
		double red = Color.redF();
		double green = Color.greenF();
		double blue = Color.blueF();
		renderer->SetBackground(red, green, blue);
	}

	// renders the window again after the color change
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();

	emit statusUpdateMessage(QString("BackGround color changed"), 0);
}

/** onClipperFilter
 * function that enables the user to clip the shape
 */
void MainWindow::on_clipperFilter_toggled(bool Clipper_Status)
{
	if (Clipper_Status == true)
	{
		// checked_Box_Status_Updater(2);
		emit statusUpdateMessage(QString("Clip filter applied"), 3000);

		planeLeft->SetOrigin(0.0, 0.0, 0.0);
		planeLeft->SetNormal(-1.0, 0.0, 0.0);

		Clipper_Filter->SetInputConnection(General->GetOutputPort());
		Clipper_Filter->SetClipFunction(planeLeft.Get());
		mapper->SetInputConnection(Clipper_Filter->GetOutputPort());
	}
	else
	{
		mapper->SetInputConnection(General->GetOutputPort());
	}
	renderWindow->Render();
	// reader->Update();
	ui->qvtkWidget->GetRenderWindow()->Render();
}

/** onCube
 * function that opens a random cube
 */
void MainWindow::on_cube_released()
{
	// Create a cube using a vtkCubeSource
	vtkSmartPointer<vtkCubeSource> cubeSource = vtkSmartPointer<vtkCubeSource>::New();

	General = cubeSource;
	mapper->SetInputConnection(cubeSource->GetOutputPort());

	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();

	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
	actor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());

	// Add the actor to the scene
	renderer->AddActor(actor);
	renderer->SetBackground(colors->GetColor3d("Silver").GetData());

	// Setup the renderers's camera
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);
	renderer->ResetCameraClippingRange();

	// renders the window again after the color change
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();

	emit statusUpdateMessage(QString("Cube Displayed"), 0);
}

/** onSphere
 * function that opens random sphere
 */
void MainWindow::on_sphere_released()
{
	// Create a cube using a vtkCubeSource
	vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();

	General = sphereSource;
	mapper->SetInputConnection(sphereSource->GetOutputPort());

	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();

	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
	actor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());

	// Add the actor to the scene
	renderer->AddActor(actor);
	renderer->SetBackground(colors->GetColor3d("Silver").GetData());

	// Setup the renderers's camera
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);
	renderer->ResetCameraClippingRange();

	// renders the window again after the color change
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();

	emit statusUpdateMessage(QString("Sphere displayed"), 0);
}

/*void seconndting(){
	
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open STL File"), "/home", tr("STL Files (*.stl)"));
		
	// Convert QString to standard C string
	QByteArray STL = fileName.toLatin1();
	const char* c_fileName = STL.data();

	General = reader;
	reader->SetFileName(c_fileName);
	reader->Update();

	// Code to display the STL file data
	mapper->SetInputConnection(reader->GetOutputPort());

	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();

	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
	actor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());

	// Add the actor to the scene
	renderer2->AddActor(actor);
	renderer2->SetBackground(colors->GetColor3d("Blue").GetData());

	// Setup the renderers's camera
	renderer2->ResetCamera();
	renderer2->GetActiveCamera()->Azimuth(30);
	renderer2->GetActiveCamera()->Elevation(30);
	renderer2->ResetCameraClippingRange();


	ui->qvtkWidget->GetRenderWindow()->Render();

}*/

//closes any tab that is opened
void MainWindow::on_tabWidget_tabCloseRequested(int index){

ui->tabWidget->removeTab(index);

}

//create new tab 
void MainWindow::handleNewWindowButton(){

     ui->tabWidget->addTab(new tabcontent(), QString("Tab %0").arg(ui->tabWidget->count() +1 ) );//still need to know how to make the tab have the name of the filer
	 ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}