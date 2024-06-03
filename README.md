# tree-image-compression

![image](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![image](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![image](https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![image](https://img.shields.io/badge/windows%20terminal-4D4D4D?style=for-the-badge&logo=windows%20terminal&logoColor=white)

>[!WARNING]
>This project hasn't yet been tested as of late and is still in development

Author: [Andrew Gyakobo](https://github.com/Gyakobo)

This project aims utilize a graph(a tree) as form of two-dimensional image compression by implementing a special kind of data structure where it basically groups repeating variables into a node and ungroups non-repeating values into their own nodes.

## Introduction

In this example specifically we shall be compressing a grayscale image. Given that pixels are usually stored as a series of integers, we would be using the `int` type to store said pixels.

## Methodology

One method to compress an image is to store it in a tree data structure where each node would have up to 4 children. They shall present  


## License
MIT