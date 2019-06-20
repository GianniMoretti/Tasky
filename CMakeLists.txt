cmake_minimum_required(VERSION 3.14)
project(Tasky)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED net gl core base xrc adv)
include(${wxWidgets_USE_FILE})

add_executable(Tasky main.cpp Views/MainView.cpp Views/MainView.h Models/Task.h Models/Task.cpp Models/IModel.h IObserver.h Models/Model.cpp Models/Model.h FileManagement/IFIleRepository.h FileManagement/XMLFileRepository.cpp FileManagement/XMLFileRepository.h)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})