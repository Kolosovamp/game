#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private:
    Ui::Settings *ui;
    int maxW = 10;
    int maxH = 10;
    int minW = 5;
    int minH = 5;
};

#endif // SETTINGS_H
