#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->errorLabel->hide();
    devView = new QWebEngineView(this);

    connect(ui->btnGo, &QPushButton::clicked, this, [this](){
        QString port = ui->portEdit->text();
        if(port.isEmpty()) {
            ui->errorLabel->show();
        }
        else {
            devView->load(QUrl("http://localhost:" + port));
            ui->errorLabel->hide();
        }
    });

    QStackedLayout* layout = new QStackedLayout(ui->frame);
    ui->frame->setLayout(layout);
    layout->addWidget(devView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    ui->frame->resize(this->width(), this->height()-80);
}

