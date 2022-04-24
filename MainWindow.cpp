#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QFileDialog>
#include <QList>
 using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_chooseFile_clicked()
{
    linkhash.clear();
    rehash.clear();
    ui->listId->clear();
    QString str = QFileDialog::getOpenFileName();
    QFile file(str);
    QStringList parts = str.split("/");
    QString lastBit = parts.at(parts.size()-1);
    ui->fileEdit->clear();
    ui->fileEdit->setText(lastBit);
    list_id.clear();
    if (file.open(QIODevice::ReadOnly))
    {
        while(!file.atEnd())
        {
            QString id = file.readLine();
            if (id[id.length()-1]=='\n')
            {
                id.chop(1);
            }
            if (id != "")
            {
                list_id.append(id.toStdString());
                ui->listId->addItem(id);
            }

        }
    }
    ui->id_num->setText(QString::number(list_id.length()));
    rehash.fill(list_id);
    linkhash.fill(list_id);
    file.close();
}


void MainWindow::on_searchButton_clicked()
{
    QString search = ui->searchIdEdit->text();
    int compareCount = rehash.search(search.toStdString());
    int comareCount2 = linkhash.search(search.toStdString());
    ui->compareCount->setText(QString::number(compareCount));
    ui->comareCount2->setText(QString::number(comareCount2));
    if (compareCount > 0) ui->result->setText("Идентификатор найден");
    else ui->result->setText("Идентификатор не найден");
    if (comareCount2 > 0) ui->result2->setText("Идентификатор найден");
    else ui->result2->setText("Идентификатор не найден");
}


void MainWindow::on_searchAllButton_clicked()
{
    int count = list_id.length();
    int countCompare = 0;
    int countCompare2 = 0;

    for (auto i:list_id)
    {
        countCompare += rehash.search(i);
        countCompare2 += linkhash.search(i);
    }
    double average = static_cast<double>(countCompare)/static_cast<double>(count);
    double average2 = static_cast<double>(countCompare2)/static_cast<double>(count);
    ui->allCompareCount->setText(QString::number(countCompare));
    ui->average->setText(QString::number(average));
    ui->allCompareCount2->setText(QString::number(countCompare2));
    ui->average2->setText(QString::number(average2));

}

