#pragma once

#include <pluginterfaces/base/funknown.h>
#include <pluginterfaces/vst/vsttypes.h>

namespace vstsync {

static const Steinberg::FUID kvstsyncProcessorUID(0x47132ABE, 0xAC0B5605, 0xBBE04172, 0xD9D94E3F);
static const Steinberg::FUID kvstsyncControllerUID(0xE30272C3, 0x76F855AE, 0x98B90963, 0xCB242400);

#define vstsyncVST3Category "Fx"
}
