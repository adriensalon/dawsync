#pragma once

#include <memory>

#include <RtMidi.h>

namespace vstsync {

struct master_transport {

    master_transport();
    ~master_transport();

private:
    std::unique_ptr<RtMidiOut> _midi_out = nullptr;
};

}