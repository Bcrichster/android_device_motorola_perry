/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void vendor_load_properties()
{
    std::string platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    std::string sku = property_get("ro.boot.hardware.sku");
    property_set("ro.product.model", sku.c_str());

    // rmt_storage
    std::string device = property_get("ro.boot.device");
    std::string radio = property_get("ro.boot.radio");
    property_set("ro.hw.device", device.c_str());
    property_set("ro.hw.radio", radio.c_str());

    if (device == "perry") {
        if (radio == "US_CA") {
            std::string carrier = property_get("ro.boot.carrier");
            if (carrier == "sprint") {
                property_set("ro.build.description","sperry_sprint-user 7.1.1 NCQ26.69-56 59 release-keys");
                property_set("ro.build.fingerprint","motorola/sperry_sprint/sperry:7.1.1/NCQ26.69-56/59:user/release-keys");
                property_set("ro.mot.build.oem.product","sperry_sprint");
                property_set("ro.mot.build.customerid ","sprint");
                property_set("persist.rcs.supported","1");
                property_set("persist.vt.supported","1");
                property_set("persist.eab.supported","1");
                property_set("persist.radio.videopause.mode","1");
                property_set("ro.hw.nfc","false");
                property_set("ro.hw.fps","false");
                property_set("persist.sys.dun.override", "0");
                property_set("net.tethering.noprovisioning", "true");
            } else {
                property_set("ro.carrier", "retus");
                property_set("ro.build.description","perry-user 7.1.1 NPQ26.69-27 31 release-keys");
                property_set("ro.build.fingerprint","motorola/perry/perry:7.1.1/NPQ26.69-27/31:user/release-keys");
                property_set("ro.mot.build.oem.product","perry");
                property_set("ro.mot.build.customerid","retail");
                property_set("persist.ims.volte","true");
                property_set("persist.ims.vt","false");
                property_set("persist.ims.vt.epdg","false");
                property_set("persist.ims.rcs","false");
                property_set("persist.radio.videopause.mode","0");
                property_set("persist.vt.supported","0");
                property_set("persist.eab.supported","0");
                property_set("persist.rcs.supported","0");
                property_set("ro.hw.nfc","true");
                property_set("ro.hw.fps","true");
            }
            property_set("ro.radio.imei.sv", "6");
        }
    }
}
