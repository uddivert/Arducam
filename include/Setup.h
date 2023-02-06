#ifndef SETUP_H
#define SETUP_H

#include <iostream>
#include <fstream> 
#include <unistd.h>
#include <cstring>
#include <cstdio>

#include "include/ArduCamLib.h"
#include "arducam_config_parser.h"

extern "C" {
    struct USBCamera {
        std::ofstream cfg_file;
        CameraConfigs cam_cfgs;
    } CameraSetup;
    
    int cameraInit(char *fileName); // will initialize Camera
}
#endif