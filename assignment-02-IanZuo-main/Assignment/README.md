**SDL Window + Abstraction**

This is the start of your game engine. We will be building upon the code in this assignment. Keep that in mind while you write clean code.

**Task 1 - Install SDL2 (not SDL3)**

To install SDL use the resources provided in the Module.

**Task 2 - Starter Code**

Run the starter code to render a window and screenshot the window. Feel free to change things if it doesn't work exactly for you.

**Task 3 - Abstraction**

Create an abstraction (class or struct) in Application.cpp that will include methods for rendering your window. You should have a main.cpp that you will call your Application from to run your program for this assignment.

**Task 4 - Handle Input**

Add logic to your program to handle input. Pressing "1" should change the screen red, "2" should change the screen green, and "3" should change the screen blue.

After adding logic, take a screenshot of your SDL window being created and place it in the assignment folder. It should be named 'screenshot.jpg'. It doesn't need to be a video of your program, just a screenshot of your SDL window being rendered properly.

**How to compile and run your program**

Your code may compile with different commands based on your architecture, but a sample compilation command may look like: g++ -std=c++20 ./src/*.cpp `pkg-config --cflags --libs sdl2` -o prog.

![](../Media/ColorChanger.mov)

**Submission/Deliverables**

Submission

Commit all of your files to github, including any additional files you create.
Do not commit any binary files unless told to do so.
Do not commit any 'data' files generated when executing a binary.
Submit your GitHub link on Canvas.

Deliverables

You need to commit your code to this repository and a screenshot.jpg of your window.

Q: Can I do more than is required?
A: Sure, have as much fun with it as you like!

Found a bug?

If you found a mistake (big or small, including spelling mistakes) in this lab, kindly send me an e-mail. It is not seen as nitpicky, but appreciated! (Or rather, future generations of students will appreciate it!)
