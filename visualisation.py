# Import visualisation libraries
import matplotlib.pyplot as plt
import pandas as pd

# Immport data file
df = pd.read_csv("Task_1/task_1_data")

# Create plot
plt.figure(figsize = (12,8))

# Plot populations
plt.plot(df["time"], df["s"], label = "Suseptible (S)", linewidth = 2)
plt.plot(df["time"], df["e"], label = "Exposed (E)", linewidth = 2)
plt.plot(df["time"], df["i"], label = "Infected (I)", linewidth = 2)
plt.plot(df["time"], df["r"], label = "Recovered (R)", linewidth = 2)

# Spice it up!
plt.xlabel("Time")
plt.ylabel("Populations")
plt.title("SEIR Model")
plt.legend()

# Save the graph
plt.savefig("SEIR_Model_Task_1")

# Display graph
plt.show()

# Immport data file
df = pd.read_csv("Task_2/task_2_data.txt")

# Create plot
plt.figure(figsize = (12,8))

# Plot populations
plt.plot(df["Step"], df["s"], label = "Suseptible (S)", linewidth = 2)
plt.plot(df["Step"], df["e"], label = "Exposed (E)", linewidth = 2)
plt.plot(df["Step"], df["i"], label = "Infected (I)", linewidth = 2)
plt.plot(df["Step"], df["r"], label = "Recovered (R)", linewidth = 2)

# Spice it up!
plt.xlabel("Steps")
plt.ylabel("Populations")
plt.title("SEIR Model")
plt.legend()

# Save the graph
plt.savefig("SEIR_Model_Task_2")

# Display graph
plt.show()