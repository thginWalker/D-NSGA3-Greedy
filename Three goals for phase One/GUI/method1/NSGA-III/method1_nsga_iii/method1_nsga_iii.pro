QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alg_comparator.cpp \
    alg_crossover.cpp \
    alg_environmental_selection.cpp \
    alg_individual.cpp \
    alg_initialization.cpp \
    alg_mutation.cpp \
    alg_nondominated_sort.cpp \
    alg_nsgaiii.cpp \
    alg_reference_point.cpp \
    aux_math.cpp \
    aux_misc.cpp \
    exp_experiment.cpp \
    exp_indicator.cpp \
    gnuplot_interface.cpp \
    log.cpp \
    main.cpp \
    problem_DTLZ.cpp \
    problem_ZDT.cpp \
    problem_factory.cpp \
    problem_self.cpp \
    widget.cpp

HEADERS += \
    alg_comparator.h \
    alg_crossover.h \
    alg_environmental_selection.h \
    alg_individual.h \
    alg_initialization.h \
    alg_mutation.h \
    alg_nondominated_sort.h \
    alg_nsgaiii.h \
    alg_population.h \
    alg_reference_point.h \
    aux_math.h \
    aux_misc.h \
    exp_experiment.h \
    exp_indicator.h \
    gnuplot_interface.h \
    log.h \
    problem_DTLZ.h \
    problem_ZDT.h \
    problem_base.h \
    problem_factory.h \
    problem_self.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
