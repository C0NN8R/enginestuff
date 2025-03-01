# EngineStuff
This repository contains code and scripts for programs relating to engines, mainly used to assist in building and modifying existing engines.

## FuzzyGears
This program takes vehicle information (speed, rpm, etc.) and recommends a gear to select.
This is meant for theoretical estimates and is not very accurate. Therefore, it cannot replace a properly crafted shift map.

## BoreCalc
The bore calculator takes user input of an existing engine as well as some preferred specifications and recommends an appropriate bore size for the cylinder.
This does not take into account the existing size of the engine block, the cylinder walls or the effects of temperature fluctuations on the system.

## AudioCheck
This script takes in an engine sound file, preferably with noticable stroke sequence, and analyzes it.
A more consistent sequence of points is a sign of a healthy engine combustion cycle, while more "random" seeming points may indicate problems with the cycle.
Note that this only works on an engine running at idle.
