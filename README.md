## Fract-ol

A program designed to render two complex numbers equations, which are Julia and Mandlebrot

## Code Structure

.
└── main()                          # Entry point
    ├── fractal_init()              # Setup MLX connection, Window, Image & Data
    │   ├── mlx_init()
    │   ├── mlx_new_window()
    │   ├── mlx_new_image()
    │   └── data_init()             # Set default zoom, colors, iter
    │
    ├── fractal_render()            # The infinite graphics loop
    │   ├── mlx_clear_window()      # (Optional) specific cleanup
    │   └── y/x loop (0 to WIDTH/HEIGHT)
    │       └── pixel_handling()    # Core logic per pixel
    │           ├── scale()         # Map screen coord to math coord
    │           ├── mandelbrot()    # Z = Z^2 + C logic
    │           ├── julia()         # Z = Z^2 + C (constant C)
    │           └── my_mlx_pixel_put() # Draw pixel to image buffer
    │   └── mlx_put_image_to_window() # Push buffer to screen
    │
    ├── mlx_loop()                  # Keep window open & listen to events
    │   ├── key_handler()           # ESC to close, Arrows to move
    │   ├── mouse_handler()         # Scroll to Zoom In/Out
    │   └── close_handler()         # Clean exit (free memory)
    │
    └── clean_exit()                # Free MLX ptrs & destroy window

## Notes

- in data_init() function initialization is done to :

init_iteration: which determines the number of iterations to test the numbers until it explodes or not, if its assigned to a small number the image shows quickly and its not accurate at all(filled with an exploded numbers but the samll number of test identified the as an non exploded).

escape_value: 

1-