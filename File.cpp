#include "File.h"

File::File(const char *filename) : file(fopen(filename, "r")), fileSize(0)  {
    if (!file) {
        throw std::runtime_error("Could not open file!");
    } else {
        fseek(file, 0, SEEK_END);
        fileSize = static_cast<int>(ftell(file));
    }
}

File::~File() {
    if (fclose(file)) {
        throw std::runtime_error("Could not close file!");
    }
}
