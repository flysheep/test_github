#include <iostream>
#include <string>
#include <set>
#include <stdlib.h>

class Date {
public:
	Date();
	Date(int year, int month, int day);
	void NextDay(int n = 1);
	bool SetDate(int year, int month, int day);
	int year() const { return year_; }
	int month() const { return month_; }
	int day() const { return day_; }
private:
	// 윤년을 판단하여 주어진 연도에 해당하는 날짜 수(365 또는 366)를 리턴.
	static int GetDaysInYear(int year);
	// 해당 날짜가 해당 연도의 처음(1월 1일)부터 며칠째인지를 계산.
	static int ComputeDaysFromYearStart(int year, int month, int day);
	int year_, month_, day_;
};

struct InvalidDateException {
	std::string input_date;
	InvalidDateException(const std::string& str) : input_date(str) {}
};

// yyyy.mm.dd 형식으로 입출력.
// 사용자 입력 오류시 >> operator는 InvalidDateException을 발생할 수 있음.
std::ostream& operator<<(std::ostream& os, const Date& c);
std::istream& operator>>(std::istream& is, Date& c);
