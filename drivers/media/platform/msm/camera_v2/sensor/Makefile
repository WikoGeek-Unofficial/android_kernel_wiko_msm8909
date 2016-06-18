RO_TARGET := $(strip $(subst ro.target =,,$(shell cat $(PWD)/../build.ini |grep ^ro.target)))
ifeq ($(strip $(RO_TARGET)),V3903)
ccflags-y += -DTINNO_TARGET_V3903
endif
ifeq ($(strip $(RO_TARGET)),V3901)
ccflags-y += -DTINNO_TARGET_V3901
RO_PROJECT := $(strip $(subst ro.project =,,$(shell cat $(PWD)/../build.ini |grep ^ro.project)))
$(warning -wlj--PWD= $(PWD)-------RO_TARGET=$(RO_TARGET))
ifeq ($(strip $(RO_PROJECT)),bq_ru)
$(warning -wlj--PWD= $(PWD)-------RO_PROJECT=$(RO_PROJECT))
ccflags-y += -DTINNO_MAIN_CAMERA_INTERPOLATION
ccflags-y += -DTINNO_SUB_CAMERA_INTERPOLATION
endif
ifeq ($(strip $(RO_PROJECT)),mcl_za)
$(warning -wlj--PWD= $(PWD)-------RO_PROJECT=$(RO_PROJECT))
ccflags-y += -DTINNO_MAIN_CAMERA_INTERPOLATION_V3901_MCL_ZA
ccflags-y += -DTINNO_SUB_CAMERA_INTERPOLATION_V3901_MCL_ZA
endif
endif
ccflags-y += -Idrivers/media/platform/msm/camera_v2
ccflags-y += -Idrivers/media/platform/msm/camera_v2/msm_vb2
ccflags-y += -Idrivers/media/platform/msm/camera_v2/camera
ccflags-y += -Idrivers/media/platform/msm/camera_v2/sensor/io
ccflags-y += -Idrivers/media/platform/msm/camera_v2/sensor/cci
obj-$(CONFIG_MSMB_CAMERA) += cci/ io/ csiphy/ csid/ actuator/ flash/ eeprom/ ois/
obj-$(CONFIG_MSM_CAMERA_SENSOR) += msm_sensor_init.o msm_sensor_driver.o msm_sensor.o
obj-$(CONFIG_MT9M114) += mt9m114.o
obj-$(CONFIG_OV5645) += ov5645.o
obj-$(CONFIG_OV5645) += ov7695.o
obj-y += gc0310.o
obj-y += hi258_8909.o
