#include "depositcalc.h"

DepositCalc::DepositCalc(QWidget *parent)
    : QDialog(parent), ui(new Ui::DepositCalc) {
  ui->setupUi(this);
  _ter = 1;
  _period = 1;
  _kap = 0;
}

DepositCalc::~DepositCalc() { delete ui; }

void DepositCalc::on_pushButton_drez_clicked() {
  s21::Controller ctrl;
  std::map<double, double> r1;
  std::map<double, double> w1;
  r1.insert({ui->lineEdit_r1_1->value(), ui->lineEdit_r2_1->value()});
  r1.insert({ui->lineEdit_r1_2->value(), ui->lineEdit_r2_2->value()});
  r1.insert({ui->lineEdit_r1_3->value(), ui->lineEdit_r2_3->value()});
  r1.insert({ui->lineEdit_r1_4->value(), ui->lineEdit_r2_4->value()});
  r1.insert({ui->lineEdit_r1_5->value(), ui->lineEdit_r2_5->value()});
  r1.insert({ui->lineEdit_r1_6->value(), ui->lineEdit_r2_6->value()});
  r1.insert({ui->lineEdit_r1_7->value(), ui->lineEdit_r2_7->value()});
  r1.insert({ui->lineEdit_r1_8->value(), ui->lineEdit_r2_8->value()});
  r1.insert({ui->lineEdit_r1_9->value(), ui->lineEdit_r2_9->value()});
  r1.insert({ui->lineEdit_r1_10->value(), ui->lineEdit_r2_10->value()});
  w1.insert({ui->lineEdit_w1_1->value(), ui->lineEdit_w2_1->value()});
  w1.insert({ui->lineEdit_w1_2->value(), ui->lineEdit_w2_2->value()});
  w1.insert({ui->lineEdit_w1_3->value(), ui->lineEdit_w2_3->value()});
  w1.insert({ui->lineEdit_w1_4->value(), ui->lineEdit_w2_4->value()});
  w1.insert({ui->lineEdit_w1_5->value(), ui->lineEdit_w2_5->value()});
  w1.insert({ui->lineEdit_w1_6->value(), ui->lineEdit_w2_6->value()});
  w1.insert({ui->lineEdit_w1_7->value(), ui->lineEdit_w2_7->value()});
  w1.insert({ui->lineEdit_w1_8->value(), ui->lineEdit_w2_8->value()});
  w1.insert({ui->lineEdit_w1_9->value(), ui->lineEdit_w2_9->value()});
  w1.insert({ui->lineEdit_w1_10->value(), ui->lineEdit_w2_10->value()});
  double all_sum = ui->lineEdit_1->value();
  double tern = ui->lineEdit_2->value();
  tern *= _ter;
  double interest = ui->lineEdit_3->value();
  double tax = ui->lineEdit_4->value();
  std::vector<double> rez =
      ctrl.dep_calc(r1, w1, all_sum, tern, interest, tax, _period, _kap);
  ui->label_10->setText(QString::number(rez[0], 'f', 2));
  ui->label_12->setText(QString::number(rez[1], 'f', 2));
  ui->label_14->setText(QString::number(rez[2], 'f', 2));
}

void DepositCalc::on_comboBox_currentIndexChanged(int index) {
  if (index == 1) {
    _ter = 12;
  } else if (index == 0) {
    _ter = 1;
  }
}

void DepositCalc::on_comboBox_2_currentIndexChanged(int index) {
  if (index == 0) {
    _period = 1;
  } else if (index == 1) {
    _period = 6;
  } else if (index == 2) {
    _period = 12;
  } else if (index == 3) {
    _period = 1;
  }
}

void DepositCalc::on_checkBox_clicked(bool checked) {
  if (checked == true) {
    _kap = 1;
  } else {
    _kap = 0;
  }
}
