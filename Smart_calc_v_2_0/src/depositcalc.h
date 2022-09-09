#ifndef SRC_DEPOSITCALC_H_
#define SRC_DEPOSITCALC_H_

#include <QDialog>
#include <QMessageBox>
#include <map>
#include <vector>

#include "control.h"
#include "ui_depositcalc.h"

namespace Ui {
class DepositCalc;
}

class DepositCalc : public QDialog {
  Q_OBJECT

 public:
  explicit DepositCalc(QWidget *parent = nullptr);
  ~DepositCalc();

 private slots:
  void on_pushButton_drez_clicked();
  void on_comboBox_currentIndexChanged(int index);
  void on_comboBox_2_currentIndexChanged(int index);
  void on_checkBox_clicked(bool checked);

 private:
  Ui::DepositCalc *ui;
  int _ter;
  int _period;
  int _kap;
};

#endif  // SRC_DEPOSITCALC_H_
