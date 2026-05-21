# motion-detection

just some stuff i made in my free time. nothing crazy to look at, basically just a small c++ project to mess around with opencv and cmake. 

it takes an mp4 video, compares the frames, and spits out a new video showing only the pixels that moved. basically frame differencing using grayscale matrices and some basic thresholding/blur to kill the camera noise. 

### stuff used
- c++
- opencv (mostly just for matrix math and video i/o)
- cmake
