#include "chx.h"

Chx::Chx(QWidget *parent, QString strOut) : QDialog(parent), ui(new Ui::Chx) {
  ui->setupUi(this);
  _inpStr = strOut;
  ui->show->setText(_inpStr);
  connect(ui->pButton_0, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_1, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_2, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_3, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_4, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_5, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_6, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_7, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_8, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_9, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(d_numbers()));
}

Chx::~Chx() { delete ui; }

void Chx::d_numbers() {
  QPushButton *butt = (QPushButton *)sender();
  QString str;
  str = (ui->inter->text() + butt->text());
  ui->inter->setText(str);
}

bool Chx::notNumber(QString str, size_t pos) {
  return str[pos] != '0' && str[pos] != '1' && str[pos] != '2' &&
         str[pos] != '3' && str[pos] != '4' && str[pos] != '5' &&
         str[pos] != '6' && str[pos] != '7' && str[pos] != '8' &&
         str[pos] != '9';
}

std::pair<size_t, int> Chx::helperDotClick() {
  int count = 0;
  QString str = ui->inter->text();
  size_t len = str.isNull() ? 0 : str.length();
  for (size_t i = 0; i < len; i++) {
    if (str[i] == '.') {
      count = 1;
    } else if (notNumber(str, i)) {
      count = 0;
    }
  }
  std::pair<size_t, int> result = {len, count};
  return result;
}

void Chx::on_pButton_dot_clicked() {
  std::pair<size_t, int> rez = helperDotClick();
  QString str = ui->inter->text();
  if (rez.first != 0) {
    if (rez.second == 0 &&
        (str[rez.first - 1] >= '0' && str[rez.first - 1] <= '9')) {
      ui->inter->setText(ui->inter->text() + ".");
    }
  }
}

void Chx::on_pButton_del_clicked() {
  QString str = ui->inter->text();
  if (str.isNull() == false) {
    str.chop(1);
    ui->inter->setText(str);
  }
}

void Chx::on_pushpButton_AC_clicked() {
  ui->inter->setText("");
  ui->show->setText(_inpStr);
}

void Chx::on_pButton_equals_clicked() {
  QString buf = _inpStr;
  QString str_expr = buf.replace(QString("x"), ui->inter->text());
  std::string strIn = str_expr.toLocal8Bit().data();
  s21::Controller control(strIn);
  std::pair<std::string, double> result = control.calculations();
  if (result.first.size() == 0) {
    char outStr[256] = {0};
    sprintf(outStr, "%.15g", result.second);
    ui->show->setText(_inpStr + " = " + outStr);
  } else {
    QString qs = QString::fromLocal8Bit(result.first.c_str());
    ui->show->setText(qs);
  }
}
