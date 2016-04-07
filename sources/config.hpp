#pragma once
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <opencv2/opencv.hpp>
#include <pthread.h>
#include "queue.hpp"
#include "Engine.hpp"
#include "signs.hpp"

using namespace cv;

enum VALUE_TYPE
{
	INT_VAL = 0,
	STRING_VAL =1
};

enum modes
{
	CAMERA = 0,
	VIDEO  = 2
};

class System
{
	private:
	pthread_mutex_t engine_mutex = PTHREAD_MUTEX_INITIALIZER; //мутекс для контроля доступа к Engine
	Engine engine; //содержит основные динамические параметры движения робота
	pthread_mutex_t signs_mutex = PTHREAD_MUTEX_INITIALIZER; //мутекс для контроля доступа к Engine
	vector<sign_data> Signs;
	public:
	void init();
	
	
	void engine_get(Engine &destination);
	void engine_set(Engine &source);
	void signs_get(vector<sign_data> &destination);
	void signs_set(vector<sign_data> &source);
	
	Queue<Mat> queue; //очередь для кадров с видеокамеры
	Queue<line_data> qline; //очередь для дзанных линии
	
	char arduino_port[30];
	modes MODE;
	
	bool videomaker;
	char videoname[80];
	
	Rect linearea;
	Rect signarea;
	
	int capture_width;
	int capture_height;
	int image_quality;
	uint32_t robot_center;//will be used as center of robot on image
	System() //default settings
	{
		MODE = CAMERA;
		capture_width = 640;
		capture_height = 360;
		snprintf(arduino_port,30,"/dev/ttyACM0");
		image_quality = 80;
		videomaker = false;
		robot_center = 320;
		signarea = Rect( Point( capture_width/2, 0 ), Point( capture_width-1, capture_height/2 ) );
		linearea = Rect( Point( 0, capture_height - capture_height/4 ), Point( capture_width-1, capture_height-1) );
	}
};

struct config
{
	char name[180];
	VALUE_TYPE type;
	void *value;
};
