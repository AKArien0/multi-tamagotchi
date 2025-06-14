School project, derived from tamagotchi.
Made using an esp32, a lil screen, and other revolutionary technologies such as buttons and cables.

The idea was about overwhelming the player with more tamagotchis than they could ever handle, to force them to do unethical treatments in order to keep the most possible alive. It aims to shed light on the poor living conditions of animals in mass farming, by putting the player in the conditions that force farmers to do the same.
It is NOT a judgement call or an imperative, as i myself still eat meat. However, i believe that no matter what one does, it is imperative to recognise the living conditions in mass farming.

Documentation is quite poor, but you will find :
  - tama.c/h
    defines the life cycle of a tamagotchi. Extremely arbitrary and a bit ugly at times, but good enough.
  - Input.cpp/hpp
    custom input library for boards that are supported by the arduino compiler. See [it's repo](https://github.com/AKArien0/arduino-input-handler) for details
  - PW.cpp/hpp
    custom hardware-agnostic graphics/widgets library. See [it's repo](https://github.com/AKArien0/PW-lib) for details
  - main.ino
    the script that ties this all together ! Handles the hardware and making the tamagotchis live
