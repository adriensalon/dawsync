#include <vstgui/plugin-bindings/vst3editor.h>

#include <plugin/cids.h>
#include <plugin/controller.h>

using namespace Steinberg;

namespace vstsync {

tresult PLUGIN_API vstsyncController::initialize(FUnknown* context)
{
    // Here the Plug-in will be instantiated

    //---do not forget to call parent ------
    tresult result = EditControllerEx1::initialize(context);
    if (result != kResultOk) {
        return result;
    }

    // Here you could register some parameters

    return result;
}

tresult PLUGIN_API vstsyncController::terminate()
{
    // Here the Plug-in will be de-instantiated, last possibility to remove some memory!

    //---do not forget to call parent ------
    return EditControllerEx1::terminate();
}

tresult PLUGIN_API vstsyncController::setComponentState(IBStream* state)
{
    // Here you get the state of the component (Processor part)
    if (!state)
        return kResultFalse;

    return kResultOk;
}

tresult PLUGIN_API vstsyncController::setState(IBStream* state)
{
    // Here you get the state of the controller

    return kResultTrue;
}

tresult PLUGIN_API vstsyncController::getState(IBStream* state)
{
    // Here you are asked to deliver the state of the controller (if needed)
    // Note: the real state of your plug-in is saved in the processor

    return kResultTrue;
}

// IPlugView* PLUGIN_API vstsyncController::createView (FIDString name)
// {
// 	// Here the Host wants to open your editor (if you have one)
// 	if (FIDStringsEqual (name, Vst::ViewType::kEditor))
// 	{
// 		// create your editor here and return a IPlugView ptr of it
// 		auto* view = new VSTGUI::VST3Editor (this, "view", "plugin_editor.uidesc");
// 		return view;
// 	}
// 	return nullptr;
// }

tresult PLUGIN_API vstsyncController::setParamNormalized(Vst::ParamID tag, Vst::ParamValue value)
{
    // called by host to update your parameters
    tresult result = EditControllerEx1::setParamNormalized(tag, value);
    return result;
}

tresult PLUGIN_API vstsyncController::getParamStringByValue(Vst::ParamID tag, Vst::ParamValue valueNormalized, Vst::String128 string)
{
    // called by host to get a string for given normalized value of a specific parameter
    // (without having to set the value!)
    return EditControllerEx1::getParamStringByValue(tag, valueNormalized, string);
}

tresult PLUGIN_API vstsyncController::getParamValueByString(Vst::ParamID tag, Vst::TChar* string, Vst::ParamValue& valueNormalized)
{
    // called by host to get a normalized value from a string representation of a specific parameter
    // (without having to set the value!)
    return EditControllerEx1::getParamValueByString(tag, string, valueNormalized);
}

}
