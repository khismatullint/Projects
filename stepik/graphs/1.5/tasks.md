1.5 Урок 4. Список смежности и поиск компонент связности
#1


Дан неориентированный граф, возможно, с петлями и кратными ребрами. Необходимо построить компоненту связности, содержащую первую вершину.

Входные данные

Во входном файле записано два числа N и M (0 < N ≤ 100000, 0 ≤ M ≤ 100000). В следующих M строках записаны по два числа i и j (1 ≤ i, j ≤ N), которые означают, что вершины i и j соединены ребром.

Выходные данные

В первой строке выведите число K - количество вершин в искомой компоненте.

В следующей строке через пробел выведите отсортированные по возрастанию номера вершин, которые принадлежат той же компоненте связности, что и первая вершина (включая первую вершину).

Sample Input:

6 4
3 1
1 2
5 4
2 3

Sample Output:

3
1 2 3 

#2


Дан неориентированный граф, возможно, с петлями и кратными ребрами. Необходимо вывести все компоненты связности.

Входные данные

Во входном файле записано два числа N и M (0 < N ≤ 100000, 0 ≤ M ≤ 100000). В следующих M строках записаны по два числа i и j (1 ≤ i, j ≤ N), которые означают, что вершины i и j соединены ребром.

Выходные данные

В первой строчке выходного файла выведите количество компонент связности. Далее выведите сами компоненты связности в следующем формате: в первой строке количество вершин в компоненте, во второй - сами вершины в отсортированном порядке. Компоненты связности должны быть отсортированы по возрастанию минимального номера вершины из этой компоненты.

Sample Input 1:

6 4
3 1
1 2
5 4
2 3

Sample Output 1:

3
3
1 2 3 
2
4 5 
1
6 

Sample Input 2:

6 4
4 2
1 4
6 4
3 6

Sample Output 2:

2
5
1 2 3 4 6 
1
5 

#3


Дан ориентированный граф, возможно, с петлями и кратными ребрами.

Необходимо найти все вершины, из которых достижима первая вершина.

Входные данные

Во входном файле записано два числа N и M (0 < N ≤ 100000, 0 ≤ M ≤ 100000). В следующих M строках записаны по два числа i и j (1 ≤ i, j ≤ N), которые означают, что существует ребро из вершины i в j.

Выходные данные

Выведите все вершины, из которых достижима первая, в порядке возрастания их номеров.

Sample Input:

6 4
3 1
1 2
5 4
2 3

Sample Output:

1 2 3 

#4


Дан неориентированный граф без петель и кратных рёбер.

Вершины пронумерованы числами от 1 до N. Ребро между вершинами с номерами u и v существует, если и только если сумма этих номеров кратна заданному числу K. 

Необходимо вывести количество компонент связности данного графа. 

Входные данные

Во входном файле записано два числа N, K (0 < N ≤ 100000, 0 ≤ K ≤ 100000).

Выходные данные

Выведите  количество компонент связности данного графа.

Sample Input:

10 3

Sample Output:

2

#5


Дан неориентированный граф без петель и кратных ребер.

Необходимо найти лексикографически минимальный путь между вершинами u и v.

Входные данные

Во входном файле записано два числа N и M (0 < N ≤ 100000, 0 ≤ M ≤ 100000) - количество вершин и количество ребер соответственно. В следующих M строках записаны по два числа i и j (1 ≤ i, j ≤ N), которые означают, что вершины i и j соединены ребром.

В последней строке записаны два числа - u и v (0 < u, v ≤ N)

Выходные данные

Выведите все вершины на лексикографически минимальном пути от u до v (включая эти две вершины). Если пути между вершинами не существует, выведите строку "no solution" без кавычек.

Sample Input:

6 5
4 3
3 2
4 1
1 5
5 2
4 2

Sample Output:

4 1 5 2 

