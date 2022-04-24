#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	graphic = new MyScene(&fractal, this);
	ui->image->setScene(graphic);
	fractal = new fractal_mandelbrot();

	timer = new QTimer();       // Инициализируем таймер
	connect(timer, &QTimer::timeout, this, &MainWindow::draw_fractal);
	timer->start(100);          // Запускаем таймер
	max_sens = 200;
	draw = 1;
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::draw_fractal()
{
	graphic->setSceneRect(0,0, ui->image->width() - 3, ui->image->height() - 3);
	QImage img(ui->image->width(), ui->image->height(), QImage::Format_RGB32);
	fractal->draw_fractal(&img);
	graphic->addPixmap(QPixmap::fromImage(img));
}
