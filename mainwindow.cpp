#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), graphic(this)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
    set_fractal(0);
	timer = new QTimer();

    ui->image->setScene(&graphic);
	ui->set_sensibility->setMinimum(10);
	ui->set_sensibility->setMaximum(300);
	connect(ui->set_sensibility, &QSlider::valueChanged, this, &MainWindow::setValue);
	connect(timer, &QTimer::timeout, this, &MainWindow::draw_fractal);
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
    ranges::for_each(fractals, [](auto &n){ delete &n; });
}

fractal_base *MainWindow::get_curent_fractal()
{
    return *fractal;
}

void MainWindow::draw_fractal()
{
    if (!graphic.drow)
        return;
    graphic.setSceneRect(0,0, ui->image->width() - 3, ui->image->height() - 3);
    QImage img(graphic.width(), graphic.height(), QImage::Format_RGB32);
    auto fractal_ptr = *fractal;
    img.fill(fractal_ptr->iter_color(0));
    fractal_ptr->draw_fractal(&img);
    graphic.addPixmap(QPixmap::fromImage(img));
    graphic.drow = 0;

}

void MainWindow::set_fractal(int f)
{
    fractal = fractals.begin() + f;
    setValue(50);
}

void MainWindow::setValue(int value)
{
    ui->set_sensibility->setValue(value);
    (*this->fractal)->set_sensibility(value);
    graphic.drow = 1;
}
