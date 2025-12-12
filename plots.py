import numpy as np
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D

def set_equal_aspect(ax):
    """Force equal aspect ratio for 3D axes."""
    xlims = ax.get_xlim()
    ylims = ax.get_ylim()
    zlims = ax.get_zlim()

    spans = [
        xlims[1] - xlims[0],
        ylims[1] - ylims[0],
        zlims[1] - zlims[0]
    ]
    centers = [
        (xlims[0] + xlims[1]) / 2,
        (ylims[0] + ylims[1]) / 2,
        (zlims[0] + zlims[1]) / 2
    ]

    max_span = max(spans)
    half = max_span / 2

    ax.set_xlim(centers[0] - half, centers[0] + half)
    ax.set_ylim(centers[1] - half, centers[1] + half)
    ax.set_zlim(centers[2] - half, centers[2] + half)


def plot_cell(cell):
    fig = plt.figure(figsize=(8, 6))
    ax = fig.add_subplot(111, projection='3d')

    # Colors for different parts
    colors = {
        'soma': 'purple',
        'dend': 'orange',
        'axon': 'tomato',
        'term': 'gold'
    }

    for sec in cell.all:
        x = [sec.x3d(i) for i in range(sec.n3d())]
        y = [sec.y3d(i) for i in range(sec.n3d())]
        z = [sec.z3d(i) for i in range(sec.n3d())]
        # Determine color
        if 'soma' in sec.name():
            c = colors['soma']
        elif 'dend' in sec.name():
            c = colors['dend']
        elif 'axon' in sec.name():
            c = colors['axon']
        elif 'term' in sec.name():
            c = colors['term']
        else:
            c = 'black'
        ax.plot(x, y, z, c=c, linewidth=2)

    legend_elements = [
        Line2D([0], [0], color='purple', lw=3, label='BC soma'),
        Line2D([0], [0], color='orange', lw=3, label='BC dendrites'),
        Line2D([0], [0], color='tomato', lw=3, label='BC axon'),
        Line2D([0], [0], color='gold', lw=3, label='BC terminals'),
    ]
    ax.legend(handles=legend_elements, loc='upper left')
    ax.set_xlabel('X (µm)')
    ax.set_ylabel('Y (µm)')
    ax.set_zlabel('Z (µm)')
    ax.set_title('ON Bipolar Cell Morphology')
    ax.view_init(elev=30, azim=45)
    set_equal_aspect(ax)
    plt.show()


def plot_bc_rgc(bc, rgc):
    fig = plt.figure(figsize=(8, 6))
    ax = fig.add_subplot(111, projection='3d')

    # --- Colors for each structure ---
    colors_bc = {
        'soma': 'purple',
        'dend': 'orange',
        'axon': 'tomato',
        'term': 'gold'
    }
    colors_rgc = {
        'soma': 'navy',
        'dend': 'cyan',
        'axon': 'dodgerblue'
    }

    # --- Plot BC ---
    for sec in bc.all:
        x = [sec.x3d(i) for i in range(sec.n3d())]
        y = [sec.y3d(i) for i in range(sec.n3d())]
        z = [sec.z3d(i) for i in range(sec.n3d())]

        if 'soma' in sec.name():
            c = colors_bc['soma']
        elif 'dend' in sec.name():
            c = colors_bc['dend']
        elif 'axon' in sec.name():
            c = colors_bc['axon']
        elif 'term' in sec.name():
            c = colors_bc['term']
        else:
            c = 'grey'

        ax.plot(x, y, z, c=c, linewidth=2)

    # --- Plot RGC ---
    for sec in rgc.all:
        x = [sec.x3d(i) for i in range(sec.n3d())]
        y = [sec.y3d(i) for i in range(sec.n3d())]
        z = [sec.z3d(i) for i in range(sec.n3d())]

        name = sec.name().split('.')[-1]   

        if name == "soma":
            c = colors_rgc['soma']
        elif name.startswith("dend"):
            c = colors_rgc['dend']
        elif name in ("hill", "AISP", "AISD"):
            c = colors_rgc['axon']   
        elif name.startswith("axon"):
            c = colors_rgc['axon']
        else:
            c = "black"

        ax.plot(x, y, z, c=c, linewidth=2)

    # --- Legend ---
    legend_elements = [
        Line2D([0], [0], color='purple', lw=3, label='BC soma'),
        Line2D([0], [0], color='orange', lw=3, label='BC dendrites'),
        Line2D([0], [0], color='tomato', lw=3, label='BC axon'),
        Line2D([0], [0], color='gold', lw=3, label='BC terminals'),

        Line2D([0], [0], color='navy', lw=3, label='RGC soma'),
        Line2D([0], [0], color='cyan', lw=3, label='RGC dendrites'),
        Line2D([0], [0], color='dodgerblue', lw=3, label='RGC axon'),
    ]

    ax.legend(handles=legend_elements, loc='upper left')

    ax.set_xlabel('X (µm)')
    ax.set_ylabel('Y (µm)')
    ax.set_zlabel('Z (µm)')
    ax.set_title('BC + RGC morphology')
    ax.view_init(elev=30, azim=45)
    #set_equal_aspect(ax)
    plt.tight_layout()
    plt.show()

def plot_cell_with_electrode(cell, Stim):
    fig = plt.figure(figsize=(8, 6))
    ax = fig.add_subplot(111, projection='3d')

    # Colors
    colors = {
        'soma': 'purple',
        'dend': 'orange',
        'axon': 'tomato',
        'term': 'gold'
    }

    # Plot cell morphology
    for sec in cell.all:
        x = [sec.x3d(i) for i in range(sec.n3d())]
        y = [sec.y3d(i) for i in range(sec.n3d())]
        z = [sec.z3d(i) for i in range(sec.n3d())]

        if 'soma' in sec.name():
            c = colors['soma']
        elif 'dend' in sec.name():
            c = colors['dend']
        elif 'axon' in sec.name():
            c = colors['axon']
        elif 'term' in sec.name():
            c = colors['term']
        else:
            c = 'black'

        ax.plot(x, y, z, c=c, linewidth=2)

    # Plot electrode
    ex, ey, ez = Stim['stimXShift'], Stim['stimYShift'], Stim['stimZShift']
    ax.scatter([ex], [ey], [ez], s=200, c='red', marker='o',
               label='Point Electrode')

    ax.set_xlabel('X (µm)')
    ax.set_ylabel('Y (µm)')
    ax.set_zlabel('Z (µm)')
    ax.set_title("BC Morphology + Electrode Position")
    ax.legend()

    ax.view_init(elev=30, azim=45)
    set_equal_aspect(ax)
    plt.show()
