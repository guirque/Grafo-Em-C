<h1>Grafo Em C</h1>
Uma implementação de grafo na linguagem C.</br>
Utiliza um arquivo header adaptado da implementação de listas encadeadas.

<h2>Structs</h2>
<ul>
<li><i><code>llist** graph</code></i></li>
Referida, por meio de <code>typedef</code>, como <code>graph</code>, armazena a estrutura básica de um grafo, isto é, um vetor de listas encadeadas, cujos elementos representam as arestas.
<hr/>
 
 <li><i><code>struct degree</code></i></li>
Referida, por meio de <code>typedef</code>, como <code>degree</code>, armazena a estrutura de três valores inteiros: <code>indegree</code> (grau de entrada), <code>outdegree</code> (grau de saída), e <code>total</code> (a soma do grau de entrada com o de saída). É relacionado a um vértice, por meio da função <code>vertexDegree</code>. 
  
</ul>

<h2>Funções</h2>
<ul>
<li><i><code>createGraph</code></i> (int size)</li>
  Retorna um novo grafo de tamanho <code>size</code>. Um grafo pode ser criado com <code>graph nome = createGraph(tamanho);</code> 
<hr/>

<li><i><code>insertEdge</code></i> (graph aGraph, int origin, int destination, int weight)</code></li>
  Cria uma aresta partindo de um vértice de origem em direção a um outro, de origem, com um custo (peso) atribuído.
<hr/>

<li><i><code>removeEdge</code></i> (graph aGraph, int origin, int destination, int weight)</code></li>
  Remove uma aresta, dadas as informações sobre o vértice de origem, o de destino e o custo (peso) relacionado a essa aresta.
<hr/>

<li><i><code>printGraph</code></i> (graph aGraph)</code></li>
  Imprime um grafo.
<hr/>

<li><i><code>isCompleteGraph</code></i> (graph aGraph)</code></li>
  Retorna 0, caso o grafo não seja completo, e 1, caso contrário. É importante destacar que a definição de completo se aplica a grafos simples (sem laços (self-loops) e duplas direções (mais uma aresta ligando dois vértices)) e não direcionados. Como a implementação do grafo, para este repositório, supõe direções, elas podem ser ignoradas ao analisar se esse grafo é completo ou não.
<hr/>

<li><i><code>vertexDegree</code></i> (graph aGraph, int vertex)</code></li>
  Retorna uma struct <code>degree</code> contendo informações sobre o grau de um vértice de um grafo. Ela inclui o grau de entrada (<code>indegree</code>), o de saída (<code>outdegree</code>), e o grau do vértice em si (<code>total</code>).
<hr/>

<li><i><code>printAllPaths</code></i> (graph aGraph, int origin, int destination)</code></li>
  Imprime todos os caminhos entre dois vértices.
<hr/>

<li><i><code>printLowestWeightPath</code></i> (graph aGraph, int origin, int destination, int weight)</code></li>
  Imprime o caminho de menor peso (custo) total entre dois vértices. Também imprime o valor total do custo desse caminho. 
<hr/>

<li><i><code>printShortestPath</code></i> (graph aGraph, int origin, int destination, int weight)</code></li>
  Imprime o caminho mais curto entre dois vértices. Também imprime o número total de vértices contidos nesse caminho. 

</ul>
