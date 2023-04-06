#pragma once

#include<QFile>
#include<QString>
#include <QTextStream>

#include "CTime.h"

class CLrc2Ass {
public:
	CLrc2Ass();
	void SetLrcPath(QString lrc);
	void SetAssPath(QString ass);
	void Run();
private:
	QString ASS_DEFAULT;
	QString sLrcPath, sAssPath;
	QFile fin, fout;
	QTextStream sin;
	QTextStream sout;
	bool OpenFile();	//打开文件
	void CloseFile();	//关闭文件
	void CopyDefault();	//复制默认ass格式
	void Convert();		//开始转换

	QString sCurLine;
	void FinishCurLine(CTime& tBegin, CTime& tEnd);
	void AddCurLine(CTime& tPre, CTime& tCur, QString& words);
	CTime GetTime(QString& str, int& pos);
	QString GetWords(QString& str, int& pos);

	void ConvertLine(QString& str);		//转换单独一行

	int cnt;
};


