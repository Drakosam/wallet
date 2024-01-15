//
// Created by drakosam on 13.01.24.
//

#ifndef BALANCELISTITEM_H
#define BALANCELISTITEM_H
#include <QLabel>
#include <QWidget>
#include "../utility/utilityItems.h"

class BalanceListItem: public QWidget {
public:
    BalanceListItem(QWidget* parent = nullptr);
    ~BalanceListItem();

    void setBalanceChange(BalanceChange& change);
    void setCurrency(QString currency);
    void updateView();

private:
    QLabel* balanceChangeLabel;
    QLabel* balanceChangeValue;
    QLabel* balanceChangeStatus;
    QLabel* balanceChangeCurrency;
    QFrame* separator;
    BalanceChange change;
    QString currency;

    void resizeEvent(QResizeEvent* event) override;

};



#endif //BALANCELISTITEM_H
