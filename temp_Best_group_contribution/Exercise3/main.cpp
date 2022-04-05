// main.cpp-------------------------------------------------------------------
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

  // Initialize Splash Screen
  QSplashScreen *splash = new QSplashScreen;
  splash->setPixmap(QPixmap("C:/Users/ADMIN/Desktop/Splash.JPG")); // splash picture
  splash->show();

  MainWindow window;

  // Initialize Timer To Show Splash Screen Before Running the Program
  QTimer::singleShot(2500, splash,SLOT(close())); // Timer
  QTimer::singleShot(2500,&window,SLOT(show())); // Window

  // window.show();

  return a.exec();
}
// /main.cpp------------------------------------------------------------------
