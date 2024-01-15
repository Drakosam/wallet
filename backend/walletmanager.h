//
// Created by drakosam on 13.01.24.
//

#ifndef WALLETMANAGER_H
#define WALLETMANAGER_H

#include <vector>

#include "../utility/utilityItems.h"


class WalletManager {
public:
    WalletManager();
    ~WalletManager();

    std::vector<AccontWallet> getWallets();

private:
    std::vector<AccontWallet> wallets;

    void setupWallets();
    std::vector<BalanceChange> setupWalletbalanceChanges(int changeSize);
};



#endif //WALLETMANAGER_H
