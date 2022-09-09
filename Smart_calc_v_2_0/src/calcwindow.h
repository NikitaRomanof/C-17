#ifndef SRC_CALCWINDOW_H_
#define SRC_CALCWINDOW_H_

#include <QMainWindow>
#include <QMessageBox>

#include "chx.h"
#include "control.h"
#include "creditcalc.h"
#include "depositcalc.h"
#include "plot.h"
#include "ui_calcwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class windowx;
}

class CalcWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit CalcWindow(QWidget *parent = nullptr);
  ~CalcWindow();

 private:
  Ui::CalcWindow *ui;

 private slots:
  void digits_numbers();
  bool notNumber(QString str, size_t pos);
  std::pair<size_t, int> helperDotClick();
  bool helperMD();
  void on_pushButton_dot_clicked();
  void on_pushButton_pi_clicked();
  void on_pushButton_e_clicked();
  void on_pushButton_div_clicked();
  void on_pushButton_mul_clicked();
  void on_pushButton_equals_clicked();
  void on_pushButton_ac_clicked();
  void on_pushButton_del_clicked();
  void on_pushButton_credit_clicked();
  void on_pushButton_deposit_clicked();
};
#endif  // SRC_CALCWINDOW_H_
