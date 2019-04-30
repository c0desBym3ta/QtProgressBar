#ifndef LAB_PROGRAMMAZIONE_FILE_H
#define LAB_PROGRAMMAZIONE_FILE_H

#include <string>
#include <iostream>

class File {
public:
    explicit File(const char* filename);
    ~File();
    int getFileSizeInBytes() {
        return fileSize;
    }

private:
    int fileSize;
    FILE* file;
};


#endif //LAB_PROGRAMMAZIONE_FILE_H
