#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../backend/walletmanager.h"
#include "accountview.h"
#include "walletoperationview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<WalletManager> walletManager;
    QTabWidget* tabWidget;
    WalletOperationView* walletOperationView;
    std::vector<AccountView*> accountViews;
    AccontWallet currentWallet;

    void walletChanged(int index);
    void addToWallet(double value, QString name);
    void withdrawFromWallet(double value, QString name);
    void resizeEvent(QResizeEvent* event) override;

};
#endif // MAINWINDOW_H
