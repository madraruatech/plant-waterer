# Love your plants
*IN PROGRESS: Working, but not primetime*

An automation project using Arduino to water house plants. This project is a simple "starter" project to show how to wire up and program an automated plant waterer.

## Functionality

- Monitoring
    - Soil moisture checking
    - If soil is dry then turn on pump to water
    - If not then sleep for 4 hours
- Watering
    - Minimal watering (avoid over watering)
    - Pump water for ~3 seconds then wait ~3 seconds to allow absorption into soil
    - Recheck (monitor) then repeat
- Testing
    - Check how much water is pumped in dry to moist cycle
    - Test how long do plants go without watering between cycles
    - Evaluate size of container to allow watering for a month
- Extensions
    - Wireless Connections
    - Data logging
    - Measure air temperature
    - Measure water levels
    - Alerting on high air temperature
    - Alerting on low water levels

## Current state of project

- Fully functioning, but with issues
- No clear component manifest
- Better diagram required
- Long-term testing

## Build steps

Here

## Components

*NOTE: Many of these components were procured in China, they may not be easily available in other countries.*

- Arduino board: UNO
- Moisture sensor:
- Relay:
- Water pump: 5v DC, ideally an immersion solar pump unit

# Wiring

![Plant waterer wiring](images/plantwaterer-wiring.jpg)

# Libraries

All libraries are included in the lib dir in the project.

Using the following: (*SUBJECT TO CHANGE*)

- [elapsedMillis](https://github.com/pfeerick/elapsedMillis)
