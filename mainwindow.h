#pragma once
#ifndef FORMAL_H
#define FORMAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include "binarytree.h"
#include "hash.h"
//#include "linkhash.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_chooseFile_clicked();

    void on_searchButton_clicked();

    void on_searchAllButton_clicked();

private:
    QList<string> list_id;
    Hash hash;
    BinaryTree tree;
    Ui::MainWindow *ui;
};
#endif // FORMAL_H
