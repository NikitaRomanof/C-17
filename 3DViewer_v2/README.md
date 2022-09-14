A program for visualizing a model in three-dimensional space.

- The program was developed in the C++ language of the C++17 standard
- The build is configured with a Makefile with a standard set of targets for GNU programs: all, install, uninstall, clean, dvi, dist, tests.
- Only one model can exist on the screen at a time.
- The program provides an opportunity:
    - Load model from obj format file (support for list of vertices, surfaces and normals).
    - Move the model at a given distance relative to the X, Y, Z axes.
    - Rotate the model by a given angle relative to its X, Y, Z axes.
    - Scale the model by the given value.
    - Switch object display type: wireframe, flat shading, soft shading (Gouraud or Phong).
    - Set the light source, its base intensity (via three components) and position.
- Graphical user interface contains:
    - A button to select a file with a model and a field to display its name.
    - Model visualization zone.
    - Buttons and input fields for moving the model.
    - Buttons and input fields for model rotation.
    - Buttons and input fields for scaling the model.
    - Information about the loaded model - file name, number of vertices and edges.

- The program allows you to set the type of projection (parallel and central)
- The program allows you to customize the type (solid, dotted), color and thickness of edges, display method (none, circle, square), color and size of vertices, select background color, select the base color of the object
- Settings are saved between program restarts

- The program allows you to save the received ("rendered") images to a file in bmp and jpeg formats
- The program allows you to record small "screencasts" using a special button - current custom affine transformations of the loaded object into gif-animation (640x480, 10fps, 5s)
- The program allows using a special button to save a short preview of the model - gif-animation (640x480, 10fps, 5s) with object rotation around one axis.
- The program allows you to apply a texture to an object
- Texture is not displayed in wireframe mode
