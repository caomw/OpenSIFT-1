// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2//video/video.hpp>
#include <stdarg.h>

using namespace cv;


#define M_PI 3.1415926535


extern void fatal_error(char* format, ...);


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

class CStopWatch
{
private:
	LARGE_INTEGER freq, start, end;
public:
	CStopWatch()
	{
		QueryPerformanceFrequency(&freq);
		start.QuadPart = 0; end.QuadPart = 0;
		StartTime();
	};

	void StartTime()
	{		
		QueryPerformanceCounter(&start);
	};

	double CheckTime()
	{
		QueryPerformanceCounter(&end);

		return (double)(end.QuadPart-start.QuadPart)/freq.QuadPart*1000;
		//TRACE("%.2f msec\n", elapsed);
	};
};