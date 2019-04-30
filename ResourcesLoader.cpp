#include "ResourcesLoader.h"

ResourcesLoader::ResourcesLoader() {
    numOfResources = 0;
}

void ResourcesLoader::registerObserver(Observer *o) {
    observers.push_back(o);
}

void ResourcesLoader::removeObserver(Observer *o) {
    observers.remove(o);
}

void ResourcesLoader::notifyObserver() const {
    for (const auto &itr : observers) {
        itr->update();
    }
}

void ResourcesLoader::loadFiles(std::vector<const char *> fileNames) throw(std::runtime_error) {
    try {
        numOfResources = int(fileNames.size());
        if (numOfResources == 0) {
            throw std::runtime_error("No resouces detected!");
        }
    } catch(std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    for (auto& itr : fileNames) {
        handleFile(itr);
    }
}

void ResourcesLoader::handleFile(const char * itr) {
    try {
        File file(itr);
        fileName = QString(itr);
        fileSize = file.getFileSizeInBytes();
        loadingCompleted = true;
        notifyObserver();
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        fileName = QString(itr);
        loadingCompleted = false;
        notifyObserver();
    } catch (...) {
        std::cerr << "Unknow exception caught!" << std::endl;
    }
}