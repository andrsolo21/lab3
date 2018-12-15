/********************************************************************************
** Form generated from reading UI file 'lab1_3.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB1_3_H
#define UI_LAB1_3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab1_3Class
{
public:
    QWidget *centralWidget;
    QGroupBox *groupField;
    QWidget *verticalLayoutWidget_11;
    QVBoxLayout *verticalLayout_11;
    QRadioButton *radioRazm;
    QHBoxLayout *horizontalLayout;
    QLineEdit *fieldGabsX;
    QLineEdit *fieldGabsY;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioFile;
    QLineEdit *lineEdit_3;
    QPushButton *but_3;
    QGroupBox *groupPres;
    QWidget *verticalLayoutWidget_12;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_24;
    QComboBox *comboPress_3;
    QLineEdit *namePresLine_3;
    QLabel *label_25;
    QLineEdit *radiusPresLine_3;
    QLabel *label_26;
    QHBoxLayout *horizontalLayout_17;
    QLineEdit *coordPresX_3;
    QLineEdit *coordPresY_3;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *but4_3;
    QPushButton *but3_3;
    QSpacerItem *horizontalSpacer_18;
    QPushButton *but8_3;
    QGroupBox *changeField;
    QWidget *verticalLayoutWidget_14;
    QVBoxLayout *verticalLayout_14;
    QPushButton *delAll_3;
    QLabel *label_29;
    QLineEdit *strToFile_3;
    QPushButton *printBtn_3;
    QGroupBox *groupCar;
    QWidget *verticalLayoutWidget_15;
    QVBoxLayout *verticalLayout_15;
    QComboBox *comboBoxCar_3;
    QLabel *label_30;
    QLineEdit *nameAddLine_3;
    QLabel *label_31;
    QHBoxLayout *horizontalLayout_22;
    QLineEdit *coordXLine_3;
    QLineEdit *coordYLine_3;
    QSpacerItem *horizontalSpacer_22;
    QLabel *label_32;
    QHBoxLayout *horizontalLayout_23;
    QLineEdit *gabXLine_3;
    QLineEdit *gabYLine_3;
    QSpacerItem *horizontalSpacer_23;
    QLabel *label_33;
    QLineEdit *angleLine_3;
    QHBoxLayout *horizontalLayout_24;
    QPushButton *but5_3;
    QPushButton *but2_3;
    QSpacerItem *horizontalSpacer_24;
    QPushButton *but7_3;
    QPushButton *reduceBut;
    QGroupBox *btnGroup;
    QWidget *verticalLayoutWidget_13;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *addFieldBut_3;
    QPushButton *changeFieldBut_3;
    QSpacerItem *horizontalSpacer_19;
    QLabel *label_27;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *addCarBut_3;
    QPushButton *changeCarBut_3;
    QSpacerItem *horizontalSpacer_20;
    QLabel *label_28;
    QHBoxLayout *horizontalLayout_21;
    QPushButton *addPresBut_3;
    QPushButton *changePressBut_3;
    QSpacerItem *horizontalSpacer_21;

    void setupUi(QMainWindow *Lab1_3Class)
    {
        if (Lab1_3Class->objectName().isEmpty())
            Lab1_3Class->setObjectName(QStringLiteral("Lab1_3Class"));
        Lab1_3Class->resize(900, 600);
        Lab1_3Class->setMinimumSize(QSize(650, 488));
        centralWidget = new QWidget(Lab1_3Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupField = new QGroupBox(centralWidget);
        groupField->setObjectName(QStringLiteral("groupField"));
        groupField->setGeometry(QRect(130, 20, 221, 271));
        verticalLayoutWidget_11 = new QWidget(groupField);
        verticalLayoutWidget_11->setObjectName(QStringLiteral("verticalLayoutWidget_11"));
        verticalLayoutWidget_11->setGeometry(QRect(10, 20, 201, 141));
        verticalLayout_11 = new QVBoxLayout(verticalLayoutWidget_11);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        radioRazm = new QRadioButton(verticalLayoutWidget_11);
        radioRazm->setObjectName(QStringLiteral("radioRazm"));
        radioRazm->setChecked(true);

        verticalLayout_11->addWidget(radioRazm);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        fieldGabsX = new QLineEdit(verticalLayoutWidget_11);
        fieldGabsX->setObjectName(QStringLiteral("fieldGabsX"));

        horizontalLayout->addWidget(fieldGabsX);

        fieldGabsY = new QLineEdit(verticalLayoutWidget_11);
        fieldGabsY->setObjectName(QStringLiteral("fieldGabsY"));

        horizontalLayout->addWidget(fieldGabsY);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_11->addLayout(horizontalLayout);

        radioFile = new QRadioButton(verticalLayoutWidget_11);
        radioFile->setObjectName(QStringLiteral("radioFile"));

        verticalLayout_11->addWidget(radioFile);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget_11);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout_11->addWidget(lineEdit_3);

        but_3 = new QPushButton(verticalLayoutWidget_11);
        but_3->setObjectName(QStringLiteral("but_3"));

        verticalLayout_11->addWidget(but_3);

        groupPres = new QGroupBox(centralWidget);
        groupPres->setObjectName(QStringLiteral("groupPres"));
        groupPres->setGeometry(QRect(520, 120, 281, 281));
        verticalLayoutWidget_12 = new QWidget(groupPres);
        verticalLayoutWidget_12->setObjectName(QStringLiteral("verticalLayoutWidget_12"));
        verticalLayoutWidget_12->setGeometry(QRect(10, 20, 211, 221));
        verticalLayout_12 = new QVBoxLayout(verticalLayoutWidget_12);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_24 = new QLabel(verticalLayoutWidget_12);
        label_24->setObjectName(QStringLiteral("label_24"));

        verticalLayout_12->addWidget(label_24);

        comboPress_3 = new QComboBox(verticalLayoutWidget_12);
        comboPress_3->setObjectName(QStringLiteral("comboPress_3"));

        verticalLayout_12->addWidget(comboPress_3);

        namePresLine_3 = new QLineEdit(verticalLayoutWidget_12);
        namePresLine_3->setObjectName(QStringLiteral("namePresLine_3"));

        verticalLayout_12->addWidget(namePresLine_3);

        label_25 = new QLabel(verticalLayoutWidget_12);
        label_25->setObjectName(QStringLiteral("label_25"));

        verticalLayout_12->addWidget(label_25);

        radiusPresLine_3 = new QLineEdit(verticalLayoutWidget_12);
        radiusPresLine_3->setObjectName(QStringLiteral("radiusPresLine_3"));

        verticalLayout_12->addWidget(radiusPresLine_3);

        label_26 = new QLabel(verticalLayoutWidget_12);
        label_26->setObjectName(QStringLiteral("label_26"));

        verticalLayout_12->addWidget(label_26);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_17->setSizeConstraint(QLayout::SetMinAndMaxSize);
        coordPresX_3 = new QLineEdit(verticalLayoutWidget_12);
        coordPresX_3->setObjectName(QStringLiteral("coordPresX_3"));

        horizontalLayout_17->addWidget(coordPresX_3);

        coordPresY_3 = new QLineEdit(verticalLayoutWidget_12);
        coordPresY_3->setObjectName(QStringLiteral("coordPresY_3"));

        horizontalLayout_17->addWidget(coordPresY_3);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_17);


        verticalLayout_12->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setSizeConstraint(QLayout::SetMinAndMaxSize);
        but4_3 = new QPushButton(verticalLayoutWidget_12);
        but4_3->setObjectName(QStringLiteral("but4_3"));

        horizontalLayout_18->addWidget(but4_3);

        but3_3 = new QPushButton(verticalLayoutWidget_12);
        but3_3->setObjectName(QStringLiteral("but3_3"));

        horizontalLayout_18->addWidget(but3_3);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_18);


        verticalLayout_12->addLayout(horizontalLayout_18);

        but8_3 = new QPushButton(verticalLayoutWidget_12);
        but8_3->setObjectName(QStringLiteral("but8_3"));

        verticalLayout_12->addWidget(but8_3);

        changeField = new QGroupBox(centralWidget);
        changeField->setObjectName(QStringLiteral("changeField"));
        changeField->setGeometry(QRect(290, 240, 231, 281));
        verticalLayoutWidget_14 = new QWidget(changeField);
        verticalLayoutWidget_14->setObjectName(QStringLiteral("verticalLayoutWidget_14"));
        verticalLayoutWidget_14->setGeometry(QRect(10, 30, 261, 101));
        verticalLayout_14 = new QVBoxLayout(verticalLayoutWidget_14);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        delAll_3 = new QPushButton(verticalLayoutWidget_14);
        delAll_3->setObjectName(QStringLiteral("delAll_3"));

        verticalLayout_14->addWidget(delAll_3);

        label_29 = new QLabel(verticalLayoutWidget_14);
        label_29->setObjectName(QStringLiteral("label_29"));

        verticalLayout_14->addWidget(label_29);

        strToFile_3 = new QLineEdit(verticalLayoutWidget_14);
        strToFile_3->setObjectName(QStringLiteral("strToFile_3"));

        verticalLayout_14->addWidget(strToFile_3);

        printBtn_3 = new QPushButton(verticalLayoutWidget_14);
        printBtn_3->setObjectName(QStringLiteral("printBtn_3"));

        verticalLayout_14->addWidget(printBtn_3);

        groupCar = new QGroupBox(centralWidget);
        groupCar->setObjectName(QStringLiteral("groupCar"));
        groupCar->setGeometry(QRect(30, 90, 61, 51));
        verticalLayoutWidget_15 = new QWidget(groupCar);
        verticalLayoutWidget_15->setObjectName(QStringLiteral("verticalLayoutWidget_15"));
        verticalLayoutWidget_15->setGeometry(QRect(10, 20, 271, 301));
        verticalLayout_15 = new QVBoxLayout(verticalLayoutWidget_15);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        comboBoxCar_3 = new QComboBox(verticalLayoutWidget_15);
        comboBoxCar_3->setObjectName(QStringLiteral("comboBoxCar_3"));

        verticalLayout_15->addWidget(comboBoxCar_3);

        label_30 = new QLabel(verticalLayoutWidget_15);
        label_30->setObjectName(QStringLiteral("label_30"));

        verticalLayout_15->addWidget(label_30);

        nameAddLine_3 = new QLineEdit(verticalLayoutWidget_15);
        nameAddLine_3->setObjectName(QStringLiteral("nameAddLine_3"));

        verticalLayout_15->addWidget(nameAddLine_3);

        label_31 = new QLabel(verticalLayoutWidget_15);
        label_31->setObjectName(QStringLiteral("label_31"));

        verticalLayout_15->addWidget(label_31);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setSizeConstraint(QLayout::SetMinAndMaxSize);
        coordXLine_3 = new QLineEdit(verticalLayoutWidget_15);
        coordXLine_3->setObjectName(QStringLiteral("coordXLine_3"));

        horizontalLayout_22->addWidget(coordXLine_3);

        coordYLine_3 = new QLineEdit(verticalLayoutWidget_15);
        coordYLine_3->setObjectName(QStringLiteral("coordYLine_3"));

        horizontalLayout_22->addWidget(coordYLine_3);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_22);


        verticalLayout_15->addLayout(horizontalLayout_22);

        label_32 = new QLabel(verticalLayoutWidget_15);
        label_32->setObjectName(QStringLiteral("label_32"));

        verticalLayout_15->addWidget(label_32);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        horizontalLayout_23->setSizeConstraint(QLayout::SetMinAndMaxSize);
        gabXLine_3 = new QLineEdit(verticalLayoutWidget_15);
        gabXLine_3->setObjectName(QStringLiteral("gabXLine_3"));

        horizontalLayout_23->addWidget(gabXLine_3);

        gabYLine_3 = new QLineEdit(verticalLayoutWidget_15);
        gabYLine_3->setObjectName(QStringLiteral("gabYLine_3"));

        horizontalLayout_23->addWidget(gabYLine_3);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_23);


        verticalLayout_15->addLayout(horizontalLayout_23);

        label_33 = new QLabel(verticalLayoutWidget_15);
        label_33->setObjectName(QStringLiteral("label_33"));

        verticalLayout_15->addWidget(label_33);

        angleLine_3 = new QLineEdit(verticalLayoutWidget_15);
        angleLine_3->setObjectName(QStringLiteral("angleLine_3"));

        verticalLayout_15->addWidget(angleLine_3);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        horizontalLayout_24->setSizeConstraint(QLayout::SetMinAndMaxSize);
        but5_3 = new QPushButton(verticalLayoutWidget_15);
        but5_3->setObjectName(QStringLiteral("but5_3"));

        horizontalLayout_24->addWidget(but5_3);

        but2_3 = new QPushButton(verticalLayoutWidget_15);
        but2_3->setObjectName(QStringLiteral("but2_3"));

        horizontalLayout_24->addWidget(but2_3);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_24);


        verticalLayout_15->addLayout(horizontalLayout_24);

        but7_3 = new QPushButton(verticalLayoutWidget_15);
        but7_3->setObjectName(QStringLiteral("but7_3"));

        verticalLayout_15->addWidget(but7_3);

        reduceBut = new QPushButton(centralWidget);
        reduceBut->setObjectName(QStringLiteral("reduceBut"));
        reduceBut->setGeometry(QRect(0, 0, 31, 16));
        btnGroup = new QGroupBox(centralWidget);
        btnGroup->setObjectName(QStringLiteral("btnGroup"));
        btnGroup->setGeometry(QRect(20, 310, 141, 121));
        verticalLayoutWidget_13 = new QWidget(btnGroup);
        verticalLayoutWidget_13->setObjectName(QStringLiteral("verticalLayoutWidget_13"));
        verticalLayoutWidget_13->setGeometry(QRect(10, 20, 211, 127));
        verticalLayout_13 = new QVBoxLayout(verticalLayoutWidget_13);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setSizeConstraint(QLayout::SetMinAndMaxSize);
        addFieldBut_3 = new QPushButton(verticalLayoutWidget_13);
        addFieldBut_3->setObjectName(QStringLiteral("addFieldBut_3"));

        horizontalLayout_19->addWidget(addFieldBut_3);

        changeFieldBut_3 = new QPushButton(verticalLayoutWidget_13);
        changeFieldBut_3->setObjectName(QStringLiteral("changeFieldBut_3"));

        horizontalLayout_19->addWidget(changeFieldBut_3);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_19);


        verticalLayout_13->addLayout(horizontalLayout_19);

        label_27 = new QLabel(verticalLayoutWidget_13);
        label_27->setObjectName(QStringLiteral("label_27"));

        verticalLayout_13->addWidget(label_27);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalLayout_20->setSizeConstraint(QLayout::SetMinAndMaxSize);
        addCarBut_3 = new QPushButton(verticalLayoutWidget_13);
        addCarBut_3->setObjectName(QStringLiteral("addCarBut_3"));

        horizontalLayout_20->addWidget(addCarBut_3);

        changeCarBut_3 = new QPushButton(verticalLayoutWidget_13);
        changeCarBut_3->setObjectName(QStringLiteral("changeCarBut_3"));

        horizontalLayout_20->addWidget(changeCarBut_3);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_20);


        verticalLayout_13->addLayout(horizontalLayout_20);

        label_28 = new QLabel(verticalLayoutWidget_13);
        label_28->setObjectName(QStringLiteral("label_28"));

        verticalLayout_13->addWidget(label_28);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalLayout_21->setSizeConstraint(QLayout::SetMinAndMaxSize);
        addPresBut_3 = new QPushButton(verticalLayoutWidget_13);
        addPresBut_3->setObjectName(QStringLiteral("addPresBut_3"));

        horizontalLayout_21->addWidget(addPresBut_3);

        changePressBut_3 = new QPushButton(verticalLayoutWidget_13);
        changePressBut_3->setObjectName(QStringLiteral("changePressBut_3"));

        horizontalLayout_21->addWidget(changePressBut_3);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_21);


        verticalLayout_13->addLayout(horizontalLayout_21);

        Lab1_3Class->setCentralWidget(centralWidget);

        retranslateUi(Lab1_3Class);

        QMetaObject::connectSlotsByName(Lab1_3Class);
    } // setupUi

    void retranslateUi(QMainWindow *Lab1_3Class)
    {
        Lab1_3Class->setWindowTitle(QApplication::translate("Lab1_3Class", "Lab1_3", Q_NULLPTR));
        groupField->setTitle(QApplication::translate("Lab1_3Class", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\320\276\320\273\320\265", Q_NULLPTR));
        radioRazm->setText(QApplication::translate("Lab1_3Class", "\320\267\320\260\320\264\320\260\321\202\321\214 \321\200\320\260\320\267\320\274\320\265\321\200", Q_NULLPTR));
        radioFile->setText(QApplication::translate("Lab1_3Class", "\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", Q_NULLPTR));
        lineEdit_3->setText(QString());
        but_3->setText(QApplication::translate("Lab1_3Class", "\321\201\320\276\320\267\320\264\320\260\321\202\321\214", Q_NULLPTR));
        groupPres->setTitle(QApplication::translate("Lab1_3Class", "\320\241\321\202\320\265\320\275\320\264", Q_NULLPTR));
        label_24->setText(QApplication::translate("Lab1_3Class", "name", Q_NULLPTR));
        namePresLine_3->setText(QString());
        label_25->setText(QApplication::translate("Lab1_3Class", "radius", Q_NULLPTR));
        radiusPresLine_3->setText(QString());
        label_26->setText(QApplication::translate("Lab1_3Class", "coord", Q_NULLPTR));
        coordPresX_3->setText(QString());
        coordPresY_3->setText(QString());
        but4_3->setText(QApplication::translate("Lab1_3Class", "\320\276\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
        but3_3->setText(QApplication::translate("Lab1_3Class", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        but8_3->setText(QApplication::translate("Lab1_3Class", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        changeField->setTitle(QApplication::translate("Lab1_3Class", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\276\320\273\320\265", Q_NULLPTR));
        delAll_3->setText(QApplication::translate("Lab1_3Class", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265", Q_NULLPTR));
        label_29->setText(QApplication::translate("Lab1_3Class", "\320\277\320\265\321\207\320\260\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        printBtn_3->setText(QApplication::translate("Lab1_3Class", "\320\277\320\265\321\207\320\260\321\202\321\214", Q_NULLPTR));
        groupCar->setTitle(QApplication::translate("Lab1_3Class", "\320\234\320\260\321\210\320\270\320\275\320\260", Q_NULLPTR));
        label_30->setText(QApplication::translate("Lab1_3Class", "name", Q_NULLPTR));
        nameAddLine_3->setText(QString());
        label_31->setText(QApplication::translate("Lab1_3Class", "Coord", Q_NULLPTR));
        coordXLine_3->setText(QString());
        coordYLine_3->setText(QString());
        label_32->setText(QApplication::translate("Lab1_3Class", "Gabarites", Q_NULLPTR));
        gabXLine_3->setText(QString());
        gabYLine_3->setText(QString());
        label_33->setText(QApplication::translate("Lab1_3Class", "Angle", Q_NULLPTR));
        angleLine_3->setText(QString());
        but5_3->setText(QApplication::translate("Lab1_3Class", "\320\276\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
        but2_3->setText(QApplication::translate("Lab1_3Class", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        but7_3->setText(QApplication::translate("Lab1_3Class", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        reduceBut->setText(QApplication::translate("Lab1_3Class", "...", Q_NULLPTR));
        btnGroup->setTitle(QApplication::translate("Lab1_3Class", "\320\234\320\265\320\275\321\216", Q_NULLPTR));
        addFieldBut_3->setText(QApplication::translate("Lab1_3Class", "\321\201\320\276\320\267\320\264\320\260\321\202\321\214", Q_NULLPTR));
        changeFieldBut_3->setText(QApplication::translate("Lab1_3Class", "\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
        label_27->setText(QApplication::translate("Lab1_3Class", "\320\234\320\260\321\210\320\270\320\275\320\260", Q_NULLPTR));
        addCarBut_3->setText(QApplication::translate("Lab1_3Class", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        changeCarBut_3->setText(QApplication::translate("Lab1_3Class", "\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
        label_28->setText(QApplication::translate("Lab1_3Class", "\320\241\321\202\320\265\320\275\320\264", Q_NULLPTR));
        addPresBut_3->setText(QApplication::translate("Lab1_3Class", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        changePressBut_3->setText(QApplication::translate("Lab1_3Class", "\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Lab1_3Class: public Ui_Lab1_3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB1_3_H
