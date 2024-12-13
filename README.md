# School Campus Simulation using GLUT and OpenGL

This project simulates a school campus using 2D and 3D graphics with the help of the GLUT and OpenGL libraries. The simulation includes various visual elements and interactive features, providing a basic introduction to graphics programming.

---

## Features

- 3D representation of campus structures.
- Interactive camera movement and keyboard controls.
- Modular codebase with reusable components.
- Built using OpenGL and GLUT for real-time rendering.

---

## Technologies Used

- **Programming Language:** C++
- **Graphics Libraries:** OpenGL, GLUT
- **Development Environment:** Code::Blocks

---

## Installation

### Prerequisites

1. **OpenGL Development Environment**: Ensure you have OpenGL and GLUT installed on your system.
   - For Windows: Install **freeglut** or similar libraries.
   - For Linux: Use `sudo apt-get install freeglut3-dev`.
2. **Code::Blocks IDE**: Required for building and running the project files.

### Steps

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/your-username/school_campus_using_GLUT_opengl.git
   ```
2. Open the `2_D_basic.cbp` file in Code::Blocks.
3. Configure the OpenGL and GLUT libraries in your IDE settings if not already configured.
4. Build and run the project from Code::Blocks.

---

## Usage

- **Camera Movement:**
  - Arrow keys to navigate the camera view.
- **Interactive Elements:**
  - Specific keys to trigger actions (e.g., lighting effects or object animations).
- **Display Settings:**
  - Adjust display settings through `Display.cpp` for custom rendering.

---

## File Structure

```
.
├── main.cpp                 # Entry point for the application
├── Display.cpp/.h           # Handles display and rendering logic
├── Elements.cpp/.h          # Manages different campus components
├── cube.cpp/.h              # Implements 3D cube elements
├── handleKeyboard.cpp/.h    # Keyboard input handling
├── 2_D_basic.cbp            # Code::Blocks project file
├── .gitignore               # Git ignore settings
└── README.md                # Project documentation
```

---

## Contributing

Contributions are welcome! Feel free to fork this repository and submit a pull request with your enhancements or bug fixes.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

---

## Acknowledgments

- Inspired by OpenGL's capabilities in rendering interactive graphics.
- Thanks to the creators of Code::Blocks and GLUT for their development tools.

---

## Contact

For questions or feedback, feel free to reach out:
- GitHub: [your-username](https://github.com/your-username)
- Email: your-email@example.com

