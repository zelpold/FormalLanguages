#pragma once
#ifndef FORMAL_H
#define FORMAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Formal; }
QT_END_NAMESPACE

#include "rehash.h"
#include "linkhash.h"
class Formal : public QMainWindow
{
    Q_OBJECT

public:
    Formal(QWidget *parent = nullptr);
    ~Formal();

private slots:
    void on_chooseFile_clicked();

    void on_searchButton_clicked();

    void on_searchAllButton_clicked();

private:
    QList<string> list_id;
    Rehash rehash;
    LinkHash linkhash;
    Ui::Formal *ui;
};
#endif // FORMAL_H
