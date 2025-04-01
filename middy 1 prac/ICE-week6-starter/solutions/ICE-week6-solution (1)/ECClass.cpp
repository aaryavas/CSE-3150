#include "ECClass.h"
#include <vector>
#include <string>
using namespace std;

// Class for class
ECClass ::ECClass()
{
}

void ECClass ::AddStudent(const ECStudent &s)
{
  listStu.push_back(s);
}

double ECClass ::GetAveMedian() const
{
  vector<double> scores;
  for (const auto &student : listStu)
  {
    scores.push_back(student.GetAve());
  }
  sort(scores.begin(), scores.end());

  int n = scores.size();
  if (n % 2 == 0)
  {
    return (scores[n / 2 - 1] + scores[n / 2]) / 2.0;
  }
  else
  {
    return scores[n / 2];
  }
}

std::string ECClass ::GetRankedStudentName(int n) const
{
  vector<ECStudent> rankedStudents = listStu;
  sortStudentsByAve(rankedStudents);

  if (n >= 0 && n < rankedStudents.size())
  {
    return rankedStudents[n].GetName();
  }
  else
  {
    return "Invalid rank";
  }
}

void sortStudentsByAve(vector<ECStudent> &students)
{
  int n = students.size();
  for (int i = 0; i < n - 1; ++i)
  {
    for (int j = 0; j < n - i - 1; ++j)
    {
      if (students[j].GetAve() < students[j + 1].GetAve())
      {
        // Swap students[j] and students[j + 1]
        swap(students[j], students[j + 1]);
      }
    }
  }
}
