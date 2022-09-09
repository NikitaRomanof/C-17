#ifndef SRC_CHX_H_
#define SRC_CHX_H_

#include <QDialog>

#include "control.h"
#include "ui_chx.h"

namespace Ui {
class Chx;
}

class Chx : public QDialog {
  Q_OBJECT

 public:
  Chx(QWidget *parent, QString labelText);
  ~Chx();

 private:
  Ui::Chx *ui;

 private slots:
  void d_numbers();
  void on_pButton_dot_clicked();
  void on_pButton_del_clicked();
  void on_pushpButton_AC_clicked();
  void on_pButton_equals_clicked();
  bool notNumber(QString str, size_t pos);
  std::pair<size_t, int> helperDotClick();

 signals:

 private:
  QString _inpStr;
};

#endif  // SRC_CHX_H_
