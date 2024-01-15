//
// Created by drakosam on 13.01.24.
//

#include "walletmanager.h"

WalletManager::WalletManager() {
    setupWallets();
}

WalletManager::~WalletManager() {

}

std::vector<AccontWallet> WalletManager:: getWallets(){
    return wallets;
}



void WalletManager::setupWallets()
{
    AccontWallet wallet1;
    wallet1.name = "Wallet 1";
    wallet1.short_name = "W1";
    wallet1.currency = "PLN";
    wallet1.balance = 1000;
    wallet1.changes = setupWalletbalanceChanges(10);
    wallets.push_back(wallet1);

    AccontWallet wallet2;
    wallet2.name = "Wallet 2";
    wallet2.short_name = "W2";
    wallet2.currency = "PLN";
    wallet2.balance = 2000;
    wallet2.changes = setupWalletbalanceChanges(15);
    wallets.push_back(wallet2);

    AccontWallet wallet3;
    wallet3.name = "Wallet 3";
    wallet3.short_name = "W3";
    wallet3.currency = "PLN";
    wallet3.balance = 3000;
    wallet3.changes = setupWalletbalanceChanges(10);
    wallets.push_back(wallet3);

    AccontWallet wallet4;
    wallet4.name = "Wallet 4";
    wallet4.short_name = "W4";
    wallet4.currency = "PLN";
    wallet4.balance = 4000;
    wallet4.changes = setupWalletbalanceChanges(15);
    wallets.push_back(wallet4);
}

std::vector<BalanceChange> WalletManager::setupWalletbalanceChanges(int changeSize)
{
    std::vector<BalanceChange> changes;
    for(int i = 0; i < changeSize; i++)
    {
        BalanceChange change;
        change.name = "Change " + QString::number(i);
        change.changeValue = (rand()%20+1)*25;
        change.isPositive = i % 2 == 0;
        change.status = "applyed";
        changes.push_back(change);
    }
    return changes;
}