import numpy as np
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
import pandas as pd
from neuron import h

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

def plot_electrode_z_view(bc_cells, field_files_dir, rgc_cell=None):
    """
    Plot BC cells and electrode with detailed morphology visualization.
    Shows dendrites, soma, axon, and terminals with electric field background.
    """
    def get_section_diams(sec):
        n = int(h.n3d(sec=sec))
        if n == 0:
            return None
        return [h.diam3d(i, sec=sec) for i in range(n)]

    
    # Helper function to extract all 3D points from a section
    def get_section_coords(sec):
        n = int(h.n3d(sec=sec))
        if n == 0:
            return None, None, None
        xs = [h.x3d(i, sec=sec) for i in range(n)]
        ys = [h.y3d(i, sec=sec) for i in range(n)]
        zs = [h.z3d(i, sec=sec) for i in range(n)]
        return xs, ys, zs
    
    # ==================== Load Electric Field Data ====================
    # We'll create an X-Z slice by averaging over Y (or taking Y=ImplantY)
    z_slices_to_average = range(0, 125)  # All z slices
    
    # Load first slice to get dimensions
    with open(f'{field_files_dir}/slice_0.txt', 'r') as f:
        sample_slice = pd.read_csv(f, sep='\t', header=None).values
    
    ny, nx = sample_slice.shape
    
    # Create coordinate arrays (from your field parameters)
    x_coords = np.linspace(-1000, 1000, nx)
    y_coords = np.linspace(-1000, 1000, ny)
    z_coords = np.arange(0, 125)
    
    # Find the y-index closest to ImplantY (for X-Z slice)
    y_center_idx = np.argmin(np.abs(y_coords - h.ImplantY))
    
    # Build X-Z field array
    field_xz = np.zeros((len(z_coords), nx))
    
    print("Loading electric field data for X-Z visualization...")
    for z_idx, z in enumerate(z_coords):
        with open(f'{field_files_dir}/slice_{z}.txt', 'r') as f:
            field_data = pd.read_csv(f, sep='\t', header=None).values
        # Extract the row at y_center_idx
        field_xz[z_idx, :] = field_data[y_center_idx, :]
    
    # ==================== Create Figure ====================
    fig = plt.figure(figsize=(10, 6))
    ax = fig.add_subplot(1, 1, 1)
    
    # ==================== Plot Electric Field Background ====================
    # Plot field as background heatmap
    im = ax.imshow(field_xz, 
                   extent=(x_coords[0], x_coords[-1], z_coords[0], z_coords[-1]),
                   origin='lower',
                   aspect='auto',
                   cmap='RdBu_r',
                   alpha=0.7,  # Semi-transparent so cells show clearly
                   zorder=0,
                   vmin=-np.percentile(np.abs(field_xz), 95),  # Symmetric colormap
                   vmax=np.percentile(np.abs(field_xz), 95))
    
    # Add colorbar
    cbar = plt.colorbar(im, ax=ax, pad=0.02)
    cbar.set_label('Electric Field (mV/mA)', fontsize=12, fontweight='bold')

    
    # ==================== Plot Electrode Position ====================
    ax.plot(h.ImplantX, h.ImplantZ, 'k*', markersize=20, 
            label=f'Electrode ({h.ImplantX:.0f}, {h.ImplantZ:.0f})', 
            zorder=100, markeredgewidth=1.5)
    
    # Make horizontal line at ImplantZ
    ax.axhline(y=h.ImplantZ, color='black', linestyle='-', linewidth=2,
               label=f'Electrode Z={h.ImplantZ:.0f} μm', zorder=10)
    
    # ==================== Plot Each BC Cell ====================
    legend_added = {'dendrite': False, 'soma': False, 'axon': False, 'terminal': False, 'hill': False}
    bc_colors = plt.cm.plasma(np.linspace(0, 1, len(bc_cells)))
    
    for bc_idx, bc in enumerate(bc_cells):
        
        # --- SOMA (plot as filled region) ---
        soma_xs, soma_ys, soma_zs = get_section_coords(bc.soma)
        if soma_xs is not None and len(soma_xs) > 0:
            # Use center of soma coordinates
            soma_x_center = (max(soma_xs) + min(soma_xs)) / 2
            soma_z_center = (max(soma_zs) + min(soma_zs)) / 2
            diams = get_section_diams(bc.soma)
            if diams is not None:
                soma_diameter = float(np.max(diams))  # or np.mean(diams)
            else:
                soma_diameter = float(bc.soma.diam)

            
            # Draw circle for soma - use actual diameter in data coordinates
            circle = plt.Circle((soma_x_center, soma_z_center), 
                               soma_diameter/2,  # radius is half diameter
                               color="grey",
                               zorder=50)
            circle_edge = 'black'
            circle_linewidth = 2.5
            circle.set_edgecolor(circle_edge)
            circle.set_linewidth(circle_linewidth)
            ax.add_patch(circle)
        
        # --- DENDRITES ---
        for sec in bc.dendritic:
            xs, ys, zs = get_section_coords(sec)
            if xs is not None:
                label = 'Dendrite' if not legend_added['dendrite'] else ''
                ax.plot(xs, zs, color='darkblue', linewidth=2.5, linestyle='-', label=label, zorder=3)
                legend_added['dendrite'] = True
        
        # --- AXON ---
        for sec in bc.axonal:
            xs, ys, zs = get_section_coords(sec)
            if xs is not None:
                label = 'Axon' if not legend_added['axon'] else ''
                ax.plot(xs, zs, color='black', linewidth=2.5, linestyle='-', label=label, zorder=4)
                legend_added['axon'] = True
        
        # --- TERMINAL ---
        for sec in bc.terminal:
            xs, ys, zs = get_section_coords(sec)
            if xs is not None:
                label = 'Terminal' if not legend_added['terminal'] else ''
                ax.plot(xs, zs, color='darkred', linewidth=2.5, 
                       alpha=0.9, linestyle='-', label=label, zorder=5)
                legend_added['terminal'] = True
                
                # Mark terminal endpoint
                ax.scatter([xs[-1]], [zs[-1]], s=50, marker='s', 
                          color='red', edgecolors='darkred', 
                          linewidths=2, zorder=51)
                
    # ==================== Plot RGC Cell ====================
    if rgc_cell is not None:
        soma_xs, soma_ys, soma_zs = get_section_coords(rgc_cell.soma)
        if soma_xs is not None and len(soma_xs) > 0:
            # Use center of soma coordinates
            soma_x_center = (max(soma_xs) + min(soma_xs)) / 2
            soma_z_center = (max(soma_zs) + min(soma_zs)) / 2
            diams = get_section_diams(rgc_cell.soma)
            if diams is not None:
                soma_diameter = float(np.max(diams))  # or np.mean(diams)
            else:
                soma_diameter = float(rgc_cell.soma.diam)
            
            # Draw circle for soma - use actual diameter in data coordinates
            circle = plt.Circle((soma_x_center, soma_z_center), 
                               soma_diameter/2,  # radius is half diameter
                               color="grey",
                               zorder=50)
            circle_edge = 'black'
            circle_linewidth = 2.5
            circle.set_edgecolor(circle_edge)
            circle.set_linewidth(circle_linewidth)
            ax.add_patch(circle)
            
            # Add label only once
            if not legend_added['soma']:
                ax.scatter([], [], s=100, color='gray', edgecolor="black", marker='o', 
                          linewidths=2.5, label='BC Soma')
                legend_added['soma'] = True
        
        # --- RGC DENDRITES (cyan, thin) ---
        for i in range(len(rgc_cell.dend)):
            sec = rgc_cell.dend[i]
            xs, ys, zs = get_section_coords(sec)
            if xs is not None:
                ax.plot(xs, zs, color='darkblue', linewidth=1.5, linestyle='-', label=label, zorder=6)
        
        # --- RGC AXON INITIAL SEGMENT (hill, AISP, AISD) ---
        for sec_name, sec in [('hill', rgc_cell.hill), ('AISP', rgc_cell.AISP), ('AISD', rgc_cell.AISD)]:
            xs, ys, zs = get_section_coords(sec)
            if xs is not None:
                ax.plot(xs, zs, color='orange', linewidth=2.5, linestyle='-', label=label, zorder=7)
            # Add label only once
            if not legend_added['hill']:
                ax.plot([], [], color='orange', linewidth=2.5, linestyle='-', label='RGC Initial Segment')
                legend_added['hill'] = True

        # --- RGC AXON (magenta, thick) ---
        for i in range(len(rgc_cell.axon)):
            sec = rgc_cell.axon[i]
            xs, ys, zs = get_section_coords(sec)
            if xs is not None:
                ax.plot(xs, zs, color='black', linewidth=2.5, linestyle='-', label=label, zorder=8)
    
    # ==================== Formatting ====================
    ax.set_xlabel('X position (μm)', fontsize=14, fontweight='bold')
    ax.set_ylabel('Z position (μm)', fontsize=14, fontweight='bold')
    ax.set_title(f'BC Cells with Electric Field Background (X-Z Projection at Y={h.ImplantY:.0f} μm)', 
                fontsize=15, fontweight='bold')
    
    # Legend
    ax.legend(loc='upper left', fontsize=11, framealpha=0.95, 
             edgecolor='black', fancybox=True)
    
    # Grid
    ax.grid(True, alpha=0.3, linestyle='--', linewidth=0.5, color='white')
    
    # Set limits with some padding
    ax.set_ylim(-10, 135)
    ax.set_xlim(-100, 100)  # Adjust based on your BC_SPREAD_RADIUS
    ax.set_aspect('equal', adjustable='box')

    plt.tight_layout()
    plt.show()


def plot_synaptic_connections(bc_cells, rgc_cell, synapse_locations):
    """Visualize BC-RGC synaptic connections in X-Z and X-Y views."""
    
    def get_section_coords(sec):
        n = int(h.n3d(sec=sec))
        if n == 0:
            return None, None, None
        xs = [h.x3d(i, sec=sec) for i in range(n)]
        ys = [h.y3d(i, sec=sec) for i in range(n)]
        zs = [h.z3d(i, sec=sec) for i in range(n)]
        return xs, ys, zs
    
    fig = plt.figure(figsize=(16, 7))
    
    # ========== SUBPLOT 1: X-Z view ==========
    ax1 = plt.subplot(1, 2, 1)
    
    legend_added = {'bc_term': False, 'rgc_dend': False, 'rgc_soma': False}
    
    # Plot BC terminals
    for bc_idx, bc in enumerate(bc_cells):
        for sec in bc.terminal:
            xs, ys, zs = get_section_coords(sec)
            if xs is not None:
                label = 'BC Terminal' if not legend_added['bc_term'] else ''
                ax1.plot(xs, zs, color='darkred', linewidth=2.5, 
                        alpha=0.8, label=label, zorder=3)
                legend_added['bc_term'] = True
    
    # Plot RGC dendrites
    for i in range(len(rgc_cell.dend)):
        sec = rgc_cell.dend[i]
        xs, ys, zs = get_section_coords(sec)
        if xs is not None:
            label = 'RGC Dendrite' if not legend_added['rgc_dend'] else ''
            ax1.plot(xs, zs, color='darkblue', linewidth=1.5, 
                    alpha=0.6, label=label, zorder=2)
            legend_added['rgc_dend'] = True
    
    # Plot RGC soma
    soma_xs, soma_ys, soma_zs = get_section_coords(rgc_cell.soma)
    if soma_xs is not None:
        soma_x = np.mean(soma_xs)
        soma_z_center = (max(soma_zs) + min(soma_zs)) / 2
        soma_diam = rgc_cell.soma.diam
        soma_height = max(soma_zs) - min(soma_zs)
        
        from matplotlib.patches import Ellipse
        ellipse = Ellipse((soma_x, soma_z_center), 
                        width=soma_diam, height=soma_height,
                        facecolor='grey', edgecolor='black',
                        linewidth=1.5,  zorder=50)
        ax1.add_patch(ellipse)
        ax1.scatter([], [], s=50, color='grey', marker='o', 
                   edgecolors='black', linewidths=1.5, label='RGC Soma')
    
    # Plot synaptic connections
    for loc in synapse_locations:
        pre_x, pre_y, pre_z = loc['pre_coords']
        post_x, post_y, post_z = loc['post_coords']
        
        ax1.plot([pre_x, post_x], [pre_z, post_z], 
                'orange', linewidth=1, alpha=0.4, zorder=1)
        ax1.scatter([pre_x], [pre_z], s=30, color='red', 
                   marker='s', edgecolor='darkred', zorder=10)
        ax1.scatter([post_x], [post_z], s=30, color='blue', 
                   marker='o',  edgecolors='darkblue', zorder=10)
    
    # Legend markers for synapses
    ax1.scatter([], [], s=30, color='red', edgecolor='darkred', marker='s', label='Presynaptic', alpha=0.7)
    ax1.scatter([], [], s=30, color='blue', edgecolors='darkblue', marker='o', label='Postsynaptic', alpha=0.7)
    
    ax1.set_xlabel('X position (μm)', fontsize=14, fontweight='bold')
    ax1.set_ylabel('Z position (μm)', fontsize=14, fontweight='bold')
    ax1.set_title('BC-RGC Synaptic Connections (X-Z view)', fontsize=15, fontweight='bold')
    ax1.legend(loc='upper left', fontsize=10, framealpha=0.95, 
              edgecolor='black', fancybox=True)
    ax1.grid(True, alpha=0.3, linestyle='--', linewidth=0.5, color='gray')
    # set equal aspect
    ax1.axis('equal')

    # ========== SUBPLOT 2: X-Y view ==========
    ax2 = plt.subplot(1, 2, 2)
    
    # Plot synaptic connections
    for loc in synapse_locations:
        pre_x, pre_y, pre_z = loc['pre_coords']
        post_x, post_y, post_z = loc['post_coords']
        
        ax2.plot([pre_x, post_x], [pre_y, post_y], 
                'orange', linewidth=1, alpha=0.4, zorder=1)
        ax2.scatter([pre_x], [pre_y], s=30, color='red', edgecolor='darkred', marker='s', zorder=10, label='Presynaptic' if loc == synapse_locations[0] else '')
        ax2.scatter([post_x], [post_y], s=30, color='blue', edgecolors='darkblue', marker='o', zorder=10, label='Postsynaptic' if loc == synapse_locations[0] else '')
    
    ax2.set_xlabel('X position (μm)', fontsize=14, fontweight='bold')
    ax2.set_ylabel('Y position (μm)', fontsize=14, fontweight='bold')
    ax2.set_title('BC-RGC Synaptic Connections (X-Y view)', fontsize=15, fontweight='bold')
    ax2.legend(loc='upper left', fontsize=10, framealpha=0.95, 
              edgecolor='black', fancybox=True)
    ax2.grid(True, alpha=0.3, linestyle='--', linewidth=0.5, color='gray')
    ax2.axis('equal')
    
    plt.tight_layout()
    plt.show()




def plot_electric_field_slices(field_files_dir):
    """Plot electric field distribution at different depths."""
    
    # Load one slice to get dimensions
    with open(f'{field_files_dir}/slice_0.txt', 'r') as f:
        sample_slice = pd.read_csv(f, sep='\t', header=None).values
    
    ny, nx = sample_slice.shape
    
    # Parameters from your hoc file
    x_spacing = 4  # μm
    y_spacing = 4  # μm
    z_spacing = 1  # μm
    
    # Create coordinate arrays
    x_coords = np.linspace(-1000, 1000, nx)  # Centered at electrode
    y_coords = np.linspace(-1000, 1000, ny)
    
    # Choose interesting z-slices
    z_slices = [0, 30, 60, 90, 120]  # Different depths
    
    fig, axes = plt.subplots(2, 3, figsize=(18, 12))
    axes = axes.flatten()
    
    for idx, z_slice in enumerate(z_slices):
        if z_slice >= 125:
            continue
            
        # Load the slice
        with open(f'{field_files_dir}/slice_{z_slice}.txt', 'r') as f:
            field_data = pd.read_csv(f, sep='\t', header=None).values
        
        # Plot
        im = axes[idx].imshow(field_data, 
                             extent=(-1000, 1000, -1000, 1000),
                             origin='lower',
                             cmap='RdBu_r',
                             aspect='equal')
        
        axes[idx].set_xlabel('X (μm)', fontsize=11)
        axes[idx].set_ylabel('Y (μm)', fontsize=11)
        axes[idx].set_title(f'Z = {z_slice} μm', fontsize=12, fontweight='bold')
        
        # Add electrode marker
        axes[idx].plot(0, 0, 'k*', markersize=15, label='Electrode')
        
        # Add colorbar
        cbar = plt.colorbar(im, ax=axes[idx])
        cbar.set_label('Field (mV/mA)', fontsize=10)
        
        axes[idx].grid(True, alpha=0.2)
        axes[idx].legend(loc='upper right')
    
    # Use last subplot for colorbar reference
    axes[-1].axis('off')
    axes[-1].text(0.5, 0.5, 
                 f'Electric Field Distribution\n'
                 f'Electrode: ({h.ImplantX}, {h.ImplantY}, {h.ImplantZ}) μm\n'
                 f'Grid: {nx}×{ny}×125 voxels\n'
                 f'Resolution: {x_spacing}×{y_spacing}×{z_spacing} μm',
                 ha='center', va='center', fontsize=12,
                 bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.5))
    
    plt.tight_layout()
    plt.show()