#ifndef _EC_STUDENT_H
#define _EC_STUDENT_H

#include <string>

// Student class
class ECStudent
{
public:
  ECStudent(const std::string &nameIn)
  {
    name = nameIn;
    hwScore = 0;
    mtScore = 0;
    finalScore = 0;
  }

  std::string GetName() const { return name; }

  double GetMT() const { return mtScore; }
  void SetMT(double s) { mtScore = s; }

  double GetFinal() const { return finalScore; }
  void SetFinal(double s) { finalScore = s; }

  double GetHW() const { return hwScore; }
  void SetHW(double s) { hwScore = s; }
  // ave score: 20% HW, 30% Midterm, 50% Final
  double GetAve() const { return 0.2 * hwScore + 0.3 * mtScore + 0.5 * finalScore; }

private:
  std::string name;
  double hwScore;
  double mtScore;
  double finalScore;
};

#endif
