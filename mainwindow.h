#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include "fractal_mandelbrot.h"
#include "fractal_julia.h"
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

	void on_insert_mandelbrot_triggered();
	void on_insert_julia_triggered();

private:
	void setValue(int value);
	void draw_fractal();
	void set_fractal(fractal_base *fractal);

	fractal_base	*fractal;
	fractal_base	ref_fractal;
	MyScene			*graphic;
	Ui::MainWindow	*ui;
	QTimer			*timer;
	int				max_sens;
	bool			draw;
};
#endif // MAINWINDOW_H
