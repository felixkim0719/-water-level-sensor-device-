# water-level-sensor-device
 Instant noodle water level sensor device for the visually impaired

## Introduction

This is an improved version of the cup noodle water level device featured in OneShot Hansol's YouTube video [Cup Noodle Water Control Device](https://www.youtube.com/shorts/jPbPJbluq0A). It addresses the issues identified in the original design.

## Improvements

- **Use of rubber bands**: Allows adaptation to various cup noodle sizes
- **Non-contact water level sensor**: Provides more accurate water level detection

## Materials Needed

- Arduino
- Non-contact water level sensor
- Rubber bands
- 9V battery
- Battery case

## Circuit Diagram

![Instant noodle water level sensor device for the visually impaired](https://raw.githubusercontent.com/felixkim0719/water-level-sensor-device/main/Schematic.jpg)

## Source Code

```cpp
int Liquid_level = 0;
int first = 0;
int numTones = 5;
int tones[] = {261, 330, 392, 330, 261};

void setup() {
  Serial.begin(9600);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  if (first == 0) {
    first++;
    for (int i = 0; i < 3; i++) {
      tone(6, tones[i]);
      delay(500);
    }
    noTone(6);
  }
  
  Liquid_level = digitalRead(5);
  Serial.print("Liquid_level= ");
  Serial.println(Liquid_level, DEC);
  
  if (Liquid_level == 1) {
    for (int i = 0; i < numTones; i++) {
      tone(6, tones[i]);
      delay(70);
    }
    noTone(6);
  }
  
  delay(50);
}
```

## How It Works

1. When turned on, the device plays a startup sound.
2. The non-contact water level sensor detects the water level.
3. When the water reaches the appropriate level, an alert sound is played.
4. The rubber bands allow the device to be attached to various sizes of cup noodles.

## Completed Device Video

![Demo](https://raw.githubusercontent.com/felixkim0719/water-level-sensor-device/main/demo.mp4)

## Conclusion

This improved version of the cup noodle water level device is more practical as it can be used with various sizes of cup noodles. The construction process is simple, making it easy for anyone to build.

If you have any questions, feel free to ask. I'm here to help!
