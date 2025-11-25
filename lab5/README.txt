Name: Isaac Zheng
Professor: Dr. Yasaman Ahmadiadli
TA: Majd Alber
Course: COE428 P2025 Lab 4
Submitted: 2025/08/..

~Description of Code~
Everything ran correctly with no issues present. Both requirements were met and each .c file was properly edited to include the given specifications in the lab manual.

~Questions~
In order to support a "stand-alone" tag, which combines both a start-tag and end-tag as one; for example <foo/>, requirement 1 can be modified slightly. Instead of just reading the start of the tag "<" and checking if it contains a "/" as the next character (which indicates it is a end tag), the entire tag name can be checked. Using an if statement, if the tag name ends with a "/", then it is considered a stand-alone tag and it will not be push onto the stack, nothing will be popped from the stack, and it will skip to read the next potential tag. Thus, will allow for this kind of tag without interfering with the normal starting and end tags.
