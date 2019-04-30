#include "MainWindow.h"


MainWindow::MainWindow(ResourcesLoader * concreteLoader) {
    this->setFixedSize(QSize(600, 400));

    this->setWindowTitle("Resources loader");
    this->setFixedSize(QSize(600, 400));

    text = new QLabel("File resources upload with. (Qt library)", this);
    text->setGeometry(QRect(QPoint(150, 15), QSize(300, 100)));
    text->setStyleSheet("QLabel { background-color : blue; color : white; }");
    text->setWordWrap(true);
    text->setAlignment(Qt::AlignCenter);

    button = new QPushButton("Load resources!", this);
    button->setGeometry(QRect(QPoint(225, 143), QSize(150, 30)));

    progressBar = new QProgressBar(this);
    progressBar->setGeometry(QRect(QPoint(150, 190), QSize(300, 30)));

    progressBar->setMinimum(0);
    progressBar->setMaximum(1000);
    progressBar->setValue(0);


    textBox = new QTextEdit(this);
    textBox->setGeometry(QRect(QPoint(50, 240), QSize(500, 140)));
    textBox->setText("---> Ready to load resources!\n");
    textBox->setReadOnly(true);

    loader = concreteLoader;

    connect(button, SIGNAL (released()), this, SLOT (startLoadingResources()));
}

void MainWindow::startLoadingResources() {
    progressBar->setValue(0);
    textBox->setText("");
    std::vector<const char*> files;
    files.push_back("/home/m3tacybmint/Pictures/m3ta!OxsoldierProductions.png");
    files.push_back("/home/m3tacybmint/Pictures/gea1.png");
    files.push_back("/home/m3tacybmint/Pictures/gea2.png");
    files.push_back("/home/m3tacybmint/Pictures/gea3.png");
    loader->loadFiles(files);
}

void MainWindow::update() {
    if (loader->isLoadingCompleted() == true) {

        progressBar->setValue(progressBar->value() + (1000/loader->getNumOfResources()));

        QString log = "✅ Loaded file '" + QString(loader->getFilename()) + QString("' successfully (") + QString::number(loader->getFileSize()) + QString(" bytes).") + "\n";
        textBox->append(log);

        QString percentText = QString::number(progressBar->value() / 10) + QString("% loaded!");
        button->setText(percentText);
    } else {
        QString log = "❌ Could not load file '" + QString(loader->getFilename()) + "'\n";
        textBox->append(log);
    }
}