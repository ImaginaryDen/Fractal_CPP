#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QTimer>
#include <QGraphicsScene>
#include "fractal_mandelbrot.h"
#include "myscene.h"

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

private:
	void draw_fractal();

	fractal_base	*fractal;
	MyScene			*graphic;
	Ui::MainWindow	*ui;
	QTimer			*timer;
	int				max_sens;
	bool			draw;
};
#endif // MAINWINDOW_H
