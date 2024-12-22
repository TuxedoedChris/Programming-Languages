# Programming-Languages

1. Summary of the Project and Problem It Solves
   The Grocery Tracker program reads from an input file, processes the data to determine the frequency of each item, and saves the results to a backup file. Using a linked list, the program stores and manages its items. The program has a main menu that allows the user to search for items to find their purchase frequency, view a list of items and their frequencies, or see the data as a histogram. The program could be used for data analytics, for when companies need to track popularity of items apart from inventory. Simply using inventory could be inaccurate due to spoilage, theft, or damage.

3. What I Did Particularly Well
   I originally started with string manipulation with linked lists, which I think was simpler and more dynamic for this project. Instead I rewrote the code to follow the instructions and the past zyBooks activities. These focused on pointers, and nodes. The nodes traversal was overly initialized to make sure there were no errors and could be used dynamically. I spent more time on how it looked when it printed than I should have, and since deleted most of it for efficiency and less lines of code for my teacher to read.

5. Enhancements for the Code
   I wanted to add more error catches than I did, but each time I would implement them, it would add an upwards of 50 lines to the code which seemed unnecessary for this assignment. Doing this removed an infinite loop from happening when the user input a character or a string. I also would have opted for using maps but with my little experience in them I chose to stay on the topic of our zyBooks. Doing so would have made the code much more memory efficient and reducing a lot of lines of code making the program faster and I would assume more dynamic.

7. Most Challenging Pieces of Code
   Pointers in general always seem to make me go through a flowchart in my head each time to make sure I'm implementing it correctly. I also had trouble writing error catches efficiently, always seemed to make too many lines of code as I said before, so I opted to remove them.

9. Transferable Skills from This Project
    Honestly its simple but the backup was something I will use from now on. I had never used a backup before and I think it would even be very useful for debugging when used throughout the code. This way you could keep your code nice, but have a file showing the values of items and their values changing throughout the code. Using a function to call to when editing the debug backup would also be very simple and easy to remove once completed.

11. How I Made the Program Maintainable, Readable, and Adaptable
    I made sure to have code spaced well, many comments, and separated each function to not include things that would interfere with other functions. This way if one part of the code was working incorrectly, I could just rewrite that function and it wouldn't break anything outside of that function's interactions.
