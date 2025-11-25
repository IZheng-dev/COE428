Name: Isaac Zheng
Student ID: 501263130
Professor: Dr. Yasaman Ahmadiadli
TA: Majd Alber
Course: COE428 P2025 Lab 2
Submitted: 2025/07/07

~Questions~
Question 1:
1. Suppose that towers(5, 2, 3) is invoked. The first recursive call would then be towers(4, 2, 1). This can be understood using the called method, towers(n, from, dest). The invokation has the 5 disks to be moved from peg 2 to peg 3. However, in Tower of Hanoi, the larger disk cannot be stacked ontop of smaller disks. The smaller, n-1 disks must be moved first to the spare peg. The spare peg can be determined by using the formula spare = 6 - from - dest. This means in order to move the smallest disk first, towers(n-1, from, spare) will be recursively called. Using this the first recurisve call can be determined.
Therefore, ANSWER: towers(4, 2, 1).

2. Using what is known in question 1, towers(4, 2, 1) will be the first recurisve call. This means that each subsequent call made to towers() will decrease until the base case is reached so that the smallest disk on top can be moved first. The next calls would be towers(3, 2, 3), towers(2, 2, 1), towers(1, 2, 3), and the base case (0, 2, 1).
Therefore, ANSWER: There will be 5 recursive calls to tower().

3. Once the invokation has returned, stdout will print "2 3". This is because the first move that will occur will be printed to stdout using the print statement, printf("%d %d\n", from, dest);. In the case of towers(5, 2, 3), the recursive function will be called until it reaches the base case of towers(0, 2, 1), where there are 0 disks so no moves can be made. The first move will have to involve moving the smallest disk, disk 1, to from peg 2 to peg 3.
Therefore, ANSWER: stdout will print 2 3.

4. The second recursive call will be towers(3, 2, 3). Similarly to how question 2 was described, the Towers of Hanoi is solved as smaller subsequent problems. This means in order to solve towers(4, 2, 1), towers(3, 2, 3) must be solved first and so on until the first actual move can be made using the small top disk.
Therefore, ANSWER: towers(3, 2, 3).

Question 2:
If towers(8, 1, 2) is invoked, 2^(n)-1 = 2^(8)-1 = 255 lines will be printed to stdout. Everytime a move is made, it is printed to stdout. Everytime another disk is added, the number of moves effectively double, 2^n, because each added disk forces the smaller disks to move out of the way in order to move the large disk. Furthermore, the last disk (the largest disk) will only need to be moved once; the number of moves is 1 less, subtract 1. 
Therefore: ANSWER: 255 lines.

~Description of Code~
No issues were present in the code and everything worked perfectly.


