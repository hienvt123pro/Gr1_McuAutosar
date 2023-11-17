################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autosar/Mcu/src/Mcu.c \
../Autosar/Mcu/src/Mcu_Exe.c \
../Autosar/Mcu/src/Mcu_PBcfg.c \
../Autosar/Mcu/src/Mcu_PCC.c \
../Autosar/Mcu/src/Mcu_PMC.c \
../Autosar/Mcu/src/Mcu_RCM.c \
../Autosar/Mcu/src/Mcu_SCG.c \
../Autosar/Mcu/src/Mcu_SIM.c \
../Autosar/Mcu/src/Mcu_SMC.c 

OBJS += \
./Autosar/Mcu/src/Mcu.o \
./Autosar/Mcu/src/Mcu_Exe.o \
./Autosar/Mcu/src/Mcu_PBcfg.o \
./Autosar/Mcu/src/Mcu_PCC.o \
./Autosar/Mcu/src/Mcu_PMC.o \
./Autosar/Mcu/src/Mcu_RCM.o \
./Autosar/Mcu/src/Mcu_SCG.o \
./Autosar/Mcu/src/Mcu_SIM.o \
./Autosar/Mcu/src/Mcu_SMC.o 

C_DEPS += \
./Autosar/Mcu/src/Mcu.d \
./Autosar/Mcu/src/Mcu_Exe.d \
./Autosar/Mcu/src/Mcu_PBcfg.d \
./Autosar/Mcu/src/Mcu_PCC.d \
./Autosar/Mcu/src/Mcu_PMC.d \
./Autosar/Mcu/src/Mcu_RCM.d \
./Autosar/Mcu/src/Mcu_SCG.d \
./Autosar/Mcu/src/Mcu_SIM.d \
./Autosar/Mcu/src/Mcu_SMC.d 


# Each subdirectory must supply rules for building sources it contributes
Autosar/Mcu/src/%.o: ../Autosar/Mcu/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Autosar/Mcu/src/Mcu.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


