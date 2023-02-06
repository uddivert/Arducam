#include "include/Setup.h"
#include <limits.h>

int cameraInit(char *fileName, ArduCamHandle &cameraHandle, ArduCamCfg &cameraCfg) {
  char *input_file_name = fileName;
  CameraConfigs cam_cfgs;
  //printf("%s\n", input_file_name);
	memset(&cam_cfgs, 0x00, sizeof(CameraConfigs));
	if (arducam_parse_config(input_file_name, &cam_cfgs)) {
		printf("Cannot find configuration file.\n");
    //    showHelp();
		return -1;
	}
    printf("File: %s\nbeing used as the configuration file",input_file_name);
	CameraParam *cam_param = &cam_cfgs.camera_param;
	Config *configs = cam_cfgs.configs;
	int configs_length = cam_cfgs.configs_length;
    
    switch (cam_param->i2c_mode) {
        case 0:
            cameraCfg.emI2cMode = I2C_MODE_8_8; 
            break;
        case 1: 
            cameraCfg.emI2cMode = I2C_MODE_8_16;
            break;
            case 2: 
            cameraCfg.emI2cMode = I2C_MODE_16_8;
            break;
        case 3:
            cameraCfg.emI2cMode = I2C_MODE_16_16;
            break;
        default:
            break;
	}
    int color_mode = 0;
	color_mode = cam_param->format & 0xFF;
	switch (cam_param->format >> 8) {
        case 0: 
            cameraCfg.emImageFmtMode = FORMAT_MODE_RAW; 
            break;
        case 1:
            cameraCfg.emImageFmtMode = FORMAT_MODE_RGB; 
            break;
        case 2: 
            cameraCfg.emImageFmtMode = FORMAT_MODE_YUV;
            break;
        case 3:
            cameraCfg.emImageFmtMode = FORMAT_MODE_JPG;
            break;
        case 4:
            cameraCfg.emImageFmtMode = FORMAT_MODE_MON;
            break;
        case 5:
            cameraCfg.emImageFmtMode = FORMAT_MODE_RAW_D;
            break;
        case 6:
            cameraCfg.emImageFmtMode = FORMAT_MODE_MON_D;
            break;
        default:
            break;
	}

	cameraCfg.u32Width = cam_param->width;
	cameraCfg.u32Height = cam_param->height;

	cameraCfg.u32I2cAddr = cam_param->i2c_addr;
	cameraCfg.u8PixelBits = cam_param->bit_width;
	cameraCfg.u32TransLvl = cam_param->trans_lvl;

    bool save_raw = false;
	if (cameraCfg.u8PixelBits <= 8) {
		cameraCfg.u8PixelBytes = 1;
	}
	else if (cameraCfg.u8PixelBits > 8 && cameraCfg.u8PixelBits <= 16) {
		cameraCfg.u8PixelBytes = 2;
		save_raw = true;
	}
    
    return 0;
} // main

/*
void getDir() {
   char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
   }
}
*/


int main( int argc , char *argv[]) {
 //   getDir();
    char *cfgPath = "configs/MT9J001_MONO_12b_3664x2748_2fps.cfg";
    if (argc != 1) 
        cfgPath= argv[1];
    //cameraInit(cfgPath);
    ArduCamHandle cameraHandle;
    ArduCamCfg cameraCfg;
    cameraInit(cfgPath, cameraHandle, cameraCfg);
} // main