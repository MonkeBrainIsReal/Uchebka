#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Select_clicked()
{

    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "Image Files (*.png *.jpg *.jpeg)");

    if (!filename.isEmpty()) {
        Custom_View *customView = ui->graphicsView;
        customView->loadImage(filename);
    }
    else{

    }
}


void MainWindow::on_Monochrome_clicked()
{
    // Получаем текущее изображение из сцены
    QGraphicsItem *item = ui->graphicsView->scene->items().first(); // Предполагается, что на сцене только один элемент
    if (!item) {
        QMessageBox::warning(this, tr("Error"), tr("No image loaded!"));
        return;
    }

    // Создаем копию изображения
    QGraphicsPixmapItem *pixmapItem = qgraphicsitem_cast<QGraphicsPixmapItem*>(item);
    if (!pixmapItem) {
        QMessageBox::warning(this, tr("Error"), tr("No image loaded!"));
        return;
    }

    QImage originalImage = pixmapItem->pixmap().toImage();
    QImage monochromeImage = originalImage.copy(); // Создаем копию оригинального изображения

    // Преобразуем копию в монохромное изображение
    for (int y = 0; y < monochromeImage.height(); ++y) {
        for (int x = 0; x < monochromeImage.width(); ++x) {
            QColor color = monochromeImage.pixelColor(x, y);
            int gray = qGray(color.rgb());
            monochromeImage.setPixelColor(x, y, QColor(gray, gray, gray));
        }
    }

    // Сохраняем оригинальное и монохромное изображения для возможности отката
    originalPixmapItem=  new QGraphicsPixmapItem(QPixmap::fromImage(originalImage));
    monochromePixmapItem=  new QGraphicsPixmapItem(QPixmap::fromImage(monochromeImage));

    // Добавляем монохромное изображение на сцену и отображаем его
    ui->graphicsView->scene->addItem(monochromePixmapItem);
    ui->graphicsView->fitInView(monochromePixmapItem, Qt::KeepAspectRatio);
}
