#include "control.h"

namespace s21 {

std::pair<std::string, double> Controller::calculations() {
  std::string error = "";
  double rez = 0.0;
  try {
    Model model(m_inputString);
    rez = model.start();
  } catch (const std::exception& e) {
    error = e.what();
  }
  std::pair<std::string, double> result = {error, rez};
  return result;
}

std::vector<double> Controller::cr_annuity(double sum_credit,
                                           double time_credit, double per) {
  Model model(m_inputString);
  return model.credit_annuity(sum_credit, time_credit, per);
}

std::vector<double> Controller::cr_dif(double sum_credit, double time_credit,
                                       double per) {
  Model model(m_inputString);
  return model.credit_dif(sum_credit, time_credit, per);
}

std::vector<double> Controller::dep_calc(std::map<double, double> r1,
                                         std::map<double, double> w1,
                                         double all_sum, double tern,
                                         double interest, double tax,
                                         int period_s, int kap) {
  Model model(m_inputString);
  return model.deposit_calculator(r1, w1, all_sum, tern, interest, tax,
                                  period_s, kap);
}

}  // namespace s21
