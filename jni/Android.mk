LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := xenon
LOCAL_SRC_FILES := src/main.cpp \
                   src/menu.cpp \
                   src/esp.cpp \
                   src/features.cpp \
                   src/world.cpp \
                   src/config.cpp \
                   src/utils.cpp \
                   src/gui/ui.cpp \
                   src/gui/widgets.cpp \
                   src/gui/util.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/src \
                    $(LOCAL_PATH)/src/axlebolt \
                    $(LOCAL_PATH)/src/unity \
                    $(LOCAL_PATH)/src/il2cpp \
                    $(LOCAL_PATH)/src/gui \
                    $(LOCAL_PATH)/src/hooks \
                    $(LOCAL_PATH)/src/sdk

LOCAL_CPP_FEATURES := exceptions rtti
LOCAL_CFLAGS := -O2 -fvisibility=hidden -fPIC -std=c++17
LOCAL_LDFLAGS := -llog -landroid -lEGL -lGLESv2 -lz -ldl

include $(BUILD_SHARED_LIBRARY)
