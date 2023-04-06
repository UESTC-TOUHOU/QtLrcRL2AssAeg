#include "CTime.h"

QString CTime::str() {
	//aegisub	0:min:sec.msec
	QString ret("0:%1:%2.%3");
	ret = ret
		.arg(min, 2, 10, QChar('0'))
		.arg(sec, 2, 10, QChar('0'))
		.arg(msec / 10, 2, 10, QChar('0'));
	return ret;
}

int CTime::GetDiff(CTime& t2) {
	CTime& t1 = *this;
	int diff = 0;
	diff += 60000 * (t1.min - t2.min);
	diff += 1000 * (t1.sec - t2.sec);
	diff += t1.msec - t2.msec;
	return diff;
}

void CTime::SetTime(int m, int s, int ms) {
	min = m;
	sec = s;
	msec = ms;
}


bool CTime::isValid() {
	if (min < 0 || sec < 0 || msec < 0) {
		return false;
	}
	return true;
}

void CTime::Add1s() {
	sec += 1;
	if (sec >= 60) {
		sec -= 60;
		min += 1;
	}
}

void CTime::Minus2s() {
	sec -= 2;
	if (sec < 0) {
		sec += 60;
		min -= 1;
		if (min < 0) {
			min = 0;
		}
	}

}
