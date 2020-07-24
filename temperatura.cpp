#include "temperatura.h"
#include "ui_temperatura.h"
#include <QDebug>

Temperatura::Temperatura(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Temperatura)
{
    ui->setupUi(this);
    connect(ui->dialCent,SIGNAL(valueChanged(int)),
            this,SLOT(cent2Fahr(int)));
    connect(ui->dialFahr,SIGNAL(valueChanged(int)),
            this,SLOT(fahr2Cent(int)));
    connect(ui->dialKel,SIGNAL(valueChanged(int)),
            this,SLOT(kel2Cent(int)));

    //Cambio cursor
    connect(ui->dialCent, SIGNAL(sliderPressed()),
            this,SLOT(cambioCursor()));
    connect(ui->dialCent, SIGNAL(sliderReleased()),
            this,SLOT(cambioCursor()));

    connect(ui->dialFahr, SIGNAL(sliderPressed()),
            this,SLOT(cambioCursor()));
    connect(ui->dialFahr, SIGNAL(sliderReleased()),
            this,SLOT(cambioCursor()));

    connect(ui->dialKel, SIGNAL(sliderPressed()),
            this,SLOT(cambioCursor()));
    connect(ui->dialKel, SIGNAL(sliderReleased()),
            this,SLOT(cambioCursor()));

    //establecer el valor inicial
    ui->dialFahr->setValue(32);
    ui->dialKel->setValue(273);
    ui->dialCent->setValue(0);
}

Temperatura::~Temperatura()
{
    delete ui;
}

void Temperatura::cent2Fahr(int valor)
{
    if (ui->dialCent->hasFocus()){
        double f = valor * 9.0/5 + 32;
        double k = valor + 273.15;
        QString fahr = QString::number(f);
        QString kelvin = QString::number(k);
        QString cen = QString::number(valor);

        ui->dialFahr->setValue(f);
        ui->dialKel->setValue(k);
        ui->lblFahr->setText(fahr + "\n ºF");
        ui->lblKel->setText(kelvin + "\n ºK");
        ui->lblCent->setText(cen + "\n ºC");
    }
}

void Temperatura::fahr2Cent(int valor)
{
    if (ui->dialFahr->hasFocus()){
        float c = (valor - 32) * 5.0/9;
        float k = (valor - 32) * 5.0/9 + 273.15;
        QString fahr = QString::number(valor);
        QString kelvin = QString::number(k);
        QString cen = QString::number(c);

        ui->dialCent->setValue(c);
        ui->dialKel->setValue(k);
        ui->lblFahr->setText(fahr + "\n°F");
        ui->lblKel->setText(kelvin + "\n°K");
        ui->lblCent->setText(cen + "\n°C");
    }
}

void Temperatura::kel2Cent(int valor)
{

    if (ui->dialKel->hasFocus()){
        float c = (valor - 273.15);
        float f = (valor - 273.15) * 9/5.0 + 32;
        QString fahr = QString::number(f);
        QString kelvin = QString::number(valor);
        QString cen = QString::number(c);

        ui->dialFahr->setValue(f);
        ui->dialCent->setValue(c);
        ui->lblFahr->setText(fahr + "\n°F");
        ui->lblKel->setText(kelvin + "\n°K");
        ui->lblCent->setText(cen + "\n°C");
   }
}

void Temperatura::cambioCursor()
{
    if(ui->dialCent->hasFocus()){
        if (ui->dialCent->cursor() == Qt::OpenHandCursor){
            ui->dialCent->setCursor(Qt::ClosedHandCursor);
        }else{
            ui->dialCent->setCursor(Qt::OpenHandCursor);
        }
    } else if (ui->dialFahr->hasFocus()){
        if (ui->dialFahr->cursor() == Qt::OpenHandCursor){
            ui->dialFahr->setCursor(Qt::ClosedHandCursor);
        }else{
            ui->dialFahr->setCursor(Qt::OpenHandCursor);
        }
    } else if (ui->dialKel->hasFocus()){
        if (ui->dialKel->cursor() == Qt::OpenHandCursor){
            ui->dialKel->setCursor(Qt::ClosedHandCursor);
        }else{
            ui->dialKel->setCursor(Qt::OpenHandCursor);
        }
    }
}

