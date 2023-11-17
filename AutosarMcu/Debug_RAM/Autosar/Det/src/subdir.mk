################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autosar/Det/src/Det.c 

OBJS += \
./Autosar/Det/src/Det.o 

C_DEPS += \
./Autosar/Det/src/Det.d 


# Each subdirectory must supply rules for building sources it contributes
Autosar/Det/src/%.o: ../Autosar/Det/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Autosar/Det/src/Det.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


