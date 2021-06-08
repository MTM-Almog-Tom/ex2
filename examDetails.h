#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class ExamDetails
{
private:
    int course_number;
    int month;
    int day;
    double starting_time;
    int duration_time;
    string zoom_link;

public:
    ExamDetails(int course_number,
                int month,
                int day,
                double starting_time,
                int duration_time,
                string zoom_link = "");                                      //constructor
    ExamDetails(const ExamDetails &copy_from);                               //copy constructor
    ExamDetails &operator=(const ExamDetails &copy_from);                    //copy assignment
    int operator-(const ExamDetails &exam_details) const;                    //time sub assignment
    bool operator<(const ExamDetails &exam_details) const;                   //early time assignment
    string getLink() const;                                                  // accessor function
    void setLink(string zoom_link);                                          // accessor function
    void print() const;                                                      //print function
    static ExamDetails makeMatamExam();                                      //static function makeMatamExam
    ~ExamDetails();                                                          //distructor
    friend std::ostream &operator<<(std::ostream &os, const ExamDetails &r); // cout << s1;
    class InvalidDateException                                               //exeptions
    {
    };
    class InvalidTimeException
    {
    };
    class InvalidArgsException
    {
    };
};
