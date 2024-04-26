<h1>fract-ol</h1>

<h3>Mark: 105/100</h3>

fract-ol, a ring 2 project of the 42 Cursus, is one of the introductory projects for utilising a graphical libary and creating a basic computer graphics program. Students had the choice between `fract-ol`, `FdF` and `so_long`. The graphical library is 42's own proprietary graphical library, `MiniLibX`.

The purpose of fract-ol was about creating graphically beautiful fractals. It delved into the notion of complex numbers, optimisation in graphics, and event handling.

<h3>Running the program</h3>

To compile and run the program, run the following commands:

```bash

# Make using the Makefile

make	# Creates the fract-ol executable

# Run the fract-ol executable

./fract-ol <parameters>
```

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

_Note_: `<Options>` ONLY accept floats. Option 1 and Option 2 combine to form a complex number.

**For the best outputs keep the values &gt; -2 and &lt; 2.**

### Program Output Examples

TBC

### Plans for repository

- [ ] Screenshots to this documentation of exmaple outputs
- [ ] Add mouse position zoom management (bonus)
- [ ] Add another fractal set (bonus)
- [ ] Re-evaluate project with bonuses

### Personal Note

I really enjoy mathematics, and personally find it quite beautiful, and this project was a perfect exmaple of this. Delving into the concept of complex numbers and their applications, as well as quadratics, was something I've missed since finishing school mathematics. I'm glad I chose this program, and got to create these works of art.
