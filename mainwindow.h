#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QGraphicsScene>
#include "fractal_mandelbrot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_draw_fractal_clicked();

private:
	fractal_base *fractal;
	QGraphicsScene *graphic;
	Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
