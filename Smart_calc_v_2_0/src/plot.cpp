#include "plot.h"

#include "control.h"
#include "ui_plot.h"

Plot::Plot(QWidget *parent, QString str) : QDialog(parent), ui(new Ui::Plot) {
  ui->setupUi(this);
  _inStr = str;
  ui->show->setText(_inStr);
}

Plot::~Plot() { delete ui; }

void Plot::on_pButton_graph_clicked() {
  ui->widget->clearGraphs();
  ui->error->setText("Start build graph");
  QPen pen;
  pen.setColor(QColor(0, 0, 0));
  if (ui->buttonXMin->value() >= ui->buttonXMax->value() ||
      ui->buttonYMin->value() >= ui->buttonYMax->value()) {
    QMessageBox::warning(this, "",
                         "Заданное выражение содержит неверный интервал x/y",
                         QMessageBox::Ok);

  } else {
    ui->widget->xAxis->setRange(ui->buttonXMin->value(),
                                ui->buttonXMax->value());
    ui->widget->yAxis->setRange(ui->buttonYMin->value(),
                                ui->buttonYMax->value());
    ui->widget->addGraph()->setPen(pen);
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    QList<double> x;
    QList<double> y;
    for (double i = ui->buttonXMin->value(); i < ui->buttonXMax->value();) {
      x.push_back(i);
      QString buf = _inStr;
      QString str_expr = buf.replace(QString("x"), QString::number(i, 'f', 3));
      std::string strBuf = str_expr.toLocal8Bit().data();
      s21::Controller ctrl(strBuf);
      std::pair<std::string, double> result = ctrl.calculations();
      if (result.first.length() != 0) {
        QString strErr = QString::fromUtf8(result.first.c_str());
        ui->error->setText(strErr);
      } else {
        ui->error->setText("Build finished");
      }
      y.push_back(result.second);
      i += ui->step->value();
    }
    ui->widget->graph(0)->addData(x, y);
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget->setBackground(QColor(74, 189, 172));
    ui->widget->replot();
  }
}
