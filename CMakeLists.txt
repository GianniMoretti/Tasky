cmake_minimum_required(VERSION 3.14)
project(Tasky)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

find_package(wxWidgets REQUIRED net gl core base xrc adv)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES Views/MainView.cpp Views/MainView.h Models/Task.h Models/Task.cpp Models/IModel.h IObserver.h Models/Model.cpp Models/Model.h FileManagement/IFIleRepository.h FileManagement/XMLFileRepository.cpp FileManagement/XMLFileRepository.h Views/wxDayBoxView.h Views/wxDayBoxView.cpp pugi/pugiconfig.hpp pugi/pugixml.cpp pugi/pugixml.hpp Views/MainFrame.cpp Views/MainFrame.h Views/wxDayView.cpp Views/wxDayView.h Views/wxEditTaskView.cpp Views/wxEditTaskView.h Controllers/MainViewController.cpp Controllers/MainViewController.h Controllers/DayViewController.cpp Controllers/DayViewController.h Controllers/EditTaskViewController.cpp Controllers/EditTaskViewController.h Views/ListTasksView.cpp Views/ListTasksView.h Controllers/ListTasksViewController.cpp Controllers/ListTasksViewController.h)
add_executable(Tasky main.cpp ${SOURCE_FILES} )
add_library(core ${SOURCE_FILES} )
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} core)