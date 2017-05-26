# Gyrostick for GPN17 badge

Have you ever dreamt of using your GPN17 badge as a joystick? Now you can!

## Globals

gyrostick currently introduces the global variable `bno`. You have to call `bno.begin()` in your `setup()` method to
initialize the sensor.

## Usage

Use like this:

```c
Gyrostick stick;
stick.coords() // Returns an imu::Vector<2> with x and y axis coordinates
```

The coordinates range from `0` to `128`.
