#ifndef SRC_PLOT_H_
#define SRC_PLOT_H_

#include <QDialog>

#include "PlotLibrary/qcustomplot.h"
#include "control.h"

namespace Ui {
class Plot;
}

class Plot : public QDialog {
  Q_OBJECT

 public:
  Plot(QWidget *parent, QString labelText);
  ~Plot();

 private slots:
  void on_pButton_graph_clicked();

 private:
  Ui::Plot *ui;
  QString _inStr;
};

#endif  // SRC_PLOT_H_
