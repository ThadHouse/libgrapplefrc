#include "grpl/LaserCan.h"
#include "grpl/utils.h"

#include <iostream>

using namespace libgrapplefrc;
using namespace grpl;

LaserCan::LaserCan(uint8_t can_id) : _can_id(can_id) {
  _handle = ffi::lasercan_new(can_id);
}

LaserCan::~LaserCan() {
  ffi::lasercan_free(_handle);
}

std::optional<LaserCanMeasurement> LaserCan::get_measurement() const {
  return conv_opt(ffi::lasercan_get_status(_handle)._0);
}

int LaserCan::set_ranging_mode(LaserCanRangingMode mode) {
  return wrap_error(ffi::lasercan_set_range(_handle, mode == LaserCanRangingMode::Long));
}

int LaserCan::set_timing_budget(LaserCanTimingBudget budget) {
  return wrap_error(ffi::lasercan_set_timing_budget(_handle, (uint8_t)budget));
}

int LaserCan::set_roi(LaserCanROI roi) {
  return wrap_error(ffi::lasercan_set_roi(_handle, roi));
}
