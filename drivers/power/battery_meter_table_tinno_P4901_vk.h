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
{0,4341},
{50,4308},
{100,4282},
{150,4257},
{200,4233},
{250,4210},
{300,4188},
{350,4165},
{400,4143},
{450,4122},
{500,4101},
{550,4080},
{600,4060},
{650,4041},
{700,4022},
{750,4004},
{800,3988},
{850,3971},
{900,3954},
{949,3937},
{999,3919},
{1049,3900},
{1099,3881},
{1149,3865},
{1199,3852},
{1249,3841},
{1299,3831},
{1349,3822},
{1399,3813},
{1449,3807},
{1499,3799},
{1549,3793},
{1599,3787},
{1649,3781},
{1699,3776},
{1749,3768},
{1799,3755},
{1849,3746},
{1899,3739},
{1949,3731},
{1999,3724},
{2049,3716},
{2099,3704},
{2149,3692},
{2199,3677},
{2249,3674},
{2299,3670},
{2349,3661},
{2399,3602},
{2449,3479},
{2489,3290},
{2493,3270},
{2495,3264},
{2497,3259},
{2498,3255},
{2499,3250},
{2499,3248},
{2500,3246},
{2500,3245},
{2501,3245},
{2501,3244},
{2501,3243},
{2501,3243},
{2501,3243}  
};

BATTERY_Q_COST_PROFILE_STRUC vk_battery_q_cost_profile_t2[] =
{
{0,4341},
{50,4313},
{100,4288},
{150,4265},
{200,4241},
{250,4219},
{300,4197},
{350,4175},
{400,4153},
{450,4132},
{500,4111},
{550,4091},
{600,4073},
{650,4057},
{700,4034},
{750,4010},
{800,3991},
{850,3977},
{900,3964},
{949,3949},
{999,3932},
{1049,3912},
{1099,3891},
{1149,3874},
{1199,3860},
{1249,3848},
{1299,3838},
{1349,3829},
{1399,3821},
{1449,3813},
{1499,3806},
{1549,3800},
{1599,3794},
{1649,3788},
{1699,3783},
{1749,3778},
{1799,3773},
{1849,3768},
{1899,3761},
{1949,3753},
{1999,3745},
{2049,3739},
{2099,3729},
{2149,3717},
{2199,3706},
{2249,3691},
{2299,3686},
{2349,3682},
{2399,3674},
{2449,3630},
{2499,3520},
{2538,3366},
{2547,3325},
{2552,3305},
{2554,3294},
{2556,3286},
{2557,3281},
{2558,3277},
{2559,3274},
{2559,3273},
{2559,3272},
{2559,3270},
{2560,3271},
{2560,3271}  
};

BATTERY_Q_COST_PROFILE_STRUC vk_battery_q_cost_profile_t1[] =
{
{0,4327},
{50,4305},
{100,4272},
{150,4244},
{200,4218},
{250,4193},
{300,4170},
{350,4148},
{400,4126},
{450,4104},
{500,4087},
{550,4067},
{600,4043},
{650,4018},
{700,3993},
{750,3972},
{800,3953},
{850,3935},
{900,3917},
{949,3900},
{999,3885},
{1049,3871},
{1099,3858},
{1149,3846},
{1199,3835},
{1249,3825},
{1299,3816},
{1349,3807},
{1399,3800},
{1449,3793},
{1499,3789},
{1549,3786},
{1599,3783},
{1649,3781},
{1699,3777},
{1749,3772},
{1799,3767},
{1849,3761},
{1899,3755},
{1949,3747},
{1999,3738},
{2049,3727},
{2099,3715},
{2149,3704},
{2199,3692},
{2219,3689},
{2237,3686},
{2254,3684},
{2269,3682},
{2282,3681},
{2294,3679},
{2305,3677},
{2316,3675},
{2325,3673},
{2334,3670},
{2343,3667},
{2350,3663},
{2358,3659},
{2364,3654},
{2371,3648},
{2376,3640},
{2382,3632},
{2386,3625},
{2391,3400} 
}; 	

BATTERY_Q_COST_PROFILE_STRUC vk_battery_q_cost_profile_t0[] =
{
{0,4317},
{50,4293},
{100,4272},
{150,4251},
{200,4230},
{249,4206},
{299,4179},
{349,4138},
{399,4097},
{449,4075},
{499,4047},
{549,4006},
{599,3970},
{649,3946},
{699,3928},
{748,3916},
{798,3908},
{848,3899},
{898,3889},
{948,3879},
{998,3869},
{1048,3859},
{1098,3850},
{1148,3841},
{1198,3831},
{1247,3822},
{1297,3813},
{1347,3803},
{1397,3792},
{1447,3782},
{1497,3770},
{1547,3757},
{1596,3744},
{1625,3737},
{1647,3732},
{1666,3728},
{1681,3724},
{1695,3721},
{1708,3719},
{1720,3717},
{1730,3716},
{1741,3714},
{1750,3714},
{1760,3713},
{1769,3712},
{1777,3711},
{1785,3710},
{1793,3710},
{1801,3709},
{1808,3708},
{1815,3708},
{1822,3707},
{1829,3706},
{1835,3706},
{1841,3705},
{1847,3705},
{1853,3704},
{1859,3703},
{1865,3702},
{1870,3701},
{1875,3700},
{1880,3699},
{1885,3698},
{1889,3400}
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
{0,0}    
};

R_PROFILE_STRUC vk_tinno_r_profile_t3[] =
{
{165 ,4341},
{165 ,4308},
{123 ,4282},
{120 ,4257},
{118 ,4233},
{118 ,4210},
{120 ,4188},
{120 ,4165},
{123 ,4143},
{125 ,4122},
{125 ,4101},
{125 ,4080},
{128 ,4060},
{128 ,4041},
{130 ,4022},
{133 ,4004},
{138 ,3988},
{140 ,3971},
{143 ,3954},
{145 ,3937},
{145 ,3919},
{138 ,3900},
{128 ,3881},
{123 ,3865},
{120 ,3852},
{120 ,3841},
{120 ,3831},
{120 ,3822},
{120 ,3813},
{125 ,3807},
{125 ,3799},
{128 ,3793},
{130 ,3787},
{133 ,3781},
{135 ,3776},
{133 ,3768},
{120 ,3755},
{120 ,3746},
{123 ,3739},
{123 ,3731},
{125 ,3724},
{128 ,3716},
{125 ,3704},
{128 ,3692},
{120 ,3677},
{125 ,3674},
{135 ,3670},
{148 ,3661},
{148 ,3602},
{165 ,3479},
{228 ,3290},
{180 ,3270},
{163 ,3264},
{150 ,3259},
{140 ,3255},
{130 ,3250},
{123 ,3248},
{120 ,3246},
{115 ,3245},
{115 ,3245},
{113 ,3244},
{113 ,3243},
{110 ,3243},
{110 ,3243} 
};       
       
R_PROFILE_STRUC vk_tinno_r_profile_t2[] =
{           
{193 ,4341},
{193 ,4313},
{193 ,4288},
{193 ,4265},
{190 ,4241},
{190 ,4219},
{193 ,4197},
{198 ,4175},
{195 ,4153},
{195 ,4132},
{198 ,4111},
{200 ,4091},
{208 ,4073},
{218 ,4057},
{213 ,4034},
{210 ,4010},
{213 ,3991},
{223 ,3977},
{233 ,3964},
{228 ,3949},
{223 ,3932},
{213 ,3912},
{195 ,3891},
{185 ,3874},
{180 ,3860},
{178 ,3848},
{178 ,3838},
{178 ,3829},
{178 ,3821},
{175 ,3813},
{175 ,3806},
{178 ,3800},
{183 ,3794},
{183 ,3788},
{183 ,3783},
{178 ,3778},
{178 ,3773},
{178 ,3768},
{175 ,3761},
{173 ,3753},
{175 ,3745},
{188 ,3739},
{193 ,3729},
{198 ,3717},
{205 ,3706},
{210 ,3691},
{223 ,3686},
{248 ,3682},
{273 ,3674},
{283 ,3630},
{328 ,3520},
{418 ,3366},
{313 ,3325},
{265 ,3305},
{238 ,3294},
{215 ,3286},
{208 ,3281},
{198 ,3277},
{190 ,3274},
{185 ,3273},
{183 ,3272},
{183 ,3270},
{180 ,3271},
{178 ,3271}
};

R_PROFILE_STRUC vk_tinno_r_profile_t1[] =
{ 
{180 ,4327},
{180 ,4305},
{578 ,4272},
{610 ,4244},
{618 ,4218},
{615 ,4193},
{618 ,4170},
{620 ,4148},
{618 ,4126},
{620 ,4104},
{638 ,4087},
{643 ,4067},
{625 ,4043},
{603 ,4018},
{583 ,3993},
{570 ,3972},
{565 ,3953},
{560 ,3935},
{550 ,3917},
{540 ,3900},
{535 ,3885},
{530 ,3871},
{528 ,3858},
{525 ,3846},
{525 ,3835},
{525 ,3825},
{528 ,3816},
{528 ,3807},
{533 ,3800},
{535 ,3793},
{548 ,3789},
{565 ,3786},
{588 ,3783},
{625 ,3781},
{675 ,3777},
{738 ,3772},
{800 ,3767},
{853 ,3761},
{900 ,3755},
{945 ,3747},
{995 ,3738},
{1050 ,3727},
{1120 ,3715},
{1210 ,3704},
{1065 ,3692},
{1225 ,3689},
{1215 ,3686},
{1213 ,3684},
{1208 ,3682},
{1205 ,3681},
{1200 ,3679},
{1195 ,3677},
{1190 ,3675},
{1185 ,3673},
{1178 ,3670},
{1173 ,3667},
{1160 ,3663},
{1153 ,3659},
{1140 ,3654},
{1120 ,3648},
{1103 ,3640},
{1083 ,3632},
{1065 ,3625},
{508 ,3400} 
};

R_PROFILE_STRUC vk_tinno_r_profile_t0[] =
{ 
{578 ,4317},
{578 ,4293},
{603 ,4272},
{615 ,4251},
{630 ,4230},
{643 ,4206},
{663 ,4179},
{688 ,4138},
{885 ,4097},
{998 ,4075},
{1018 ,4047},
{1005 ,4006},
{1003 ,3970},
{1010 ,3946},
{1015 ,3928},
{1025 ,3916},
{1043 ,3908},
{1050 ,3899},
{1058 ,3889},
{1068 ,3879},
{1083 ,3869},
{1098 ,3859},
{1118 ,3850},
{1138 ,3841},
{1155 ,3831},
{1178 ,3822},
{1205 ,3813},
{1228 ,3803},
{1248 ,3792},
{1278 ,3782},
{1305 ,3770},
{1333 ,3757},
{1360 ,3744},
{1343 ,3737},
{1330 ,3732},
{1320 ,3728},
{1310 ,3724},
{1305 ,3721},
{1300 ,3719},
{1295 ,3717},
{1290 ,3716},
{1285 ,3714},
{1285 ,3714},
{1283 ,3713},
{1283 ,3712},
{1280 ,3711},
{1278 ,3710},
{1275 ,3710},
{1275 ,3709},
{1273 ,3708},
{1273 ,3708},
{1270 ,3707},
{1268 ,3706},
{1265 ,3706},
{1263 ,3705},
{1263 ,3705},
{1260 ,3704},
{1260 ,3703},
{1258 ,3702},
{1253 ,3701},
{1253 ,3700},
{1250 ,3699},
{1248 ,3698},
{503 ,3400}
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
{0,0}
}; 

