#pragma once
#include <stdio.h>
#include <stdint.h>
#include <string.h>

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
	public:
	void init();
	
	char arduino_port[30];
	modes MODE;
	
	bool videomaker;
	char videoname[80];
	
	int capture_width;
	int capture_height;
	int image_quality;
	uint32_t robot_center;//will be used as center of robot on image
	System() //default settings
	{
		MODE = CAMERA;
		capture_width = 640;
		capture_height = 480;
		snprintf(arduino_port,30,"/dev/ttyACM0");
		image_quality = 80;
		videomaker = false;
		robot_center = 320;
	}
};

struct config
{
	char name[180];
	VALUE_TYPE type;
	void *value;
};