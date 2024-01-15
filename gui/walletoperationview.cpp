#include "walletoperationview.h"
#include <QIntValidator>
#include <QDebug>

WalletOperationView::WalletOperationView(QWidget* parent) : QWidget(parent) {

    balanceChangeValueLabel = new QLabel("Balance change value", this);
    balanceChangeValueLabel->setGeometry(10, 60, 100, 30);

    balanceChangeValue = new QLineEdit(this);
    balanceChangeValue->setGeometry(110,60, 100, 30);
    balanceChangeValue->setValidator(new QDoubleValidator(0, 10000000, 2, this));

    addBalanceButton = new QPushButton("Add", this);
    addBalanceButton->setGeometry(220,60, 100, 30);
    QObject::connect(addBalanceButton, &QPushButton::clicked, this, &WalletOperationView::add_to_wallet);

    withdrawBalanceButton = new QPushButton("Withdraw", this);
    withdrawBalanceButton->setGeometry(330,60, 100, 30);
    QObject::connect(withdrawBalanceButton, &QPushButton::clicked, this, &WalletOperationView::withdraw_from_wallet);

    balanceChangeNameLabel = new QLabel("Balance change name", this);
    balanceChangeNameLabel->setGeometry(10, 10, 100, 30);

    balanceChangeName = new QLineEdit(this);
    balanceChangeName->setGeometry(110,10, 1000, 30);
}

WalletOperationView::~WalletOperationView() {
    delete balanceChangeValue;
    delete addBalanceButton;
    delete withdrawBalanceButton;
    delete balanceChangeName;
    delete balanceChangeNameLabel;
    delete balanceChangeValueLabel;

}

void WalletOperationView::add_to_wallet() {
    qDebug() << "Add to wallet";
    emit walletChangedAdd(balanceChangeValue->text().replace(",",".").toDouble(), balanceChangeName->text());
    balanceChangeValue->setText("");
    balanceChangeName->setText("");
}

void WalletOperationView::withdraw_from_wallet() {
    emit wallerChangedWithdraw(balanceChangeValue->text().replace(",",".").toDouble(), balanceChangeName->text());
    balanceChangeValue->setText("");
    balanceChangeName->setText("");
}