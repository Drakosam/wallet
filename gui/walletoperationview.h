//
// Created by drakosam on 14.01.24.
//

#ifndef WALLETOPERATIONVIEW_H
#define WALLETOPERATIONVIEW_H
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "../utility/utilityItems.h"

class WalletOperationView : public QWidget {

    Q_OBJECT
public:
    WalletOperationView(QWidget* parent = nullptr);
    ~WalletOperationView();

    void setWallet(AccontWallet& wallet);

private:
    AccontWallet operationWallet;
    QLineEdit* balanceChangeValue;
    QLineEdit* balanceChangeName;
    QLabel* balanceChangeNameLabel;
    QLabel* balanceChangeValueLabel;
    QPushButton* addBalanceButton;
    QPushButton* withdrawBalanceButton;


    void add_to_wallet();
    void withdraw_from_wallet();

signals:
    void walletChangedAdd(double value, QString name);
    void wallerChangedWithdraw(double value, QString name);
};



#endif //WALLETOPERATIONVIEW_H
