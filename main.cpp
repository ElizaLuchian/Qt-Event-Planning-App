//
// Created by 40745 on 14/04/2024.
//

#include "main.h"
#include "Tests.h"
#include "Ui/ui.h"
#include "Gui/GUI.h"
#include <QtWidgets/QApplication>

#include <QLabel>

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
   // Tests();
    //ui Ui=ui();
   // Ui.start();
    GUI gui;
    gui.show();
   // return 0;



    return app.exec();
}


