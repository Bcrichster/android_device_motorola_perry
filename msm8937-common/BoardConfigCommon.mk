#
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Platform
TARGET_BOARD_PLATFORM := msm8937
TARGET_BOARD_PLATFORM_GPU := qcom-adreno505
TARGET_BOOTLOADER_BOARD_NAME := MSM8937

include device/motorola/qcom318-32/BoardConfigCommon.mk

-include vendor/motorola/msm8937-common/BoardConfigVendor.mk

PLATFORM_PATH := device/motorola/msm8937-common

# Properties
TARGET_SYSTEM_PROP += $(PLATFORM_PATH)/system.prop
