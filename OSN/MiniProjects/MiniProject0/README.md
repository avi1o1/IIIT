# Mini Project 0

All files in this repository are structured and coded to meet the provided guidelines and requirements, with minor adjustments as necessary. While I have tried my best to stick to them, there may have been some areas of confusion or gaps in understanding. Below are the assumptions and deviations made during the implementation.

## Part 1: File Management

The [`fileManagement.c`](/Part-1/fileManagement.c) file demonstrates basic file operations such as creating a file, writing to it, and reading from it.

My assumptions for this section are as follows:
- I am storing all the `INPUT` messages from the user; and printing all of them when `PRINT` is called.
- I am using `fopen()` to read through the contents of the file. Note that I am using `dup2` for printing, and fopen() only read through the contents and display them.
- While I am using a single file descriptor for the file, I am creating temporary ones to store the terminal descriptor. My implementation requires that, and I am unable to find a way around for writing to files.
- I am attaching a `\n` to the end of user input, while saving to `newfile.txt`.
- I am also printing some additional characters, to guide the user in what inputs the code is expecting. While this doesn't change any functionality, it is a slight diversion from the doc.

## Part 2: Process Management

The [`processManagement.c`](/Part-2/processManagement.c) file demonstrates basic process operations such as forking, child & parent processes, process ID and other related process (sys) calls.

My assumptions for this section are as follows:
- I have put some redundant `wait()` calls between each task, in order for the evaluator to clearly and easily distinguish between the tasks. I have also added ample guiding messages to comment what is happening in which call.
- Yeah just that, I believe rest is mostly in line with what is expected.

### End