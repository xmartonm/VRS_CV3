################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F3xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
vrs_cv2_ll_programming.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
vrs_cv2_ll_programming.list \

OBJCOPY_BIN += \
vrs_cv2_ll_programming.bin \


# All Target
all: vrs_cv2_ll_programming.elf secondary-outputs

# Tool invocations
vrs_cv2_ll_programming.elf: $(OBJS) $(USER_OBJS) C:\STM_TEST\cv1\vrs_cvicenie_3\STM32F303K8TX_FLASH.ld
	arm-none-eabi-gcc -o "vrs_cv2_ll_programming.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\STM_TEST\cv1\vrs_cvicenie_3\STM32F303K8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="vrs_cv2_ll_programming.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

vrs_cv2_ll_programming.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "vrs_cv2_ll_programming.list"
	@echo 'Finished building: $@'
	@echo ' '

vrs_cv2_ll_programming.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "vrs_cv2_ll_programming.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
