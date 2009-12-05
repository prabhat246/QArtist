/********************************************************************************
** Form generated from reading ui file 'MainWindow.ui'
**
** Created: Mon Nov 24 21:50:57 2008
**      by: Qt User Interface Compiler version 4.3.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionClose;
    QAction *actionGuassian_Blur;
    QAction *actionEdge_Detection;
    QAction *actionNPR1;
    QAction *actionNPR2_10;
    QAction *actionNPR2_20;
    QAction *actionNPR2_30;
    QAction *actionZoom_To_Fit;
    QAction *actionCanny;
    QAction *actionSegmentation;
    QAction *actionNPR_3;
    QAction *actionHalftoning;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuStyle;
    QMenu *menuView;
    QMenu *menuBasic_Operations;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(1276, 750);
    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
    MainWindow->setSizePolicy(sizePolicy);
    MainWindow->setMinimumSize(QSize(50, 0));
    MainWindow->setAutoFillBackground(false);
    actionExit = new QAction(MainWindow);
    actionExit->setObjectName(QString::fromUtf8("actionExit"));
    actionExit->setIcon(QIcon(QString::fromUtf8("Resource/Shutdown.png")));
    actionExit->setMenuRole(QAction::QuitRole);
    actionSave = new QAction(MainWindow);
    actionSave->setObjectName(QString::fromUtf8("actionSave"));
    actionSave->setIcon(QIcon(QString::fromUtf8("Resource/HD.png")));
    actionOpen = new QAction(MainWindow);
    actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
    actionOpen->setIcon(QIcon(QString::fromUtf8("Resource/Folder.png")));
    actionNew = new QAction(MainWindow);
    actionNew->setObjectName(QString::fromUtf8("actionNew"));
    actionNew->setIcon(QIcon(QString::fromUtf8("Resource/Blank.png")));
    actionClose = new QAction(MainWindow);
    actionClose->setObjectName(QString::fromUtf8("actionClose"));
    actionClose->setIcon(QIcon(QString::fromUtf8("Resource/Close.png")));
    actionGuassian_Blur = new QAction(MainWindow);
    actionGuassian_Blur->setObjectName(QString::fromUtf8("actionGuassian_Blur"));
    actionEdge_Detection = new QAction(MainWindow);
    actionEdge_Detection->setObjectName(QString::fromUtf8("actionEdge_Detection"));
    actionNPR1 = new QAction(MainWindow);
    actionNPR1->setObjectName(QString::fromUtf8("actionNPR1"));
    actionNPR2_10 = new QAction(MainWindow);
    actionNPR2_10->setObjectName(QString::fromUtf8("actionNPR2_10"));
    actionNPR2_20 = new QAction(MainWindow);
    actionNPR2_20->setObjectName(QString::fromUtf8("actionNPR2_20"));
    actionNPR2_30 = new QAction(MainWindow);
    actionNPR2_30->setObjectName(QString::fromUtf8("actionNPR2_30"));
    actionZoom_To_Fit = new QAction(MainWindow);
    actionZoom_To_Fit->setObjectName(QString::fromUtf8("actionZoom_To_Fit"));
    actionZoom_To_Fit->setCheckable(true);
    actionCanny = new QAction(MainWindow);
    actionCanny->setObjectName(QString::fromUtf8("actionCanny"));
    actionSegmentation = new QAction(MainWindow);
    actionSegmentation->setObjectName(QString::fromUtf8("actionSegmentation"));
    actionNPR_3 = new QAction(MainWindow);
    actionNPR_3->setObjectName(QString::fromUtf8("actionNPR_3"));
    actionHalftoning = new QAction(MainWindow);
    actionHalftoning->setObjectName(QString::fromUtf8("actionHalftoning"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(630, 0, 641, 651));
    label->setFrameShape(QFrame::Box);
    label->setTextFormat(Qt::AutoText);
    label->setAlignment(Qt::AlignCenter);
    label_2 = new QLabel(centralwidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(10, 0, 611, 651));
    label_2->setFrameShape(QFrame::Box);
    label_2->setTextFormat(Qt::AutoText);
    label_2->setAlignment(Qt::AlignCenter);
    MainWindow->setCentralWidget(centralwidget);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 1276, 21));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    menuStyle = new QMenu(menubar);
    menuStyle->setObjectName(QString::fromUtf8("menuStyle"));
    menuView = new QMenu(menubar);
    menuView->setObjectName(QString::fromUtf8("menuView"));
    menuBasic_Operations = new QMenu(menubar);
    menuBasic_Operations->setObjectName(QString::fromUtf8("menuBasic_Operations"));
    MainWindow->setMenuBar(menubar);
    toolBar = new QToolBar(MainWindow);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

    menubar->addAction(menuFile->menuAction());
    menubar->addAction(menuBasic_Operations->menuAction());
    menubar->addAction(menuStyle->menuAction());
    menubar->addAction(menuView->menuAction());
    menuFile->addAction(actionNew);
    menuFile->addAction(actionOpen);
    menuFile->addAction(actionSave);
    menuFile->addAction(actionClose);
    menuFile->addAction(actionExit);
    menuStyle->addAction(actionNPR1);
    menuStyle->addSeparator();
    menuStyle->addAction(actionNPR2_10);
    menuStyle->addAction(actionNPR2_20);
    menuStyle->addAction(actionNPR2_30);
    menuStyle->addSeparator();
    menuStyle->addAction(actionNPR_3);
    menuView->addAction(actionZoom_To_Fit);
    menuBasic_Operations->addAction(actionGuassian_Blur);
    menuBasic_Operations->addAction(actionEdge_Detection);
    menuBasic_Operations->addAction(actionCanny);
    menuBasic_Operations->addAction(actionSegmentation);
    menuBasic_Operations->addAction(actionHalftoning);
    toolBar->addAction(actionOpen);
    toolBar->addAction(actionSave);
    toolBar->addAction(actionClose);
    toolBar->addAction(actionExit);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QArtist", 0, QApplication::UnicodeUTF8));
    actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
    actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+F4", 0, QApplication::UnicodeUTF8));
    actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
    actionSave->setToolTip(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
    actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
    actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
    actionOpen->setToolTip(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
    actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
    actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
    actionNew->setToolTip(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
    actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
    actionClose->setToolTip(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
    actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+F4", 0, QApplication::UnicodeUTF8));
    actionGuassian_Blur->setText(QApplication::translate("MainWindow", "Guassian Blur", 0, QApplication::UnicodeUTF8));
    actionEdge_Detection->setText(QApplication::translate("MainWindow", "Edge Detection", 0, QApplication::UnicodeUTF8));
    actionNPR1->setText(QApplication::translate("MainWindow", "NPR1", 0, QApplication::UnicodeUTF8));
    actionNPR2_10->setText(QApplication::translate("MainWindow", "NPR2 TS 10", 0, QApplication::UnicodeUTF8));
    actionNPR2_20->setText(QApplication::translate("MainWindow", "NPR2 TS 20", 0, QApplication::UnicodeUTF8));
    actionNPR2_30->setText(QApplication::translate("MainWindow", "NPR2 TS 30", 0, QApplication::UnicodeUTF8));
    actionZoom_To_Fit->setText(QApplication::translate("MainWindow", "Zoom To Fit", 0, QApplication::UnicodeUTF8));
    actionZoom_To_Fit->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0, QApplication::UnicodeUTF8));
    actionCanny->setText(QApplication::translate("MainWindow", "Canny", 0, QApplication::UnicodeUTF8));
    actionSegmentation->setText(QApplication::translate("MainWindow", "Segmentation", 0, QApplication::UnicodeUTF8));
    actionNPR_3->setText(QApplication::translate("MainWindow", "NPR 3", 0, QApplication::UnicodeUTF8));
    actionHalftoning->setText(QApplication::translate("MainWindow", "Halftoning", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindow", "Result", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "Source", 0, QApplication::UnicodeUTF8));
    menuFile->setWindowTitle(QApplication::translate("MainWindow", "Dicom Viewer", 0, QApplication::UnicodeUTF8));
    menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    menuStyle->setTitle(QApplication::translate("MainWindow", "Style", 0, QApplication::UnicodeUTF8));
    menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
    menuBasic_Operations->setTitle(QApplication::translate("MainWindow", "Basic Operations", 0, QApplication::UnicodeUTF8));
    toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

#endif // UI_MAINWINDOW_H
