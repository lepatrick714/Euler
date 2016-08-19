#Though process for P042
Problem can be found at [link](https://projecteuler.net/problem=42)

I will share my thought process for the C++ solution. The Python solution was by Jason B Hill whose blog is linked at the bottom. In addition, I transcribed Kristian's solution to Java. The link to her blog is linked below too. The reason why I chose to include both Jason's and Kristian's solution was to show you that there are multiple ways to solve this problem and that my solution is not necessary the best one. Although ranking the complexity and efficiency of each algorithm is pretty straight forward, I believe that each solution should be explored for future reference.

### C++ Solution
My initial plan of attack is to brute force my way to the solution. As stated in the problem, there's only, "two-thousand common English words" in the words.txt file. Although Project Euler problems are not meant to be just solved but the purpose of these problem is to have fun solving them. Thus shall we give this a little thought.

Note that the formula for the sequence of triangle numbers is just simple the 1+2+3+4+5+...+n sequence. Not that it has any value, I just thought that this was cool :).

Anyways my thought process was to have a vector of integers to cache the sequence itself. Since we already know the first 10 integers, we shall initialize the cache collection with those 10 integers. I have created the main boolean function called is_triangle which will take in a const string and a reference of the cache collection. This way we can populate the cache collection whenever we need too. Lastly I have two helper function, one that returns the Nth term based on the formula they provided for us and the other is a binary search algorithm used to find a specific value in our cache collection.

Inside the is_triangle algorithm, we must first get the total value of the word. Please don't be a noob and create a dictionary for the different letter values. Just iterate through the word and grab the ascii value of each letter of said word. Simple. From there we will check if the value of the word is greater than the greatest value in the cache collection. Since the cache collection will always be sorted, the largest will always be at the end. If this check is true then we must continue to populate the cache collection until the largest value is greater or equal to the total value of the word. If the check is false then we will call the binarySearch helper function to determine whether the value is in the cache collection. Return true if it is, false if it isn't.

Thus the caching solution is probably the easiest solution to undertake. Overall that's my explanation.

### Kristian's solution
I must say that Kristian's solution is probably my favorite mainly because I love math and hate Python. Nothing against Python programmers, I just don't like the language. I don't know the syntax just triggers me. Anyways, Kristian explains it the best in her blog so please do check it out.

[Kristian's Solution](http://www.mathblog.dk/project-euler-42-triangle-words/)

### To be continue
