# RGB to Gray conversion in OpenCV

This repository uses OpenCV in C++ to convert an RGB input image to a grayscale image according to the following formula ([luminosity method](https://www.tutorialspoint.com/dip/grayscale_to_rgb_conversion.htm)):
$$
I_{gray} = 0.2989 \times I_r + 0.5871 \times I_g + 0.1140 \times I_b
$$

Where $I_{gray}$ is the output grayscale image and $I_r$, $I_g$, and $I_b$ are the red, green, and blue components of the input image $I$ respectively.

The program uses a double for loop to calculate each pixel independently for simplicity. 

## Compiling and running
1. Compile the program using `cmake` and `make`
    
    ```bash
    cmake .
    make
    ```

1. Run the program
    
    ```
    ./rgb2gray input_color_image_filename output_grayscale_image_filename
    ```