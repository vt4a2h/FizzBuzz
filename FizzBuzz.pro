TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++1y
QMAKE_CXX = g++-5

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

