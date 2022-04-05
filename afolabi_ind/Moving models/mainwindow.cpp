
#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
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
#include <vtkPolyDataMapper.h>
#include <vtkSTLReader.h>
#include <vtkPlane.h>
#include <vtkSmartPointer.h>
#include <vtkProp3D.h>

#include <QColorDialog>
#include <QDebug>           
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QStatusBar>



#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

	ui->setupUi(this);

	connect(this, &MainWindow::statusUpdateMessage, ui->statusbar, &QStatusBar::showMessage);
	connect(ui->actionFileOpen, &QAction::triggered, this, &MainWindow::handleOpenButton);
	connect(ui->CubeButton, &QPushButton::released, this, &MainWindow::handleCubeButton);
	connect(ui->SphereButton, &QPushButton::released, this, &MainWindow::handleSphereButton);
	connect(ui->ModelColor, &QPushButton::released, this, &MainWindow::handleModelColor);
	connect(ui->BackgroundColor, &QPushButton::released, this, &MainWindow::handleBackgroundColor);
	//	connect(ui->CutShape, &QPushButton::released, this, &MainWindow::handleCutShape);
	//	connect(ui->MoveObject, &QPushButton::released, this, &MainWindow::handleMoveObject);
	//connect(ui->XCoordinate, QOverload<const QString&>::of(&QSpinBox::valueChanged), this, &MainWindow::handleXCoordinate);
	//connect(ui->YCoordinate, QOverload<const QString&>::of(&QSpinBox::valueChanged), this, &MainWindow::handleYCoordinate);
	//connect(ui->ZCoordinate, QOverload<const QString&>::of(&QSpinBox::valueChanged), this, &MainWindow::handleZCoordinate);
	connect(ui->ChangeCoordinates, &QPushButton::released, this, &MainWindow::handleMotion);



	vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
	ui->qvtkWidget->SetRenderWindow(renderWindow);


	renderer = vtkSmartPointer<vtkRenderer>::New();

	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);


}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::handleOpenButton() {

	QString fileName = QFileDialog::getOpenFileName(this, tr("Open CAD File"), "/home", tr("CAD Files (*.stl)"));


	QByteArray ba = fileName.toLocal8Bit();
	const char* c_fileName = ba.data();

	reader->SetFileName(c_fileName);
	reader->Update();


	mapper->SetInputConnection(reader->GetOutputPort());

	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();

	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
	actor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());


	renderer->AddActor(actor);
	renderer->SetBackground(colors->GetColor3d("Silver").GetData());



	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);
	renderer->ResetCameraClippingRange();



}



void MainWindow::handleModelColor()
{



	QColor Color = QColorDialog::getColor(Qt::white, this, "Choose Color");

	if (Color.isValid())
	{
		double red = Color.redF();
		double green = Color.greenF();
		double blue = Color.blueF();
		actor->GetProperty()->SetColor(red, green, blue);
	}


	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();

}

void MainWindow::handleBackgroundColor()
{


	QColor Color = QColorDialog::getColor(Qt::white, this, "Choose Back Ground Color");
	if (Color.isValid())
	{
		double red = Color.redF();
		double green = Color.greenF();
		double blue = Color.blueF();
		renderer->SetBackground(red, green, blue);
	}

	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();

}



void MainWindow::on_Shrink_Filter_toggled(bool Shrink_Filter_Status)
{
	if (Shrink_Filter_Status == true)
	{

		emit statusUpdateMessage(QString("-"), 3000);


		Shrink_Filter->SetInputConnection(reader->GetOutputPort());
		Shrink_Filter->SetShrinkFactor(.5);
		Shrink_Filter->Update();


		mapper->SetInputConnection(Shrink_Filter->GetOutputPort());


	}
	else
	{
		mapper->SetInputConnection(reader->GetOutputPort());
	}
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();
}


void MainWindow::on_Clipper_Filter_toggled(bool Clipper_Filter_Status)
{
	if (Clipper_Filter_Status == true)
	{


		planeLeft->SetOrigin(0.0, 0.0, 0.0);
		planeLeft->SetNormal(-1.0, 0.0, 0.0);

		Clipper_Filter->SetInputConnection(reader->GetOutputPort());
		Clipper_Filter->SetClipFunction(planeLeft.Get());
		mapper->SetInputConnection(Clipper_Filter->GetOutputPort());
	}
	else
	{
		mapper->SetInputConnection(reader->GetOutputPort());
	}
	renderWindow->Render();

	ui->qvtkWidget->GetRenderWindow()->Render();

}

void MainWindow::handleCubeButton() {


	vtkSmartPointer<vtkCubeSource> cubeSource =
		vtkSmartPointer<vtkCubeSource>::New();

	vtkSmartPointer<vtkDataSetMapper> mapper =
		vtkSmartPointer<vtkDataSetMapper>::New();
	mapper->SetInputConnection(cubeSource->GetOutputPort());
	actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();
	vtkSmartPointer<vtkNamedColors> colors =
		vtkSmartPointer<vtkNamedColors>::New();
	actor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());


	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer); // ###### // Link a renderWindowInteractor to the renderer (this allows you to

	renderer->AddActor(actor);
	renderer->SetBackground(colors->GetColor3d("Silver").GetData());

	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);
	renderer->ResetCameraClippingRange();


	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();
}




void MainWindow::handleSphereButton() {


	vtkSmartPointer<vtkSphereSource> sphereSource =
		vtkSmartPointer<vtkSphereSource>::New();

	vtkSmartPointer<vtkDataSetMapper> mapper =
		vtkSmartPointer<vtkDataSetMapper>::New();
	mapper->SetInputConnection(sphereSource->GetOutputPort());
	actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();
	vtkSmartPointer<vtkNamedColors> colors =
		vtkSmartPointer<vtkNamedColors>::New();
	actor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());


	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer); // ###### // Link a renderWindowInteractor to the renderer (this allows you to

	renderer->AddActor(actor);
	renderer->SetBackground(colors->GetColor3d("Silver").GetData());

	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);
	renderer->ResetCameraClippingRange();


	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();
}



void MainWindow::handleMotion() {





	renderWindow->Render();
    ui->qvtkWidget->GetRenderWindow()->Render();
}