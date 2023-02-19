#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include "myscene.h"
#include "fractal_julia.h"
#include "fractal_mandelbrot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, IGetFractal
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    fractal_base *get_curent_fractal() override;

private:
	void setValue(int value);
	void draw_fractal();
    void set_fractal(int f);

    std::vector<fractal_base *> fractals = {
        new fractal_mandelbrot(), new fractal_julia()};

private slots:

    void on_insert_mandelbrot_triggered(){set_fractal(0);};
    void on_insert_julia_triggered(){set_fractal(1);};

private:
    vector<fractal_base *>::iterator fractal;
    MyScene			graphic;
	Ui::MainWindow	*ui;
	QTimer			*timer;
    const int       max_sens = 200;
};
#endif // MAINWINDOW_H
