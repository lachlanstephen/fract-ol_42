<h1>fract-ol</h1>

<h3>Mark: 105/100</h3>

fract-ol, a ring 2 project of the 42 Cursus, is one of the introductory projects for utilising a graphical libary and creating a basic computer graphics program. Students had the choice between `fract-ol`, `FdF` and `so_long`. The graphical library is 42's own proprietary graphical library, `MiniLibX`.

The purpose of fract-ol was about creating graphically beautiful fractals. It delved into the notion of complex numbers, optimisation in graphics, and event handling.

> [!NOTE]
> Currently, the project only works on MacOS, as I only imported the Mac versions of miniLibX

<h3>Running the program</h3>

Depending on what operating system your computer is running on, you may find you have issues. I include two versions of miniLibX to try and use.

To compile and run the program, run the following commands:

```bash

# Make using the Makefile for openGL

make -f opengl_Makefile		# Creates the fract-ol executable with openGL

# If that doesn't work, use Makefile for swift

make re -f swift_Makefile	# Creates the fract-ol executable with swift

# Run the fract-ol executable

./fract-ol <parameters>
```

> [!WARNING]
> You may find the program won't compile because of issues with miniLibX. If you can't solve the issue, message me and I'll take you through it.

_Note_: The bonus 5 marks came from having cool colours. You'll notice I have a snippet of code commented out for both Mandelbrot and Julia where you can make the colours almost psychedelic, when you sub out for the current colours I use. Personally I like the shades of black and white, I think it looks cleaner, and very pleasing to the eye.

<h3>Program parameters</h3>

The parameters my program takes are as follows:

```bash

# Program parameters

./fractol <Set> <Option1> <Option2>

# Sets

'm'		# Mandelbrot Set

'j'		# Julia Set

# Options - If no options given, defaults to '0' '0'

<Option1>	# Real Part

<Option2>	# Imaginary Part

# e.g. ./fract-ol m

# e.g. ./fract-ol j 0.0065 .2
```

_Note_: Mandelbrot Set does not accept options.

_Note_: `<Options>` ONLY accept floats. Option 1 and Option 2 combine to form a complex number. For the best outputs keep the values &gt; -2 and &lt; 2.

### Program Output Examples

TO BE ADDED.

### Mathematical Theory

Essentially, the Mandelbrot set, is the behaviour of the iteration from 0 of the equation Z<sub>n + 1</sub> = Z<sub>n</sub><sup>2</sup> + C. Where C is the complex number formed from its starting position on the complex plane. So the value of C changes as you move around the x and y<sub>i</sub> axis.

There are two potential results:

1. The number gets arbitrarily large
2. The number remains small, never exceeds 2 from the origin

Based on the result of the point when subbed into the equation, we assign it relevant colours, which gives us the stunning Mandelbrot fractal most people are familiar with.

The Julia Set, is similarly the behaviour of iteration from 0 of the same equation, however, the C remains constant, and instead we change the starting value of Z.

If you're interested in finding out more or just want to have a chat, reach out to me on my social links (I only really have LinkedIn or my email), or leave a comment :) I had a lot of fun with this project and would love to share my enthusiasm.

### Plans for repository

- [ ] Screenshots to this documentation of exmaple outputs
- [ ] Add mouse position zoom management (bonus)
- [ ] Add another fractal set (bonus)
- [ ] Re-evaluate project with bonuses

### Personal Note

I really enjoy mathematics, and personally find it quite beautiful, and this project was a perfect exmaple of this. Delving into the concept of complex numbers and their applications, as well as quadratics, was something I've missed since finishing school mathematics. I'm glad I chose this program, and got to create these works of art. Whilst quite complicated, once you understand what's happening it can be very satisfying to see the outputs.
