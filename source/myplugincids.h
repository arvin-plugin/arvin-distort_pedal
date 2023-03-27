//------------------------------------------------------------------------
// Copyright(c) 2023 Arvin Plugin.
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace MyCompanyName {
//------------------------------------------------------------------------
static const Steinberg::FUID kARVIN_DIST_PEDAL_FXProcessorUID (0x06C86355, 0xF79C5897, 0x88BDC7A9, 0x8A7296E9);
static const Steinberg::FUID kARVIN_DIST_PEDAL_FXControllerUID (0x30C6D9B2, 0x7EC75DC7, 0xB7F1D14E, 0xDD8C1BDE);

#define ARVIN_DIST_PEDAL_FXVST3Category "Fx"

//------------------------------------------------------------------------
} // namespace MyCompanyName
