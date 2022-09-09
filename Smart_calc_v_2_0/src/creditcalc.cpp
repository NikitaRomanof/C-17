#include "creditcalc.h"

CreditCalc::CreditCalc(QWidget *parent)
    : QDialog(parent), ui(new Ui::CreditCalc) {
  ui->setupUi(this);
  _str = "";
  _count = 1;
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::on_radioButton_clicked() { _str = "A"; }

void CreditCalc::on_radioButton_2_clicked() { _str = "D"; }

void CreditCalc::on_pushButton_ac_clicked() {
  bool ok1;
  bool ok2;
  bool ok3;
  s21::Controller ctrl;
  double sumCredit = ui->lineEdit->text().toDouble(&ok1);
  double tern = ui->lineEdit_2->text().toDouble(&ok2);
  tern *= _count;
  double per = ui->lineEdit_3->text().toDouble(&ok3);
  if (ok1 == true && ok2 == true && ok3 == true && tern < 601.00 &&
      _str.contains("A")) {
    std::vector<double> rez = ctrl.cr_annuity(sumCredit, tern, per);
    ui->label_7->setText(QString::number(rez[0], 'f', 2));
    ui->label_9->setText(QString::number(rez[1], 'f', 2));
    ui->label_11->setText(QString::number(rez[2], 'f', 2));
  } else if (ok1 == true && ok2 == true && ok3 == true && tern < 601.00 &&
             _str.contains("D")) {
    std::vector<double> rez = ctrl.cr_dif(sumCredit, tern, per);
    ui->label_7->setText(QString::number(rez[0], 'f', 2) + " ... " +
                         QString::number(rez[1], 'f', 2));
    ui->label_9->setText(QString::number(rez[2], 'f', 2));
    ui->label_11->setText(QString::number(rez[3], 'f', 2));
  } else {
    QMessageBox::critical(this, "Error", "Incorrect data entry!");
  }
}

void CreditCalc::on_comboBox_currentIndexChanged(int index) {
  if (index == 1) {
    _count = 12;
  } else if (index == 0) {
    _count = 1;
  }
}
