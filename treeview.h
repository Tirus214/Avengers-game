#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QDialog>

namespace Ui {
class treeView;
}

class treeView : public QDialog
{
    Q_OBJECT

public:
    explicit treeView(QWidget *parent = nullptr);
    ~treeView();

private:
    Ui::treeView *ui;
};

#endif // TREEVIEW_H
