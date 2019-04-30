#ifndef LAB_PROGRAMMAZIONE_RESOURCESLOADER_H
#define LAB_PROGRAMMAZIONE_RESOURCESLOADER_H

#include <list>
#include <QTextEdit>
#include "File.h"
#include "Observer.h"
#include "Subject.h"

class ResourcesLoader : public Subject {
public:
    ResourcesLoader();
    void loadFiles(std::vector<const char*> fileNames) throw(std::runtime_error);
    void handleFile(const char* itr);

    virtual void registerObserver (Observer *o) override;
    virtual void removeObserver (Observer * o) override;
    virtual void notifyObserver () const override;

    int getNumOfResources() {
        return numOfResources;
    }

    bool isLoadingCompleted() {
        return loadingCompleted;
    }

    const QString &getFilename() const {
        return fileName;
    }

    int getFileSize() {
        return fileSize;
    }

private:
    std::list<Observer*> observers;
    int numOfResources;

    bool loadingCompleted;
    QString fileName;
    int fileSize;
};


#endif //LAB_PROGRAMMAZIONE_RESOURCESLOADER_H
