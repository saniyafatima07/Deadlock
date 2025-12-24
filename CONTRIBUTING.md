# Contributing to Deadlock

Thank you for your interest in contributing to **Deadlock**!  
This project demonstrates classic **deadlock conditions** in operating systems and shows how to **simulate, prevent, and avoid deadlock** using C++ programs. :contentReference[oaicite:1]{index=1}

We welcome improvements, new features, optimizations, additional simulations, documentation updates, and bug fixes.

---

## 🛠️ Development Setup

### 1. Clone the Repository

```bash
git clone https://github.com/saniyafatima07/Deadlock.git
cd Deadlock
```

### 2. Install Dependencies

- Make sure you have a C++ compiler installed (e.g., g++).
- You will also need pthread support for threading.

## Running the Simulations

### 1. Deadlock Simulation
```bash
g++ deadlock_simulation.cpp -o deadlock_simulation -pthread
./deadlock_simulation
```

### 2. Deadlock Prevention
```bash
g++ deadlock_prevention.cpp -o deadlock_prevention -pthread
./deadlock_prevention
```

### 3. Deadlock Avoidance
```bash
g++ deadlock_avoidance.cpp -o deadlock_avoidance -pthread
./deadlock_avoidance
```
Each program demonstrates how processes interact with resources and how deadlock can occur or be prevented.

## Code Contributions

Follow these steps to contribute code:

1. Fork the Repository
   
3. Click the Fork button on the top right of the repository page.
   
5. Create a New Branch
```bash
git checkout -b feature/your-feature-name
```

4. Make Changes
   
6. Write clean, well-documented code and ensure existing functionality is not broken.
   
8. Commit Changes
```bash
git commit -m "Add meaningful commit message"
```

7. Push to Your Branch
```bash
git push origin feature/your-feature-name
```

8. Submit a Pull Request
  - Go to the original repository and click New Pull Request.
  - Provide a clear description of the changes you’ve made.

## Code Style Guidelines

To keep the repository consistent and readable:

- Follow standard C++ conventions.
- Use meaningful variable and function names.
- Add comments to explain logic, especially in simulation code.
- Keep code modular and organized.
