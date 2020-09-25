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
    main.cpp \
    src/alg_comparator.cpp \
    src/alg_crossover.cpp \
    src/alg_environmental_selection.cpp \
    src/alg_individual.cpp \
    src/alg_initialization.cpp \
    src/alg_mutation.cpp \
    src/alg_nondominated_sort.cpp \
    src/alg_nsgaiii.cpp \
    src/alg_reference_point.cpp \
    src/aux_math.cpp \
    src/aux_misc.cpp \
    src/exp_experiment.cpp \
    src/exp_indicator.cpp \
    src/gnuplot_interface.cpp \
    src/log.cpp \
    src/print_data.cpp \
    src/problem_DTLZ.cpp \
    src/problem_ZDT.cpp \
    src/problem_factory.cpp \
    src/problem_self.cpp \
    src/update_chromosome.cpp \
    widget.cpp

HEADERS += \
    src/alg_comparator.h \
    src/alg_crossover.h \
    src/alg_environmental_selection.h \
    src/alg_individual.h \
    src/alg_initialization.h \
    src/alg_mutation.h \
    src/alg_nondominated_sort.h \
    src/alg_nsgaiii.h \
    src/alg_population.h \
    src/alg_reference_point.h \
    src/aux_math.h \
    src/aux_misc.h \
    src/exp_experiment.h \
    src/exp_indicator.h \
    src/gnuplot_interface.h \
    src/log.h \
    src/print_data.h \
    src/problem_DTLZ.h \
    src/problem_ZDT.h \
    src/problem_base.h \
    src/problem_factory.h \
    src/problem_self.h \
    src/update_chromosome.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
