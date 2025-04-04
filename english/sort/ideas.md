# Sorting Ideas
* To group, add a "change line" label
	- "Revive" them afterwords
* Add labels `n` times until all the `n+1`th word of each line isn't a blocked word

> [!WARNING]
> Ignore the first line of the file for all the steps below, so that the second line of the file is
> the first line and so on

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
	* `n` starts with 1
	* Scan each line, if the `n`th word isn't in the block list, add another label
	* Do it until all the `n+1`th word of each line isn't a blocked word
	* Lastly you found that you iterate through the lines `n` times
3. Sorting
	* Sort based on the `n`th word
4. Labeling
	* Add the respective line number on each line followed with ', '
5. Restoring
	* Make a new line before the label
	* Reomve both the newline labels and the block labels
