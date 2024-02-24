Ben Quackenbush Open Ended Project
-------------------------------------------------------------------------------
Welcome to my Open ended project for module 2. The upgrades I made to the 
project for this module is creating a way for you to type up a file with 
certain syntax that will be used to build a level there are two text files 
already in the project that can build a level with the guid.txt file providing 
more in depth explanation on how to use the program. The concepts used for 
this is file input which takes the input from a file to build out the area.
I also made SubArea.h a component class of Area.h within the subAreas vector.
I also made inventory.h a component class of player.h to reduce the amount
of parameters for a few functions and overall organization.
-------------------------------------------------------------------------------
To expand the project I would try and create a way for different areas to 
connect this would require more syntax within the LevelFromFile class 
or an entirely different file that would outline the connections between areas
would also require something similar to the -D for finding new maps that was 
seen in my module 1 project.
-------------------------------------------------------------------------------
I think I should be given a 100 as the complexity of the code required a lot 
of debugging and troubleshooting combined with the scale of the file input
that is being used. also because nothing was hard coded I needed to create 
systems that would work under different conditions an example of this is the 
system used to store items for subarea options and the text for subarea options
because I wanted to be able to get 3 items per option and needed two types of 
text per option as well and using a 2D array was very messy. So I used math each 
time search is called in subarea.h it uses the lowerIndex to calculate what is 
where so if an item is supposed to be assigned to option at index 2 it can be
located at indexes six, seven, or eight a similar system is used for options 
text
-------------------------------------------------------------------------------
all code written by me
-------------------------------------------------------------------------------
no known bugs 
-------------------------------------------------------------------------------