#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	graphic = new QGraphicsScene(this);
	ui->image->setScene(graphic);
	fractal = new fractal_mandelbrot();
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_draw_fractal_clicked()
{
	graphic->setSceneRect(0,0, ui->image->width() - 3, ui->image->height() - 3);
	int	width = ui->image->width();
	int	height = ui->image->height();
	QImage img(ui->image->width(), ui->image->height(), QImage::Format_RGB32);
	fractal->resize(width, height);
	for(int i = 0; i < width; i++)
		for(int j = 0; j < height; j++)
			img.setPixel(i, j, fractal->get_color(i, j));
	graphic->addPixmap(QPixmap::fromImage(img));
}
