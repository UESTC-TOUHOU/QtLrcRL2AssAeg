#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtLrcRL2AssAeg.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QtLrcRL2AssAegClass; };
QT_END_NAMESPACE

class QtLrcRL2AssAeg : public QWidget
{
    Q_OBJECT

public:
    QtLrcRL2AssAeg(QWidget *parent = nullptr);
    ~QtLrcRL2AssAeg();

private:
    Ui::QtLrcRL2AssAegClass *ui;
};
