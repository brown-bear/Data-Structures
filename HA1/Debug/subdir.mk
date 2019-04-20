################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Burke_HA1.cpp \
../HA1.cpp \
../HA1_help.cpp \
../Home\ Assignment\ 1.cpp \
../bubblesort.cpp 

OBJS += \
./Burke_HA1.o \
./HA1_help.o \
./Home\ Assignment\ 1.o \
./bubblesort.o 

CPP_DEPS += \
./Burke_HA1.d \
./HA1_help.d \
./Home\ Assignment\ 1.d \
./bubblesort.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HA1: ../HA1.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Resource Custom Build Step'
	
	@echo 'Finished building: $<'
	@echo ' '

Home\ Assignment\ 1.o: ../Home\ Assignment\ 1.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Home Assignment 1.d" -MT"Home\ Assignment\ 1.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


