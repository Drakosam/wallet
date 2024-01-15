//
// Created by drakosam on 13.01.24.
//

#ifndef UTILITYITEMS_H
#define UTILITYITEMS_H
#include <qstring.h>

struct BalanceChange
{
    QString name;
    double changeValue;
    QString status;
    bool isPositive;
};

struct AccontWallet
{
    QString name;
    QString short_name;
    QString currency;
    double balance;
    std::vector<BalanceChange> changes;

};

#endif //UTILITYITEMS_H
