// main.cpp

/** @file
* Responsible for setting up the mainwindow & splash screen.
*/

/** Brief description
* This file sets up the Qapplication and loads the splash screen
*/

#include <QApplication>
#include <QSurfaceFormat>
#include <QVTKOpenGLWidget.h>
#include <QSplashScreen>
#include <QTimer>

#include "mainwindow.h"

int main( int argc, char** argv )
{
  // needed to ensure appropriate OpenGL context is created for VTK rendering.
  QSurfaceFormat::setDefaultFormat( QVTKOpenGLWidget::defaultFormat() );

  QApplication a( argc, argv );

//TODO: could splash screen go into its own function?

  // Initialize Splash Screen
  QSplashScreen *splash = new QSplashScreen;
  splash->setPixmap(QPixmap("../images/Splash.JPG")); // splash picture
  splash->show();
  // Initialize Timer To Show Splash Screen Before Running the Program
  QTimer::singleShot(1000, splash,SLOT(close())); // Timer  
  //2500 is nice for the real thing, reduced to 1000 for testing

  MainWindow window;
  QTimer::singleShot(1000,&window,SLOT(show())); // Window

  // window.show();

  return a.exec();
}
// /main.cpp------------------------------------------------------------------