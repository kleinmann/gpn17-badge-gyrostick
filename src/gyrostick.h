#pragma once

#include <gyrostick_sensor.h>

class Gyrostick {
 public:
  imu::Vector<3> coords();
 private:
  Gyrostick_Sensor sensor;
  double getUsableX(double x);
};

imu::Vector<3> Gyrostick::coords() {
  imu::Vector<3> data = this->sensor.euler();

  double x = getUsableX(data.x());
  double y = constrain(data.y() * 8.0, -180.0, 180.0) + 180.0;
  double z = constrain((data.z() - 60.0) * 8.0, -180.0, 180.0) + 180.0; // holding device in front of you means "centered"

  y = (y / 360.0) * 128.0;
  z = (z / 360.0) * 128.0;

  return imu::Vector<3>(y, z, x);
}

double Gyrostick::getUsableX(double x) {
  if (x >= 180.0) {
    // x geht nach rechts
    // x geht von 360 nach 180 (negativ)
    // 360 = 1, 359 = 2, 358 = 3)
    x = (x - 360) * (-1);
  } else { // x < 180.0)
    // x geht nach links
    // x geht von 0 nach 180 (positiv)
    x = x * (-1);
  }

  x = x + 180.0;

  return x;
}
