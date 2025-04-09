# Sorting Ideas

## Objective
- Sort the whole csv document while ignoring some specific words when sorting

## Fragments of ideas
- To group, add a "change line" label
	* "Revive" them afterwords
- Add labels `n` times until all the `n`th word of each line isn't a blocked word

> [!WARNING]
> Ignore the top x lines of the file for all the steps below, but remember to add them back

> [!NOTE]
> The labels should be expressed as a variable

# Algorithm Sorting Steps
0. Cleaning
	- Remove extra whitespaces
1. Grouping
	> [!NOTE]
	> The "main-line" is defined to be the lines that starts with a number + ','
	> The "sub-line" are the ones who don't in the initial file
	- Add a unique, unified newline label followed by a whitespace on the first word of each sub-lines
	- Join the sub-lines with the main-line
	- Remove until meeting ','(including) for each line
	- Checking
		* Check if the user have phrases that's made out of blocked words
			- If yes then add them to unblock.txt
2. Blocking
	- Setup
		* Search for each line that starts with '(' and ends with ')'
		* If the words inside these include spaces, replace it with the parenthesis label
	- Main Course
		* `n` starts with 0
		* if all `n`th word of each line is not in the block list: break;
		* Scan each line, if the `n`th word isn't in the block list, add another label
		* Do it until all the `n`th word of each line isn't a blocked word
		* n++
3. Sorting
	- Sort based on the `n`th word
4. Labeling
	- Add the respective line number on each line followed with ', '
5. Restoring
	- Make a new line before the label
	- Reomve the newline label, the block label, and the parenthesis label

> [!NOTE]
> A specific step by step on how to process "Blocking"

n = 0
a witness
an apple
the world
cat
(this刂is) a happy ending
(it's刂a) hat

n = 1
a witness
an apple
the world
3D cat
(this刂is) a happy ending
(it's刂a) hat

n = 2(all the 2nd word are not blocked, break)
3D a witness
3D an apple
3D the world
3D 3D cat
(this刂is) a happy ending
3D (it's刂a) hat
