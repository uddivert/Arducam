#include "include/Setup.h"

int cameraInit(char *fileName) {
  char *input_file_name = fileName;
  //printf("%s\n", input_file_name);
	memset(&CameraSetup.cam_cfgs, 0x00, sizeof(CameraConfigs));
	if (arducam_parse_config(input_file_name, &CameraSetup.cam_cfgs)) {
		printf("Cannot find configuration file.\n");
    //    showHelp();
		return -1;
	}
    return 0;
} // main

int main( int argc , char *argv[]) {
    char *cfgPath = "../configs/sample.cfg";
    if (argc != 1) 
        cfgPath= argv[1];
    cameraInit(cfgPath);
} // main