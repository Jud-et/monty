0x19. C - Stacks, Queues - LIFO, FIFO
In this project, i'll explore the concepts of stacks and queues, focusing on two fundamental principles: LIFO (Last In, First Out) and FIFO (First In, First Out). They are used to solve a wide range of problems efficiently. This README provides an overview of these concepts and their applications in C programming.

> What do LIFO and FIFO mean
LIFO (Last In, First Out): LIFO is a fundamental principle in stack data structures. It means that the last item added to the stack is the first one to be removed. Think of it like a stack of books where you add a new book to the top and remove the topmost book when needed.

FIFO (First In, First Out): FIFO, on the other hand, is a fundamental principle in queue data structures. It implies that the first item added to the queue is the first one to be removed. Imagine a line of people waiting for a bus – the person who arrived first gets on the bus first.

> What is a stack, and when to use it
A stack is a linear data structure that follows the LIFO principle. It consists of two primary operations:

Push: Adds an item to the top of the stack.
Pop: Removes the top item from the stack.
When to use a stack:

Function Call Stack: In many programming languages, the stack is used to manage function calls. Each function call is pushed onto the stack, and when the function returns, it is popped off the stack.

Expression Evaluation: Stacks are used in evaluating expressions, like converting infix expressions to postfix notation.

Backtracking: In algorithms that require backtracking, a stack can be used to maintain a history of choices.

> What is a queue, and when to use it
A queue is a linear data structure that adheres to the FIFO principle. It has two primary operations:

Enqueue: Adds an item to the rear of the queue.
Dequeue: Removes an item from the front of the queue.
When to use a queue:

Breadth-First Search (BFS): BFS traversal in graphs and trees often employs queues to visit nodes level by level.

Print Queue: In operating systems, a print queue manages print jobs in the order they are received.

Task Scheduling: Queues are used for scheduling tasks in various applications.

> Common Implementations of Stacks and Queues
Stacks:
Array Implementation: Stacks can be implemented using arrays, which provide a simple and efficient solution.

Linked List Implementation: Stacks can also be implemented using linked lists, offering dynamic memory allocation.

Queues:
Array Implementation: Similar to stacks, queues can be implemented using arrays.

Linked List Implementation: Queues can also be implemented using linked lists.

Circular Queue: Circular queues use arrays efficiently by reusing empty spaces.

> Common Use Cases
Stacks:
Expression Evaluation: Stacks help evaluate expressions like infix to postfix.

Undo Functionality: Stacks are used to implement undo functionality in applications.

Parentheses Matching: Stacks can be used to check if parentheses in an expression are balanced.

Queues:
Breadth-First Search: BFS in graphs and trees uses queues to explore neighbors level by level.

Task Scheduling: Scheduling tasks for execution based on priority.

Print Job Management: Managing print jobs in the order they are received.

> Proper Use of Global Variables
Global variables should be used sparingly and with caution. In general, it's best practice to limit the use of global variables because they can make code harder to understand and maintain. When global variables are necessary, follow these guidelines:

Use descriptive names for global variables to indicate their purpose.

Declare global variables at the top of your source file to make them easily visible.

Avoid modifying global variables from multiple parts of your code to prevent unexpected side effects.

Consider encapsulating global variables within a separate module or struct to limit their scope.

Remember that global variables can lead to debugging challenges and make it harder to reason about the behavior of your code, use them judiciously.

By understanding and effectively using stacks and queues, one can solve a wide range of problems in computer science and programming. These fundamental data structures are invaluable tools in programming toolkit.

# Monty

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
 push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$

```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$

```

# Usage

All the files are compiled in the following form:

```
 gcc -Wall -Werror -Wextra -pedantic *.c -o monty.

```

To run the program:

```
 ./monty bytecode_file
```

Available operation codes:

| Opcode | Description |
|------------------- | --------------|
|push   | Pushes an element to the stack. e.g (push 1 # pushes 1 into the stack)|
|pall   | Prints all the values on the stack, starting from the to of the stack.|
|pint   | Prints the value at the top of the stack.|
|pop    | Removes the to element of the stack. |
|swap   | Swaps the top to elements of the stack.|
|add    | Adds the top two elements of the stack. The result is then stored in the second node, and the first node is removed.|
|nop    | This opcode does not do anything.|
|sub    | Subtracts the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|div    | Divides the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|mul | Multiplies the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|mod    | Computes the remainder of the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|#      | When the first non-space of a line is a # the line will be trated as a comment.|
|pchar  | Prints the integer stored in the top of the stack as its ascii value representation.|
|pstr   | Prints the integers stored in the stack as their ascii value representation. It stops printing when the value is 0, when the stack is over and when the value of the element is a non-ascii value.|
|rotl   | Rotates the top of the stack to the bottom of the stack.|
|rotr   | Rotates the bottom of the stack to the top of the stack.|
|stack  | This is the default behavior. Sets the format of the data into a stack (LIFO).|
|queue  | Sets the format of the data into a queue (FIFO).|



