#ifndef SRC_CREDITCALC_H_
#define SRC_CREDITCALC_H_

#include <QDialog>
#include <QMessageBox>
#include <vector>

#include "control.h"
#include "ui_creditcalc.h"

namespace Ui {
class CreditCalc;
}

class CreditCalc : public QDialog {
  Q_OBJECT

 public:
  explicit CreditCalc(QWidget *parent = nullptr);
  ~CreditCalc();

 private slots:
  void on_radioButton_clicked();
  void on_radioButton_2_clicked();
  void on_pushButton_ac_clicked();
  void on_comboBox_currentIndexChanged(int index);

 private:
  Ui::CreditCalc *ui;
  QString _str;
  int _count;
};

#endif  // SRC_CREDITCALC_H_
