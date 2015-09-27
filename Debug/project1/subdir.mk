################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../project1/ADTbag.cpp \
../project1/RBTree.cpp \
../project1/main.cpp 

OBJS += \
./project1/ADTbag.o \
./project1/RBTree.o \
./project1/main.o 

CPP_DEPS += \
./project1/ADTbag.d \
./project1/RBTree.d \
./project1/main.d 


# Each subdirectory must supply rules for building sources it contributes
project1/%.o: ../project1/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


