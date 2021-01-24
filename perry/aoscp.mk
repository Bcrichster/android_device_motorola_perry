#
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

$(call inherit-product, device/motorola/perry/full_perry.mk)
$(call inherit-product, vendor/aoscp/configs/common_full_phone.mk)

# Boot animation
TARGET_SCREEN_WIDTH := 720
TARGET_SCREEN_HEIGHT := 1280
TARGET_BOOT_ANIMATION_RES := 720

## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := perry
PRODUCT_NAME := aoscp_perry
PRODUCT_BRAND := motorola
PRODUCT_MANUFACTURER := motorola

PRODUCT_SYSTEM_PROPERTY_BLACKLIST := ro.product.model

PRODUCT_BUILD_PROP_OVERRIDES += \
    BUILD_FINGERPRINT=motorola/perry/perry:7.1.1/NPNS26.118-22-1/1:user/release-keys \
    PRIVATE_BUILD_DESC="perry-user 7.1.1 NPNS26.118-22-1 1 release-keys" \
    PRODUCT_MODEL="Moto E4" \
    PRODUCT_NAME="perry"
    
