#ifndef LAB_PROGRAMMAZIONE_MAINWINDOW_H
#define LAB_PROGRAMMAZIONE_MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QDesktopWidget>
#include <QProgressBar>
#include "ResourcesLoader.h"
#include "Observer.h"


class MainWindow : public QMainWindow, public Observer {
    Q_OBJECT
public:
    MainWindow (ResourcesLoader * loader);

    virtual ~MainWindow() {
        loader->removeObserver(this);
    }

    ResourcesLoader* getResouceLoader () {
        return loader;
    }

    virtual void update() override ;

private slots:
    void startLoadingResources ();

private:
    ResourcesLoader * loader;

    QLabel * text;
    QPushButton * button;
    QProgressBar * progressBar;
    QTextEdit * textBox;
};


#endif //LAB_PROGRAMMAZIONE_MAINWINDOW_H
