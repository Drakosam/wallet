//
// Created by drakosam on 12.01.24.
//

#ifndef ACCONTVIEW_H
#define ACCONTVIEW_H
#include <QVBoxLayout>
#include <QScrollArea>

#include "../utility/utilityItems.h"
#include "balancelistitem.h"

class AccountView: public QWidget
{
    Q_OBJECT
public:
    AccountView(QWidget *parent = nullptr);
    ~AccountView();


    QLabel* nameLabel;
    QLabel* balanceLabel;
    QWidget* topWidget;

    QWidget balanceInfoList;

    QVBoxLayout* balanceList;
    QScrollArea* scrollArea;

    AccontWallet wallet;

    void setWallet(AccontWallet &wallet);
    void updateview();

private:
    void resizeEvent(QResizeEvent* event) override;


    std::vector<BalanceListItem*> balanceItems;

};



#endif //ACCONTVIEW_H
