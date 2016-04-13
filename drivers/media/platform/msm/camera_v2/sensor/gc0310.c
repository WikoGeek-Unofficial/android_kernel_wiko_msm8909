/* Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 *         Modify History For This Module
 * When           Who             What,Where,Why
 * --------------------------------------------------------------------------------------
 * 13/11/25              Add GC0310 camera driver code   
 * --------------------------------------------------------------------------------------
*/
#include "msm_sensor.h"
#include "msm_cci.h"
#include "msm_camera_io_util.h"
#include <linux/proc_fs.h>
#define GC0310_SENSOR_NAME "gc0310"
#define PLATFORM_DRIVER_NAME "msm_camera_gc0310"
//#include <linux/productinfo.h>
#define gc0310_obj gc0310_##obj
/*#define CONFIG_MSMB_CAMERA_DEBUG*/
#undef CDBG
#ifdef CONFIG_MSMB_CAMERA_DEBUG
#define CDBG(fmt, args...) pr_err(fmt, ##args)
#else
#define CDBG(fmt, args...) do { } while (0)
#endif
#define GC0310_DEBUGFS 1

//#define DEBUG_SENSOR_GC
DEFINE_MSM_MUTEX(gc0310_mut);
static struct msm_sensor_ctrl_t gc0310_s_ctrl;

static struct msm_sensor_power_setting gc0310_power_setting[] = {
	{
		.seq_type = SENSOR_GPIO,
		.seq_val = SENSOR_GPIO_RESET,
		 .config_val = GPIO_OUT_LOW,
		.delay = 5,
	},

	{
	  .seq_type = SENSOR_GPIO,
	  .seq_val = SENSOR_GPIO_VANA,
	  .config_val = GPIO_OUT_LOW,
	  .delay = 5,
	},

	{
	   .seq_type = SENSOR_VREG,
	   .seq_val = CAM_VIO,
	   .config_val = 0,
	   .delay = 5,
	 },

	{
	  .seq_type = SENSOR_GPIO,
	  .seq_val = SENSOR_GPIO_VANA,
	  .config_val = GPIO_OUT_HIGH,
	  .delay = 5,
	},

	{
		.seq_type = SENSOR_CLK,
		.seq_val = SENSOR_CAM_MCLK,
		.config_val = 24000000,
		.delay = 10,
	},
		  
	{
		 .seq_type = SENSOR_GPIO,
		.seq_val = SENSOR_GPIO_STANDBY,
		  .config_val = GPIO_OUT_LOW,
		 .delay = 5,
	 },

	{
		.seq_type = SENSOR_GPIO,
		.seq_val = SENSOR_GPIO_STANDBY,
		.config_val = GPIO_OUT_HIGH,
		.delay = 5,
	},
	{
		.seq_type = SENSOR_GPIO,
		.seq_val = SENSOR_GPIO_STANDBY,
		.config_val = GPIO_OUT_LOW,
		.delay = 5,
	},	
	{
		.seq_type = SENSOR_I2C_MUX,
		.seq_val = 0,
		.config_val = 0,
		.delay = 0,
	},

};

//for snapshot
static struct msm_camera_i2c_reg_conf gc0310_vga_settings[] = {
	{0xfe,0x00}, //crop enable
	{0x50,0x01}, //crop enable
	{0x55,0x01}, //crop window height
	{0x56,0xe0},
	{0x57,0x02}, //crop window width
	{0x58,0x80},
};







#ifdef DEBUG_SENSOR_GC
///T_flash_start////////
static struct msm_camera_i2c_reg_conf GC0310_reg_T_flash[1000];
///T_flash_end//////////
#endif


//set sensor init setting
static struct msm_camera_i2c_reg_conf gc0310_recommend_settings[] = {
	{0xfe, 0xf0},
	{0xfe, 0xf0},
	{0xfe, 0x00},
	{0xfc, 0x0e},
	{0xfc, 0x0e},
	{0xf2, 0x80},
	{0xf3, 0x00},
	{0xf7, 0x1b},////1f //f9
	{0xf8, 0x04},
	{0xf9, 0x8e}, ////0e//0f
	{0xfa, 0x11},
	/////////////////////////////////////////////////      
	///////////////////   MIPI   ////////////////////      
	/////////////////////////////////////////////////      
	{0xfe, 0x03},
	{0x40, 0x08},
	{0x42, 0x00},
	{0x43, 0x00},
	{0x01, 0x03},
	{0x10, 0x84},


	{0x01, 0x03},             
	{0x02, 0x00},             
	{0x03, 0x94},             
	{0x04, 0x01},            
	{0x05, 0x00},             
	{0x06, 0x80},             
	{0x11, 0x1e},             
	{0x12, 0x00},      
	{0x13, 0x05},             
	{0x15, 0x10},                                                                    
	{0x21, 0x10},             
	{0x22, 0x01},             
	{0x23, 0x10},                                             
	{0x24, 0x02},                                             
	{0x25, 0x10},                                             
	{0x26, 0x03},                                             
	{0x29, 0x02},                                             
	{0x2a, 0x0a},                                             
	{0x2b, 0x04},                                             
	{0xfe, 0x00},
	
	/////////////////////////////////////////////////
	/////////////////	CISCTL reg	/////////////////
	/////////////////////////////////////////////////
	{0x00, 0x2f},
	{0x01, 0x0f},//06
	{0x02, 0x04},
	{0x03, 0x03},
	{0x04, 0x50},
	{0x09, 0x00},
	{0x0a, 0x00},
	{0x0b, 0x00},
	{0x0c, 0x04},
	{0x0d, 0x01},
	{0x0e, 0xe8},
	{0x0f, 0x02},
	{0x10, 0x88},
	{0x16, 0x00},
	{0x17, 0x17},
	{0x18, 0x1a},
	{0x19, 0x14},
	{0x1b, 0x48},
	{0x1e, 0x6b},
	{0x1f, 0x28},
	{0x20, 0x8b},
	{0x21, 0x49},
	{0x22, 0xb0},
	{0x23, 0x04},
	{0x24, 0x16},
	{0x34, 0x20},
	
	//add hyper
	{0x4f, 0x00},
	{0x03, 0x04},
	{0x04, 0x24},
	{0x4f, 0x01}, 
	{0x42, 0x00},
	{0x77, 0x68},
	{0x78, 0x40},
	{0x79, 0x5f},
	{0x42, 0xcf},
	
	/////////////////////////////////////////////////
	////////////////////   BLK	 ////////////////////
	/////////////////////////////////////////////////
	{0x26, 0x23},
	{0x28, 0xff},
	{0x29, 0x00},
	{0x33, 0x10}, 
	{0x37, 0x20},
	{0x38, 0x10},
	{0x47, 0x80},
	{0x4e, 0x66},
	{0xa8, 0x02},
	{0xa9, 0x80},
	//////////////////	ISP reg   ///////////////////
	/////////////////////////////////////////////////
	{0x40, 0xff}, //48 
	{0x41, 0x21}, //00//[0]curve_en
	{0x42, 0xcf},
	{0x44, 0x02},
	{0x45, 0xa8}, 
	{0x46, 0x03}, 
	{0x4a, 0x11},
	{0x4b, 0x01},
	{0x4c, 0x20},
	{0x4d, 0x05},
	{0x4f, 0x01},
	{0x50, 0x01},
	{0x55, 0x01},
	{0x56, 0xe0},
	{0x57, 0x02},
	{0x58, 0x80},
	
	/////////////////////////////////////////////////
	///////////////////   GAIN   ////////////////////
	/////////////////////////////////////////////////
	{0x70, 0x70},
	{0x5a, 0x84},
	{0x5b, 0xc9},
	{0x5c, 0xed},
	{0x77, 0x74},
	{0x78, 0x40},
	{0x79, 0x5f},
	
	///////////////////////////////////////////////// 
	///////////////////   DNDD  /////////////////////
	///////////////////////////////////////////////// 
	{0x80, 0x00}, 
	{0x82, 0x08}, 
	{0x83, 0x0b},// 0b b-
	{0x89, 0xf0},
	
	///////////////////////////////////////////////// 
	//////////////////   EEINTP  ////////////////////
	///////////////////////////////////////////////// 
	{0x8f, 0xaa}, 
	{0x90, 0x8c}, 
	{0x91, 0x90}, 
	{0x92, 0x03}, 
	{0x93, 0x03}, 
	{0x94, 0x05},
	{0x95, 0x65}, 
	{0x96, 0xf0},
	
	///////////////////////////////////////////////// 
	/////////////////////  ASDE  ////////////////////
	///////////////////////////////////////////////// 
	{0xfe, 0x00},
	{0x9a, 0x20},
	{0x9b, 0x80},
	{0x9c, 0x40},
	{0x9d, 0x80},
	{0xa1, 0x30},
 	{0xa2, 0x32},
	{0xa4, 0x30},
	{0xa5, 0x30},
	{0xaa, 0x10}, 
	{0xac, 0x22},
	
	/////////////////////////////////////////////////
	///////////////////   GAMMA   ///////////////////
	/////////////////////////////////////////////////
	{0xfe, 0x00},//default
	{0xbf, 0x0b},
	{0xc0, 0x19},
	{0xc1, 0x2d},
	{0xc2, 0x42},
	{0xc3, 0x55},
	{0xc4, 0x66},
	{0xc5, 0x76},
	{0xc6, 0x90},
	{0xc7, 0xa5},
	{0xc8, 0xb7},
	{0xc9, 0xc6},
	{0xca, 0xd2},
	{0xcb, 0xdc},
	{0xcc, 0xe3},
	{0xcd, 0xef},
	{0xce, 0xf7},
	{0xcf, 0xfe},
                                 
	/////////////////////////////////////////////////
	///////////////////   YCP  //////////////////////
	/////////////////////////////////////////////////
	{0xd0, 0x40}, 
	{0xd1, 0x2b}, 
	{0xd2, 0x2b}, 
	{0xd3, 0x3d}, 
	{0xd6, 0xf2}, 
	{0xd7, 0x1b}, 
	{0xd8, 0x18}, 
	{0xdd, 0x03}, 
                                 
	/////////////////////////////////////////////////
	////////////////////   AEC   ////////////////////
	/////////////////////////////////////////////////
	{0xfe, 0x01},
	{0x05, 0x30},
	{0x06, 0x75},
	{0x07, 0x40},
	{0x08, 0xb0},
	{0x0a, 0xc5},
	{0x0b, 0x11},
	{0x0c, 0x00},
	{0x12, 0x52},
	{0x13, 0x38},
	{0x18, 0x95},
	{0x19, 0x96},
	{0x1f, 0x20},
	{0x20, 0xc0}, 
	{0x3e, 0x40}, 
	{0x3f, 0x57}, 
	{0x40, 0x7d}, 
	{0x03, 0x60}, 
	{0x44, 0x02}, 
                                 
	/////////////////////////////////////////////////
	////////////////////   AWB   ////////////////////
	/////////////////////////////////////////////////
	{0x1c, 0x91}, 
	{0x21, 0x15}, 
	{0x50, 0x80},
	{0x56, 0x04},
	{0x59, 0x08}, 
	{0x5b, 0x02},
	{0x61, 0x8d}, 
	{0x62, 0xa7}, 
	{0x63, 0xd0}, 
	{0x65, 0x06},
	{0x66, 0x06}, 
	{0x67, 0x84}, 
	{0x69, 0x08}, 
	{0x6a, 0x25}, 
	{0x6b, 0x01}, 
	{0x6c, 0x00}, 
	{0x6d, 0x02}, 
	{0x6e, 0xf0}, 
	{0x6f, 0x80}, 
	{0x76, 0x80}, 
	{0x78, 0xaf}, 
	{0x79, 0x75},
	{0x7a, 0x40},
	{0x7b, 0x70},
	{0x7c, 0x0c}, 
                                 
	{0x90, 0x00}, 
	{0x91, 0x00},
	{0x92, 0xf4}, 
	{0x93, 0xcc},                                
	{0x95, 0x21}, 
	{0x96, 0xf4}, 
	{0x97, 0x43}, 
	{0x98, 0x21},                                  
	{0x9a, 0x43}, 
	{0x9b, 0x21}, 
	{0x9c, 0x78}, 
	{0x9d, 0x43},                                  
	{0x9f, 0x00}, 
	{0xa0, 0x00},
	{0xa1, 0x00}, 
	{0xa2, 0x00},                                  
	{0x86, 0x00}, 
	{0x87, 0x00}, 
	{0x88, 0x00},
	{0x89, 0x00},                                  
	{0xa4, 0x00}, 
	{0xa5, 0x00},
	{0xa6, 0xb8}, 
	{0xa7, 0x91},                                  
	{0xa9, 0xbe}, 
	{0xaa, 0x77},
	{0xab, 0x91},
	{0xac, 0x77},                                  
	{0xae, 0xbd}, 
	{0xaf, 0x91},
	{0xb0, 0xc1},
	{0xb1, 0x81},                                 
	{0xb3, 0x00},
	{0xb4, 0x00},
	{0xb5, 0x00},
	{0xb6, 0x00},
	{0x8b, 0x00},
	{0x8c, 0x00},
	{0x8d, 0x00},
	{0x8e, 0x00},                                 
	{0x94, 0x50},
	{0x99, 0xa6},
	{0x9e, 0xaa},
	{0xa3, 0x00},
	{0x8a, 0x00},
	{0xa8, 0x50},
	{0xad, 0x55},
	{0xb2, 0x55},
	{0xb7, 0x00},
	{0x8f, 0x00},                                 
	{0xb8, 0xc2},
	{0xb9, 0xa6},
                                
	/////////////////////////////////////////////////
	////////////////////  CC ////////////////////////
	/////////////////////////////////////////////////
	{0xfe, 0x01},
                                 
	{0xd0, 0x3f},//skin red
	{0xd1, 0xfe},
	{0xd2, 0x09},
	{0xd3, 0x00},
	{0xd4, 0x43},
	{0xd5, 0xf3},
                                 
	{0xd6, 0x37},
	{0xd7, 0xfa},
	{0xd8, 0x06},
	{0xd9, 0x03},
	{0xda, 0x44},
	{0xdb, 0xf0},
                                 
	/////////////////////////////////////////////////
	////////////////////   LSC   ////////////////////
	/////////////////////////////////////////////////
	{0xfe, 0x01}, 
	{0xc1, 0x3c}, 
	{0xc2, 0x50}, 
	{0xc3, 0x00}, 
	{0xc4, 0x5c}, 
	{0xc5, 0x30}, 
	{0xc6, 0x2d}, 
	{0xc7, 0x10}, 
	{0xc8, 0x00}, 
	{0xc9, 0x00}, 
	{0xdc, 0x20}, 
	{0xdd, 0x10}, 
	{0xdf, 0x00}, 
	{0xde, 0x00}, 
                                 
	/////////////////////////////////////////////////
	///////////////////  Histogram  /////////////////
	/////////////////////////////////////////////////
	{0x01, 0x10}, 
	{0x0b, 0x31}, 
	{0x0e, 0x50}, 
	{0x0f, 0x0f}, 
	{0x10, 0x6e}, 
	{0x12, 0xa0}, 
	{0x15, 0x60}, 
	{0x16, 0x60}, 
	{0x17, 0xe0}, 
                                 
	/////////////////////////////////////////////////
	//////////////   Measure Window   ///////////////
	/////////////////////////////////////////////////
	{0xcc, 0x0c}, 
	{0xcd, 0x10}, 
	{0xce, 0xa0}, 
	{0xcf,0xe6}, 
                                 
	/////////////////////////////////////////////////
	/////////////////   dark sun   //////////////////
	/////////////////////////////////////////////////
	{0x45,0xf7},
	{0x46,0xff}, 
	{0x47,0x15},
	{0x48,0x03}, 
	{0x4f,0x60}, 
                                 
	/////////////////////////////////////////////////
	///////////////////  banding  ///////////////////
	/////////////////////////////////////////////////
	{0xfe,0x00},
	{0x05,0x02},
	{0x06,0xd1}, //HB
	{0x07,0x00},
	{0x08,0x22}, //VB
	{0xfe,0x01},
	{0x25,0x00}, //step 
	{0x26,0x6a}, 
	{0x27,0x02}, //20fps
	{0x28,0x12},  
	{0x29,0x03}, //12.5fps
	{0x2a,0x50}, 
	{0x2b,0x05}, //7.14fps
	{0x2c,0xcc}, 
	{0x2d,0x07}, //5.55fps
	{0x2e,0x74},
	{0x3c,0x20},
	{0xfe,0x00},
};

static struct v4l2_subdev_info gc0310_subdev_info[] = {
	{
		.code   = V4L2_MBUS_FMT_YUYV8_2X8,
		.colorspace = V4L2_COLORSPACE_JPEG,
		.fmt    = 1,
		.order    = 0,
	},
};

static struct msm_camera_i2c_reg_conf gc0310_start_settings[] = {
	{0xfe, 0x03},
	{0x10, 0x90},//94 ppp
	{0xfe, 0x00},
};

static struct msm_camera_i2c_reg_conf gc0310_stop_settings[] = {
	{0xfe, 0x03},
	{0x10, 0x80},
	{0xfe, 0x00},
};



static const struct i2c_device_id gc0310_i2c_id[] = {
	{GC0310_SENSOR_NAME, (kernel_ulong_t)&gc0310_s_ctrl},
	{ }
};
/////T_flash_start///////
#ifdef DEBUG_SENSOR_GC
u16 my_asictox(const char *nptr)
{
u16 ret=-1,base=16;
	CDBG("nptr= %c \n", *nptr); 
if((base==16 && *nptr>='A' && *nptr<='F') || 
				(base==16 && *nptr>='a' && *nptr<='f') || 
				(base>=10 && *nptr>='0' && *nptr<='9') ||
				(base>=8 && *nptr>='0' && *nptr<='7') )
		{
			//ret *= base;
			ret=0;
			if(base==16 && *nptr>='A' && *nptr<='F')
				ret += *nptr-'A'+10;
			else if(base==16 && *nptr>='a' && *nptr<='f')
				ret += *nptr-'a'+10;
			else if(base>=10 && *nptr>='0' && *nptr<='9')
				ret += *nptr-'0';
			else if(base>=8 && *nptr>='0' && *nptr<='7')
				ret += *nptr-'0';
		}
		CDBG("rettttttttttt= %x \n", ret); 
			return ret;

}

u16 strtol(const char *nptr, u8 base)
{
	u16 ret,ret2;
	if(!nptr || (base!=16 && base!=10 && base!=8))
	{
		CDBG("%s(): NULL pointer input\n", __FUNCTION__);
		return -1;
	}
	#if 0
	for(ret=0; *nptr; nptr++)
	{
		if((base==16 && *nptr>='A' && *nptr<='F') || 
				(base==16 && *nptr>='a' && *nptr<='f') || 
				(base>=10 && *nptr>='0' && *nptr<='9') ||
				(base>=8 && *nptr>='0' && *nptr<='7') )
		{
			ret *= base;
			if(base==16 && *nptr>='A' && *nptr<='F')
				ret += *nptr-'A'+10;
			else if(base==16 && *nptr>='a' && *nptr<='f')
				ret += *nptr-'a'+10;
			else if(base>=10 && *nptr>='0' && *nptr<='9')
				ret += *nptr-'0';
			else if(base>=8 && *nptr>='0' && *nptr<='7')
				ret += *nptr-'0';
		}
		else
			return ret;
	}

	#endif
ret=0;
ret=my_asictox(nptr);
CDBG("ret= %x \n", ret); 
ret=(ret<<4)&0xf0;
if(ret==-1) return -1;
CDBG("ret= %x \n", ret); 
nptr++;
ret2=my_asictox(nptr);
CDBG("ret2= %x \n", ret2); 
ret2=ret2	&0x0f;
if(ret2==-1) return -1;
CDBG("ret2= %x \n", ret2); 
ret=ret+ret2;
CDBG("ret= %x \n", ret); 
	return ret;
}

u32 reg_num = 0;

u8 GC_Initialize_from_T_Flash(void)
{
	//FS_HANDLE fp = -1;				/* Default, no file opened. */
	//u8 *data_buff = NULL;
	u8 *curr_ptr = NULL;
	u32 file_size = 0;
	//u32 bytes_read = 0;
	u32 i = 0;
	u8 func_ind[4] = {0};	/* REG or DLY */
   u16 temp=0;

	struct file *fp; 
	mm_segment_t fs; 
	loff_t pos = 0; 
	static u8 data_buff[10*1024] ;

	fp = filp_open("/system/lib/gc_sd", O_RDONLY , 0); 
	if (IS_ERR(fp)) { 
		CDBG("create file error %x \n", (unsigned int)fp); 
		return 0; 
	} 
	fs = get_fs(); 
	set_fs(KERNEL_DS); 

	file_size = vfs_llseek(fp, 0, SEEK_END);
	vfs_read(fp, data_buff, file_size, &pos); 
//	CDBG("%s %d %d\n", buf,iFileLen,pos); 
	filp_close(fp, NULL); 
	set_fs(fs);

	reg_num = 0;

	/* Start parse the setting witch read from t-flash. */
	curr_ptr = data_buff;
	while (curr_ptr < (data_buff + file_size))
	{
		while ((*curr_ptr == ' ') || (*curr_ptr == '\t'))/* Skip the Space & TAB */
			curr_ptr++;				

		if (((*curr_ptr) == '/') && ((*(curr_ptr + 1)) == '*'))
		{
			while (!(((*curr_ptr) == '*') && ((*(curr_ptr + 1)) == '/')))
			{
				curr_ptr++;		/* Skip block comment code. */
			}

			while (!((*curr_ptr == 0x0D) && (*(curr_ptr+1) == 0x0A)))
			{
				curr_ptr++;
			}

			curr_ptr += 2;						/* Skip the enter line */

			continue ;
		}

		if (((*curr_ptr) == '/') || ((*curr_ptr) == '{') || ((*curr_ptr) == '}'))		/* Comment line, skip it. */
		{
			while (!((*curr_ptr == 0x0D) && (*(curr_ptr+1) == 0x0A)))
			{
				curr_ptr++;
			}

			curr_ptr += 2;						/* Skip the enter line */

			continue ;
		}
		/* This just content one enter line. */
		if (((*curr_ptr) == 0x0D) && ((*(curr_ptr + 1)) == 0x0A))
		{
			curr_ptr += 2;
			continue ;
		}
//		CDBG(" curr_ptr1 = %s\n",curr_ptr);
		memcpy(func_ind, curr_ptr, 3);


		if (strcmp((const char *)func_ind, "REG") == 0)		/* REG */
		{
			curr_ptr += 6;				/* Skip "REG(0x" or "DLY(" */
temp= strtol((const char *)curr_ptr, 16);
if(temp!=-1)
			GC0310_reg_T_flash[i].reg_addr = temp;
			CDBG("i= %d, GC0310_reg_T_flash[i].reg_addr= %x \n", i,GC0310_reg_T_flash[i].reg_addr);
			curr_ptr += 5;	/* Skip "00, 0x" */
temp= strtol((const char *)curr_ptr, 16);
if(temp!=-1)
			GC0310_reg_T_flash[i].reg_data = temp;
			CDBG("i %d, GC0310_reg_T_flash[i].reg_data %x \n", i, GC0310_reg_T_flash[i].reg_data);
			curr_ptr += 4;	/* Skip "00);" */

			reg_num = i;
			CDBG("i %d, reg_num %x \n", i, reg_num);
		}
		
		i++;


		/* Skip to next line directly. */
		while (!((*curr_ptr == 0x0D) && (*(curr_ptr+1) == 0x0A)))
		{
			curr_ptr++;
		}
		curr_ptr += 2;
	}

	
	return 1;	
}

#endif
/////////T_flash_end//////////
#if GC0310_DEBUGFS
struct proc_dir_entry *gc0310_proc_entry;

#define GC0310_MAX_PROC 255
static int gc0310_procfs_read(struct file *flip, char __user *user_buf,
			      size_t count, loff_t *ppos) {
	return 0;
}

static int gc0310_procfs_write(struct file *flip,
			       const char __user *buf,
			       size_t count,
			       loff_t *data)
{
	char str[GC0310_MAX_PROC+1];

	int rc,iRegister = 0;
	int iValue = 0xff;
	uint16_t u8Value = 0xff;

	if (count > GC0310_MAX_PROC)
		count = GC0310_MAX_PROC;
	if (copy_from_user(str, buf, count))
		return -EFAULT;
	str[min_t(unsigned long, GC0310_MAX_PROC, count)] = 0;
	CDBG("%s(): str=\"%s\"", __func__, str);


	//write/read register
	if (sscanf(str, "%x %x", &iRegister, &iValue) == 2) {
		rc = gc0310_s_ctrl.sensor_i2c_client->i2c_func_tbl->			
			i2c_write(gc0310_s_ctrl.sensor_i2c_client, iRegister,
			(u8)iValue,MSM_CAMERA_I2C_BYTE_DATA);
		
		CDBG("%s,addr=0x%x,data=0x%x",__func__, iRegister, iValue);
	} else if (sscanf(str, "%x", &iRegister) == 1) {
		rc = gc0310_s_ctrl.sensor_i2c_client->i2c_func_tbl->
			i2c_read(gc0310_s_ctrl.sensor_i2c_client,iRegister,
			&u8Value, MSM_CAMERA_I2C_BYTE_DATA);
		
		CDBG("%s,addr=0x%x, data=0x%x", __func__,iRegister, u8Value);
	}

	return count;
}

static const struct file_operations proc_fops = {
	.write	=	gc0310_procfs_write,
	.read	=	gc0310_procfs_read,
};


static int gc0310_procfs_init(struct i2c_client *client)
{
	gc0310_proc_entry = proc_create_data(GC0310_SENSOR_NAME,
					      (S_IRUSR | S_IRGRP),
					      NULL,
					      &proc_fops,
					      client);
	if (NULL == gc0310_proc_entry) {
		dev_err(&client->dev, "%s(): error creating proc entry %s",
			__func__,
			GC0310_SENSOR_NAME);
		return -ENOMEM;
	}
	dev_info(&client->dev, "%s(): proc entry %s OK",
		 __func__, GC0310_SENSOR_NAME);
	return 0;
}

static int gc0310_procfs_exit(struct i2c_client *client)
{
	if (gc0310_proc_entry) {
		remove_proc_entry(GC0310_SENSOR_NAME,  NULL);
		dev_info(&client->dev, "%s(): proc entry %s removed",
			 __func__, GC0310_SENSOR_NAME);
	}
	return 0;
}

#endif
static int32_t msm_gc0310_i2c_probe(struct i2c_client *client,
	   const struct i2c_device_id *id)
{
	return msm_sensor_i2c_probe(client, id, &gc0310_s_ctrl);
#if GC0310_DEBUGFS
	gc0310_procfs_init(client);
#endif
}

static int msm_gc0310_i2c_remove(struct i2c_client *client)
{
#if GC0310_DEBUGFS
	gc0310_procfs_exit(client);
#endif
	return 0;
}
static struct i2c_driver gc0310_i2c_driver = {
	.id_table = gc0310_i2c_id,
	.probe  = msm_gc0310_i2c_probe,
	.remove = msm_gc0310_i2c_remove,
	.driver = {
		.name = GC0310_SENSOR_NAME,
	},
};
static struct msm_camera_i2c_client gc0310_sensor_i2c_client = {
	.addr_type = MSM_CAMERA_I2C_BYTE_ADDR,
};

static const struct of_device_id gc0310_dt_match[] = {
	{.compatible = "qcom,gc0310", .data = &gc0310_s_ctrl},
	{}
};

MODULE_DEVICE_TABLE(of, gc0310_dt_match);


static void gc0310_i2c_write_table(struct msm_sensor_ctrl_t *s_ctrl,
		struct msm_camera_i2c_reg_conf *table,
		int num)
{
	int i = 0;
	int rc = 0;
	for (i = 0; i < num; ++i) 
	{
        if(0xff == table->reg_addr)
        {
        	msleep(50);
			printk("[TSP] delay 100ms.(%s,%d)\n",__func__,__LINE__);
        }		
		else
		{
		rc = s_ctrl->sensor_i2c_client->i2c_func_tbl->
			i2c_write(s_ctrl->sensor_i2c_client, table->reg_addr,
			table->reg_data,MSM_CAMERA_I2C_BYTE_DATA);
			if (rc < 0) 
			{
			msleep(100);
			rc = s_ctrl->sensor_i2c_client->i2c_func_tbl->
			i2c_write(
				s_ctrl->sensor_i2c_client, table->reg_addr,
				table->reg_data,MSM_CAMERA_I2C_BYTE_DATA);
			}
		}
		table++;
	}
}

static int32_t gc0310_platform_probe(struct platform_device *pdev)
{
	int32_t rc;
	const struct of_device_id *match;
	match = of_match_device(gc0310_dt_match, &pdev->dev);
	rc = msm_sensor_platform_probe(pdev, match->data);
	return rc;
}

static struct platform_driver gc0310_platform_driver = {
	.driver = {
		.name = "qcom,gc0310",
		.owner = THIS_MODULE,
		.of_match_table = gc0310_dt_match,
	},
};
static int __init gc0310_init_module(void)
{
	int32_t rc;
	pr_err("%s:%d\n", __func__, __LINE__);
	rc = platform_driver_probe(
	&gc0310_platform_driver,gc0310_platform_probe);
	if (!rc)
		return rc;
	pr_err("%s:%d rc %d\n", __func__, __LINE__, rc);
		
	return i2c_add_driver(&gc0310_i2c_driver);

}

static void __exit gc0310_exit_module(void)
{
	pr_err("%s:%d\n", __func__, __LINE__);
	if (gc0310_s_ctrl.pdev) {
		msm_sensor_free_sensor_data(&gc0310_s_ctrl);
		platform_driver_unregister(&gc0310_platform_driver);
	} else
		i2c_del_driver(&gc0310_i2c_driver);
	return;
}

int32_t gc0310_sensor_config(struct msm_sensor_ctrl_t *s_ctrl,
	void __user *argp)
{
	struct sensorb_cfg_data *cdata = (struct sensorb_cfg_data *)argp;
	long rc = 0;
	int32_t i = 0;
    
	mutex_lock(s_ctrl->msm_sensor_mutex);
	pr_err("%s:%d %s cfgtype = %d\n", __func__, __LINE__,
		s_ctrl->sensordata->sensor_name, cdata->cfgtype);
	switch (cdata->cfgtype) {
	case CFG_GET_SENSOR_INFO:
		pr_err("hi258 CFG_GET_SENSOR_INFO\n");
		memcpy(cdata->cfg.sensor_info.sensor_name,
			s_ctrl->sensordata->sensor_name,
			sizeof(cdata->cfg.sensor_info.sensor_name));
		cdata->cfg.sensor_info.session_id =
			s_ctrl->sensordata->sensor_info->session_id;
		for (i = 0; i < SUB_MODULE_MAX; i++)
			cdata->cfg.sensor_info.subdev_id[i] =
				s_ctrl->sensordata->sensor_info->subdev_id[i];
		cdata->cfg.sensor_info.is_mount_angle_valid =
			s_ctrl->sensordata->sensor_info->is_mount_angle_valid;
		cdata->cfg.sensor_info.sensor_mount_angle =
			s_ctrl->sensordata->sensor_info->sensor_mount_angle;
		pr_err("%s:%d sensor name %s\n", __func__, __LINE__,
			cdata->cfg.sensor_info.sensor_name);
		pr_err("%s:%d session id %d\n", __func__, __LINE__,
			cdata->cfg.sensor_info.session_id);
		for (i = 0; i < SUB_MODULE_MAX; i++)
			pr_err("%s:%d subdev_id[%d] %d\n", __func__, __LINE__, i,
				cdata->cfg.sensor_info.subdev_id[i]);
		pr_err("%s:%d mount angle valid %d value %d\n", __func__,
			__LINE__, cdata->cfg.sensor_info.is_mount_angle_valid,
			cdata->cfg.sensor_info.sensor_mount_angle);

		break;
	case CFG_SET_INIT_SETTING:
		CDBG("init setting\n");
	    #ifdef DEBUG_SENSOR_GC
		if(1 == GC_Initialize_from_T_Flash())
		{
		gc0310_i2c_write_table(s_ctrl,&gc0310_recommend_settings[0],
				ARRAY_SIZE(gc0310_recommend_settings));
		gc0310_i2c_write_table(s_ctrl,&GC0310_reg_T_flash[0],
		ARRAY_SIZE(GC0310_reg_T_flash));
		} 
		else
		{		
		gc0310_i2c_write_table(s_ctrl,&gc0310_recommend_settings[0],
		ARRAY_SIZE(gc0310_recommend_settings));
        }
		#else
		gc0310_i2c_write_table(s_ctrl,&gc0310_recommend_settings[0],
		ARRAY_SIZE(gc0310_recommend_settings));
		CDBG("init setting X\n");
        #endif
		break;
	case CFG_SET_RESOLUTION: {
			/*copy from user the desired resoltuion*/
			enum msm_sensor_resolution_t res =
				MSM_SENSOR_INVALID_RES;
			pr_err("gc0310 CFG_SET_RESOLUTION\n");
			if (copy_from_user(&res, (void *)cdata->cfg.setting,
				sizeof(enum msm_sensor_resolution_t))) {
			pr_err("%s:%d failed\n", __func__, __LINE__);
			rc = -EFAULT;
			break;
		}

	    	   CDBG("gc0310_PETER-preview/capture-VAL = %d" , val);
		gc0310_i2c_write_table(s_ctrl,&gc0310_vga_settings[0],
				ARRAY_SIZE(gc0310_vga_settings));
					msleep(100);//add

		}
		break;
	case CFG_SET_STOP_STREAM:
		pr_err("gc0310 CFG_SET_STOP_STREAM\n");
		gc0310_i2c_write_table(s_ctrl,&gc0310_stop_settings[0],
				ARRAY_SIZE(gc0310_stop_settings));
		break;
	case CFG_SET_START_STREAM:
		pr_err("gc0310 CFG_SET_START_STREAM\n");
		gc0310_i2c_write_table(s_ctrl,&gc0310_start_settings[0],
				ARRAY_SIZE(gc0310_start_settings));
		break;
	case CFG_GET_SENSOR_INIT_PARAMS:
		pr_err("hi258 CFG_GET_SENSOR_INIT_PARAMS\n");
		cdata->cfg.sensor_init_params.modes_supported =
			s_ctrl->sensordata->sensor_info->modes_supported;
		cdata->cfg.sensor_init_params.position =
			s_ctrl->sensordata->sensor_info->position;
		cdata->cfg.sensor_init_params.sensor_mount_angle =
			s_ctrl->sensordata->sensor_info->sensor_mount_angle;
		pr_err("%s:%d init params mode %d pos %d mount %d\n", __func__,
			__LINE__,
			cdata->cfg.sensor_init_params.modes_supported,
			cdata->cfg.sensor_init_params.position,
			cdata->cfg.sensor_init_params.sensor_mount_angle);
		break;
	case CFG_SET_SLAVE_INFO: {
		struct msm_camera_sensor_slave_info *sensor_slave_info = NULL;
		struct msm_camera_power_ctrl_t *p_ctrl;
		uint16_t size;
		int slave_index = 0;
		sensor_slave_info = kmalloc(sizeof(struct msm_camera_sensor_slave_info)
			*1, GFP_KERNEL);
		if (!sensor_slave_info) {
			rc = -ENOMEM;
			break;	
		}
		if (copy_from_user(sensor_slave_info,
		    (void *)cdata->cfg.setting,
		    sizeof(struct msm_camera_sensor_slave_info))) {
			pr_err("%s:%d failed\n", __func__, __LINE__);
			rc = -EFAULT;
			break;
		}
		/* Update sensor slave address */
		if (sensor_slave_info->slave_addr)
			s_ctrl->sensor_i2c_client->cci_client->sid =
			sensor_slave_info->slave_addr >> 1;

		/* Update sensor address type */
		s_ctrl->sensor_i2c_client->addr_type =
			sensor_slave_info->addr_type;

		/* Update power up / down sequence */
			p_ctrl = &s_ctrl->sensordata->power_info;
			size = sensor_slave_info->power_setting_array.size;
		if (p_ctrl->power_setting_size < size) {
			struct msm_sensor_power_setting *tmp;
			tmp = kmalloc(sizeof(struct msm_sensor_power_setting)
				      * size, GFP_KERNEL);
			if (!tmp) {
				pr_err("%s: failed to alloc mem\n", __func__);
				rc = -ENOMEM;
				break;
			}
			kfree(p_ctrl->power_setting);
			p_ctrl->power_setting = tmp;
		}
		p_ctrl->power_setting_size = size;

		rc = copy_from_user(p_ctrl->power_setting, (void *)
			sensor_slave_info->power_setting_array.power_setting,
			size * sizeof(struct msm_sensor_power_setting));
		if (rc) {
			pr_err("%s:%d failed\n", __func__, __LINE__);
			rc = -EFAULT;
			break;
		}
			pr_err("%s sensor id %x addr type %d sensor reg %x\n"
				"sensor id %x\n", __func__,
				sensor_slave_info->slave_addr,
				sensor_slave_info->addr_type,
				sensor_slave_info->
					sensor_id_info.sensor_id_reg_addr,
				sensor_slave_info->sensor_id_info.sensor_id);
		for (slave_index = 0; 
		slave_index <p_ctrl->power_setting_size;
		 slave_index++) {
			pr_err("%s i %d power setting %d %d %ld %d\n", __func__,
				slave_index,
				p_ctrl->power_setting[slave_index].seq_type,
				p_ctrl->power_setting[slave_index].seq_val,
				p_ctrl->power_setting[slave_index].config_val,
				p_ctrl->power_setting[slave_index].delay);
		}
		break;
	}
	case CFG_WRITE_I2C_ARRAY: {
		struct msm_camera_i2c_reg_setting conf_array;
		struct msm_camera_i2c_reg_array *reg_setting = NULL;
		CDBG("CFG_WRITE_I2C_ARRAY\n");
		if (copy_from_user(&conf_array,
			(void *)cdata->cfg.setting,
			sizeof(struct msm_camera_i2c_reg_setting))) {
			pr_err("%s:%d failed\n", __func__, __LINE__);
			rc = -EFAULT;
			break;
		}

		reg_setting = kzalloc(conf_array.size *
			(sizeof(struct msm_camera_i2c_reg_array)), GFP_KERNEL);
		if (!reg_setting) {
			pr_err("%s:%d failed\n", __func__, __LINE__);
			rc = -ENOMEM;
			break;
		}
		if (copy_from_user(reg_setting, (void *)conf_array.reg_setting,
			conf_array.size *
			sizeof(struct msm_camera_i2c_reg_array))) {
			pr_err("%s:%d failed\n", __func__, __LINE__);
			kfree(reg_setting);
			rc = -EFAULT;
			break;
		}

		conf_array.reg_setting = reg_setting;
		rc = s_ctrl->sensor_i2c_client->i2c_func_tbl->i2c_write_table(
			s_ctrl->sensor_i2c_client, &conf_array);
		kfree(reg_setting);
		break;
	}
	case CFG_WRITE_I2C_SEQ_ARRAY: {
		struct msm_camera_i2c_seq_reg_setting conf_array;
		struct msm_camera_i2c_seq_reg_array *reg_setting = NULL;
		CDBG("CFG_WRITE_I2C_SEQ_ARRAY\n");
		if (copy_from_user(&conf_array,
			(void *)cdata->cfg.setting,
			sizeof(struct msm_camera_i2c_seq_reg_setting))) {
			pr_err("%s:%d failed\n", __func__, __LINE__);
			rc = -EFAULT;
			break;
		}

		reg_setting = kzalloc(conf_array.size *
			(sizeof(struct msm_camera_i2c_seq_reg_array)),
			GFP_KERNEL);
		if (!reg_setting) {
			pr_err("%s:%d failed\n", __func__, __LINE__);
			rc = -ENOMEM;
			break;
		}
		if (copy_from_user(reg_setting, (void *)conf_array.reg_setting,
			conf_array.size *
			sizeof(struct msm_camera_i2c_seq_reg_array))) {
			pr_err("%s:%d failed\n", __func__, __LINE__);
			kfree(reg_setting);
			rc = -EFAULT;
			break;
		}

		conf_array.reg_setting = reg_setting;
		rc = s_ctrl->sensor_i2c_client->i2c_func_tbl->
			i2c_write_seq_table(s_ctrl->sensor_i2c_client,
			&conf_array);
		kfree(reg_setting);
		break;
	}

	case CFG_POWER_UP:
		if (s_ctrl->func_tbl->sensor_power_up)
			rc = s_ctrl->func_tbl->sensor_power_up(s_ctrl);
		else
			rc = -EFAULT;
		break;

	case CFG_POWER_DOWN:

		if (s_ctrl->func_tbl->sensor_power_down)
			rc = s_ctrl->func_tbl->sensor_power_down(s_ctrl);
		else
			rc = -EFAULT;

		break;

	case CFG_SET_STOP_STREAM_SETTING: {
		struct msm_camera_i2c_reg_setting *stop_setting =
			&s_ctrl->stop_setting;
		struct msm_camera_i2c_reg_array *reg_setting = NULL;
		if (copy_from_user(stop_setting, (void *)cdata->cfg.setting,
		    sizeof(struct msm_camera_i2c_reg_setting))) {
			pr_err("%s:%d failed\n", __func__, __LINE__);
			rc = -EFAULT;
			break;
		}

		reg_setting = stop_setting->reg_setting;
		stop_setting->reg_setting = kzalloc(stop_setting->size *
			(sizeof(struct msm_camera_i2c_reg_array)), GFP_KERNEL);
		if (!stop_setting->reg_setting) {
			pr_err("%s:%d failed\n", __func__, __LINE__);
			rc = -ENOMEM;
			break;
		}
		if (copy_from_user(stop_setting->reg_setting,
		    (void *)reg_setting, stop_setting->size *
		    sizeof(struct msm_camera_i2c_reg_array))) {
			pr_err("%s:%d failed\n", __func__, __LINE__);
			kfree(stop_setting->reg_setting);
			stop_setting->reg_setting = NULL;
			stop_setting->size = 0;
			rc = -EFAULT;
			break;
		}
		break;
		}
	case CFG_SET_SATURATION: 
		break;
	case CFG_SET_CONTRAST:
		break;
	case CFG_SET_SHARPNESS: 
		break;
	case CFG_SET_ISO:
		break;
	case CFG_SET_EXPOSURE_COMPENSATION: 
		break;
	case CFG_SET_EFFECT: 
		break;
	case CFG_SET_ANTIBANDING: 
		break;
	case CFG_SET_BESTSHOT_MODE:
		break;
	case CFG_SET_WHITE_BALANCE: 
		break;
	default:
		rc = -EFAULT;
		break;
	}

	mutex_unlock(s_ctrl->msm_sensor_mutex);

	return rc;
}

static struct msm_sensor_fn_t gc0310_sensor_func_tbl = {
	.sensor_config = gc0310_sensor_config,
	.sensor_power_up = msm_sensor_power_up,
	.sensor_power_down = msm_sensor_power_down,
	.sensor_match_id = msm_sensor_match_id,
};

static struct msm_sensor_ctrl_t gc0310_s_ctrl = {
	.sensor_i2c_client = &gc0310_sensor_i2c_client,
	.power_setting_array.power_setting = gc0310_power_setting,
	.power_setting_array.size = ARRAY_SIZE(gc0310_power_setting),
	.msm_sensor_mutex = &gc0310_mut,
	.sensor_v4l2_subdev_info = gc0310_subdev_info,
	.sensor_v4l2_subdev_info_size = ARRAY_SIZE(gc0310_subdev_info),
	.func_tbl = &gc0310_sensor_func_tbl,
};

module_init(gc0310_init_module);
module_exit(gc0310_exit_module);
MODULE_DESCRIPTION("GC0310 2MP YUV sensor driver");
MODULE_LICENSE("GPL v2");

