#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1200,800);
    move(100,100);
    tabWidget = new QTabWidget(this);
    walletOperationView = new WalletOperationView(this);

    walletManager = std::make_unique<WalletManager>();
    for (auto& wallet : walletManager->getWallets())
    {
        auto *accountView = new AccountView();
        accountViews.push_back(accountView);
        accountView->setWallet(wallet);
        tabWidget->addTab(accountView, wallet.short_name + " " + wallet.currency);
    }
    currentWallet = walletManager->getWallets()[0];

    QObject::connect(tabWidget, &QTabWidget::currentChanged, this, &MainWindow::walletChanged);
    QObject::connect(walletOperationView, &WalletOperationView::walletChangedAdd, this, &MainWindow::addToWallet);
    QObject::connect(walletOperationView, &WalletOperationView::wallerChangedWithdraw, this, &MainWindow::withdrawFromWallet);
}

MainWindow::~MainWindow()
{
    for(int i = accountViews.size()-1; i >= 0 ; i--)
    {
        delete accountViews[i];
    }
    delete ui;
    delete tabWidget;
    delete walletOperationView;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    tabWidget->resize(this->width(), this->height()-100);
    walletOperationView->setGeometry(0, this->height()-100, this->width(), 100);
}

void MainWindow::walletChanged(int index)
{
    auto  wallets =  walletManager->getWallets();
    if( index < 0 || index >=  walletManager->getWallets().size())
    {
        return;
    }

    currentWallet = wallets[index];
    qDebug() << "Wallet changed to " << index;
}

void MainWindow::addToWallet(double value, QString name)
{
    qDebug() << "Add to wallet " << value;
    currentWallet.balance += value;
    BalanceChange change;
    change.name = name;
    change.changeValue = value;
    change.status = "Added";
    change.isPositive = true;
    currentWallet.changes.insert(currentWallet.changes.begin(), change);

    accountViews[tabWidget->currentIndex()]->setWallet(currentWallet);


}

void MainWindow::withdrawFromWallet(double value, QString name)
{
    currentWallet.balance -= value;
    BalanceChange change;
    change.name = name;
    change.changeValue = value;
    change.status = "Added";
    change.isPositive = false;
    currentWallet.changes.insert(currentWallet.changes.begin(), change);
    accountViews[tabWidget->currentIndex()]->setWallet(currentWallet);
}