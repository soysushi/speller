# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

The longest word in the dictionary and also means a lung disease that is gotten from inhaling fine particles.

## According to its man page, what does `getrusage` do?

getrusage stands for get resource usage and returns all the statistics of the calling process (the entire, including children/parents)

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

it is much faster to pass it by reference as opposed to copying the entire structure (which seems like it uses alot). Same idea in
if you wanted to look for something in your friend's dictionary, you wouldn't want to copy the entire dictionary and then look for the
word, although depends on what you need to do in your program if you needed that copy.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

Main looks for files in the directory that it is given and each file will indicate how it should be read in its header, much like jpeg files and
which in our case is txt file. Specifically once the address is given, you must use the FILE function to read the file until EOF (End of file), this
can be done character by character or by strings and many other formats.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

String only looks for terminating 0's, that mean's if a string contained numbers and other special characters, it would end up reading it (which we don't want)

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

constant is useful to make sure that the data we're using, in this case the pointer that we are accessing, does not get changed.
For example, the pie constant 3.14 could be changed in a function that used it and later on other functions will get inaccurate results.
