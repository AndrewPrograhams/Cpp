/*
Legal acknowledgements:

This program uses qt.io open source components. ( https://www.qt.io/ )
It is used by me, Andrew Graham, to create user interfaces to generate queries to Chat GPT. 

*/

#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        QVBoxLayout *layout = new QVBoxLayout(centralWidget);

        QHBoxLayout *inputLayout = new QHBoxLayout;
        QLabel *variableNameLabel = new QLabel("Variable Name:");
        inputLayout->addWidget(variableNameLabel);
        variableNameLineEdit = new QLineEdit;
        inputLayout->addWidget(variableNameLineEdit);

        QLabel *variableTypeLabel = new QLabel("Variable Type:");
        inputLayout->addWidget(variableTypeLabel);
        variableTypeLineEdit = new QLineEdit;
        inputLayout->addWidget(variableTypeLineEdit);

        layout->addLayout(inputLayout);

        addVariableButton = new QPushButton("Add New Variable");
        layout->addWidget(addVariableButton);

        connect(addVariableButton, &QPushButton::clicked, this, &MainWindow::addVariable);

        setWindowTitle("Window with Text Inputs and Checkboxes");
    }

private slots:
    void addVariable()
    {
        QGroupBox *variableGroupBox = new QGroupBox;
        QVBoxLayout *variableLayout = new QVBoxLayout(variableGroupBox);

        QHBoxLayout *permissionLayout = new QHBoxLayout;
        QCheckBox *brReadCheckBox = new QCheckBox("BR Read");
        permissionLayout->addWidget(brReadCheckBox);
        QCheckBox *brWriteCheckBox = new QCheckBox("BR Write");
        permissionLayout->addWidget(brWriteCheckBox);
        QCheckBox *brReWrCheckBox = new QCheckBox("BR ReWr");
        permissionLayout->addWidget(brReWrCheckBox);
        brPermissionCheckBoxes.append({ brReadCheckBox, brWriteCheckBox, brReWrCheckBox });
        variableLayout->addLayout(permissionLayout);

        QHBoxLayout *visLayout = new QHBoxLayout;
        QCheckBox *visAnyCheckBox = new QCheckBox("Vis Any");
        visLayout->addWidget(visAnyCheckBox);
        QCheckBox *visDefCheckBox = new QCheckBox("Vis Def");
        visLayout->addWidget(visDefCheckBox);
        QCheckBox *visInstCheckBox = new QCheckBox("Vis Inst");
        visLayout->addWidget(visInstCheckBox);
        visCheckBoxes.append({ visAnyCheckBox, visDefCheckBox, visInstCheckBox });
        variableLayout->addLayout(visLayout);

        QHBoxLayout *editLayout = new QHBoxLayout;
        QCheckBox *editAnyCheckBox = new QCheckBox("Edit Any");
        editLayout->addWidget(editAnyCheckBox);
        QCheckBox *editDefCheckBox = new QCheckBox("Edit Def");
        editLayout->addWidget(editDefCheckBox);
        QCheckBox *editInstCheckBox = new QCheckBox("Edit Inst");
        editLayout->addWidget(editInstCheckBox);
        editCheckBoxes.append({ editAnyCheckBox, editDefCheckBox, editInstCheckBox });
        variableLayout->addLayout(editLayout);

        QCheckBox *saveCheckBox = new QCheckBox("Save?");
        saveCheckBoxes.append(saveCheckBox);
        variableLayout->addWidget(saveCheckBox);

        QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(centralWidget()->layout());
        layout->addWidget(variableGroupBox);
    }

private:
    QLineEdit *variableNameLineEdit;
    QLineEdit *variableTypeLineEdit;
    QPushButton *addVariableButton;

    QList<QVector<QCheckBox*>> brPermissionCheckBoxes;
    QList<QVector<QCheckBox*>> visCheckBoxes;
    QList<QVector<QCheckBox*>> editCheckBoxes;
    QList<QCheckBox*> saveCheckBoxes;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}

#include "main.moc"