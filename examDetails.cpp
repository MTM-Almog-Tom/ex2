#include "examDetails.h"

// constractor of ExamDetails
ExamDetails::ExamDetails(int course_number, int month, int day, double starting_time, int duration_time, string zoom_link)
{
    if (course_number < 100000 || course_number > 999999)
    {
        throw InvalidArgsException();
    }
    if (month < 0 || month > 12 || day < 0 || day > 30)
    {
        throw InvalidDateException();
    }
    if ((starting_time - (int)starting_time != 0.5) && (starting_time - (int)starting_time != 0) || duration_time < 0)
    {
        throw InvalidTimeException();
    }
    this->course_number = course_number;
    this->month = month;
    this->day = day;
    this->starting_time = starting_time;
    this->duration_time = duration_time;
    this->zoom_link = zoom_link;
}

// copy constractor if ExamDetails
ExamDetails::ExamDetails(const ExamDetails &copy_from)
{
    this->course_number = copy_from.course_number;
    this->month = copy_from.month;
    this->day = copy_from.day;
    this->starting_time = copy_from.starting_time;
    this->duration_time = copy_from.duration_time;
    this->zoom_link = copy_from.zoom_link;
}

//copy assignment for assigning an ExamDetails from one ExamDetails to another
ExamDetails &ExamDetails::operator=(const ExamDetails &copy_from)
{
    this->course_number = copy_from.course_number;
    this->month = copy_from.month;
    this->day = copy_from.day;
    this->starting_time = copy_from.starting_time;
    this->duration_time = copy_from.duration_time;
    this->zoom_link = copy_from.zoom_link;
    return *this;
}
string ExamDetails::getLink() const
{
    return this->zoom_link;
}
void ExamDetails::setLink(string zoom_link)
{
    this->zoom_link = zoom_link;
}
int ExamDetails::operator-(const ExamDetails &ExamDetails) const
{
    int month_to_days = (month * 30) - (ExamDetails.month * 30);
    return this->day - ExamDetails.day + month_to_days;
}
bool ExamDetails::operator<(const ExamDetails &ExamDetails) const
{
    if (*this - ExamDetails >= 0)
    {
        return false;
    }
    return true;
}
ExamDetails ExamDetails::makeMatamExam()
{
    ExamDetails res(234124, 7, 28, 13, 3);
    return res;
}

void ExamDetails::print() const
{
    cout << *this;
}
std::ostream &operator<<(std::ostream &os, const ExamDetails &r)
{
    os << "Course Number: " << r.course_number << endl
       << "Time: " << r.day << "." << r.month << " at " << (int)r.starting_time;
    if (r.starting_time - (int)r.starting_time == 0)
    {
        os << ":00" << endl;
    }
    else
    {
        os << ":30" << endl;
    }
    os << "Duration: " << r.duration_time << ":00" << endl
       << "zoom link: " << r.zoom_link;
    return os;
}
ExamDetails::~ExamDetails() {}