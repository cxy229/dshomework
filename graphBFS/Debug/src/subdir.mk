################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AdjGraph.cpp \
../src/Graph.cpp \
../src/MinHeap.cpp \
../src/graphBFS.cpp 

OBJS += \
./src/AdjGraph.o \
./src/Graph.o \
./src/MinHeap.o \
./src/graphBFS.o 

CPP_DEPS += \
./src/AdjGraph.d \
./src/Graph.d \
./src/MinHeap.d \
./src/graphBFS.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


