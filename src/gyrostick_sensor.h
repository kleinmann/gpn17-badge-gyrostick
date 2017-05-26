#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

#define BNO055_SAMPLERATE_DELAY_MS (100)

Adafruit_BNO055 bno = Adafruit_BNO055(BNO055_ID, BNO055_ADDRESS_B);

class Gyrostick_Sensor {
 public:
  imu::Vector<3> euler();
};

/**
 * x in [0;360]
 * y in [-180;180]
 * z in [-180;180]
 *
 * x = yaw
 * y = rot
 * z = pitch
 */
imu::Vector<3> Gyrostick_Sensor::euler() {
  return bno.getVector(Adafruit_BNO055::VECTOR_EULER);
}
