import plotly.graph_objs as go  
import numpy as np
import csv

# Data extraction
data = []
try:
    with open('resultRowColumn.txt', newline='') as file:
        CSV_operator = csv.reader(file)
        next(CSV_operator)
        for fila in CSV_operator:
            data.append([float(fila[0]), float(fila[1]), float(fila[2]), float(fila[3])])
except FileNotFoundError:
    path = input("Path to your results file: ")
    with open(path, newline='') as file:
        CSV_operator = csv.reader(file)
        next(CSV_operator)
        for fila in CSV_operator:
            data.append([float(fila[0]), float(fila[1]), float(fila[2]), float(fila[3])])
            
# Data organizing
data = np.array(data)

size_row = data[:, 0]
random_row = data[:, 1]
results_row = data[:, 2]

size_column = data[:, 0]
random_column = data[:, 1]
results_column = data[:, 3]

# Plotting
fig = go.Figure()

fig.add_trace(go.Scatter3d(
    x=size_row,
    y=random_row,
    z=results_row,
    mode='markers',  
    marker=dict(
        size=5,         
        color=results_row,  
        colorscale='earth',
        opacity=0.8  
    ),
    name='Rows'
))

fig.add_trace(go.Scatter3d(
    x=size_column,
    y=random_column,
    z=results_column,
    mode='markers', 
    marker=dict(
        size=5,        
        color=results_column,  
        colorscale='prgn',  
        opacity=0.8     
    ),
    name='Columns'
))

# Configuring layout of the figure
fig.update_layout(
    scene=dict(
        xaxis_title='Size',
        yaxis_title='Random',
        zaxis_title='Execution time',
    )
)

# Displaying in the web browser
fig.show()
