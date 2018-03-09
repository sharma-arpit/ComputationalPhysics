import math
import numpy as np

def gaussian(x,parameter):
  return (x/parameter)*np.exp(-(x/parameter)**2/2)

N = 40
max_iterations = 1000
dr = 0.2 # grid spacing
hbar = 41.437
initial_parameter = 1.4
damping = 0.0001

# HF Potential parameters
a = -1090.0
b = 17488.0

grid = np.array([i*dr for i in range(N)])

# init wf with gaussian * r (so that we don't have to care about the 1/r^2 term in the spherical laplacian; YOLO)
wavefunction = np.array([gaussian(r,initial_parameter) for r in grid])

for i in range(max_iterations):  
  wavefunction /= np.sqrt(dr*sum(wavefunction**2))
  
  # define density with a new, "virtual" wf (wf / grid) that is also normalised (for reasons yet unknown)
  density = np.array([0] + [4 * (wavefunction[j]/grid[j])**2 / (4*np.pi) for j in xrange(1,N)])
  
  potential = (3*a/4)*density + 3*b*density**2/16

  # calculate laplacian on the wave function with three-point approach, treating the edges with two-point
  kinetic = np.empty(N)
  kinetic[0] = hbar*wavefunction[0]/(dr**2)
  kinetic[N-1] = -(hbar/(2*dr**2))*(wavefunction[N-2]-wavefunction[N-1])
  for j in xrange(1,N-1):
    kinetic[j] = -(hbar/(2*dr**2))*(wavefunction[j-1]-2*wavefunction[j]+ wavefunction[j+1])
  
  transformed = kinetic + potential*wavefunction
  energy = dr * sum(transformed*wavefunction)
  wavefunction -= damping * (transformed - energy * wavefunction)
  

# compare original fortran values with ours
#test = sum(np.array([0.0, 0.16082111, 0.318332911, 0.46795094, 0.602513671, 0.711465359, 0.78208679, 0.804534018, 0.778795719, 0.716483831, 0.634517372, 0.54747957, 0.464517713, 0.390013307, 0.325332254, 0.270266443, 0.22391808, 0.185168654, 0.152902335, 0.12610051, 0.103872754, 0.0854586437, 0.070216991, 0.0576112382, 0.0471942723, 0.0385944098, 0.0315031111, 0.0256644022, 0.0208660848, 0.0169323254, 0.0137175629, 0.0111015057, 0.00898501649, 0.00728676701, 0.00594055373, 0.0048931092, 0.00410239166, 0.00353624555, 0.00317138853, 0.00299268612])-wavefunction)
total = sum(kinetic + potential)
#print abs(test)
print wavefunction
print kinetic
print potential
print total