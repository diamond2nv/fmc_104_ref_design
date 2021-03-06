################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/AtmelAtsha204a.c \
../src/I2cInterface.c \
../src/InterruptController.c \
../src/ModuleConfigConstants.c \
../src/ModuleConfigValueKeys.c \
../src/ModuleEeprom.c \
../src/RealtimeClock.c \
../src/SystemController.c \
../src/TimerInterface.c \
../src/fsbl_hooks.c \
../src/image_mover.c \
../src/main.c \
../src/md5.c \
../src/nand.c \
../src/nor.c \
../src/pcap.c \
/media/2TB/workspace/rsarwar/work/enclastra/pe1_zx1/mercury_pe1_fmc104/SdkExport/system_top_hw_platform_0/ps7_init.c \
../src/qspi.c \
../src/rsa.c \
../src/sd.c 

S_UPPER_SRCS += \
../src/fsbl_handoff.S 

OBJS += \
./src/AtmelAtsha204a.o \
./src/I2cInterface.o \
./src/InterruptController.o \
./src/ModuleConfigConstants.o \
./src/ModuleConfigValueKeys.o \
./src/ModuleEeprom.o \
./src/RealtimeClock.o \
./src/SystemController.o \
./src/TimerInterface.o \
./src/fsbl_handoff.o \
./src/fsbl_hooks.o \
./src/image_mover.o \
./src/main.o \
./src/md5.o \
./src/nand.o \
./src/nor.o \
./src/pcap.o \
./src/ps7_init.o \
./src/qspi.o \
./src/rsa.o \
./src/sd.o 

S_UPPER_DEPS += \
./src/fsbl_handoff.d 

C_DEPS += \
./src/AtmelAtsha204a.d \
./src/I2cInterface.d \
./src/InterruptController.d \
./src/ModuleConfigConstants.d \
./src/ModuleConfigValueKeys.d \
./src/ModuleEeprom.d \
./src/RealtimeClock.d \
./src/SystemController.d \
./src/TimerInterface.d \
./src/fsbl_hooks.d \
./src/image_mover.d \
./src/main.d \
./src/md5.d \
./src/nand.d \
./src/nor.d \
./src/pcap.d \
./src/ps7_init.d \
./src/qspi.d \
./src/rsa.d \
./src/sd.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O2 -I"/media/2TB/workspace/rsarwar/work/enclastra/pe1_zx1/mercury_pe1_fmc104/SdkExport/system_top_hw_platform_0" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../FSLB_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O2 -I"/media/2TB/workspace/rsarwar/work/enclastra/pe1_zx1/mercury_pe1_fmc104/SdkExport/system_top_hw_platform_0" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../FSLB_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/ps7_init.o: /media/2TB/workspace/rsarwar/work/enclastra/pe1_zx1/mercury_pe1_fmc104/SdkExport/system_top_hw_platform_0/ps7_init.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O2 -I"/media/2TB/workspace/rsarwar/work/enclastra/pe1_zx1/mercury_pe1_fmc104/SdkExport/system_top_hw_platform_0" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../FSLB_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


