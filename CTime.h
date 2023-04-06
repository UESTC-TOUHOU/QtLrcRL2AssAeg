#pragma once

#include <QString>

class CTime {
public:
	CTime() {
		min = sec = msec = -1;
	}
	QString str();
	int GetDiff(CTime& t2);
	void SetTime(int m, int s, int ms);
	bool isValid();
	void Add1s();
	void Minus2s();
private:
	int min, sec, msec;
};

