QT += quick widgets sql printsupport
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_FILE = icone.rc

SOURCES += \
        main.cpp \
    telaprincipal.cpp \
    administracaodeclientes.cpp \
    administracaodecidades.cpp \
    dadoscadastrais.cpp \
    cadastrarcliente.cpp \
    adicionarcidade.cpp \
    estatisticas.cpp \
    visualizarcliente.cpp \
    visualizarcarga.cpp \
    clientesdacarga.cpp \
    visualizarpedido.cpp \
    adicionarproduto.cpp \
    adicionarcliente.cpp \
    cargas.cpp \
    relatoriocarga.cpp \
    definircidades.cpp \
    novacarga.cpp \
    administracaodeprodutos.cpp \
    cadastrarproduto.cpp \
    atualizarproduto.cpp \
    database.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    telaprincipal.ui \
    administracaodeclientes.ui \
    visualizarpedido.ui \
    dadoscadastrais.ui \
    cadastrarcliente.ui \
    adicionarcidade.ui \
    estatisticas.ui \
    visualizarcliente.ui \
    visualizarcarga.ui \
    clientesdacarga.ui \
    adicionarproduto.ui \
    adicionarcliente.ui \
    cargas.ui \
    relatoriocarga.ui \
    definircidades.ui \
    novacarga.ui \
    administracaodecidades.ui \
    administracaodeprodutos.ui \
    cadastrarproduto.ui \
    atualizarproduto.ui

HEADERS += \
    telaprincipal.h \
    administracaodeclientes.h \
    dadoscadastrais.h \
    cadastrarcliente.h \
    adicionarcidade.h \
    estatisticas.h \
    visualizarcliente.h \
    visualizarcarga.h \
    clientesdacarga.h \
    visualizarpedido.h \
    adicionarproduto.h \
    adicionarcliente.h \
    cargas.h \
    relatoriocarga.h \
    definircidades.h \
    novacarga.h \
    administracaodecidades.h \
    administracaodeprodutos.h \
    cadastrarproduto.h \
    atualizarproduto.h \
    database.h



