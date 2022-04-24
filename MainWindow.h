#pragma once
#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include "rehash.h"
#include "linkhash.h"
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
    Rehash rehash;
    LinkHash linkhash;
    Ui::MainWindow *ui;
};
#endif // MainWindow_H
