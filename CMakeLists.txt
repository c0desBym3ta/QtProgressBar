cmake_minimum_required(VERSION 3.9)
project(qtProgressBar)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(CMAKE_AUTOMOC ON)


find_package(Qt5Widgets REQUIRED)


set(SOURCE_FILES main.cpp Subject.h Observer.h MainWindow.cpp MainWindow.h ResourcesLoader.cpp ResourcesLoader.h File.cpp File.h ConcreteObserver.h)
add_executable(qtProgressBar main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(core Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} core)

