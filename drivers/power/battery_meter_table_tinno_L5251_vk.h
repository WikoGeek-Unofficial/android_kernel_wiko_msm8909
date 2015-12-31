/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _TINNO_DATA_TYPE_DEFINE
#define _TINNO_DATA_TYPE_DEFINE
typedef struct _BATTERY_Q_COST_PROFILE_STRUC
{
    int  q_cost;
    int  voltage;
} BATTERY_Q_COST_PROFILE_STRUC, *BATTERY_Q_COST_PROFILE_STRUC_P;



typedef struct _R_PROFILE_STRUC
{
    int  resistance; // Ohm
    int  voltage;
} R_PROFILE_STRUC, *R_PROFILE_STRUC_P;

typedef enum
{
    T1_0C,
    T2_25C,
    T3_50C
} PROFILE_TEMPERATURE;
#endif
// <Qcost, Battery_Voltage> Table
// ============================================================


BATTERY_Q_COST_PROFILE_STRUC vk_battery_q_cost_profile_t3[] =
{
{0   ,4342},
{50  ,4316},
{100 ,4291},
{150 ,4268},
{200 ,4245},
{249 ,4224},
{299 ,4202},
{349 ,4180},
{399 ,4159},
{449 ,4139},
{499 ,4118},
{549 ,4098},
{599 ,4078},
{649 ,4059},
{699 ,4041},
{748 ,4022},
{798 ,4005},
{848 ,3989},
{898 ,3974},
{948 ,3958},
{998 ,3943},
{1048,3927},
{1098,3910},
{1148,3891},
{1198,3873},
{1247,3858},
{1297,3846},
{1347,3836},
{1397,3826},
{1447,3818},
{1497,3811},
{1547,3803},
{1597,3797},
{1647,3791},
{1696,3785},
{1746,3780},
{1796,3774},
{1846,3764},
{1896,3752},
{1946,3745},
{1996,3737},
{2046,3729},
{2096,3722},
{2146,3712},
{2195,3700},
{2245,3685},
{2295,3677},
{2345,3676},
{2395,3673},
{2445,3660},
{2495,3587},
{2545,3460},
{2583,3274},
{2587,3262},
{2589,3258},
{2591,3256},
{2592,3254},
{2594,3251},
{2595,3249},
{2596,3246},
{2596,3243},
{2597,3243},
{2597,3242},
{2597,3242},
{2598,3241},
{2598,3242},
{2598,3241},
{2598,3240},
{2598,3240},
{2599,3240},
{2599,3240},
{2599,3240},
{2599,3240},
{2599,3240}   
};


BATTERY_Q_COST_PROFILE_STRUC vk_battery_q_cost_profile_t2[] =
{
{0   ,4340},
{50  ,4312},
{100 ,4287},
{150 ,4264},
{200 ,4241},
{250 ,4220},
{300 ,4198},
{350 ,4177},
{400 ,4156},
{450 ,4135},
{500 ,4115},
{550 ,4094},
{600 ,4076},
{650 ,4068},
{700 ,4042},
{750 ,4010},
{800 ,3988},
{850 ,3978},
{900 ,3970},
{949 ,3956},
{999 ,3940},
{1049,3924},
{1099,3906},
{1149,3887},
{1199,3870},
{1249,3856},
{1299,3844},
{1349,3834},
{1399,3825},
{1449,3817},
{1499,3810},
{1549,3804},
{1599,3798},
{1649,3792},
{1699,3786},
{1749,3782},
{1799,3777},
{1849,3770},
{1899,3765},
{1949,3760},
{1999,3752},
{2049,3743},
{2099,3738},
{2149,3727},
{2199,3713},
{2249,3699},
{2299,3690},
{2349,3686},
{2399,3686},
{2449,3677},
{2499,3608},
{2549,3482},
{2590,3282},
{2593,3266},
{2595,3257},
{2596,3258},
{2598,3257},
{2599,3255},
{2600,3251},
{2601,3253},
{2601,3254},
{2602,3250},
{2603,3243},
{2603,3246},
{2603,3246},
{2604,3244},
{2604,3240},
{2604,3244},
{2604,3244},
{2604,3243},
{2604,3238},
{2604,3240},
{2605,3242},
{2605,3242}   
};


BATTERY_Q_COST_PROFILE_STRUC vk_battery_q_cost_profile_t1[] =
{
{0   ,4344},
{50  ,4314},
{100 ,4289},
{150 ,4266},
{200 ,4245},
{249 ,4223},
{299 ,4203},
{349 ,4182},
{399 ,4163},
{449 ,4142},
{499 ,4122},
{549 ,4102},
{599 ,4088},
{649 ,4078},
{699 ,4047},
{748 ,4005},
{798 ,3978},
{848 ,3959},
{898 ,3944},
{948 ,3933},
{998 ,3921},
{1048,3907},
{1098,3892},
{1148,3878},
{1198,3865},
{1247,3854},
{1297,3844},
{1347,3834},
{1397,3826},
{1447,3818},
{1497,3811},
{1547,3804},
{1597,3798},
{1647,3793},
{1696,3787},
{1746,3783},
{1796,3780},
{1846,3776},
{1896,3773},
{1946,3768},
{1996,3762},
{2046,3754},
{2096,3745},
{2146,3734},
{2195,3720},
{2245,3710},
{2295,3705},
{2345,3701},
{2395,3695},
{2445,3671},
{2495,3588},
{2525,3509},
{2542,3452},
{2553,3411},
{2559,3384},
{2562,3367},
{2565,3357},
{2567,3350},
{2568,3346},
{2569,3343},
{2570,3341},
{2571,3340},
{2572,3339},
{2573,3338},
{2573,3337},
{2574,3337},
{2574,3337},
{2575,3336},
{2575,3336},
{2576,3335},
{2576,3334},
{2577,3335},
{2577,3334},
{2577,3334}   
 }; 	
BATTERY_Q_COST_PROFILE_STRUC vk_battery_q_cost_profile_t0[] =
{
{0   ,4338},
{50  ,4305},
{100 ,4277},
{150 ,4254},
{200 ,4231},
{249 ,4209},
{299 ,4188},
{349 ,4168},
{399 ,4147},
{449 ,4125},
{499 ,4105},
{549 ,4090},
{599 ,4077},
{649 ,4045},
{699 ,4000},
{748 ,3970},
{798 ,3950},
{848 ,3934},
{898 ,3923},
{948 ,3913},
{998 ,3901},
{1048,3888},
{1098,3875},
{1148,3863},
{1198,3853},
{1247,3842},
{1297,3833},
{1347,3824},
{1397,3818},
{1198,3810},
{1247,3802},
{1297,3795},
{1347,3787},
{1397,3779},
{1447,3771},
{1497,3761},
{1547,3749},
{1597,3736},
{1647,3724},
{1696,3715},
{1746,3707},
{1782,3702},
{1809,3698},
{1831,3694},
{1849,3688},
{1865,3681},
{1879,3673},
{1891,3664},
{1901,3654},
{1909,3643},
{1915,3633},
{1920,3624},
{1925,3617},
{1928,3610},
{1931,3605},
{1933,3600},
{1935,3596},
{1937,3592},
{1938,3589},
{1940,3587},
{1941,3584},
{1942,3582},
{1943,3580},
{1943,3579},
{1944,3577},
{1945,3576},
{1945,3575},
{1946,3574},
{1946,3573},
{1947,3572},
{1947,3571},
{1948,3570},
{1948,3570},
{1949,3569} 
 };
BATTERY_Q_COST_PROFILE_STRUC vk_battery_q_cost_profile_temperature[] =
{
 {0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0},      
{0,0}    
};


R_PROFILE_STRUC vk_tinno_r_profile_t3[] =
{
{103,4342},   
{105,4316},
{103,4291},
{105,4268},
{103,4245},
{108,4224},
{105,4202},
{105,4180},
{105,4159},
{110,4139},
{108,4118},
{110,4098},
{110,4078},
{110,4059},
{113,4041},
{113,4022},
{118,4005},
{118,3989},
{123,3974},
{125,3958},
{130,3943},
{133,3927},
{130,3910},
{123,3891},
{115,3873},
{110,3858},
{108,3846},
{108,3836},
{108,3826},
{108,3818},
{110,3811},
{110,3803},
{115,3797},
{115,3791},
{118,3785},
{120,3780},
{120,3774},
{115,3764},
{108,3752},
{110,3745},
{110,3737},
{110,3729},
{110,3722},
{110,3712},
{110,3700},
{110,3685},
{108,3677},
{113,3676},
{118,3673},
{118,3660},
{120,3587},
{138,3460},
{188,3274},
{155,3262},
{145,3258},
{140,3256},
{138,3254},
{128,3251},
{123,3249},
{115,3246},
{113,3243},
{108,3243},
{108,3242},
{108,3242},
{105,3241},
{105,3242},
{103,3241},
{103,3240},
{103,3240},
{103,3240},
{103,3240},
{103,3240},
{103,3240},
{103,3240}     
};
       
       
R_PROFILE_STRUC vk_tinno_r_profile_t2[] =
{           
{125,4340},
{118,4312},
{113,4287},
{118,4264},
{118,4241},
{115,4220},
{118,4198},
{123,4177},
{123,4156},
{120,4135},
{130,4115},
{128,4094},
{130,4076},
{143,4068},
{138,4042},
{130,4010},
{138,3988},
{155,3978},
{150,3970},
{155,3956},
{163,3940},
{160,3924},
{148,3906},
{138,3887},
{130,3870},
{120,3856},
{120,3844},
{120,3834},
{115,3825},
{120,3817},
{125,3810},
{128,3804},
{128,3798},
{130,3792},
{128,3786},
{128,3782},
{130,3777},
{125,3770},
{125,3765},
{125,3760},
{123,3752},
{120,3743},
{125,3738},
{125,3727},
{120,3713},
{123,3699},
{120,3690},
{120,3686},
{133,3686},
{140,3677},
{133,3608},
{153,3482},
{208,3282},
{165,3266},
{145,3257},
{150,3258},
{148,3257},
{140,3255},
{130,3251},
{135,3253},
{135,3254},
{125,3250},
{108,3243},
{115,3246},
{120,3246},
{113,3244},
{103,3240},
{113,3244},
{118,3244},
{113,3243},
{98 ,3238},
{108,3240},
{110,3242},
{108,3242}  
};

R_PROFILE_STRUC vk_tinno_r_profile_t1[] =
{ 
{213,4344},
{343,4314},
{345,4289},
{345,4266},
{348,4245},
{345,4223},
{348,4203},
{348,4182},
{355,4163},
{355,4142},
{360,4122},
{360,4102},
{365,4088},
{383,4078},
{378,4047},
{363,4005},
{358,3978},
{353,3959},
{345,3944},
{343,3933},
{338,3921},
{328,3907},
{323,3892},
{318,3878},
{315,3865},
{315,3854},
{318,3844},
{318,3834},
{320,3826},
{323,3818},
{325,3811},
{328,3804},
{333,3798},
{335,3793},
{335,3787},
{338,3783},
{343,3780},
{348,3776},
{353,3773},
{358,3768},
{363,3762},
{365,3754},
{370,3745},
{378,3734},
{380,3720},
{388,3710},
{408,3705},
{448,3701},
{523,3695},
{640,3671},
{785,3588},
{773,3509},
{633,3452},
{530,3411},
{460,3384},
{420,3367},
{395,3357},
{380,3350},
{370,3346},
{360,3343},
{358,3341},
{350,3340},
{350,3339},
{350,3338},
{345,3337},
{343,3337},
{343,3337},
{343,3336},
{343,3336},
{343,3335},
{338,3334},
{338,3335},
{343,3334},
{338,3334}  
};

R_PROFILE_STRUC vk_tinno_r_profile_t0[] =
{ 
{285 ,4338},
{760 ,4305},
{753 ,4277},
{748 ,4254},
{740 ,4231},
{730 ,4209},
{725 ,4188},
{723 ,4168},
{718 ,4147},
{713 ,4125},
{708 ,4105},
{718 ,4090},
{738 ,4077},
{718 ,4045},
{678 ,4000},
{663 ,3970},
{658 ,3950},
{653 ,3934},
{658 ,3923},
{663 ,3913},
{658 ,3901},
{655 ,3888},
{655 ,3875},
{658 ,3863},
{665 ,3853},
{653 ,3842},
{660 ,3833},
{668 ,3824},
{680 ,3818},
{1078,3810},
{1083,3802},
{1093,3795},
{1100,3787},
{1108,3779},
{1120,3771},
{1133,3761},
{1145,3749},
{1160,3736},
{1180,3724},
{1213,3715},
{1253,3707},
{1255,3702},
{1248,3698},
{1235,3694},
{1220,3688},
{1203,3681},
{1185,3673},
{1163,3664},
{1135,3654},
{1108,3643},
{1085,3633},
{1060,3624},
{1043,3617},
{1028,3610},
{1015,3605},
{1000,3600},
{995 ,3596},
{983 ,3592},
{973 ,3589},
{970 ,3587},
{965 ,3584},
{958 ,3582},
{953 ,3580},
{953 ,3579},
{948 ,3577},
{940 ,3576},
{940 ,3575},
{938 ,3574},
{938 ,3573},
{938 ,3572},
{940 ,3571},
{928 ,3570},
{928 ,3570},
{928 ,3569}
};

R_PROFILE_STRUC vk_tinno_r_profile_temperature[] =
{
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0}
}; 


