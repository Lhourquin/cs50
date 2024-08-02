# Week 0 - Scratch

Week 0 is a introduction about some concept and notion really useful to know like what is binary, ASCII, hexadecimal, what is input output with example etc. This class of cs50 is more about course about computer programming, indeed, this class is about problem solving.

## Computer Science

* Essentialy, computer programming is babout taking some input and creating some output - thus solving a problem. What happens between the input and output, what we could call *a black box*, is the focus of this course.
![black-box](img/input-output-blackbox.png)

### Numeral system

* For example, we may need to take attendance for a class. We could use a system called *unary system* to count, one finger at time. In *Unary Sytem*, each elements are represented by only one unit by only one symbol.
* If we want to know how many students are in a class, we can use the unary system to count them. With unary system, we count each unit with our fingers, each finger represent one unit. If we count to 5, we use 5 fingers, each finger representing one number. So, in our case, if we have 5 students in the class, we use 5 fingers.
* For computers today coubt using a system called *binary*. It's from the term *binary digit* that we get a fmailiar term called *bit*. A *bit* is a zero or one: **on** or **off**.
* Computers only speak in terms or zeros and ones. Zeros represent **off**. Ones represent **on**. Computers are millions, and perhaps billions, of transistors that are being turned on and off. Transistores is a semiconductor device used to amplify or switch electorinic signals and electrical power. There are located in the CPU, memory chips, and other integrated circuits.
* If you imagine using a light bulb, a single bulb can only count from zero to one.
* However if you were to have three light bulbs, there are more options open to you!
* Using light bulb could represent zero:
```
0 0 0
```
* Similary, the following would represent one:
```
0 0 1 
```
* By this logic, we could propose that the following equals two:
```
0 1 0
```
* Extending this logic furhter, the following represents three:
```
1 1 1
```
* Four would apear a:
```
1 0 0
```
* Five would apear a:
```
1 0 1
```
* Six:
```
1 1 0
```
* Seven:
```
1 1 1
```
* Why we have this result ? because, as a heuristic, we could imagine that the following values represent each possible place in ou *binary digit*:
```
4 2 1
```
* Computers use base-2 to count. This can be pictured as follows:
```
2^2		2^1		2^0
4		2		1
```
* Therefore, you could say that it would require three bits (the four's place, the two's place, and the one's place) to represent a number as high as seven.
* Computers generally use eight bits (also known as a *byte*) to represent a number. For example, 00000010 is the number 2 in *binary*, 00010101 is the number 21, 11111111 represent 255.
