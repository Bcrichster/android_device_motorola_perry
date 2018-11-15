# Copyright (C) 2016 The CyanogenMod Project
#               2017 The LineageOS Project
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

def IncrementalOTA_VerifyBegin(info):
  # Workaround for apn list changes
  RestoreApnList(info)

def IncrementalOTA_InstallEnd(info):
  ReplaceApnList(info)

def FullOTA_InstallEnd(info):
  ReplaceApnList(info)

def ReplaceApnList(info):
  info.script.AppendExtra('if getprop("ro.boot.radio") == "US_CA" then')
  info.script.Mount("/system")
  info.script.AppendExtra('run_program("/sbin/sh", "-c", "mv /system/etc/apns-conf.xml /system/etc/apns-conf.xml.bak");')
  info.script.AppendExtra('run_program("/sbin/sh", "-c", "mv /system/etc/stockapn/apns-conf.xml /system/etc/apns-conf.xml");')
  info.script.Unmount("/system")
  info.script.AppendExtra('endif;')

def RestoreApnList(info):
  info.script.AppendExtra('if getprop("ro.boot.radio") == "US_CA" then')
  info.script.Mount("/system")
  info.script.AppendExtra('delete("/system/etc/apns-conf.xml");')
  info.script.AppendExtra('run_program("/sbin/sh", "-c", "mv /system/etc/apns-conf.xml.bak /system/etc/apns-conf.xml");')
  info.script.Unmount("/system")
  info.script.AppendExtra('endif;')
