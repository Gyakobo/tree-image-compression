# tree-image-compression

![image](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![image](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![image](https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![image](https://img.shields.io/badge/windows%20terminal-4D4D4D?style=for-the-badge&logo=windows%20terminal&logoColor=white)

>[!NOTE]
>Each processed image file by default have to be in a form a square in order to be processed.

>[!WARNING]
>This project hasn't yet been tested as of late and is still in development.

Author: [Andrew Gyakobo](https://github.com/Gyakobo)

This project aims utilize a graph(a tree) as a form of two-dimensional image compression by implementing a special kind of data structure where it basically groups repeating variables into a node and ungroups non-repeating values into their own nodes.

## Introduction

In this example specifically we shall be compressing a grayscale image. Given that pixels are usually stored as a series of integers, we would be using the `int` type to store said pixels.

## Methodology

One method to compress an image is to store it in a tree data structure where each node would have up to 4 children. Each of them shall represent a select partition of the image in one of the four quartiles: northwest, northeast, southwest, and southeast. Needless to say, the root node marked with a `-1` will either represent the entire image or another subset of partitions. The partitioning process will continue till each node in the partitioned subset carries the same color intensity. 

1) Let's consider the following image content from the given [sample.txt](https://github.com/Gyakobo/tree-image-compression/blob/main/sample.txt):

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

2) Assuming all the pixels are not unique, we then partition the image into equal subsets of 4 by 4 smaller images as shown by the below:

<table>
<tr><td>

| 3 | 3 | 3 | 3 |
|---|---|---|---|
| 3 | 3 | 3 | 3 |
| 3 | 3 | 3 | 3 |
| 3 | 3 | 3 | 3 |

</td><td>

| 2 | 2 | 1 | 1 |
|---|---|---|---|
| 2 | 2 | 1 | 1 |
| 0 | 5 | 1 | 0 |
| 0 | 0 | 0 | 2 |

</td></tr>

<tr><td>

| 1 | 1 | 1 | 1 |
|---|---|---|---|
| 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 |

</td><td>

| 1 | 1 | 0 | 3 |
|---|---|---|---|
| 1 | 1 | 0 | 0 |
| 5 | 5 | 0 | 0 |
| 5 | 5 | 0 | 0 |

</td></tr>
</table>

3) Afterwards we delve into the partitions more, and subsequently divide them into even smaller subsets, in this case 2 by 2 partitions. You may have noticed a recurring partain: each partition is in multiples of 2. From the getgo our partition is 8, then 4, then 2 and soon enough 1.

<table>
<tr><td>

| 3 | 3 | 3 | 3 |
|---|---|---|---|
| 3 | 3 | 3 | 3 |
| 3 | 3 | 3 | 3 |
| 3 | 3 | 3 | 3 |

</td>    <td> <table>     <tr><td>

| 2 | 2 |
|---|---|
| 2 | 2 |


</td><td>

| 1 | 1 |
|---|---|
| 1 | 1 |

</td></tr><tr>

<td>

| 0 | 5 |
|---|---|
| 0 | 0 |

</td><td>

| 1 | 0 |
|---|---|
| 0 | 2 |

</td></tr> </table>      </td> 

</tr>

<tr><td>

| 1 | 1 | 1 | 1 |
|---|---|---|---|
| 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 |

</td><td>

<table>

<tr><td>

| 1 | 1 |
|---|---|
| 1 | 1 |

</td><td>

| 0 | 3 |
|---|---|
| 0 | 0 |

</td></tr>

<tr><td>

| 5 | 5 |
|---|---|
| 5 | 5 |

</td><td>

| 0 | 0 |
|---|---|
| 0 | 0 |

</td></tr>

</table>

</td></tr>
</table>

4) As the last step we make quick work of all the last non-unique variables. Judging by the remaining 10 partitions there are only 3 subsets to worked on. This shall be our final partition.

<table>
<tr><td>

| 3 | 3 | 3 | 3 |
|---|---|---|---|
| 3 | 3 | 3 | 3 |
| 3 | 3 | 3 | 3 |
| 3 | 3 | 3 | 3 |

</td>    <td> <table>     <tr><td>

| 2 | 2 |
|---|---|
| 2 | 2 |


</td><td>

| 1 | 1 |
|---|---|
| 1 | 1 |

</td></tr><tr>

<td>

<!---
| 0 | 5 |
|---|---|
| 0 | 0 |
-->

<table>
<tr>
<td><table><tr><td>0</td></tr></table></td>
<td><table><tr><td>5</td></tr></table></td>
</tr>

<tr>
<td><table><tr><td>0</td></tr></table></td>
<td><table><tr><td>0</td></tr></table></td>
</tr>
</table>

</td><td>

<!--
| 1 | 0 |
|---|---|
| 0 | 2 |
-->

<table>
<tr>
<td><table><tr><td>1</td></tr></table></td>
<td><table><tr><td>0</td></tr></table></td>
</tr>

<tr>
<td><table><tr><td>0</td></tr></table></td>
<td><table><tr><td>2</td></tr></table></td>
</tr>
</table>

</td></tr> </table>      </td> 

</tr>

<tr><td>

| 1 | 1 | 1 | 1 |
|---|---|---|---|
| 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 |

</td><td>

<table>

<tr><td>

| 1 | 1 |
|---|---|
| 1 | 1 |

</td><td>

<!--
| 0 | 3 |
|---|---|
| 0 | 0 |
-->

<table>
<tr>
<td><table><tr><td>0</td></tr></table></td>
<td><table><tr><td>3</td></tr></table></td>
</tr>

<tr>
<td><table><tr><td>0</td></tr></table></td>
<td><table><tr><td>0</td></tr></table></td>
</tr>
</table>


</td></tr>

<tr><td>

| 5 | 5 |
|---|---|
| 5 | 5 |

</td><td>

| 0 | 0 |
|---|---|
| 0 | 0 |

</td></tr>

</table>

</td></tr>
</table>

5) All this partitions can thereafter be presented in the following tree below. Each node the tree shall have four other nodes representing the four partitions (NW, NE, SW, and SE order). If however the partition fully consists of pixels of the same intensity, then the node would just be labeled with such intensity.

<image src="./assets/compression_tree.png">

>[!NOTE]
>Each circle denotes a node with 4 other leaf nodes. Each double circle is the 'end' node with no child leaf nodes(null references).

6) Finally, the image can then be encoded in a sequence of integers by performing a preorder traversal of the corresponding. You could of course change the traversal order by just switching the places of the `preorder(root->children[n])` functions. Hence you could even easily simulate both inorder and postorder traversals or any other traversal you may come up with.

```c
void preorder(struct Node *root) {
    printf("d: %d\n", root->intensity);

    if (root->intensity == -1) {
        preorder(root->children[0]);
        preorder(root->children[1]);
        preorder(root->children[2]);
        preorder(root->children[3]);
    } 
    else {
        free(root);
        return;
    } 
}
```

## Code snippets



## License
MIT
