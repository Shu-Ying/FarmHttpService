QT       += core network httpserver

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
  Handle/CHandle.cpp \
  Handle/CHandleManager.cpp \
  Model/CJsonParse.cpp \
  Model/CModelManager.cpp \
  Service/CHttpService.cpp \
  Service/CServiceManager.cpp \
  Ui/CUiManager.cpp \
  Ui/Widget.cpp \
  main.cpp

HEADERS += \
  Handle/CHandle.h \
  Handle/CHandleManager.h \
  Model/CJsonParse.h \
  Model/CModelManager.h \
  Service/CHttpService.h \
  Service/CServiceManager.h \
  Ui/CUiManager.h \
  Ui/Widget.h

FORMS += \
  Ui/Widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
