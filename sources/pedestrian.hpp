#pragma once
#include <stdlib.h>
#include <vector>
#include <opencv2/opencv.hpp>
#include <unistd.h>
#include "signs.hpp"
#include "timer.hpp"
#include "config.hpp"
#include <stdint.h>
#include <fstream>

#include "tiny_dnn/tiny_dnn.h"

void* recognize_ped_fnc(void *ptr);

void recognize_ped(cv::Mat &frame, bool &ped_state);
