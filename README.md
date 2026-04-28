# Assessment 2 - SEIR Model For Disease Transmission

This repository is used to model disease transmission using the SEIR compartment model. It consists of two parts: 
- Task 1 uses coupled differential equations to simulate the population moving through the stages, Susceptible, Exposed, Infected and finally Recovered. 
 - Task 2 uses Monte-Carlo simulations to simulate the same thing.

They both produce text files which can then be read by the Python file `visualisation.py` to produce graphical outputs to interpret the results.

The Monte-Carlo simulation also has the added feature of the additional Python file `make_gif.py` to generate an animation of the agents moving across the lattice, infecting one another.

## Requirements

- Python 3.x
- A C compiler (e.g. GCC) and `make` for compiling the C source files
- pip packages:
  - matplotlib
  - pandas
  - numpy

## Install packages (If not already installed)

Use the package manager [pip](https://pip.pypa.io/en/stable/) to first install the necessary packages.

```bash
pip install matplotlib pandas numpy
```

## Usage

From Assessment_2 navigate to Task 1 with

```bash
cd Task_1
```

Then run this

```bash
make
./main
```

Follow the prompts and fill in the parameters as required.
Then navigate to Task 2 with

```bash
cd ../Task_2
```

Then run this

```bash
make
./main
```

Follow the prompt again and fill in the parameters as required.
Then navigate back to Assessment_2 with

```bash
cd ..
```

After this, to produce the graphs run this

```bash
python3 visualisation.py
```

Finally if you want to create the animation (it may take some time) run this

```bash
python3 make_gif.py
```

The two graphs and the animation can be located in the Assessment_2 folder.