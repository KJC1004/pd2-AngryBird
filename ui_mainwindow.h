/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *playButton;
    QPushButton *powerButton;
    QLabel *label_Sample;
    QLabel *label_Remain;
    QLabel *label_Result;
    QLabel *label_Score;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1600, 900);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1600, 900));
        MainWindow->setMaximumSize(QSize(1600, 900));
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(0, 0, 1600, 900));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMinimumSize(QSize(0, 0));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(0, 0, 150, 150));
        playButton->setStyleSheet(QStringLiteral("border-image: url(:/image/image/playbutton.png);"));
        powerButton = new QPushButton(centralWidget);
        powerButton->setObjectName(QStringLiteral("powerButton"));
        powerButton->setGeometry(QRect(0, 150, 150, 150));
        powerButton->setStyleSheet(QStringLiteral("border-image: url(:/image/image/powerbutton.png);"));
        label_Sample = new QLabel(centralWidget);
        label_Sample->setObjectName(QStringLiteral("label_Sample"));
        label_Sample->setGeometry(QRect(150, 150, 150, 150));
        label_Sample->setStyleSheet(QStringLiteral("image: url(:/image/image/red.png);"));
        label_Remain = new QLabel(centralWidget);
        label_Remain->setObjectName(QStringLiteral("label_Remain"));
        label_Remain->setGeometry(QRect(320, 150, 150, 150));
        label_Remain->setStyleSheet(QStringLiteral("font: 75 65pt \"Smudger LET\";"));
        label_Result = new QLabel(centralWidget);
        label_Result->setObjectName(QStringLiteral("label_Result"));
        label_Result->setGeometry(QRect(600, 200, 400, 200));
        QFont font;
        font.setFamily(QStringLiteral("Smudger LET"));
        font.setPointSize(72);
        font.setBold(true);
        font.setWeight(75);
        label_Result->setFont(font);
        label_Result->setAlignment(Qt::AlignCenter);
        label_Score = new QLabel(centralWidget);
        label_Score->setObjectName(QStringLiteral("label_Score"));
        label_Score->setGeometry(QRect(150, 0, 800, 150));
        QFont font1;
        font1.setFamily(QStringLiteral("Smudger LET"));
        font1.setPointSize(48);
        font1.setBold(true);
        font1.setWeight(75);
        label_Score->setFont(font1);
        label_Score->setStyleSheet(QStringLiteral(""));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        playButton->setText(QString());
        powerButton->setText(QString());
        label_Sample->setText(QString());
        label_Remain->setText(QString());
        label_Result->setText(QString());
        label_Score->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
