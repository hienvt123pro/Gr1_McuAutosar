################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autosar/Mcl/src/CDD_Mcl.c \
../Autosar/Mcl/src/CDD_Mcl_Cfg.c \
../Autosar/Mcl/src/CDD_Mcl_PBcfg.c \
../Autosar/Mcl/src/Ftm_Common.c \
../Autosar/Mcl/src/LPit_Common.c \
../Autosar/Mcl/src/Lptmr_Common.c \
../Autosar/Mcl/src/SchM_Mcl.c 

OBJS += \
./Autosar/Mcl/src/CDD_Mcl.o \
./Autosar/Mcl/src/CDD_Mcl_Cfg.o \
./Autosar/Mcl/src/CDD_Mcl_PBcfg.o \
./Autosar/Mcl/src/Ftm_Common.o \
./Autosar/Mcl/src/LPit_Common.o \
./Autosar/Mcl/src/Lptmr_Common.o \
./Autosar/Mcl/src/SchM_Mcl.o 

C_DEPS += \
./Autosar/Mcl/src/CDD_Mcl.d \
./Autosar/Mcl/src/CDD_Mcl_Cfg.d \
./Autosar/Mcl/src/CDD_Mcl_PBcfg.d \
./Autosar/Mcl/src/Ftm_Common.d \
./Autosar/Mcl/src/LPit_Common.d \
./Autosar/Mcl/src/Lptmr_Common.d \
./Autosar/Mcl/src/SchM_Mcl.d 


# Each subdirectory must supply rules for building sources it contributes
Autosar/Mcl/src/%.o: ../Autosar/Mcl/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Autosar/Mcl/src/CDD_Mcl.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


