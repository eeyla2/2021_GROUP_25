// main.cpp-------------------------------------------------------------------
#include <QApplication>
#include <QSurfaceFormat>
#include <QVTKOpenGLWidget.h>
#include "mainwindow.h"
int main(int argc, char **argv)
{

  QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());

  QApplication a(argc, argv);

  MainWindow example;
  example.show();

  return a.exec();
}
// /main.cpp------------------------------------------------------------------
