#include "shapes.h"
#include "ui_shapes.h"

Shapes::Shapes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shapes)
{
    ui->setupUi(this);
}

Shapes::~Shapes()
{
    delete ui;
}
