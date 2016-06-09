# Multi-level Feedback Queue Scheduler for XV6


## Course project of Operating Systems

### Team member: Wuji Situ

In this project, I implemented Multi-Level Feedback Queue schedule algorithm to replace the Round Robin scheduler in xv6. This is done by adding three queues associating with three different priority values, and reprogram scheduler to choose processes from the queues. Details of the changes are listed below.

### Modifications:
- In proc.h, added a new filed int priority to struct proc, and added a 2-D array of pointers and an array of three integers to ptable. The array of pointers represent the three queues, while these tree integers represent how many processes are in each queue.
- Changed pinit() in proc.c, added three instructions to initialize the newly added integers.
- Modified functions:fork(), userinit(), yield(), wakeup1(), kill(). In fork() and userinit(), the new arrived process will be added to the end of queue 0. In wakeup1() and kill(), the corresponding process will be added to the queue associating with its priority. In yield(), the process will decrease its priority level(by increasing it priority value), and added to the end of corresponding queue.
- Modified function scheduler(). Now this function will trying to get process from the queues instead of the original ptable.proc. It will look up the queue 0 first and move to other queues if no runnable processes found. Once it find a process to switch to, it will loop again from the beginning queue 0.
- Implemented a new function resetPriority() in proc.c. It will be called in trap(), every 200msec. It will move all runnable process to queue 0, and delete them from its original queue. Besides that, it will also reset all processes priority value to 0.
- Implemented two new system calls, nice() and getpri(). nice() can be used to set the priority value. getpri() will print the pid, parent’s pid and priority value of caller process.