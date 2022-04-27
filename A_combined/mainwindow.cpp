#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "tabcontent.h"
#include "currentstl.h"
#include "recentstl.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{

    // standard call to setup Qt UI (same as previously)
    ui->setupUi(this);

    // Link the nameListCurrent to the currentSTLs
    ui->currentSTLs->setModel(&nameListCurrent);

    // Link the reentFiles to the nameListRecent
    ui->recentFiles->setModel(&nameListRecent);
    // Tell this list view to only accept single selections
    ui->currentSTLs->setSelectionBehavior(QAbstractItemView::SelectItems);

    ui->qvtkWidget->setRenderWindow(renderWindow);

    //for lists of stls currently visible
   // ui->

    // Create an actor that is used to set the model's properties for rendering and place it in the window
    actor->SetMapper(mapper);
    actor->GetProperty()->EdgeVisibilityOn();
    actor->GetProperty()->SetColor(colors->GetColor3d("White").GetData());

    // Create a renderer, and render window
    ui->qvtkWidget->renderWindow()->AddRenderer(renderer); // ###### ask the QtVTKOpenGLWidget for its renderWindow ######
    renderer->SetBackground(colors->GetColor3d("Silver").GetData());

    // Initial Setup: Disable Filters When Model File is Not Loaded
    ui->clipFilter->setEnabled(false);
    ui->shrinkFilter->setEnabled(false);
    ui->outlineFilter->setEnabled(false);
    ui->edgeVisibilityFilter->setEnabled(false);
    ui->changeModelColor->setEnabled(false);
    ui->changeOutlineColor->setEnabled(false);

    connect(this, &MainWindow::statusUpdateMessage, ui->statusBar, &QStatusBar::showMessage);   //status bar

    // Connect the released() signal of the renderCube object to the handleRenderCube slot in this object
    connect(ui->renderCube, &QPushButton::released, this, &MainWindow::handleRenderCube);

    // Connect the released() signal of the renderPyramid object to the handleRenderPyramid slot in this object
    connect(ui->renderPyramid, &QPushButton::released, this, &MainWindow::handleRenderPyramid);

    // Connect the released() signal of the changeModelColor object to the handleChangeModelColor slot in this object
    connect(ui->changeModelColor, &QPushButton::released, this, &MainWindow::handleChangeModelColor);

    // Connect the released() signal of the changeOutlineColor object to the handleChangeOutlineColor slot in this object
    connect(ui->changeOutlineColor, &QPushButton::released, this, &MainWindow::handleChangeOutlineColor);

    // Connect the released() signal of the changeBackgroundColor object to the handleChangeBackgroundColor slot in this object
    connect(ui->changeBackgroundColor, &QPushButton::released, this, &MainWindow::handleChangeBackgroundColor);

    // Connect the released() signal of the cutobject object to the handleCutter slot in this object
    connect(ui->cutObject, &QPushButton::released, this, &MainWindow::handleCutter);

    // Connect the released() signal of the changePosition object to the handleChangePosition slot in this object
    connect(ui->changePosition, &QPushButton::released, this, &MainWindow::handleChangePosition);

    // connect(ui->displayProperties, &QPushButton::released, this, &MainWindow::handleDisplayProperties);

    // Connect the released() signal of the insertObject object to the handleInsertObject slot in this object
    connect(ui->insertObject, &QPushButton::released, this, &MainWindow::handleInsertObject);

    // Connect the released() signal of the removeObject object to the handleRemoveObject slot in this object
    connect(ui->removeObject, &QPushButton::released, this, &MainWindow::handleRemoveObject);

// Connect the released() signal of the newWindowButton object to the handleNewWindowButton slot in this object
    connect(ui->newWindowButton, &QAction::triggered, this, &MainWindow::handleNewWindowButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot implementation in mainwindow.cpp---------------------

void MainWindow::handleRenderCube()
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

    // Link the QtVTK widget with a VTK render window
    ui->qvtkWidget->setRenderWindow(renderWindow);

    mapper->SetInputConnection(cubeSource->GetOutputPort());

    // Assign 'cubeSource' <vtkCubeSource> type to generic pointer 'modelData' <vtkAlgorithm> type
    modelData = cubeSource;

    actor->SetMapper(mapper);

    actor->GetProperty()->EdgeVisibilityOn();

    ui->qvtkWidget->renderWindow()->AddRenderer(renderer); // ###### ask the QtVTKOpenGLWidget for its renderWindow ######

    // Add the actor to the scene
    renderer->AddActor(actor);

    // Setup the renderers's camera
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Azimuth(0);
    renderer->GetActiveCamera()->Elevation(0);
    renderer->ResetCameraClippingRange();
    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

void MainWindow::handleRenderPyramid()
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

    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    vtkSmartPointer<vtkPyramid> pyramid = vtkSmartPointer<vtkPyramid>::New();
    vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();
    vtkSmartPointer<vtkUnstructuredGrid> ug = vtkSmartPointer<vtkUnstructuredGrid>::New();

    // Link the QtVTK widget with a VTK render window
    ui->qvtkWidget->setRenderWindow(renderWindow);

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
    // Assign Converted 'convertToPolygonal' <vtkGeometryFilter> or Polygonal type to generic pointer 'modelData' <vtkAlgorithm> type
    modelData = convertToPolygonal;

    // Create an actor that is used to set the pyramid's properties for rendering and place it in the window
    actor->SetMapper(mapper);
    actor->GetProperty()->EdgeVisibilityOn();

    // Link the QtVTK widget with a renderer, and render window
    ui->qvtkWidget->renderWindow()->AddRenderer(renderer); // ###### ask the QtVTKOpenGLWidget for its renderWindow ######

    // Add the actor to the scene
    renderer->AddActor(actor);

    // Setup the renderers's camera
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Azimuth(0);
    renderer->GetActiveCamera()->Elevation(0);
    renderer->ResetCameraClippingRange();

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

void MainWindow::handleChangeModelColor()
{

    QColor color = QColorDialog::getColor(Qt::red, this);

    if (color.isValid())
    {
        // Approach 1
        // actor->GetProperty()->SetColor( colors->GetColor3d("Blue").GetData() );

        // Approach 2
        // actor->GetProperty()->SetColor( color );

        // Approach 3
        // Returns red, blue, green colors components from the selected color in QColorDialog
        actor->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
    }

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

void MainWindow::handleChangeBackgroundColor()
{
    QColor backgroundColor = QColorDialog::getColor(Qt::red, this);

    if (backgroundColor.isValid())
    {
        // Approach 1
        // renderer->SetBackground( colors->GetColor3d("Blue").GetData() );

        // Approach 2
        // renderer->SetBackground( backgroundColor );

        // Approach 3
        // Returns red, blue, green colors components from the selected color in QColorDialog
        renderer->SetBackground(backgroundColor.redF(), backgroundColor.greenF(), backgroundColor.blueF());
    }

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

void MainWindow::handleChangeOutlineColor()
{

    QColor color = QColorDialog::getColor(Qt::red, this);

    if (color.isValid())
    {
        // Returns red, blue, green colors components from the selected color in QColorDialog
        outlineActor->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
    }

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

/// Clip Filter
void MainWindow::on_clipFilter_stateChanged(int amp)
{
    if (ui->clipFilter->isChecked())
    {
        if (ui->shrinkFilter->isChecked())
        {
            planeLeft->SetOrigin(0.0, 0.0, 0.0);
            planeLeft->SetNormal(-1.0, 0.0, 0.0);

            clipFilter->SetInputConnection(modelData->GetOutputPort());
            clipFilter->SetClipFunction(planeLeft.Get());

            shrinkFilter->SetInputConnection(clipFilter->GetOutputPort());
            shrinkFilter->SetShrinkFactor(.8);
            shrinkFilter->Update();

            mapper->SetInputConnection(shrinkFilter->GetOutputPort());
        }
        else
        {
            planeLeft->SetOrigin(0.0, 0.0, 0.0);
            planeLeft->SetNormal(-1.0, 0.0, 0.0);

            clipFilter->SetInputConnection(modelData->GetOutputPort());
            clipFilter->SetClipFunction(planeLeft.Get());

            mapper->SetInputConnection(clipFilter->GetOutputPort());
        }
    }
    else
    {
        if (ui->shrinkFilter->isChecked())
        {
            shrinkFilter->SetInputConnection(modelData->GetOutputPort());
            shrinkFilter->SetShrinkFactor(.8);
            shrinkFilter->Update();

            mapper->SetInputConnection(shrinkFilter->GetOutputPort());
        }
        else
        {
            mapper->SetInputConnection(modelData->GetOutputPort());
        }
    }

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

/// Shrink Filter
void MainWindow::on_shrinkFilter_stateChanged(int amp)
{
    if (ui->shrinkFilter->isChecked())
    {
        if (ui->clipFilter->isChecked())
        {
            shrinkFilter->SetInputConnection(modelData->GetOutputPort());
            shrinkFilter->SetShrinkFactor(.8);
            shrinkFilter->Update();

            planeLeft->SetOrigin(0.0, 0.0, 0.0);
            planeLeft->SetNormal(-1.0, 0.0, 0.0);

            clipFilter->SetInputConnection(shrinkFilter->GetOutputPort());
            clipFilter->SetClipFunction(planeLeft.Get());

            mapper->SetInputConnection(clipFilter->GetOutputPort());
        }
        else
        {
            shrinkFilter->SetInputConnection(modelData->GetOutputPort());
            shrinkFilter->SetShrinkFactor(.8);
            shrinkFilter->Update();

            mapper->SetInputConnection(shrinkFilter->GetOutputPort());
        }
    }
    else
    {
        if (ui->clipFilter->isChecked())
        {
            planeLeft->SetOrigin(0.0, 0.0, 0.0);
            planeLeft->SetNormal(-1.0, 0.0, 0.0);

            clipFilter->SetInputConnection(modelData->GetOutputPort());
            clipFilter->SetClipFunction(planeLeft.Get());

            mapper->SetInputConnection(clipFilter->GetOutputPort());
        }
        else
        {
            shrinkFilter->SetInputConnection(modelData->GetOutputPort());
            shrinkFilter->SetShrinkFactor(1);
            shrinkFilter->Update();

            mapper->SetInputConnection(shrinkFilter->GetOutputPort());
        }
    }

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

/// Outline Filter
void MainWindow::on_outlineFilter_stateChanged(int amp)
{
    if (ui->outlineFilter->isChecked())
    {
        // Enable Change Outline Color Push Button After the Outline Filter Checkbox has been checked
        ui->changeOutlineColor->setEnabled(true);

        // Create the outline
        outlineFilter->SetInputConnection(modelData->GetOutputPort());

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
    if (ui->edgeVisibilityFilter->isChecked())
    {
        actor->GetProperty()->EdgeVisibilityOn();
    }
    else
    {
        actor->GetProperty()->EdgeVisibilityOff();
    }

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
}

void MainWindow::handleCutter()
{

    plane->SetOrigin(0.0, 0.0, 0.0);
    plane->SetNormal(-0.287, 0, 0.9579); // these values were chosen randomly

    planeCutter->SetInputConnection(reader->GetOutputPort());
    planeCutter->SetCutFunction(plane);
    mapper->SetInputConnection(planeCutter->GetOutputPort());

    renderWindow->Render();
    ui->qvtkWidget->renderWindow()->Render();
}

void MainWindow::handleChangePosition()
{
    x = ui->xCoordinate->value(); // getting coordinate values
    y = ui->yCoordinate->value();
    z = ui->zCoordinate->value();

    // qDebug() << "Spin Box Value: " << x; //Debugging

    actor->SetMapper(mapper);

    actor->SetPosition(x, y, z);
    //  actor->SetPosition(-0.287, 0, 0.9579);

    renderWindow->Render();
    ui->qvtkWidget->renderWindow()->Render();
}

/*void MainWindow::handleDisplayProperties()
{
   modelProperties->SetInputConnection(reader->GetOutputPort());
 //  mapper->SetInputConnection(modelProperties->GetOutputPort());



   // qDebug() << "Model Volume: " << volume;->GetVolume() //Debugging
   std::cout << "Volume: " << modelProperties->GetVolume() << std::endl
       << "Area:   " << modelProperties->GetSurfaceArea() << std::endl;

    renderWindow->Render();
    ui->qvtkWidget->renderWindow()->Render();

}
*/


//adds new items to current stls list
void MainWindow::listCurrentSTLs( const QString &fileName){

//Add new object to the List 
    QModelIndexList selectedList;
    selectedList = ui->currentSTLs->selectionModel()->selectedIndexes();
    if (selectedList.length() == 0) //no items have been added yet so we want to add rather than insert
    {
        nameListCurrent.addItem(fileName);
        emit statusUpdateMessage(QString("Add button was clicked"), 0);
    }
    if (selectedList.length() == 1)
    {
        // selectedList is a list of all selected items in the listView. Since we set its
        // behaviour to single selection, were only interested in the first selecteded item.
        emit statusUpdateMessage(QString("Add button was clicked"), 0);
        nameListCurrent.insertItem(fileName, selectedList[0]);
    }

}

//adds items to recent STLs files
void MainWindow::listRecentSTLs( const QString &fileName){

//Add new object to the List 
    QModelIndexList selectedList;
    selectedList = ui->recentFiles->selectionModel()->selectedIndexes();
    
        nameListRecent.addItem(fileName);
        emit statusUpdateMessage(QString("Add button was clicked"), 0);


}

//removes chosen item from currenSTLs list
void MainWindow::removeCurrentSTLs()
{
    QModelIndexList selectedList;
    selectedList = ui->currentSTLs->selectionModel()->selectedIndexes();
    if (selectedList.length() == 1)
    {
        // selectedList is a list of all selected items in the listView. Since we set its
        // behaviour to single selection, were only interested in the first selecteded item.
        emit statusUpdateMessage(QString("Remove button was clicked"), 0);
        nameListCurrent.removeItem(selectedList[0]);
    }
    else
    {
        emit statusUpdateMessage(QString("No item selected to remove!"), 0);
    }
}

void MainWindow::handleInsertObject()
{
    //we want to use this button to add multiple STLs to same world
    //when we open a file we are replacing the current object with a new one, when in
    emit statusUpdateMessage(QString("Inserting object into this world"), 0);

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "../", tr("(*.stl)")); // filename gives entire path

    if (fileName.isEmpty())
        return;

    QByteArray ba = fileName.toLatin1();
    const char *c_str = ba.data();
    std::cout << c_str << "\n";

    //start reading 
    vtkNew<vtkSTLReader> _reader;

    _reader->SetFileName(c_str);
    _reader->Update();

    auto itR = listOfSTLReaders.insert(listOfSTLReaders.begin()+numSTL, _reader);

    vtkNew<vtkDataSetMapper> STLmapper;
    STLmapper->SetInputConnection(_reader->GetOutputPort());

    auto itM = listOfSTLMappers.insert(listOfSTLMappers.begin()+numSTL, STLmapper);

    vtkNew<vtkActor> STLActor;
    STLActor->SetMapper(STLmapper);
    STLActor->GetProperty()->EdgeVisibilityOn();

    auto itA = listOfSTLActors.insert(listOfSTLActors.begin()+numSTL, STLActor);

    //add all actors to renderer
    for (int i=0; i<listOfSTLActors.size(); i++)
    {
        renderer->AddActor(listOfSTLActors.at(i));
    }

    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
    renderWindow->Render();

    numSTL++;

    //extract file name from its path to 
    QFileInfo fileInfo(fileName);
    QString fileShortName (fileInfo.fileName());


    //add to recent and current STLs list
    listCurrentSTLs(fileShortName);

    listRecentSTLs(fileShortName);


}

void MainWindow::handleRemoveObject(){



removeCurrentSTLs();


}


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


    auto itR = listOfSTLReaders.insert(listOfSTLReaders.begin()+numSTL, reader);

    // Assign 'reader' <vtkSTLReader> type to generic pointer 'modelData' <vtkAlgorithm> type
    //modelData = reader;

    // Create a mapper that will hold the cube's geometry in a format suitable for rendering
    mapper->SetInputConnection(reader->GetOutputPort());

    auto itM = listOfSTLMappers.insert(listOfSTLMappers.begin()+numSTL, mapper);

    // Create an actor that is used to set the cube's properties for rendering and place it in the window
    actor->SetMapper(mapper);
    actor->GetProperty()->EdgeVisibilityOn();

    auto itA = listOfSTLActors.insert(listOfSTLActors.begin()+numSTL, actor);

    // Create a renderer, and render window
    vtkNew<vtkRenderWindow> renderWindow;
    ui->qvtkWidget->renderWindow()->AddRenderer(renderer); // ###### ask the QtVTKOpenGLWidget for its renderWindow ######

    // Add the actor to the scene
    renderer->AddActor(actor);

    // Setup the renderers's camera
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Azimuth(0);
    renderer->GetActiveCamera()->Elevation(0);
    renderer->ResetCameraClippingRange();
    ui->qvtkWidget->renderWindow()->Render(); // Load Model Instantly
    renderWindow->Render();

    numSTL++;
}

void MainWindow::on_actionHelp_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Help:\n\n\
                   Open: Open STL File\n\
                   Print: Take a snip of the window in .png\n\
                   Change Model Color: Change Model Color from Color Dialog\n\
                   Change Background Color: Change Background Color from Color Dialog\n\
                   Change Outline Color: Change Color of the Outline from Color Dialog\n\
                   Render Cube: Render a Cube from a Cube Source\n\
                   Render Pyramid: Render a Pyramid from a Pyarmid Source\n\
                   Apply Shrink Filter: Shrink all the model(s) in the current window\n\
                   Apply Clip Filter: Clip all the model(s) in the current window\n\
                   Apply Outline Filter: Outline all the model(s) in the current window\n\
                   Apply Edge Visibility: Apply edge to all the model(s) in the current window\n");
    msgBox.exec();
}

//Screenshot
void MainWindow::on_actionPrint_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Take a Screenshot"), "./", tr("PNG (*.png)"));

    QFile file(fileName);

    QByteArray filePNG = fileName.toLatin1();
    const char *c_str = filePNG.data();

    // Screenshot

        // Problem: vtkWindowToImageFilter doesn't update models

        // Solution:
            // WARNING: vtkWindowToImageFilter
                // A vtkWindow doesn't behave like other parts of the VTK pipeline:
                // its modification time doesn't get updated when an image is rendered.
                // As a result, naive use of vtkWindowToImageFilter will produce an image
                // of the first image that the window rendered, but which is never updated
                // on subsequent window updates. This behavior is unexpected and in general undesirable.
                // To force an update of the output image, call vtkWindowToImageFilter's Modified method
                // after rendering to the window.

                // https://vtk.org/doc/nightly/html/classvtkWindowToImageFilter.html
                // https://stackoverflow.com/questions/47436669/vtk-c-update-contour-from-contourfilter

    windowToImageFilter->Modified();
    windowToImageFilter->SetInput(renderWindow);
    windowToImageFilter->Update();

    if (!fileName.isEmpty())
    {
        writer->SetFileName(c_str);
        writer->SetInputConnection(windowToImageFilter->GetOutputPort());
        writer->Write();
    }
    file.close();
}

//closes any tab that is opened
void MainWindow::on_tabWidget_tabCloseRequested(int index)
{

    ui->tabWidget->removeTab(index);

}

//create new tab
void MainWindow::handleNewWindowButton()
{
    //not fuly convinced this is the way to do tabs

     //ui->tabWidget->addTab(new tabcontent(), QString("Tab %0").arg(ui->tabWidget->count() +1 ) );//still need to know how to make the tab have the name of the filer

     ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);

}
