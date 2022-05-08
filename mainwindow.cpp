#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	fractal = nullptr;
	ref_fractal.set_sensibility(1000);
	graphic = new MyScene(fractal, this);
	timer = new QTimer();

	ui->image->setScene(graphic);
	ui->set_sensibility->setMinimum(10);
	ui->set_sensibility->setMaximum(300);
	connect(ui->set_sensibility, &QSlider::valueChanged, this, &MainWindow::setValue);
	connect(timer, &QTimer::timeout, this, &MainWindow::draw_fractal);
	timer->start(100);
	max_sens = 200;
	draw = 1;
}

MainWindow::~MainWindow()
{
	delete ui;
	if (fractal)
		delete fractal;
}

void MainWindow::draw_fractal()
{
	if (fractal
			&& (ref_fractal.get_zoom() != fractal->get_zoom()
				|| ref_fractal.get_sensibility() != fractal->get_sensibility()
				|| graphic->width() != ui->image->width() - 3
				|| graphic->height() != ui->image->height() - 3))
	{
		ref_fractal = *fractal;
		graphic->setSceneRect(0,0, ui->image->width() - 3, ui->image->height() - 3);
		QImage img(graphic->width(), graphic->height(), QImage::Format_RGB32);
		img.fill(fractal->iter_color(0));
		fractal->draw_fractal(&img);
		graphic->addPixmap(QPixmap::fromImage(img));
	}
}

void MainWindow::set_fractal(fractal_base *fractal)
{
	if (this->fractal)
		delete this->fractal;
	this->fractal = fractal;
	this->ref_fractal.set_sensibility(10000);
	ui->set_sensibility->setValue(50);
	fractal->set_sensibility(50);
}

void MainWindow::on_insert_mandelbrot_triggered()
{
	set_fractal(new fractal_mandelbrot());
}

void MainWindow::on_insert_julia_triggered()
{
	set_fractal(new fractal_julia());
}

void MainWindow::setValue(int value)
{
	fractal->set_sensibility(value);
}

