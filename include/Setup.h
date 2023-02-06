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
    int cameraInit(char *fileName); // will initialize Camera
}
#endif