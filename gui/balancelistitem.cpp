//
// Created by drakosam on 13.01.24.
//

#include "balancelistitem.h"
#include <QDebug>

BalanceListItem::BalanceListItem(QWidget *parent) : QWidget(parent) {
    setMinimumHeight(120);

    balanceChangeLabel = new QLabel("Balance Change Name", this);
    balanceChangeValue = new QLabel("Balance Change Value", this);
    balanceChangeStatus = new QLabel("Balance Change Status", this);
    balanceChangeCurrency = new QLabel("PLN", this);
    separator = new QFrame(this);
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);

    change.name = "Balance Change Name";
    change.changeValue = 0;
    change.status = "Balance Change Status";
    currency = "PLN";

}

BalanceListItem::~BalanceListItem() {
    delete balanceChangeLabel;
    delete balanceChangeValue;
    delete separator;
}

void BalanceListItem::resizeEvent(QResizeEvent* event)
{
    balanceChangeLabel->setGeometry(10,10, this->width()-20, 30);
    balanceChangeValue->setGeometry(10,40, this->width()/2-40, 30);
    balanceChangeStatus->setGeometry(this->width()/2+10,40, this->width()-40, 30);
    balanceChangeCurrency->setGeometry(10,70, this->width()/2-40, 30);
    separator->setGeometry(10,110, this->width()-20, 2);
}

void BalanceListItem::setBalanceChange(BalanceChange &change) {
    this->change = change;
    balanceChangeLabel->setText(change.name);
    balanceChangeValue->setText(QString::number(change.changeValue));
    balanceChangeStatus->setText(change.status);
    updateView();
}

void BalanceListItem::setCurrency(QString currency) {
    this->currency = currency;
    balanceChangeCurrency->setText(currency);
    updateView();
}

void BalanceListItem::updateView() {
    balanceChangeLabel->setText(change.name);
    int value = change.changeValue;
    if(!change.isPositive){
        value *= (-1);
    }
    balanceChangeValue->setText(QString::number(value));
    balanceChangeStatus->setText(change.status);
    balanceChangeCurrency->setText(currency);
}