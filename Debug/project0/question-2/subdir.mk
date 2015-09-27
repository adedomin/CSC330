################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../project0/question-2/grade.cpp \
../project0/question-2/test.cpp 

OBJS += \
./project0/question-2/grade.o \
./project0/question-2/test.o 

CPP_DEPS += \
./project0/question-2/grade.d \
./project0/question-2/test.d 


# Each subdirectory must supply rules for building sources it contributes
project0/question-2/%.o: ../project0/question-2/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


