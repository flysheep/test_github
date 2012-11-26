#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

class WorldClock {
public:
	WorldClock();
	WorldClock(int hour, int minute, int second);
	void Tick(int seconds = 1);
	// �߸��� �� �Է½� false �����ϰ� ���� �ð��� �ٲ��� ����.
	bool SetTime(int hour, int minute, int second);
	static void AddTimezoneInfo(const string& city, int diff);
	// �߸��� �� �Է½� false �����ϰ� ���� �ð��� �ٲ��� ����.
	bool SetTimezone(const string& timezone);
	int hour() const { return hour_; }
	int minute() const { return minute_; }
	int second() const { return second_; }
	int time_difference() const { return time_difference_; }
private:
	// ���⿡ �ð� ���� ��� ���� ����. (GMT �ð��� ���)
	// Timezone ���� ������ �Ʒ� ������ ����. ������ �ð� �����θ� ���.
	int time_difference_;
	static map<string, int> timezone_;
	int hour_, minute_, second_;
};

struct InvalidTimeException {
	string input_time;
	InvalidTimeException(const string& str) : input_time(str) {}
};
// hh:mm:ss �������� �����. ǥ�ؽð� �ƴ� ��� (+xx) �������� ������ ǥ��.
// ����� �Է� ������ >> operator�� InvalidDateException�� �߻��� �� ����.
ostream& operator<<(ostream& os, const WorldClock& c);
istream& operator>>(istream& is, WorldClock& c);  // hh:mm:ss �� �Է¹���.