cmake_minimum_required(VERSION 3.16)
project(centrifuge-ui-demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Qml)

qt_standard_project_setup()

qt_add_executable(centrifuge-ui-demo
    src/main.cpp
    src/hal_sim.cpp
    src/hal_factory.cpp
    src/centrifuge_controller.cpp
    src/rpm_viewmodel.cpp
)

target_include_directories(centrifuge-ui-demo PRIVATE src)

qt_add_qml_module(centrifuge-ui-demo
    URI Centrifuge
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        qml/components/RpmGauge.qml
        qml/components/AlarmBanner.qml
)

target_link_libraries(centrifuge-ui-demo
    PRIVATE Qt6::Quick Qt6::Qml
)

