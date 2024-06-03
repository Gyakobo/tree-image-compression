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

One method to compress an image is to store it in a tree data structure where each node would have up to 4 children. Each of them shall represent a select partition of the image in one of the four quartiles: northwest, northeast, southwest, and southeast. Needless to say, the root node marked with a `-1` will either represent the entire image or another subset of partitions. The partitioning process will continue till each node in the partitioned subset carries the same color intensity. 

Let's consider the following image content from the given [sample.txt](https://github.com/Gyakobo/tree-image-compression/blob/main/sample.txt):


| 3 | 3 | 3 | 3 | 2 | 2 | 1 | 1 |
|---|---|---|---|---|---|---|---|
| 3 | 3 | 3 | 3 | 2 | 2 | 1 | 1 |
| 3 | 3 | 3 | 3 | 0 | 5 | 1 | 0 |
| 3 | 3 | 3 | 3 | 0 | 0 | 0 | 2 |
| 1 | 1 | 1 | 1 | 1 | 1 | 0 | 3 |
| 1 | 1 | 1 | 1 | 1 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 | 5 | 5 | 0 | 0 |
| 1 | 1 | 1 | 1 | 5 | 5 | 0 | 0 |

>[!NOTE]
>Each 8 lines in the sample file denotes a row in the [image](https://github.com/Gyakobo/tree-image-compression/blob/main/sample.txt) file

Assuming all the pixels are not unique, then partition the image into equal subsets, in out into 4 by 4 smaller images as shown by the below:

<table>
    <tr> 
        <td>
            | 3 | 3 | 3 | 3 |
            |---|---|---|---|
            | 3 | 3 | 3 | 3 |
            | 3 | 3 | 3 | 3 |
            | 3 | 3 | 3 | 3 |
        </td> 
        <td>
            | 3 | 3 | 3 | 3 |
            |---|---|---|---|
            | 3 | 3 | 3 | 3 |
            | 3 | 3 | 3 | 3 |
            | 3 | 3 | 3 | 3 |
        </td> 
    </tr>
</table>


<image src="./assets/compression_tree.png">

## License
MIT