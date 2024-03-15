#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QMainWindow>

namespace Ui {
class functions;
}

class functions : public QMainWindow
{
    Q_OBJECT

public:
    explicit functions(QWidget *parent = nullptr);
    ~functions();
    void networkReplyReadyRead();//20
    void tryy();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::functions *ui;
    QNetworkAccessManager *m_networkManager;
    QNetworkReply *m_networkReply;
};

#endif // FUNCTIONS_H
