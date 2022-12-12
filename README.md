# PC Engine Mini rapid-fire mod

A mod that enables rapid-fire on the white Japanese PC Engine Mini controllers. These controllers unfortunately lack the switches to enable rapid fire, that many feel are essential in some games.

This mod uses an Arduino Pro Mini, with a few optocouplers and white LEDs to re-enable this feature without destroying the look of the controller.

![Finished mod](/pictures/finished.jpg)

# Usage:

Press and hold **Select** + **I/II** for 2 seconds to enable rapid-fire for that button. The LED will light up as an indication. Press and hold again to disable.

# Installation:

This should be pretty self-explanatory, so I won't go into much detail. Buttons Select, I and II are connected to the A0-A2 inputs on the Arduino. 9 and 10 are outputs going to the optocouplers (connect a resistor in series), and the optocoupler is connected to the top pad where the rapid-fire switch would be, for the fastest setting. 
7 and 8 are the outputs for the LEDs, again remember to connect resistors in series with the LEDs.

| Arduino pin   | Connection                   |
| ------------- | ---------------------------- |
| A0            | Button **I**                 |
| A1            | Button **II**                |
| A2            | Select                       |
| 9             | Opto > **I** rapid fire pad  |
| 10            | Opto > **II** rapid fire pad |
| 8             | Button **I** LED             |
| 7             | Button **II** LED            |

Run the wires like in my pictures below to avoid pinching them when putting the controller back together.

![PCE controller insides](/pictures/insides.jpg)

https://github.com/Konsolkongen/PC-Engine-mini-rapid-fire-mod/blob/master/pictures/insides2.jpg

Take care when removing the front artwork from the controller. Make sure you have the right tools needed so you don't scratch the plastic or bend the artwork.
![PCE controller front removal](/pictures/front_removal.jpg)

Sand the LEDs flat and cut out a tight fit, so they sit flush against the front. If done right you won't be able to see or feel them once reassembled.
![LED placement](/pictures/LED_placement.jpg)

Reapply the artwork, and if done right you should have a nice uniform light shining through the red button labels.
