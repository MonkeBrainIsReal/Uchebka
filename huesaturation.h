#ifndef HUESATURATION_H
#define HUESATURATION_H

#include <QWidget>

namespace Ui {
class huesaturation;
}

class huesaturation : public QWidget
{
    Q_OBJECT

public:
    explicit huesaturation(QWidget *parent = nullptr);
    ~huesaturation();

private slots:
    void on_SaturationSlider_valueChanged(int value);

    void on_HueSlider_valueChanged(int value);

    void on_CancelButton_clicked();
    void on_AcceptButton_clicked();

signals:
    void parametersAccepted(int saturation, int hue);
    void saturationChanged(int saturation);
    void hueChanged(int hue);
private:
    int initialSaturation;
    int initialHue;
    int saturationValue;
    int hueValue;
    Ui::huesaturation *ui;
};

#endif // HUESATURATION_H
