#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QCloseEvent>
#include <QFile>
#include <QMainWindow>
#include <QMessageBox>
#include <QRegExpValidator>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTime>
#include <QTimer>
#include <iostream>

namespace Ui {
class ThirdWindow;
}

class ThirdWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ThirdWindow(QWidget* parent = nullptr, QString login = nullptr);
    ~ThirdWindow();
public slots:
    int text_verification(QString str, QString text);
    int speed_measurement(int time, QString text);
    QString open_file(QString path);
    void write_score(QString username, QString level, int speed);

private slots:

    QString on_pushButton_start_clicked();

    void on_pushButton_check_clicked();

    void onTimeout();

    void closeEvent(QCloseEvent* event);

private:
    Ui::ThirdWindow* thirdwindow;
    int speed, mis, ti, dop, i;
    QTimer* timer;
    QTime t;
    QString path, lvl1, lvl2, lvl3, buffer, timetext, time_show, level,
            username;
};

#endif // THIRDWINDOW_H
