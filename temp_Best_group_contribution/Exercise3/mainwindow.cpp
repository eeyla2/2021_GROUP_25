#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // standard call to setup Qt UI (same as previously)
    ui->setupUi( this );

	ui->qvtkWidget->setRenderWindow( renderWindow );

    // Create an actor that is used to set the model's properties for rendering and place it in the window
	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();
	actor->GetProperty()->SetColor( colors->GetColor3d("White").GetData() );

    // Create a renderer, and render window
	ui->qvtkWidget->renderWindow()->AddRenderer( renderer );									// ###### ask the QtVTKOpenGLWidget for its renderWindow ######
	renderer->SetBackground( colors->GetColor3d("Silver").GetData() );

	// Initial Setup: Disable Filters When Model File is Not Loaded
    ui->clipFilter->setEnabled(false);
    ui->shrinkFilter->setEnabled(false);
    ui->outlineFilter->setEnabled(false);
    ui->edgeVisibilityFilter->setEnabled(false);
    ui->changeModelColor->setEnabled(false);
    ui->changeOutlineColor->setEnabled(false);

	// Connect the released() signal of the renderCube object to the handleRenderCube slot in this object
	connect( ui->renderCube, &QPushButton::released, this, &MainWindow::handleRenderCube );

	// Connect the released() signal of the renderPyramid object to the handleRenderPyramid slot in this object
	connect( ui->renderPyramid, &QPushButton::released, this, &MainWindow::handleRenderPyramid );

    // Connect the released() signal of the changeModelColor object to the handleChangeModelColor slot in this object
	connect( ui->changeModelColor, &QPushButton::released, this, &MainWindow::handleChangeModelColor );

	// Connect the released() signal of the changeOutlineColor object to the handleChangeOutlineColor slot in this object
	connect( ui->changeOutlineColor, &QPushButton::released, this, &MainWindow::handleChangeOutlineColor );

    // Connect the released() signal of the changeBackgroundColor object to the handleChangeBackgroundColor slot in this object
	connect( ui->changeBackgroundColor, &QPushButton::released, this, &MainWindow::handleChangeBackgroundColor );
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot implementation in mainwindow.cpp---------------------

void MainWindow::handleRenderCube() {

    ui->clipFilter->setEnabled(true);
    ui->shrinkFilter->setEnabled(true);
    ui->outlineFilter->setEnabled(true);
    ui->changeModelColor->setEnabled(true);
    ui->edgeVisibilityFilter->setEnabled(true);

    ui->clipFilter->setChecked(false);
    ui->shrinkFilter->setChecked(false);
    ui->outlineFilter->setChecked(false);
    ui->edgeVisibilityFilter->setChecked(true);

    // Remove Outline Filter From Previous Model
    renderer->RemoveActor(outlineActor);

    // Link the QtVTK widget with a VTK render window
	ui->qvtkWidget->setRenderWindow( renderWindow );

	mapper->SetInputConnection( cubeSource->GetOutputPort() );

	// Assign 'cubeSource' <vtkCubeSource> type to generic pointer 'operationFilter' <vtkAlgorithm> type
	operationFilter = cubeSource;

	actor->SetMapper(mapper);
	actor2->SetMapper(mapper);

	actor->GetProperty()->EdgeVisibilityOn();
    actor2->GetProperty()->EdgeVisibilityOn();

    actor2->SetPosition(0, 2, 0);

	ui->qvtkWidget->renderWindow()->AddRenderer( renderer );									// ###### ask the QtVTKOpenGLWidget for its renderWindow ######

	// Add the actor to the scene
	renderer->AddActor(actor);
	renderer->AddActor(actor2);

	// Setup the renderers's camera
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(0);
	renderer->GetActiveCamera()->Elevation(0);
	renderer->ResetCameraClippingRange();
    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

void MainWindow::handleRenderPyramid() {

    ui->clipFilter->setEnabled(true);
    ui->shrinkFilter->setEnabled(true);
    ui->outlineFilter->setEnabled(true);
    ui->changeModelColor->setEnabled(true);
    ui->edgeVisibilityFilter->setEnabled(true);

    ui->clipFilter->setChecked(false);
    ui->shrinkFilter->setChecked(false);
    ui->outlineFilter->setChecked(false);
    ui->edgeVisibilityFilter->setChecked(true);

    // Remove Outline Filter From Previous Model
    renderer->RemoveActor(outlineActor);

    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	vtkSmartPointer<vtkPyramid> pyramid = vtkSmartPointer<vtkPyramid>::New();
	vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();
	vtkSmartPointer<vtkUnstructuredGrid> ug = vtkSmartPointer<vtkUnstructuredGrid>::New();

    // Link the QtVTK widget with a VTK render window
	ui->qvtkWidget->setRenderWindow( renderWindow );

	// Setup Pyramid Model
    float p0[3] = {1.0, 1.0, 1.0};
    float p1[3] = {-1.0, 1.0, 1.0};
    float p2[3] = {-1.0, -1.0, 1.0};
    float p3[3] = {1.0, -1.0, 1.0};
    float p4[3] = {0.0, 0.0, 0.0};

    points->InsertNextPoint(p0);
    points->InsertNextPoint(p1);
    points->InsertNextPoint(p2);
    points->InsertNextPoint(p3);
    points->InsertNextPoint(p4);

    pyramid->GetPointIds()->SetId(0, 0);
    pyramid->GetPointIds()->SetId(1, 1);
    pyramid->GetPointIds()->SetId(2, 2);
    pyramid->GetPointIds()->SetId(3, 3);
    pyramid->GetPointIds()->SetId(4, 4);

    cells->InsertNextCell(pyramid);

    ug->SetPoints(points);
    ug->InsertNextCell(pyramid->GetCellType(), pyramid->GetPointIds());
    mapper->SetInputData(ug);

    // Convert 'convertToPolygonal' <vtkUnstructuredGrid> data type to <vtkGeometryFilter> or Polygonal Type
    convertToPolygonal->SetInputData(ug);
    // Assign Converted 'convertToPolygonal' <vtkGeometryFilter> or Polygonal type to generic pointer 'operationFilter' <vtkAlgorithm> type
    operationFilter = convertToPolygonal;

	// Create an actor that is used to set the pyramid's properties for rendering and place it in the window
	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();

	// Link the QtVTK widget with a renderer, and render window
	ui->qvtkWidget->renderWindow()->AddRenderer( renderer );									// ###### ask the QtVTKOpenGLWidget for its renderWindow ######

	// Add the actor to the scene
	renderer->AddActor(actor);

    // Setup the renderers's camera
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(0);
	renderer->GetActiveCamera()->Elevation(0);
	renderer->ResetCameraClippingRange();

	ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

void MainWindow::handleChangeModelColor() {

	QColor color = QColorDialog::getColor(Qt::red,this);

	if(color.isValid())
    {
        // Approach 1
            // actor->GetProperty()->SetColor( colors->GetColor3d("Blue").GetData() );

        // Approach 2
            // actor->GetProperty()->SetColor( color );

        // Approach 3
            // Returns red, blue, green colors components from the selected color in QColorDialog
        actor->GetProperty()->SetColor( color.redF(), color.greenF(), color.blueF() );
    }

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

void MainWindow::handleChangeBackgroundColor()
{
    QColor backgroundColor = QColorDialog::getColor(Qt::red,this);

	if(backgroundColor.isValid())
    {
        // Approach 1
            // renderer->SetBackground( colors->GetColor3d("Blue").GetData() );

        // Approach 2
            // renderer->SetBackground( backgroundColor );

        // Approach 3
            // Returns red, blue, green colors components from the selected color in QColorDialog
        renderer->SetBackground( backgroundColor.redF(), backgroundColor.greenF(), backgroundColor.blueF() );
    }

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

void MainWindow::handleChangeOutlineColor() {

	QColor color = QColorDialog::getColor(Qt::red,this);

	if(color.isValid())
    {
        // Returns red, blue, green colors components from the selected color in QColorDialog
        outlineActor->GetProperty()->SetColor( color.redF(), color.greenF(), color.blueF() );
    }

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

/// Clip Filter
void MainWindow::on_clipFilter_stateChanged(int amp)
{
    if(ui->clipFilter->isChecked())
    {
        if(ui->shrinkFilter->isChecked())
        {
            planeLeft->SetOrigin(0.0, 0.0, 0.0);
            planeLeft->SetNormal(-1.0, 0.0, 0.0);

            clipFilter->SetInputConnection( operationFilter->GetOutputPort() ) ;
            clipFilter->SetClipFunction( planeLeft.Get() );

            shrinkFilter->SetInputConnection(clipFilter->GetOutputPort());
            shrinkFilter->SetShrinkFactor(.8);
            shrinkFilter->Update();

            mapper->SetInputConnection( shrinkFilter->GetOutputPort() );
        }
        else
        {
            planeLeft->SetOrigin(0.0, 0.0, 0.0);
            planeLeft->SetNormal(-1.0, 0.0, 0.0);

            clipFilter->SetInputConnection( operationFilter->GetOutputPort() ) ;
            clipFilter->SetClipFunction( planeLeft.Get() );

            mapper->SetInputConnection( clipFilter->GetOutputPort() );
        }
    }
    else
    {
        if(ui->shrinkFilter->isChecked())
        {
            shrinkFilter->SetInputConnection(operationFilter->GetOutputPort());
            shrinkFilter->SetShrinkFactor(.8);
            shrinkFilter->Update();

            mapper->SetInputConnection( shrinkFilter->GetOutputPort() );
        }
        else
        {
            mapper->SetInputConnection( operationFilter->GetOutputPort() );
        }
    }

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

/// Shrink Filter
void MainWindow::on_shrinkFilter_stateChanged(int amp)
{
    if(ui->shrinkFilter->isChecked())
    {
        if(ui->clipFilter->isChecked())
        {
            shrinkFilter->SetInputConnection(operationFilter->GetOutputPort());
            shrinkFilter->SetShrinkFactor(.8);
            shrinkFilter->Update();

            planeLeft->SetOrigin(0.0, 0.0, 0.0);
            planeLeft->SetNormal(-1.0, 0.0, 0.0);

            clipFilter->SetInputConnection( shrinkFilter->GetOutputPort() ) ;
            clipFilter->SetClipFunction( planeLeft.Get() );

            mapper->SetInputConnection( clipFilter->GetOutputPort() );
        }
        else
        {
            shrinkFilter->SetInputConnection(operationFilter->GetOutputPort());
            shrinkFilter->SetShrinkFactor(.8);
            shrinkFilter->Update();

            mapper->SetInputConnection( shrinkFilter->GetOutputPort() );
        }
    }
    else
    {
        if(ui->clipFilter->isChecked())
        {
            planeLeft->SetOrigin(0.0, 0.0, 0.0);
            planeLeft->SetNormal(-1.0, 0.0, 0.0);

            clipFilter->SetInputConnection( operationFilter->GetOutputPort() ) ;
            clipFilter->SetClipFunction( planeLeft.Get() );

            mapper->SetInputConnection( clipFilter->GetOutputPort() );
        }
        else
        {
            shrinkFilter->SetInputConnection(operationFilter->GetOutputPort());
            shrinkFilter->SetShrinkFactor(1);
            shrinkFilter->Update();

            mapper->SetInputConnection( shrinkFilter->GetOutputPort() );
        }
    }

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

/// Outline Filter
void MainWindow::on_outlineFilter_stateChanged(int amp)
{
    if(ui->outlineFilter->isChecked())
    {
        // Enable Change Outline Color Push Button After the Outline Filter Checkbox has been checked
        ui->changeOutlineColor->setEnabled(true);

        // Create the outline
        outlineFilter->SetInputConnection(operationFilter->GetOutputPort());

        outlineMapper->SetInputConnection(outlineFilter->GetOutputPort());

        outlineActor->SetMapper(outlineMapper);

        // Add the actor to the scene
        renderer->AddActor(actor);

        renderer->AddActor(outlineActor);
    }
    else
    {
        // Enable Change Outline Color Push Button After the Outline Filter Checkbox has been checked
        ui->changeOutlineColor->setEnabled(false);

        // Remove Outline Filter
        renderer->RemoveActor(outlineActor);
    }

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

/// Edge Visibility Filter
void MainWindow::on_edgeVisibilityFilter_stateChanged(int amp)
{
    if(ui->edgeVisibilityFilter->isChecked())
    {
        actor->GetProperty()->EdgeVisibilityOn();
    }
    else
    {
        actor->GetProperty()->EdgeVisibilityOff();
    }

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

// Reading STL File Type
// Source: https://kitware.github.io/vtk-examples/site/Cxx/IO/ReadSTL/
void MainWindow::on_actionFileOpen_triggered()
{
    ui->clipFilter->setEnabled(true);
    ui->shrinkFilter->setEnabled(true);
    ui->outlineFilter->setEnabled(true);
    ui->changeModelColor->setEnabled(true);
    ui->edgeVisibilityFilter->setEnabled(true);

    ui->clipFilter->setChecked(false);
    ui->shrinkFilter->setChecked(false);
    ui->outlineFilter->setChecked(false);
    ui->edgeVisibilityFilter->setChecked(true);

    // Remove Outline Filter From Previous Model
    renderer->RemoveActor(outlineActor);

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open STL File"), "./", tr("STL Files (*.stl)"));

    // const char *c_str = fileName.toLatin1().data();

    // https://www.cnblogs.com/wxl845235800/p/10796840.html
    QByteArray fileSTL = fileName.toLatin1();
    const char *c_str = fileSTL.data();

    reader->SetFileName(c_str);

    reader->Update();

    // Assign 'reader' <vtkSTLReader> type to generic pointer 'operationFilter' <vtkAlgorithm> type
    operationFilter = reader;

    // Create a mapper that will hold the cube's geometry in a format suitable for rendering
	mapper->SetInputConnection( reader->GetOutputPort() );

	// Create an actor that is used to set the cube's properties for rendering and place it in the window
	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();

	// Create a renderer, and render window
    vtkNew<vtkRenderWindow> renderWindow;
	ui->qvtkWidget->renderWindow()->AddRenderer( renderer );									// ###### ask the QtVTKOpenGLWidget for its renderWindow ######

	// Add the actor to the scene
	renderer->AddActor(actor);

	// Setup the renderers's camera
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(0);
	renderer->GetActiveCamera()->Elevation(0);
	renderer->ResetCameraClippingRange();
	ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
	renderWindow->Render();
}
