[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![GNU License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="http://github.com/umutsevdi1/Wilson-s-Maze-Generation-Algorithm">
    <img src="https://raw.githubusercontent.com/umutsevdi1/Logic-Circuit-Simulator/main/icon.png" alt="Logo" width="80" height="80">
  </a>
  
  <h3 align="center">Wilson's Maze Generation Algorithm</h3>
  <p align="center">Wilson's Maze Generation Algorithm is my project for Introduction to Structural Programming Lecture.</p>
  
</p>



## Definition of Labyrinth Algorithms
Labyrinth algorithms generate randomly generated maps. They are used in random number generations and level designs in video games. There are different types of labyrinth algorithm :
  * Graph Theory Based Algorithms : 
    * Depth-First Search, Randomized Kruskal, Randomized Prim and Wilson's Algorithm are popular choices for Graph Theory based algorithms.
  * Recursive Division Method : 
    * This method is based on creating different cells within it's components.   
  * Cellular Automata Method :
    * In Cellular Automata Methods built-in cells are placed as patterns to the map. Example : B3/S1234
  * Other methods
Those methods are not necessarily to be used individually. We can combine them in our projects.

## Wilson Algorithm's Definition 
Wilson Algorithm is a Graph Theory based labyrinth generation algorithm. Wilson Algorithm uses `random walking`, however it performs faster than Aldous-Broder like algorithms. Since Wilson algorithm uses random walking it starts slowly but it's speed increases with the number of blocks on the map. The reason behind that is the lack of space in the map.

## Process of Wilson Algorithm
1. Marks a random point on the map.
2. Marks another point which has not been marked.
3. Performs `random walking` until it reaches the second point. Random walking can walk through previously visited places. And while walking process saves the last direction to each tile.
4. Upon arrival, clears the path by selecting the  shortest walkable distance. This process is done by following the last direction sign on each selected tile.
5. If the reached point is already marked before, stops there and connects these two paths.
6. Repeats whole process until the program can not select two points that are not part of a path.

## Advantages and Disadvantages 
* Labyrinths created with Wilson Algorithm have less dead ends than the others. This causes multiple solutions on the labyrinth. Because of that it is mostly used in level designs of computer games. It does not use pre-defined cells, creates entirely new ones; which allows it to create unique maps on each use. Labyrinth's hardness increases with the size of the map. The reason is the variety of points that can be selected as start and end point. 
* Random walking increases the duration to build the map.

## Analysis of the Algorithm
Wilson Algorithm is based on following factors : screen size, frame per second and the pass value. 
* Screen size is the size of the canvas to build the map.
* Pass value is the amount of attempts avaliable until it reaches to the second point.
* FPS amount is the amount of frames displayed per second.

Screen size and pass value  increases the hardness of the map. Also each of these values increase the build time. 



## Screenshots


![Screenshot 2](https://raw.githubusercontent.com/umutsevdi1/Wilson-s-Maze-Generation/main/screenshots/230wilson100.PNG)
![Screenshot 3](https://raw.githubusercontent.com/umutsevdi1/Wilson-s-Maze-Generation/main/screenshots/labirent_1.png)
![Screenshot 4](https://raw.githubusercontent.com/umutsevdi1/Wilson-s-Maze-Generation/main/screenshots/labirent_2.png)


<!-- LICENSE -->
## License

Distributed under the  MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact
* Project Link: [https://github.com/umutsevdi1/Logic-Circuit-Simulator](https://github.com/umutsevdi1/Wilson-s-Maze-Generation-Algorithm)



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[forks-shield]: https://img.shields.io/github/forks/umutsevdi1/Wilson-s-Maze-Generation-Algorithm.svg?style=for-the-badge
[forks-url]: https://github.com/umutsevdi1/Wilson-s-Maze-Generation-Algorithm/network/members
[stars-shield]: https://img.shields.io/github/stars/umutsevdi1/Wilson-s-Maze-Generation-Algorithm.svg?style=for-the-badge
[stars-url]: https://github.com/umutsevdi1/Wilson-s-Maze-Generation-Algorithm/stargazers
[issues-shield]: https://img.shields.io/github/issues/umutsevdi1/Wilson-s-Maze-Generation-Algorithm.svg?style=for-the-badge
[issues-url]: https://github.com/umutsevdi1/Wilson-s-Maze-Generation-Algorithm/issues
[license-shield]: https://img.shields.io/github/license/umutsevdi1/Wilson-s-Maze-Generation-Algorithm.svg?style=for-the-badge
[license-url]: https://github.com/umutsevdi1/Wilson-s-Maze-Generation-Algorithm/blob/main/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/umut-sevdi
[product-screenshot]: images/screenshot.png

