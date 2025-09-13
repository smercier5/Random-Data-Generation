# Random-Data-Generation
Random data generation with uniform and normal distributions in C  File handling and CSV export  Data visualization with Python and Matplotlib  Automating reports into a single PDF

This project explores **random data generation** in C and **histogram visualization** in Python.  
The workflow includes generating data under different statistical distributions, storing results in `.csv` or `.txt` files, and then creating histograms compiled into a PDF report.  

---

## 📌 Contents
- **data_generator.c** → C program for generating random data under multiple scenarios  
- **histogram_plotter.py** → Python script to read histogram files and export them as a combined PDF  

---

## ⚙️ Program Details
### 1. `data_generator.c` (C Program)
- Generates random sequences of numbers under multiple distributions:
  - Uniform integers & reals  
  - Normally distributed integers & reals  
  - Truncated normal integers & reals  
- Runs across **3 scenarios** with different means, standard deviations, and bounds.  
- Outputs results into `.csv` files for each scenario.  

**Build & Run with Makefile**  
```bash
# Compile
make

# Run the default executable
make run

# (Optional) Run the statically linked version
./ass1_static_linked

# Clean up build files
make clean
yaml
Copy code

