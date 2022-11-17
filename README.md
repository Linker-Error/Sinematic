# Sinematic
This is the repository for Sinematic, a small sine wave visualizer.

## How to use

When you start the program up, you will be greeted with a single sine wave. Move your mouse to change the amplitude and offset of the wave, and scroll to change the frequency. To make a more advanced wave, press P to switch to Piled Wave Mode. You will see two sine waves, one you can control, and one you can't. Click to pile the controlled wave onto the other wave, or hold right click to pile it multiple times. After you are done, press D to switch back into default.


## Compilation

### Windows:

Install using these steps:

1. Install Visual Studio and make sure Visual C++ is set up too. Alternatively, you could use another compiler, but don't ask me for help.
2. Install the premake code for raylib from https://github.com/raylib-extras/game-premake.
3. Unzip it and rename the folder to something else.
4. Open the foler and run the batch script for visual studio.
5. Tell Windows Defender to calm down.
6. Go to `game/src` in the folder.
7. Copy and paste all of my source and header files into the folder.
8. Go back to the main folder, and open the .sln file premake generated.
9. Remove all of the preexisting files in the project folder and add all of mine.
10. Set to release mode and compile.

### Windows if you Know What you are Doing (or Linux):

1. Download all my code and compile with raylib.
