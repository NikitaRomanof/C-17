#include "calcwindow.h"

CalcWindow::CalcWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CalcWindow) {
  ui->setupUi(this);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_open, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_close, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digits_numbers()));
}

CalcWindow::~CalcWindow() {}

void CalcWindow::digits_numbers() {
  QPushButton *but = (QPushButton *)sender();
  QString str_form;
  str_form = (ui->result_inter->text() + but->text());
  ui->result_inter->setText(str_form);
}

bool CalcWindow::notNumber(QString str, size_t pos) {
  return str[pos] != '0' && str[pos] != '1' && str[pos] != '2' &&
         str[pos] != '3' && str[pos] != '4' && str[pos] != '5' &&
         str[pos] != '6' && str[pos] != '7' && str[pos] != '8' &&
         str[pos] != '9';
}

std::pair<size_t, int> CalcWindow::helperDotClick() {
  int count = 0;
  QString str = ui->result_inter->text();
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

void CalcWindow::on_pushButton_dot_clicked() {
  std::pair<size_t, int> rez = helperDotClick();
  QString str = ui->result_inter->text();
  if (rez.first != 0) {
    if (rez.second == 0 &&
        (str[rez.first - 1] >= '0' && str[rez.first - 1] <= '9')) {
      ui->result_inter->setText(ui->result_inter->text() + ".");
    }
  }
}

void CalcWindow::on_pushButton_pi_clicked() {
  std::pair<size_t, int> rez = helperDotClick();
  QString str = ui->result_inter->text();
  size_t j = rez.first - 1;
  if (rez.first == 0) {
    ui->result_inter->setText(ui->result_inter->text() + "3.141592653589793");
  } else if (rez.second == 0 && (notNumber(str, j) && str[j] != '.')) {
    ui->result_inter->setText(ui->result_inter->text() + "3.141592653589793");
  }
}

void CalcWindow::on_pushButton_e_clicked() {
  std::pair<size_t, int> rez = helperDotClick();
  QString str = ui->result_inter->text();
  size_t j = rez.first - 1;
  if (rez.first == 0) {
    ui->result_inter->setText(ui->result_inter->text() + "2.718281828459045");
  } else if (rez.second == 0 && (notNumber(str, j) && str[j] != '.')) {
    ui->result_inter->setText(ui->result_inter->text() + "2.718281828459045");
  }
}

bool CalcWindow::helperMD() {
  bool rez = false;
  QString str = ui->result_inter->text();
  int len = str.isNull() ? 0 : str.length();
  if (len != 0) {
    if ((str[len - 1] >= '0' && str[len - 1] <= '9') || str[len - 1] == ')' ||
        str[len - 1] == 'x') {
      rez = true;
    }
  }
  return rez;
}

void CalcWindow::on_pushButton_div_clicked() {
  if (helperMD()) {
    ui->result_inter->setText(ui->result_inter->text() + "/");
  }
}

void CalcWindow::on_pushButton_mul_clicked() {
  if (helperMD()) {
    ui->result_inter->setText(ui->result_inter->text() + "*");
  }
}

void CalcWindow::on_pushButton_ac_clicked() {
  ui->result_inter->setText("");
  ui->result_show->setText("0");
}

void CalcWindow::on_pushButton_del_clicked() {
  QString str = ui->result_inter->text();
  if (str.isNull() == false) {
    str.chop(1);
    ui->result_inter->setText(str);
  }
}

void CalcWindow::on_pushButton_equals_clicked() {
  QString str_expr = ui->result_inter->text();
  std::string strIn = str_expr.toLocal8Bit().data();

  if (str_expr.contains("x")) {
    QMessageBox::StandardButton do_x = QMessageBox::question(
        this, "",
        "Заданное выражение содержит х:\n yes - построить график функции;\n no "
        "- подставить значение х в выражение и получить результат.",
        QMessageBox::Yes | QMessageBox::No);
    if (do_x == QMessageBox::Yes) {
      Plot window(nullptr, str_expr);
      window.setModal(true);
      window.exec();
    } else if (do_x == QMessageBox::No) {
      Chx ch_wind(nullptr, str_expr);
      ch_wind.setModal(true);
      ch_wind.exec();
    }
  } else {
    s21::Controller control(strIn);
    std::pair<std::string, double> result = control.calculations();
    char outStr[256] = {0};
    if (result.first.size() == 0) {
      result.second = result.second == -0.0 ? 0.0 : result.second;
      sprintf(outStr, "%.15g", result.second);
      ui->result_show->setText(outStr);
    } else {
      QString qs = QString::fromLocal8Bit(result.first.c_str());
      ui->result_show->setText(qs);
    }
  }
}

void CalcWindow::on_pushButton_credit_clicked() {
  CreditCalc cwind(nullptr);
  cwind.setModal(true);
  cwind.exec();
}

void CalcWindow::on_pushButton_deposit_clicked() {
  DepositCalc dwind(nullptr);
  dwind.setModal(true);
  dwind.exec();
}
