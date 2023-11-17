################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autosar/Gpt/src/EcuM.c \
../Autosar/Gpt/src/Gpt.c \
../Autosar/Gpt/src/Gpt_Cfg.c \
../Autosar/Gpt/src/Gpt_Ftm.c \
../Autosar/Gpt/src/Gpt_Ipw.c \
../Autosar/Gpt/src/Gpt_LPit.c \
../Autosar/Gpt/src/Gpt_Lptmr.c \
../Autosar/Gpt/src/Gpt_PBcfg.c \
../Autosar/Gpt/src/Gpt_SRtc.c \
../Autosar/Gpt/src/SchM_Gpt.c 

OBJS += \
./Autosar/Gpt/src/EcuM.o \
./Autosar/Gpt/src/Gpt.o \
./Autosar/Gpt/src/Gpt_Cfg.o \
./Autosar/Gpt/src/Gpt_Ftm.o \
./Autosar/Gpt/src/Gpt_Ipw.o \
./Autosar/Gpt/src/Gpt_LPit.o \
./Autosar/Gpt/src/Gpt_Lptmr.o \
./Autosar/Gpt/src/Gpt_PBcfg.o \
./Autosar/Gpt/src/Gpt_SRtc.o \
./Autosar/Gpt/src/SchM_Gpt.o 

C_DEPS += \
./Autosar/Gpt/src/EcuM.d \
./Autosar/Gpt/src/Gpt.d \
./Autosar/Gpt/src/Gpt_Cfg.d \
./Autosar/Gpt/src/Gpt_Ftm.d \
./Autosar/Gpt/src/Gpt_Ipw.d \
./Autosar/Gpt/src/Gpt_LPit.d \
./Autosar/Gpt/src/Gpt_Lptmr.d \
./Autosar/Gpt/src/Gpt_PBcfg.d \
./Autosar/Gpt/src/Gpt_SRtc.d \
./Autosar/Gpt/src/SchM_Gpt.d 


# Each subdirectory must supply rules for building sources it contributes
Autosar/Gpt/src/%.o: ../Autosar/Gpt/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Autosar/Gpt/src/EcuM.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


