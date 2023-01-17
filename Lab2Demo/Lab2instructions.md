## Lab 2


This demonstrates the use of input file streams to get data from text files.

The program reads the data from the file input.txt, which contains 3 numbers at every line and displays each of them, and their sum. 

## Example 1 (uncomment lines 13-20)

In this example the while loop is conditioned on reading three characters at a time using the ` >> ` operator. We can demonstrate this terminates the loop when either of a,b or c receive characters instead of integers. To demonstrate, add the following line to input.txt

```
12 abc 35
```
Since 'abc' is a string and not an integer as expected, the loop terminates.


## Example 2 (uncomment lines 28-39 first)

In this example, the while loop is conditioned on only reading the first character. The loop fails at the last line of input.txt and the sum is displayed as 213, because b expects an integer and instead gets a string and thus inFS fails. c retains the previous value it read. To fix this, enclose the print statements within the if statement as shown in lines 42-54.


```
if(!infs.fails())
```

This does not run the print statements for the last line of input.txt and thus is a nice way to prevent the computation when an erronous read occurs. This even deals with blank spaces


Rule of thumb is to never condition your reading while loops by eof or fail but rather check for these within the loop before proceeding.


Solution to last time's prompt


```

    vector<string> v;
    string val;

    // Parsing variables    
    int loc = 0;
    uint start = 0;

    cout << "Enter a sequence of words: " << endl;
    getline(cin, val);

    // String parsing, split by space and push into vector
    while (loc != string::npos && start < val.size())
    {
        loc = val.find(" ", start);

        // Last word?
        if (loc != string::npos)
        {
            v.push_back(val.substr(start,loc));
        }
        else
        {
            v.push_back(val.substr(start));
        }  

        // Move the start location beyond the space
        start = loc+1;
    }

    // Output the size of the vector as the quantity of words
    cout << "Your string contained " << v.size() << " words." << endl;

```

Questions to ask:

How to deal with multiple spaces in the middle of the text.
Example: If the user types 'i have        a lab' the  program gives the wrong answer. To fix this. Add a while loop before the if condition

```
while(val.at(loc+1)==' '){

    loc++;

}
```

This skips all the spaces in the middle and gives the correct answer. 