# Sorting Ideas
* To group, add a "change line" label
	- "Revive" them afterwords
* Add labels `n` times until all the `n`th word of each line isn't a blocked word

> [!WARNING]
> Ignore the first line of the file for all the steps below, so that the second line of the file is
> the first line and so on

> [!NOTE]
> Here is the `blocklist = ["a", "an", "at", "be", "for", "in", "of", "on", "the", "to"]`
> And also `re.match(r"\(\w+\)", line)`
> From now on if `re.match(r"\(\w+\)", line)` is true, we define as it is in the blocklist
> The block label should be 峀
> The newline label should be 甭
> The parenthesis label should be 刂
> All the xth word start from 0 like in programming languages

# Algorithm Sorting Steps
0. Cleaning
	* Remove extra whitespaces
1. Grouping
	> [!NOTE]
	> The "main-line" is defined to be the lines that starts with a number + ','
	> The "sub-line" are the ones who don't in the initial file
	* Add a unique, unified newline label followed by a whitespace on the first word of each sub-lines
	* Join the sub-lines with the main-line
	* Remove until meeting ','(including) for each line
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
	* Sort based on the `n`th word
4. Labeling
	* Add the respective line number on each line followed with ', '
5. Restoring
	* Make a new line before the label
	* Reomve the newline label, the block label, and the parenthesis label

> [!NOTE]
> A specific step by step on how to proccess "Blocking"

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
