QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    PlotLibrary/qcustomplot.cpp \
    calc_model.cpp \
    chx.cpp \
    control.cpp \
    creditcalc.cpp \
    depositcalc.cpp \
    main.cpp \
    calcwindow.cpp \
    plot.cpp

HEADERS += \
    PlotLibrary/qcustomplot.h \
    calc_model.h \
    calcwindow.h \
    chx.h \
    control.h \
    creditcalc.h \
    depositcalc.h \
    plot.h

FORMS += \
    calcwindow.ui \
    chx.ui \
    creditcalc.ui \
    depositcalc.ui \
    plot.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
ICON = AnyConv.com__pngegg.icns

