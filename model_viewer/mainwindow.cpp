#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // standard call to setup Qt UI (same as previously)
    ui->setupUi(this);
    //---------------------------------------------------------------
    // User interface - buttons, slider etc.

    connect(ui->resetCameraButton, &QPushButton::released, this, &MainWindow::handleCameraButton);
    connect(ui->objectColourButton, &QPushButton::released, this, &MainWindow::handleObjectColourButton);
    connect(ui->backgroundColourButton, &QPushButton::released, this, &MainWindow::handleBackgroundColourButton);

    connect(ui->importCubeButton, &QPushButton::released, this, &MainWindow::handleImportCubeButton);
    connect(ui->importPyramidButton, &QPushButton::released, this, &MainWindow::handleImportPyramidButton);

    connect(ui->shrinkCheckBox, &QCheckBox::toggled, this, &MainWindow::handleShrinkCheckBox);
    connect(ui->clipCheckBox, &QCheckBox::toggled, this, &MainWindow::handleClipCheckBox);

    // exercise 5 - updating status bar
    connect(this, &MainWindow::statusUpdateMessage, ui->statusBar, &QStatusBar::showMessage);

    // exercise 8 - connecting save button
    connect(ui->actionFileSave, &QAction::triggered, this, &MainWindow::handleSaveAction);
    // drop down menu file > save as
    // connect(ui->actionSave_as, &QAction::triggered, this, &MainWindow::handleSaveAction);

    connect(ui->actionFileOpen, &QAction::triggered, this, &MainWindow::handleOpenAction);

    //-----------------------------------------------------

    // vtkNew<vtkNamedColors> colors;

    // string inputFile = "../STL_FILES/airbus_a400m.stl";    //hardcoded path

    // moved to open file function
    // vtkNew<vtkSTLReader> reader;  //moved to private variables
    // reader->SetFileName(inputFile.c_str());

    // if (fileName.isEmpty())
    //     return;

    std::cout << "Running\n";

    // reader->Update();

    // // Create a mapper and actor
    // // vtkNew<vtkPolyDataMapper> mapper;   //moved to private variables

    // mapper->SetInputConnection(reader->GetOutputPort());

    // // vtkNew<vtkActor> actor;
    // actor->SetMapper(mapper);
    // actor->GetProperty()->SetDiffuse(0.8);
    // actor->GetProperty()->SetDiffuseColor(
    //     colors->GetColor3d("LightSteelBlue").GetData());
    // actor->GetProperty()->SetSpecular(0.3);
    // actor->GetProperty()->SetSpecularPower(60.0);

    // //---------------------------------
    // // Now need to create a VTK render window and link it to the QtVTK widget
    // // vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    ui->qvtkWidget->setRenderWindow(renderWindow); // note that vtkWidget is the name I gave to my QtVTKOpenGLWidget in Qt creator

    // // Create a renderer, and render window
    // // vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    ui->qvtkWidget->renderWindow()->AddRenderer(renderer); // ###### ask the QtVTKOpenGLWidget for its renderWindow ######

    // // Add the actor to the scene
    // renderer->AddActor(actor);
    renderer->SetBackground(colors->GetColor3d("Silver").GetData());

    // // Setup the renderers's camera
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Azimuth(30);
    renderer->GetActiveCamera()->Elevation(30);
    renderer->ResetCameraClippingRange();
}

/*
void MainWindow::handleRemoveButton()
{

    QModelIndexList selectedList;
    selectedList = ui->listView->selectionModel()->selectedIndexes();
    if (selectedList.length() == 1)
    {
        // selectedList is a list of all selected items in the listView. Since we set its
        // behaviour to single selection, were only interested in the first selecteded item.
        emit statusUpdateMessage(QString("Remove button was clicked"), 0);
        stockList.removeItem(selectedList[0]);
    }
    else
    {
        emit statusUpdateMessage(QString("No item selected to remove!"), 0);
    }
}
*/

void MainWindow::handleSaveAction()

{
    emit statusUpdateMessage(QString("Save was clicked"), 0);

    // QString fileName = QFileDialog::getSaveFileName(this, tr("Save Text File"), "unititled.txt", tr("Text Files (*.txt)"));

    // if (fileName.isEmpty())
    //     return;

    // QFile file(fileName);

    // //Open the file
    // if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    //     return;

    // QTextStream out(&file);

    // int numRows = stockList.rowCount(QModelIndex());
    // out << "Num rows: " << numRows << "\n";

    // for (int i = 0; i < numRows; ++i)
    // {
    //     QModelIndex myIndex = stockList.index(i, 0, QModelIndex());
    //     StockItem item = stockList.getItem(myIndex);

    //     out << "Item Name: " << item.getName() << "\t"
    //         << "Item cost: " << item.getUnitCost() << "\t"
    //         << "Stock: "     << item.getStockLevel() << "\t"
    //         << "Reorder: "   << item.getReorder() << "\n";
    // }

    // file.close();
}

void MainWindow::handleOpenAction()
{
    emit statusUpdateMessage(QString("Open was clicked"), 0);

    vtkNew<vtkSTLReader> reader;

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "../", tr("Model Files(*.stl *.mod)")); // filename gives entire path

    if (fileName.isEmpty())
        return;

    emit statusUpdateMessage(QString(fileName), 0);

    QByteArray ba = fileName.toLatin1();
    const char *c_str = ba.data();
    std::cout << c_str << "\n";

    //--------------------------Reading in file-----------Now we change what we are doing based on .stl or .mod

    lastCharacterOfFile = c_str[strlen(c_str) - 1]; // last character of file will be 'l' for stl, 'd' for mod
    std::cout << lastCharacterOfFile << "\n"
              << endl;

    if (lastCharacterOfFile != 'l' && lastCharacterOfFile != 'd')
    {
        emit statusUpdateMessage(QString("Invalid file"), 0);
        return;
    }

    else if (lastCharacterOfFile == 'l')
    {
        
        vtkNew<vtkSTLReader> reader;
        
        listOfSTLReaders.push_back(reader);
        
        //listOfSTLReaders.size()-1
        

        listOfSTLReaders.at(numSTL)->SetFileName(c_str);
        listOfSTLReaders.at(numSTL)->Update();
        modelData = listOfSTLReaders.at(numSTL);
        
        // reader->SetFileName(c_str);
        // reader->Update();
        // modelData = reader;

        vtkNew<vtkDataSetMapper> STLmapper; 
        listOfSTLMappers.push_back(STLmapper);
        
        listOfSTLMappers.at(numSTL)->SetInputConnection(modelData->GetOutputPort());

        vtkNew<vtkActor> STLActor;
        listOfSTLActors.push_back(STLActor);

        listOfSTLActors.at(numSTL)->SetMapper(listOfSTLMappers.at(numSTL));
        listOfSTLActors.at(numSTL)->GetProperty()->SetColor(colors->GetColor3d("LightSteelBlue").GetData());
        listOfSTLActors.at(numSTL)->GetProperty()->SetSpecular(0.3);
        listOfSTLActors.at(numSTL)->GetProperty()->SetSpecularPower(60.0);

        renderer->AddActor(listOfSTLActors.at(numSTL));

        renderer->ResetCamera();
        renderer->GetActiveCamera()->Azimuth(30);
        renderer->GetActiveCamera()->Elevation(30);
        renderer->ResetCameraClippingRange();

        renderWindow->Render();
        numSTL++;
    }

    else if (lastCharacterOfFile == 'd')
    {
        // tried to open mod file
        std::cout << "Opening mod file\n";
        // std::string filePath = "ExampleModel1.mod"; //  ExampleModel1.mod  //  testFile.mod
        std::string filePath = c_str;

        // Model myModel = Model(filePath);

        Model myModel = Model(filePath);

        vtk_declare(myModel);

        // std::cout << "\n-------------------Testing Functionality-----------------\n";
    }

    // mapper->SetInputConnection(modelData->GetOutputPort());

    // actor->SetMapper(mapper);
    // actor->GetProperty()->SetColor(colors->GetColor3d("LightSteelBlue").GetData());
    // actor->GetProperty()->SetSpecular(0.3);
    // actor->GetProperty()->SetSpecularPower(60.0);

    // renderer->AddActor(actor);

    // renderer->ResetCamera();
    // renderer->GetActiveCamera()->Azimuth(30);
    // renderer->GetActiveCamera()->Elevation(30);
    // renderer->ResetCameraClippingRange();

    // renderWindow->Render();
}

void MainWindow::vtk_declare(Model &theModel)
{
    std::cout << "Test\n";
    std::string nameOfMaterial0 = theModel.get_listOfMaterials().at(0).get_materialName();
    std::cout << "\n\nName of material 0: " << nameOfMaterial0 << "\n\n";

    // get num cells
    // loop over list of cells, creating as we go?

    // for now, lets just create the tetrahedron from the mod file

    for (int i = 0; i < theModel.get_numCells(); i++) // loop over all the cells in the list
    {
        if (theModel.get_listOfCells().at(i)->get_cellLetter() == 'h')
        {
            // declare hexahedron
            vtkNew<vtkHexahedron> hex; // will need a list of hexahedra

            vtkNew<vtkPoints> hexPoints;

            hexPoints->InsertPoint(theModel.get_listOfCells().at(i)->get_cellp0().get_vectorID(),
                                   theModel.get_listOfCells().at(i)->get_cellp0().get_x(),
                                   theModel.get_listOfCells().at(i)->get_cellp0().get_y(),
                                   theModel.get_listOfCells().at(i)->get_cellp0().get_z());

            hexPoints->InsertPoint(theModel.get_listOfCells().at(i)->get_cellp1().get_vectorID(),
                                   theModel.get_listOfCells().at(i)->get_cellp1().get_x(),
                                   theModel.get_listOfCells().at(i)->get_cellp1().get_y(),
                                   theModel.get_listOfCells().at(i)->get_cellp1().get_z());

            hexPoints->InsertPoint(theModel.get_listOfCells().at(i)->get_cellp2().get_vectorID(),
                                   theModel.get_listOfCells().at(i)->get_cellp2().get_x(),
                                   theModel.get_listOfCells().at(i)->get_cellp2().get_y(),
                                   theModel.get_listOfCells().at(i)->get_cellp2().get_z());

            hexPoints->InsertPoint(theModel.get_listOfCells().at(i)->get_cellp3().get_vectorID(),
                                   theModel.get_listOfCells().at(i)->get_cellp3().get_x(),
                                   theModel.get_listOfCells().at(i)->get_cellp3().get_y(),
                                   theModel.get_listOfCells().at(i)->get_cellp3().get_z());

            hexPoints->InsertPoint(theModel.get_listOfCells().at(i)->get_cellp4().get_vectorID(),
                                   theModel.get_listOfCells().at(i)->get_cellp4().get_x(),
                                   theModel.get_listOfCells().at(i)->get_cellp4().get_y(),
                                   theModel.get_listOfCells().at(i)->get_cellp4().get_z());

            hexPoints->InsertPoint(theModel.get_listOfCells().at(i)->get_cellp5().get_vectorID(),
                                   theModel.get_listOfCells().at(i)->get_cellp5().get_x(),
                                   theModel.get_listOfCells().at(i)->get_cellp5().get_y(),
                                   theModel.get_listOfCells().at(i)->get_cellp5().get_z());

            hexPoints->InsertPoint(theModel.get_listOfCells().at(i)->get_cellp6().get_vectorID(),
                                   theModel.get_listOfCells().at(i)->get_cellp6().get_x(),
                                   theModel.get_listOfCells().at(i)->get_cellp6().get_y(),
                                   theModel.get_listOfCells().at(i)->get_cellp6().get_z());

            hexPoints->InsertPoint(theModel.get_listOfCells().at(i)->get_cellp7().get_vectorID(),
                                   theModel.get_listOfCells().at(i)->get_cellp7().get_x(),
                                   theModel.get_listOfCells().at(i)->get_cellp7().get_y(),
                                   theModel.get_listOfCells().at(i)->get_cellp7().get_z());

            for (auto j = 0; j < 8; ++j)
            {
                hex->GetPointIds()->SetId(j, j);
            }

            vtkNew<vtkUnstructuredGrid> hexUGrid;
            // uGrid->SetPoints(points);
            // uGrid->InsertNextCell(hex->GetCellType(), hex->GetPointIds());

            listOfUnstructuredGrids.push_back(hexUGrid); // inefficent
            // listOfUnstructuredGrids.at(i) = hexUGrid;

            listOfUnstructuredGrids.at(i)->SetPoints(hexPoints);
            listOfUnstructuredGrids.at(i)->InsertNextCell(hex->GetCellType(), hex->GetPointIds());
            std::cout << "Value of i: " << i << " Assigning hexa\n";

            //-----------------------------------------------
            vtkNew<vtkDataSetMapper> hexMapper;

            listOfMappers.push_back(hexMapper);

            listOfMappers.at(i)->SetInputData(listOfUnstructuredGrids.at(i));

            vtkNew<vtkActor> hexActor;
            listOfActors.push_back(hexActor);

            listOfActors.at(i)->SetMapper(listOfMappers.at(i));
            listOfActors.at(i)->GetProperty()->SetColor(colors->GetColor3d("Green").GetData());

            renderer->AddActor(listOfActors.at(i));

            renderer->ResetCamera();
            renderer->GetActiveCamera()->Azimuth(30);
            renderer->GetActiveCamera()->Elevation(30);
            renderer->ResetCameraClippingRange();

            renderWindow->Render();
        }
        
        if (theModel.get_listOfCells().at(i)->get_cellLetter() == 't')
        {
            // declare tetra
    
            vtkNew<vtkPoints> tetraPoints; // how are we going to make sure this isnt overwrtten when declaring many tetra

            tetraPoints->InsertNextPoint(theModel.get_listOfCells().at(i)->get_cellp0().get_x(),
                                         theModel.get_listOfCells().at(i)->get_cellp0().get_y(),
                                         theModel.get_listOfCells().at(i)->get_cellp0().get_z());

            tetraPoints->InsertNextPoint(theModel.get_listOfCells().at(i)->get_cellp1().get_x(),
                                         theModel.get_listOfCells().at(i)->get_cellp1().get_y(),
                                         theModel.get_listOfCells().at(i)->get_cellp1().get_z());

            tetraPoints->InsertNextPoint(theModel.get_listOfCells().at(i)->get_cellp2().get_x(),
                                         theModel.get_listOfCells().at(i)->get_cellp2().get_y(),
                                         theModel.get_listOfCells().at(i)->get_cellp2().get_z());

            tetraPoints->InsertNextPoint(theModel.get_listOfCells().at(i)->get_cellp3().get_x(),
                                         theModel.get_listOfCells().at(i)->get_cellp3().get_y(),
                                         theModel.get_listOfCells().at(i)->get_cellp3().get_z());

            // points->InsertPoint(theModel.get_listOfCells().at(i)->get_cellp0().get_vectorID(),
            //                     theModel.get_listOfCells().at(i)->get_cellp0().get_x(),
            //                     theModel.get_listOfCells().at(i)->get_cellp0().get_y(),
            //                     theModel.get_listOfCells().at(i)->get_cellp0().get_z());

            // points->InsertPoint(theModel.get_listOfCells().at(i)->get_cellp1().get_vectorID(),
            //                     theModel.get_listOfCells().at(i)->get_cellp1().get_x(),
            //                     theModel.get_listOfCells().at(i)->get_cellp1().get_y(),
            //                     theModel.get_listOfCells().at(i)->get_cellp1().get_z());

            // points->InsertPoint(theModel.get_listOfCells().at(i)->get_cellp2().get_vectorID(),
            //                     theModel.get_listOfCells().at(i)->get_cellp2().get_x(),
            //                     theModel.get_listOfCells().at(i)->get_cellp2().get_y(),
            //                     theModel.get_listOfCells().at(i)->get_cellp2().get_z());

            // points->InsertPoint(theModel.get_listOfCells().at(i)->get_cellp3().get_vectorID(),
            //                     theModel.get_listOfCells().at(i)->get_cellp3().get_x(),
            //                     theModel.get_listOfCells().at(i)->get_cellp3().get_y(),
            //                     theModel.get_listOfCells().at(i)->get_cellp3().get_z());

            // vtkIdType ptIds[] = {8,9,10,11};

            // tetraPoints->InsertPoint(ptIds[0],
            //                     theModel.get_listOfCells().at(i)->get_cellp0().get_x(),
            //                     theModel.get_listOfCells().at(i)->get_cellp0().get_y(),
            //                     theModel.get_listOfCells().at(i)->get_cellp0().get_z());

            // tetraPoints->InsertPoint(ptIds[1],
            //                     theModel.get_listOfCells().at(i)->get_cellp1().get_x(),
            //                     theModel.get_listOfCells().at(i)->get_cellp1().get_y(),
            //                     theModel.get_listOfCells().at(i)->get_cellp1().get_z());

            // tetraPoints->InsertPoint(ptIds[2],
            //                     theModel.get_listOfCells().at(i)->get_cellp2().get_x(),
            //                     theModel.get_listOfCells().at(i)->get_cellp2().get_y(),
            //                     theModel.get_listOfCells().at(i)->get_cellp2().get_z());

            // tetraPoints->InsertPoint(ptIds[3],
            //                     theModel.get_listOfCells().at(i)->get_cellp3().get_x(),
            //                     theModel.get_listOfCells().at(i)->get_cellp3().get_y(),
            //                     theModel.get_listOfCells().at(i)->get_cellp3().get_z());

            vtkNew<vtkUnstructuredGrid> tetraUGrid;
            // unstructuredGrid1->SetPoints(tetraPoints);

            listOfUnstructuredGrids.push_back(tetraUGrid);
            // listOfUnstructuredGrids.at(i) = tetraUGrid;
            listOfUnstructuredGrids.at(i)->SetPoints(tetraPoints);

            // cout << "Num points: " << tetraPoints->GetNumberOfPoints() << "\n";

            // cout << "ID: " << theModel.get_listOfCells().at(i)->get_cellp0().get_vectorID() << "\n";

            vtkIdType ptIds[] = {0, 1, 2, 3};

           
            std::cout << "Value of i: " << i << " Assigning tetra\n";
            listOfUnstructuredGrids.at(i)->InsertNextCell(VTK_TETRA, 4, ptIds);
            // unstructuredGrid1->InsertNextCell({8,9,10,11});

            // need to create a list of actors and mappers to manage multiple things at once
            //-----------------------------------------------
            vtkNew<vtkDataSetMapper> tetraMapper;
            listOfMappers.push_back(tetraMapper);

            listOfMappers.at(i)->SetInputData(listOfUnstructuredGrids.at(i));

            vtkNew<vtkActor> tetraActor;
            listOfActors.push_back(tetraActor);

            listOfActors.at(i)->SetMapper(listOfMappers.at(i));
            listOfActors.at(i)->GetProperty()->SetColor(colors->GetColor3d("Cyan").GetData());

            renderer->AddActor(listOfActors.at(i));

            // renderer->ResetCamera();
            // renderer->GetActiveCamera()->Azimuth(30);
            // renderer->GetActiveCamera()->Elevation(30);
            // renderer->ResetCameraClippingRange();

            // renderWindow->Render();
            
        }
        
    }
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Azimuth(30);
    renderer->GetActiveCamera()->Elevation(30);
    renderer->ResetCameraClippingRange();
}

void MainWindow::handleCameraButton()
{
    emit statusUpdateMessage(QString("Resetting Camera"), 0);
}

void MainWindow::handleObjectColourButton()
{
    emit statusUpdateMessage(QString("Changing object colour"), 0);

    // bool ok;

    selectedShapeColor = QColorDialog::getColor(Qt::yellow, this);

    listOfSTLActors.at(numSTL-1)->GetProperty()->SetColor(selectedShapeColor.redF(), selectedShapeColor.greenF(), selectedShapeColor.blueF());

    renderWindow->Render();
}

void MainWindow::handleBackgroundColourButton()
{
    emit statusUpdateMessage(QString("Changing background colour"), 0);

    selectedBackgroundColor = QColorDialog::getColor(Qt::yellow, this);

    renderer->SetBackground(selectedBackgroundColor.redF(), selectedBackgroundColor.greenF(), selectedBackgroundColor.blueF());
    renderWindow->Render();
}

void MainWindow::handleImportCubeButton()
{
    emit statusUpdateMessage(QString("Importing cube"), 0);
    vtkSmartPointer<vtkCubeSource> cubeSource = vtkSmartPointer<vtkCubeSource>::New();

    modelData = cubeSource;

    mapper->SetInputConnection(modelData->GetOutputPort());
    actor->SetMapper(mapper);
    // actor->GetProperty()->EdgeVisibilityOn();
    // actor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());
    actor->GetProperty()->SetDiffuseColor(colors->GetColor3d("Red").GetData());
    std::cout << colors->GetColor3d("Red").GetData() << "\n";

    renderer->AddActor(actor);
    renderer->SetBackground(colors->GetColor3d("Silver").GetData());
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Azimuth(30);
    renderer->GetActiveCamera()->Elevation(30);
    renderer->ResetCameraClippingRange();
    renderWindow->Render();
}

void MainWindow::handleImportPyramidButton()
{
    emit statusUpdateMessage(QString("Importing pyramid"), 0);

    vtkNew<vtkSphereSource> sphereSource;
    sphereSource->SetCenter(0.0, 0.0, 0.0);
    sphereSource->SetRadius(5.0);
    // Make the surface smooth.
    sphereSource->SetPhiResolution(100);
    sphereSource->SetThetaResolution(100);

    modelData = sphereSource;

    mapper->SetInputConnection(modelData->GetOutputPort());

    actor->SetMapper(mapper);
    actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());
    /*
    //----------------------------------------------------------------------

        vtkNew<vtkPoints> points;

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

        vtkNew<vtkPyramid> pyramid;
        pyramid->GetPointIds()->SetId(0, 0);
        pyramid->GetPointIds()->SetId(1, 1);
        pyramid->GetPointIds()->SetId(2, 2);
        pyramid->GetPointIds()->SetId(3, 3);
        pyramid->GetPointIds()->SetId(4, 4);

        vtkNew<vtkCellArray> cells;
        cells->InsertNextCell(pyramid);

        vtkNew<vtkUnstructuredGrid> ug;
        ug->SetPoints(points);
        ug->InsertNextCell(pyramid->GetCellType(), pyramid->GetPointIds());

        vtkNew<vtkDataSetMapper> pyramidMapper;

        //modelData = ug;
        //modelData = convert_ug_to_polydata(&ug);

        pyramidMapper->SetInputData(ug);
        actor->SetMapper(pyramidMapper);
        actor->GetProperty()->SetColor(colors->GetColor3d("Blue").GetData());
        // actor->GetProperty()->SetColor(selectedShapeColor);
    */
    //---------------------------------------------------------------

    renderer->AddActor(actor);

    renderer->ResetCamera();
    renderer->GetActiveCamera()->Azimuth(30);
    renderer->GetActiveCamera()->Elevation(30);
    renderer->ResetCameraClippingRange();
    renderWindow->Render();
}

void MainWindow::handleShrinkCheckBox()
{
    // emit statusUpdateMessage(QString("Shrink checkbox changed"), 0);
    vtkSmartPointer<vtkShrinkFilter> shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();

    if (ui->shrinkCheckBox->isChecked())
    {
        emit statusUpdateMessage(QString("Checked!"), 0);

        //shrinkFilter->SetInputConnection(modelData->GetOutputPort());
        shrinkFilter->SetInputConnection(listOfSTLReaders.at(numSTL-1)->GetOutputPort());
        
        shrinkFilter->SetShrinkFactor(.8);
        shrinkFilter->Update();
        mapper->SetInputConnection(shrinkFilter->GetOutputPort());
    }
    else
    {
        emit statusUpdateMessage(QString("Unchecked!"), 0);
        //shrinkFilter->SetInputConnection(modelData->GetOutputPort());
        shrinkFilter->SetInputConnection(listOfSTLReaders.at(numSTL-1)->GetOutputPort());
        shrinkFilter->SetShrinkFactor(1);
        shrinkFilter->Update();
        mapper->SetInputConnection(shrinkFilter->GetOutputPort());
    }

    renderWindow->Render();
}

void MainWindow::handleClipCheckBox()
{
    emit statusUpdateMessage(QString("Clip checkbox changed"), 0);

    vtkSmartPointer<vtkPlane> planeLeft = vtkSmartPointer<vtkPlane>::New();
    vtkSmartPointer<vtkClipDataSet> clipFilter = vtkSmartPointer<vtkClipDataSet>::New();

    if (ui->clipCheckBox->isChecked())
    {
        emit statusUpdateMessage(QString("Checked!"), 0);

        planeLeft->SetOrigin(0.0, 0.0, 0.0);
        planeLeft->SetNormal(-1.0, 0.0, 0.0);
        //clipFilter->SetInputConnection(modelData->GetOutputPort());
        clipFilter->SetInputConnection(listOfSTLReaders.at(numSTL-1)->GetOutputPort());
        clipFilter->SetClipFunction(planeLeft.Get());
        mapper->SetInputConnection(clipFilter->GetOutputPort());
    }
    else
    {
        emit statusUpdateMessage(QString("Unchecked!"), 0);
        // mapper->SetInputConnection(modelData->GetOutputPort());
        mapper->SetInputConnection(listOfSTLReaders.at(numSTL-1)->GetOutputPort());
    }
    renderWindow->Render();
}

MainWindow::~MainWindow()
{
    delete ui;
}