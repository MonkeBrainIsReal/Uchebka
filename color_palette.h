#ifndef COLOR_PALETTE_H
#define COLOR_PALETTE_H

#include <QWidget>
#include <QString>
#include <vector>
#include<QCloseEvent>
#include <QLabel>

namespace Ui {
class color_palette;
}

class color_palette : public QWidget
{
    Q_OBJECT

public:
    explicit color_palette(QWidget *parent = nullptr);
    ~color_palette();
public slots:
    void auto_color_pal(std::vector<QColor> colors);
private slots:
    void on_spinBox_valueChanged(int arg1);
    void closeEvent(QCloseEvent *event);

private:
    Ui::color_palette *ui;
    std::vector<QLabel*> labels;
};

#endif // COLOR_PALETTE_H