# Import visualisation libraries
import matplotlib.pyplot as plt
import matplotlib.animation as anim
import matplotlib.colors as mcolors
from matplotlib.patches import Patch
import pandas as pd
import numpy as np
import os

# Locate data for gif
files = sorted(os.listdir("Task_2/matrix_outputs"), key=lambda x: int(x.split("_")[1].split(".")[0]))
frames = [np.loadtxt(os.path.join("Task_2/matrix_outputs", f)) for f in files]

# Color map: 0 = white, 1 = blue (S), 2 = orange (E), 3 = green (I), 4 = red (R)
cmap = mcolors.ListedColormap(["white", "blue", "orange", "green", "red"])
norm = mcolors.BoundaryNorm([0 - 0.5, 1 - 0.5, 2 - 0.5, 3 - 0.5, 4 - 0.5, 4 + 0.5], cmap.N)

# Create plot
fig, ax = plt.subplots()
im = ax.imshow(frames[0], cmap = cmap, norm = norm, animated = True)
ax.set_title("SEIR Simulation")

legend_elements = [
    Patch(facecolor = "white", edgecolor = "black", label = "Empty"),
    Patch(facecolor = "blue", label = "Susceptible"),
    Patch(facecolor = "orange", label = "Exposed"),
    Patch(facecolor = "green", label = "Infected"),
    Patch(facecolor = "red", label = "Recovered")
]
ax.legend(handles = legend_elements, loc = "upper left")

def update(i):
    im.set_data(frames[i])
    ax.set_title(f"SEIR Simulation - Step {i}")
    return [im]

ani = anim.FuncAnimation(fig, update, frames = len(frames), interval = 100)
ani.save("animation.gif", writer = "pillow")
