#pragma once

#include <pluginterfaces/base/funknown.h>
#include <pluginterfaces/vst/vsttypes.h>

namespace dawsync {

static const Steinberg::FUID kdawsyncProcessorUID(0x47132ABE, 0xAC0B5605, 0xBBE04172, 0xD9D94E3F);
static const Steinberg::FUID kdawsyncControllerUID(0xE30272C3, 0x76F855AE, 0x98B90963, 0xCB242400);

#define dawsyncVST3Category "Fx"
}
