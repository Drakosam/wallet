//
// Created by drakosam on 12.01.24.
//

#include "accountview.h"


#include "QSplitter"
#include <QDebug>

AccountView::AccountView(QWidget *parent) : QWidget(parent)
{
    topWidget = new QWidget(this);
    nameLabel = new QLabel("Acont Name :: ", topWidget);
    balanceLabel = new QLabel("Account Balance :: ", topWidget);

    scrollArea = new QScrollArea(this);
    balanceList = new QVBoxLayout();

    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(&balanceInfoList);

    // change ownership for scrollArea, do not delete. balancainfoList if expire will delate balanceList
    balanceInfoList.setLayout(balanceList);


}

AccountView::~AccountView()
{
    delete nameLabel;
    delete balanceLabel;
    delete balanceList;
    delete topWidget;

    // do not delete scrollArea it have difrent owner
    // delete scrollArea;
}

void AccountView::resizeEvent(QResizeEvent* event)
{
    topWidget->resize(this->width(), 60);
    nameLabel->setGeometry(10,10,topWidget->width()/2 - 20,30);
    balanceLabel->setGeometry(topWidget->width()/2 + 10,10,topWidget->width()/2 - 20,30);
    scrollArea->setGeometry(10,60,this->width() - 20,this->height()-60);
 }

void AccountView::setWallet(AccontWallet &wallet)
{
    this->wallet = wallet;

    updateview();
}

void AccountView::updateview()
{
    for(long i = balanceItems.size()-1; i >= 0; i--)
    {
        auto* item = balanceItems.at(i);
        delete item;
    }

    balanceItems.clear();

    nameLabel->setText("Accont name : "+wallet.name);
    balanceLabel->setText("Accont Balance : " + QString::number(wallet.balance) + " " + wallet.currency);

    for(int i = 0; i < wallet.changes.size(); i++)
    {
        auto* item = new BalanceListItem();
        item->setBalanceChange(wallet.changes[i]);
        balanceItems.push_back(item);
        balanceList->addWidget(item);
    }
}