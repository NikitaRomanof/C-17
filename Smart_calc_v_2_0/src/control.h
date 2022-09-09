#ifndef SRC_CONTROL_H_
#define SRC_CONTROL_H_

#include <exception>

#include "calc_model.h"

namespace s21 {
class Controller {
 private:
  std::string m_inputString;

 public:
  explicit Controller(std::string const &str = "") : m_inputString(str) {}
  std::pair<std::string, double> calculations();
  std::vector<double> cr_annuity(double sum_credit, double time_credit,
                                 double per);
  std::vector<double> cr_dif(double sum_credit, double time_credit, double per);
  std::vector<double> dep_calc(std::map<double, double> r1,
                               std::map<double, double> w1, double all_sum,
                               double tern, double interest, double tax,
                               int period_s, int kap);
};

}  // namespace s21
#endif  // SRC_CONTROL_H_
