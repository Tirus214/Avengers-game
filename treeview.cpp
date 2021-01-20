#include "treeview.h"
#include "ui_treeview.h"

treeView::treeView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::treeView)
{
    ui->setupUi(this);
}

treeView::~treeView()
{
    delete ui;
}
